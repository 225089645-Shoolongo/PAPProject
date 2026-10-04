# Municipal Financial Management System (MFMS)

## Course

PAP521S – Programming in Practice

## Project A

Municipal Financial Management System

## Programming Language

 C 

## Development Environment

Visual Studio Code + GCC

## Version Control

Git & GitHub

## Group Name
SKEEMSOM


## Group Members                         ROLES

Fillemo Martin -225127911 -              EMPLOYEE MANAGMENT
Miguel Shamukuni- 224023640 -            BUDGET MANAGMENT 
Jacobina P Nuuyoma - 225003058 -         SUPPLIER MANAGMENT
Sacharia Kahenge Nashipili 226081745 -   ASSETS MANAGMENT
Maryna P Kashaka - 225097958 -           REPORTS MANAGMENT
Christelle E Garusoas 225028980 -        INTEGRATION AND FUNCTION
SHOOLONGO LEONARD - 225089645-           TESTING AND DOCUMENTATION


## Project Description

The Municipal Financial Management System (MFMS) is a menu-driven C application designed to manage basic municipal financial and administrative information.

The system allows users to manage employees, budgets, suppliers, assets, and generate reports.

## System Features

### Employee Management

* Add employees
* Display employees
* Search for employees
* Calculate employee salary information

### Budget Management

* Enter departmental budgets
* Enter expenditure
* Calculate remaining budget
* Check whether expenditure is within budget
* Identify departments exceeding their budgets

### Supplier Management

* Add suppliers
* Display suppliers
* Search for suppliers
* Store supplier contact information

### Asset Management

* Add assets
* Display assets
* Search for assets
* Store asset information

### Reports

* Employee Report
* Budget Report
* Supplier Report
* Asset Report

## C Programming Concepts Used

* Variables and data types
* Input and output
* Operators
* Decision-making
* Loops
* Arrays
* Strings
* Functions
* Parameters and return values
* Input validation

## String Functions Used

* `strlen()`
* `strcmp()`
* `strcpy()`
* `strcat()`

## Data Validation

The system handles:

* Invalid menu choices
* Negative salaries
* Negative budgets
* Empty names
* Invalid numerical input

## Project Structure

```text
MFMS/
├── main.c
├── employees.c
├── employees.h
├── budget.c
├── budget.h
├── suppliers.c
├── suppliers.h
├── assets.c
├── assets.h
├── reports.c
├── reports.h
└── README.md
```

## Compilation

Open the terminal in the project directory and run:

```bash
gcc main.c employees.c budget.c suppliers.c assets.c reports.c -o MFMS
```

## How to Run

### Windows

```bash
MFMS.exe
```



## Individual Responsibilities

*  Fillemo Martin– Employee Management
*  Miguel Shamukuni– Budget Management
*  Jacobina P Nuuyoma– Supplier Management
* Sacharia Kahenge Nashipili – Asset Management
* Maryna P Kashaka – Reports
* Christelle E Garusoas– Integration & Validation
* SHOOLONGO LEONARD– Testing & Documentation

## GitHub

The project is hosted on GitHub and developed collaboratively by all group members.

**Repository:** https://github.com/225089645-Shoolongo/PAPProject.git
