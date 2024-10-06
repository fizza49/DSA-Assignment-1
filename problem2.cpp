#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstdint>

struct Node {
    uint64_t value;  // 64-bit integer to store digits
    Node* next;      // Pointer to the next node

    Node(uint64_t val) : value(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addNode(uint64_t value) {
        Node* newNode = new Node(value);
        newNode->next = head; // Insert at the head
        head = newNode;
    }

    void display() {
        Node* current = head;
        int index = 0; // To keep track of the node index
        while (current) {
            if (index == 0) {
                std::cout << "Head: " << current->value << std::endl;
            } else {
                std::cout << "Node " << index << ": " << current->value << std::endl;
            }
            current = current->next;
            index++;
        }
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    Node* getHead() {
        return head;
    }

    // Function to check divisibility across nodes (starting from the least significant)
    bool isDivisibleBy(uint64_t divisor) {
        if (divisor == 0) {
            std::cerr << "Divisor cannot be zero!" << std::endl;
            return false; // Cannot divide by zero
        }

        // Use a vector to reverse the order of nodes for processing
        std::vector<uint64_t> values; // Vector to store node values
        Node* current = head;

        // Store all node values in a vector
        while (current) {
            values.push_back(current->value);
            current = current->next;
        }

        uint64_t remainder = 0;
        // Iterate through the vector in reverse order
        for (int i = values.size() - 1; i >= 0; --i) {
            remainder = (remainder + values[i]) % divisor; // Update remainder
            if (i > 0) { // If not the last node, multiply remainder by 10^20
                remainder = (remainder * 10000000000ULL) % divisor;
            }
        }

        return remainder == 0; // If remainder is 0, the number is divisible by the divisor
    }

    // Function to check if the number is prime
    void checkPrime() {
        const uint64_t maxLimit = std::numeric_limits<uint64_t>::max();
        bool isProbablyPrime = true;

        // Check for divisibility starting from 2 to the square root of the maximum limit
        for (uint64_t divisor = 2; divisor * divisor <= maxLimit; ++divisor) {
            if (isDivisibleBy(divisor)) {
                std::cout << "The number is NOT prime (divisible by " << divisor << ")." << std::endl;
                isProbablyPrime = false;
                break; // Exit the loop on first found divisor
            }
        }

        if (isProbablyPrime) {
            std::cout << "The number is probably prime." << std::endl;
        }
    }

    ~LinkedList() {
        clear();
    }
};

int main() {
    std::string input;
    std::cout << "Enter a number (up to 309 digits): ";
    std::cin >> input;

    // Check if input is valid
    if (input.length() > 309 || !std::all_of(input.begin(), input.end(), ::isdigit)) {
        std::cerr << "Invalid input! Please enter a numeric value with up to 309 digits." << std::endl;
        return 1;
    }

    LinkedList list;
    std::string segment;

    // Process the input number into segments
    int totalLength = input.length();
    int msbDigits = totalLength > 9 ? 9 : totalLength; // Most significant digits (MSB)
    segment = input.substr(0, msbDigits);
    uint64_t msbValue = std::stoull(segment);
    list.addNode(msbValue);

    // Remaining digits (complete 20 digits for each node)
    for (size_t i = msbDigits; i < totalLength; i += 20) {
        segment = input.substr(i, 20);
        // If segment has less than 20 digits, pad with zeros
        if (segment.length() < 20) {
            segment.insert(segment.begin(), 20 - segment.length(), '0');
        }
        uint64_t value = std::stoull(segment);
        list.addNode(value);
    }

    // Display the linked list with labels
    std::cout << "\nLinked List Nodes:" << std::endl;
    list.display();

    // Display the complete number
    std::cout << "\nComplete number: " << input << std::endl;
    std::cout << "Number of digits: " << totalLength << std::endl;

    // Check for primality
    list.checkPrime();

    return 0;
}
