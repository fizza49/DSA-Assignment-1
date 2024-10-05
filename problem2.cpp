#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

// Node structure
struct Node {
    uint64_t data;
    Node* next;
    Node(uint64_t value) {
        data = value;
        next = nullptr;
    }
};

class LargeNumber {
    Node* head;

public:
    LargeNumber() {
        head = nullptr;
    }

    void addNode(uint64_t node) {
        Node* newNode = new Node(node);
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void randomnumbergenerator() {
        for (int i = 0; i < 16; i++) {  // 1024/64=16
            addNode(getRandom64Bit());
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    static uint64_t getRandom64Bit() {
        random_device rd;         // Use random device for randomness
        mt19937_64 gen(rd());     // Mersenne Twister engine for 64-bit
        uniform_int_distribution<uint64_t> dist(0, UINT64_MAX);
        return dist(gen);
    }

    // Miller-Rabin primality test
    bool isPrime(uint64_t n, int k = 5) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0) return false;

        // Find r and d such that n = 2^r * d + 1
        uint64_t d = n - 1;
        int r = 0;
        while (d % 2 == 0) {
            d /= 2;
            r++;
        }

        // Perform k tests
        for (int i = 0; i < k; i++) {
            uint64_t a = 2 + rand() % (n - 4);
            uint64_t x = modularExponentiation(a, d, n);
            if (x == 1 || x == n - 1) continue;

            bool found = false;
            for (int j = 0; j < r - 1; j++) {
                x = modularExponentiation(x, 2, n);
                if (x == n - 1) {
                    found = true;
                    break;
                }
            }

            if (!found) return false;
        }
        return true;
    }

    // Modular exponentiation
    uint64_t modularExponentiation(uint64_t base, uint64_t exp, uint64_t mod) {
        uint64_t result = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % mod;
            exp = exp >> 1;
            base = (base * base) % mod;
        }
        return result;
    }

    // Check primality of the 1024-bit number
    bool checkPrimality() {
        uint64_t total = 0;
        Node* current = head;

        // Combine 64-bit nodes into a single number
        while (current) {
            total = (total << 64) | current->data; // Shift and add node
            current = current->next;
        }

        return isPrime(total);
    }

    // Destructor to free memory
    ~LargeNumber() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next; // Move to the next Node
            delete temp;            // Delete the current Node
        }
    }
};

int main() {
    LargeNumber largenumber;
    largenumber.randomnumbergenerator();
    cout << "Number: ";
    largenumber.display();

    // Check if the 1024-bit number is prime
    if (largenumber.checkPrimality()) {
        cout << "The number is prime." << endl;
    }
    else {
        cout << "The number is not prime." << endl;
    }

    return 0;
}
