#include<iostream>
using namespace std;

struct Process {
    int process_id;
    int execution_time;
    int remaining_time;
    Process* next;

    Process(int p_id, int e_time) {
        process_id = p_id;
        execution_time = e_time;
        remaining_time = e_time;
        next = nullptr;
    }
};

// Function to insert a new process
Process* insertProcess(Process* end, int process_id, int execution_time) {
    Process* newProcess = new Process(process_id, execution_time);
    if (end == nullptr) {
        newProcess->next = newProcess;
        return newProcess;
    }
    newProcess->next = end->next;
    end->next = newProcess;
    return end;
}

// Function to remove completed process
Process* removeProcess(Process* end, Process* removingProcess) {
    if (end == nullptr) return nullptr;

    if (removingProcess == end && end->next == end) {
        delete end;
        return nullptr;
    }

    Process* current = end->next;
    Process* prev = end;
    while (prev->next != removingProcess) {
        prev = prev->next;
    }

    if (removingProcess == end) {
        prev->next = removingProcess->next;
        delete removingProcess;
        return prev;
    }
    else {
        prev->next = removingProcess->next;
        delete removingProcess;
        return end;
    }
}

// Function to simulate Round Robin scheduling with user input
void roundRobinScheduler(Process* end, int quantum) {
    if (end == nullptr) {
        cout << "No processes to schedule" << endl;
        return;
    }

    int cycles = 1;
    int process_id = 4; // Start new process IDs from 4
    Process* current = end->next;

    while (end != nullptr) {
        cout << "Cycle " << cycles << ":" << endl;
        Process* temp = current;

        // Display all processes in the list with their remaining time
        do {
            cout << "Process P" << temp->process_id << " (Remaining Time: " << temp->remaining_time << ")" << endl;
            temp = temp->next;
        } while (temp != current);

        // Execute current process
        if (current->remaining_time <= quantum) {
            cout << "Process P" << current->process_id << " completed." << endl;
            end = removeProcess(end, current);
            if (end == nullptr) {
                cout << "All processes are completed." << endl;
                return;
            }
            current = end->next;
        }
        else {
            current->remaining_time -= quantum;
            cout << "Process P" << current->process_id << " executes for " << quantum << " units. Remaining Time: " << current->remaining_time << endl;
            current = current->next;
        }

        // Ask the user if they want to add a new process after every cycle
        char addNewProcess;
        cout << "Do you want to add a new process? (y/n): ";
        cin >> addNewProcess;

        if (addNewProcess == 'y' || addNewProcess == 'Y') {
            int new_execution_time;
            cout << "Enter execution time for the new process: ";
            cin >> new_execution_time;

            // Insert the new process
            end = insertProcess(end, process_id, new_execution_time);
            cout << "New Process P" << process_id << " (Execution Time: " << new_execution_time << ") added." << endl;
            process_id++;  // Increment process ID for the next new process
        }

        cycles++;
    }
}

int main() {
    Process* end = nullptr;
    int quantum =3;
    // Take user input for initial processes
    int ininum;
    cout << "Enter the number of initial processes: ";
    cin >> ininum;

    // Get process details from the user
    for (int i = 1; i <= ininum; i++) {
        int execution_time;
        cout << "Enter execution time for Process P" << i << ": ";
        cin >> execution_time;
        end = insertProcess(end, i, execution_time);
    }

    cout << "CPU Time per Cycle: " << quantum << endl;
    roundRobinScheduler(end, quantum);

    return 0;
}
