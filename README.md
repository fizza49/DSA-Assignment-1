# DSA-assignment-1

## CPU Scheduling Simulation

This project simulates the **Round Robin CPU Scheduling Algorithm** using C++. It manages processes in a circular linked list, allocating CPU time . The user can dynamically add processes during the simulation.

### Approach

1. **Circular Linked List:** Processes are stored in a circular linked list to model the cyclic nature of Round Robin scheduling.
2. **Process Execution:** Each process is given CPU time based on the quantum. If a process finishes ,it is removed from the list.
3. **Dynamic Input:** After each cycle, users can add new processes with specified execution times.

### Assumptions

- A fixed quantum of **3 units** is used for each process execution.
- Processes are dynamically added or removed based on user input and their remaining execution time.

### Public GitHub Link

Find the project [here](https://github.com/fizza49/DSA-assignment-1.git).

### Challenges Faced

- Managing dynamic addition/removal of processes.
- Handling circular linked list operations efficiently.



## 1024-bit Large Number Prime Checker

This project implements a **1024-bit large number generator** and a **Miller-Rabin primality test** in C++. It uses a linked list to store 64-bit chunks of the large number and then checks if the generated 1024-bit number is prime.

### Features

1. **Linked List Representation:**  
   The 1024-bit number is divided into 16 nodes, each holding a 64-bit segment, and stored in a linked list.
   
2. **Random Number Generation:**  
   A random 1024-bit number is generated using a random device and stored across the linked list.

3. **Primality Test:**  
   The program uses the **Miller-Rabin primality test**, a probabilistic algorithm to check if the large number is prime.

### Approach
  
- **Random Number Generation:**  
  The `mt19937_64` engine generates random 64-bit integers. These are added to the linked list to form a 1024-bit number.
  
- **Miller-Rabin Test:**  
  A probabilistic algorithm is used to check the primality of the 1024-bit number by repeatedly performing modular exponentiation on random bases.

### How It Works

1. The program generates a 1024-bit number by storing 16 random 64-bit numbers in the linked list.
2. It then combines these chunks into a single number and checks its primality using the Miller-Rabin test.
3. The result is displayed, stating whether the number is prime or not.

### Assumptions
-**Probabilistic Primality:**
The Miller-Rabin test is probabilistic, meaning it can detect composite numbers with high accuracy but may give false positives for prime numbers. In this implementation, the test is performed 5 times (k = 5) to minimize the error rate.
-**Challenges Faced:**
Handling Large Numbers:
Since C++ does not natively support numbers larger than 64 bits, the large number is divided into chunks and stored in a linked list.

-**Modular Exponentiation:**
Efficient modular exponentiation is used to handle large powers during the primality test without causing overflow.

-**Memory mangement:**
Memory needed to be efficiently managed to prevent memory leak.


### Contribution
[Fizza Kashif](https://github.com/fizza49)
