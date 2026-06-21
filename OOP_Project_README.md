# Banking Management System
A console-based banking system built in C++ as a 2nd semester Object-Oriented Programming project at Bahria University.

> **Group project** — developed collaboratively by Mohid Ali and Wahab.

---

## What It Does
Simulates a basic banking system with two types of users — Admin and Customer — each with their own login and set of operations.

**Admin can:**
- Create, display, update, delete, and search bank accounts
- Transfer money between accounts
- Manage loans (add, display all, search by account number)

**Customer can:**
- Log in with credentials
- View balance
- Deposit and withdraw money

---

## OOP Concepts Used
- **Classes & Objects** — `User`, `Customer`, `Admin`, `Account`, `Loan`, `LoanManager`, `BankSystem`
- **Inheritance** — `Customer` and `Admin` both inherit from the base `User` class
- **Polymorphism** — `showMenu()` is a pure virtual function in `User`, overridden differently in `Customer` and `Admin`
- **Encapsulation** — Private data members with public methods for controlled access
- **Vectors** — Used to manage the list of customers dynamically

---

## Tech Used
- **Language:** C++
- **Concepts:** OOP (Inheritance, Polymorphism, Encapsulation), Vectors, Classes, Input Validation

---

## How to Run

**Requirements:** A C++ compiler (g++ recommended)

```bash
# Clone the repo
git clone https://github.com/YOUR_USERNAME/banking-management-system.git
cd banking-management-system

# Compile
g++ main.cpp -o banking

# Run
./banking          # Linux/Mac
banking.exe        # Windows
```

---

## Default Credentials

**Admin:**
- Username: `admin`
- Password: `admin1235`

**Customers (pre-loaded):**
| Username | Password     |
|----------|--------------|
| wahab    | aw12345      |
| mohid    | mohid12345   |

---

## Project Structure
```
banking-management-system/
│
├── main.cpp      # All source code
└── README.md
```

---

## Context
Built as a 2nd semester project for the Object-Oriented Programming course (BSCS) at Bahria University, Lahore. The focus was applying OOP principles — inheritance, polymorphism, and encapsulation — to model a real-world banking scenario.
