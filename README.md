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

### Challenges Faced

- Managing dynamic addition/removal of processes.
- Handling circular linked list operations efficiently.

 ### Screenshorts
 ![task 1 s1](https://github.com/user-attachments/assets/f3344056-b385-478a-8387-8a83a2e0003f)

![task 1 s2](https://github.com/user-attachments/assets/7d7821df-7df5-41e6-86f5-1eef8fc2f58b)


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

### Challenges Faced
-**Handling Large Numbers:**
Since C++ does not natively support numbers larger than 64 bits, the large number is divided into chunks and stored in a linked list.

-**Modular Exponentiation:**
Efficient modular exponentiation is used to handle large powers during the primality test without causing overflow.

-**Memory mangement:**
Memory needed to be efficiently managed to prevent memory leak.

### Approch 2

## Overview

This C++ program checks the primality of a large number (up to **309 digits**) using a linked list. Each node in the linked list stores a 64-bit segment of the number, allowing efficient handling of large numbers. The program uses modular arithmetic across nodes to test divisibility and determine whether the number is prime.

## Assumptions

- **Input**: A numeric string (up to **309 digits**).
- The input number is divided into 64-bit chunks and stored in a linked list.
- Only numeric input is valid.
- Primality is checked by testing divisibility starting from 2 up to the square root of the largest possible `uint64_t` value.

## Approach

1. **Input Handling**:
   - The user is prompted to enter a number with a maximum length of 309 digits.
   - Input is validated to ensure it contains only digits.

2. **Linked List Structure**:
   - The number is split into segments of up to 64-bit size and stored in nodes of a linked list.
   - The least significant parts of the number are stored in the earlier nodes.

3. **Modular Arithmetic**:
   - Divisibility across nodes is determined using modular arithmetic, accumulating remainders while traversing the linked list.

4. **Primality Check**:
   - The program checks divisibility by integers starting from 2 up to the square root of the maximum 64-bit number (`uint64_t`).
   - If divisible, the number is declared **not prime**; otherwise, it is **probably prime**.


### Screenshort
![task 2 s1](https://github.com/user-attachments/assets/8a08a0e7-e266-4052-8ce8-0572deac5ce9)

![task2 s1](https://github.com/user-attachments/assets/13f5a42b-a86c-4247-a5dd-db4fa59d5787)

### GitHub Link
 [Project](https://github.com/fizza49/DSA-assignment-1.git).

### Contribution
[Fizza Kashif](https://github.com/fizza49)
