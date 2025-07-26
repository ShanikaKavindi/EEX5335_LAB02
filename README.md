# Multithreaded Matrix Multiplication Lab

## 📌 Lab Overview

This lab focuses on implementing **matrix multiplication** using **multithreading** in both **C (Pthreads)** and **Java (Java Threads)**. The objective is to understand thread creation, synchronization, and the performance benefits of concurrent programming.

---

## 🎯 Aim

To implement matrix multiplication using multithreaded programming in C (using Pthreads) and Java (using Java Threads), and to understand thread management and concurrency concepts.

---

## ✅ Objectives

- Learn how to create and manage threads in C and Java.
- Perform matrix multiplication concurrently by assigning each row to a separate thread.
- Compare threading APIs (Pthreads vs Java Threads).
- Gain experience using the Linux terminal to compile and run multithreaded programs.

---

## ⚙️ Technologies Used

- **Language:** C and Java  
- **API:** Pthreads (for C), Java Threads  
- **OS:** Ubuntu (Linux)

---

## 🧪 How to Run

### ✅ Running C Program (Pthreads)


Step 3: Paste your C code and save using Ctrl + O, then press Enter, then exit with Ctrl + X.

Step 4: Compile the code:

bash
Copy
Edit
gcc -o matrix_mul matrix_mul.c -pthread
Step 5: Run the program:

bash
Copy
Edit
./matrix_mul
☕ Running Java Program (Java Threads)
Step 1: Create the file:

bash
Copy
Edit
nano MatrixMultiplication.java
Step 2: Paste your Java code and save (Ctrl + O, Enter, Ctrl + X).

Step 3: Compile the code:

bash
Copy
Edit
javac MatrixMultiplication.java
Step 4: Run the program:

bash
Copy
Edit
java MatrixMultiplication


**Step 1:** Open the Terminal in Ubuntu.

**Step 2:** Create the file:
```bash
nano matrix_mul.c
