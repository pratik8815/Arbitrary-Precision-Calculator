#  Arbitrary Precision Calculator (C)

A C-based Arbitrary Precision Calculator that performs arithmetic operations 
on **very large integers** beyond the limits of standard data types (`int`, `long`, etc.) 
using a **doubly linked list**.

---

##  Features

- Supports large integers of **unlimited size**
- Operations implemented:
  - ➕ Addition  
  - ➖ Subtraction  
  - ✖️ Multiplication  
  - ➗ Division  
- Handles **positive and negative numbers**
- **Command-line interface (CLI)**
- Input validation and error handling
- Efficient digit-by-digit computation

---

##  Technologies Used

- **Language:** C  
- **Data Structure:** Doubly Linked List  
- **Concepts:** Pointers, Dynamic Memory Allocation, Algorithms  

---

##  How It Works

- Each number is stored as a **doubly linked list**, where each node contains a single digit.
- Arithmetic operations are performed manually:
  - Addition → carry handling  
  - Subtraction → borrow logic  
  - Multiplication → digit-by-digit (school method)  
  - Division → repeated subtraction  

---

##  How to Run

### 1. Compile the program
```bash
gcc *.c

./a.out <number1> <operator> <number2>
./a.out 12345678901234567890 + 98765432109876543210
./a.out 999999999999 * 888888888888
./a.out 1000 - 999
./a.out 123456789 / 12345

./a.out 5 + 1
Result of 5 + 1 is: 6

./a.out 5 - 29
Result of 5 - 29 is: -24

```
##  Time Complexity

| Operation       | Complexity |
|----------------|------------|
| Addition       | O(n)       |
| Subtraction    | O(n)       |
| Multiplication | O(n²)      |
| Division       | O(n³) approx |


##  Learning Outcomes

- Implemented arbitrary precision arithmetic  
- Learned doubly linked lists  
- Improved pointer and memory management  
- Understood low-level arithmetic logic


##  Author

Pratik Satsure
