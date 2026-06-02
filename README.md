# Interactive C Calculator with Dynamic Operation History

A robust, interactive command-line calculator built in C. This project features standard arithmetic operations, data safety guards (such as division-by-zero handling), an accumulator memory, and a custom-built rolling history buffer that tracks the last 10 operations.

---

## 🚀 Key Features

*   **Core Arithmetic:** Supports Addition, Subtraction, Multiplication, and Division using floating-point precision.
*   **Accumulator Memory:** Allows users to continuously chain calculations using the result of the previous operation as the starting point.
*   **Rolling History Buffer:** Implements a custom array-shifting algorithm that keeps track of a maximum of 10 past operations. When the limit is reached, it automatically discards the oldest entry to make room for the new one (FIFO structure).
*   **Error Handling:** Safe division architecture that catches division-by-zero attempts, logs an error state (`E`) in the history, and prevents application crashes.
*   **Clean Terminal UI:** Built-in screen clearing capabilities to provide a seamless user interface directly in the console.

---

## 🛠️ Tech Stack & Concepts Demonstrated

*   **Language:** C (Standard C Libs)
*   **Memory & Data Structures:** Static Arrays, Data Shifting, Accumulators.
*   **Control Flow:** Conditional Statements, Switch-Case State Machine, Infinite Loops with Breakpoints.

---

## 💻 How to Run the Project

### Prerequisites
You need a C compiler installed on your machine (such as `gcc`).

### Compilation
Open your terminal in the project directory and run:
```bash
gcc main.c -o calculator
