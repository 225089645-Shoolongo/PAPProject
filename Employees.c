#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Employee.h"

Employee employees[MAX_EMPLOYEES];
int empCount = 0;

static int isValidDate(const char *d) {
    if (strlen(d) != 10 || d[4] != '-' || d[7] != '-') return 0;

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit((unsigned char)d[i])) return 0;
    }

    int year, month, day;
    if (sscanf(d, "%d-%d-%d", &year, &month, &day) != 3) return 0;

    time_t now = time(NULL);
    struct tm *lt = localtime(&now);
    int currentYear = lt->tm_year + 1900;

    if (year < 1900 || year > currentYear) return 0;
    if (month < 1 || month > 12) return 0;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (leap) daysInMonth[1] = 29;

    return day >= 1 && day <= daysInMonth[month - 1];
}

double calculateNetSalary(double basic, double housing, double transport) {
    return basic + housing + transport;
}

void addEmployee(void) {
    if (empCount >= MAX_EMPLOYEES) {
        printf("\nError: Employee database is full!\n");
        return;
    }

    Employee e;
    e.id = empCount + 1;

    printf("\n===== ADD EMPLOYEE =====\n");
    printf("Assigned Employee ID: %d\n", e.id);

    readRequired("Enter employee name: ", e.name, STR_LEN, "Name");

    while (1) {
        printf("Enter date of birth (YYYY-MM-DD): ");
        readLine(e.dob, STR_LEN);
        if (isBlank(e.dob)) {
            printf("Error: Date of birth cannot be empty.\n");
        } else if (!isValidDate(e.dob)) {
            printf("Error: Invalid date. Use the format YYYY-MM-DD (e.g. 1990-05-23).\n");
        } else {
            break;
        }
    }

    readRequired("Enter department: ", e.department, STR_LEN, "Department");

    e.basicSalary = readNonNegativeDouble("Enter basic salary (N$): ",
                    "Invalid input. Salary must be a non-negative number.");
    e.housingAllowance = readNonNegativeDouble("Enter housing allowance (N$): ",
                    "Invalid input. Allowance must be a non-negative number.");
    e.transportAllowance = readNonNegativeDouble("Enter transport allowance (N$): ",
                    "Invalid input. Allowance must be a non-negative number.");

    e.netSalary = calculateNetSalary(e.basicSalary, e.housingAllowance, e.transportAllowance);
    employees[empCount++] = e;

    printf("\nEmployee record [ID: %d] successfully added!\n\n", e.id);
}

void displayEmployees(void) {
    if (empCount == 0) {
        printf("\nNo employee records found.\n\n");
        return;
    }

    printf("\n==================================== EMPLOYEE LIST ====================================\n");
    printf("%-8s %-20s %-12s %-15s %-12s %-12s\n", "ID", "Name", "DOB", "Department", "Basic (N$)", "Net (N$)");
    printf("---------------------------------------------------------------------------------------\n");
    for (int i = 0; i < empCount; i++) {
        printf("%-8d %-20s %-12s %-15s %-12.2f %-12.2f\n", 
               employees[i].id, employees[i].name, employees[i].dob, 
               employees[i].department, employees[i].basicSalary, employees[i].netSalary);
    }
    printf("\n");
}

void searchEmployee(void) {
    if (empCount == 0) {
        printf("\nNo employees available to search.\n\n");
        return;
    }

    char query[STR_LEN];
    printf("\nEnter Employee ID or Name to search: ");
    readLine(query, STR_LEN);

    int queryId = atoi(query);
    int found = 0;

    for (int i = 0; i < empCount; i++) {
        if ((queryId > 0 && employees[i].id == queryId) || strcmp(employees[i].name, query) == 0) {
            printf("\n--- Employee Found ---\n");
            printf("ID:                %d\n", employees[i].id);
            printf("Name:              %s\n", employees[i].name);
            printf("Date of Birth:     %s\n", employees[i].dob);
            printf("Department:        %s\n", employees[i].department);
            printf("Basic Salary:      N$%.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: N$%.2f\n", employees[i].housingAllowance);
            printf("Transport Allow.:  N$%.2f\n", employees[i].transportAllowance);
            printf("Net Salary:        N$%.2f\n\n", employees[i].netSalary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee '%s' not found.\n\n", query);
    }
}

void employeeSubMenu(void) {
    int choice = 0;
    do {
        printf("\n=== EMPLOYEE MANAGEMENT ===\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Return to Main Menu\n");
        printf("Enter choice: ");

        if (!readInt(&choice)) {
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid choice! Please enter 1-4.\n");
        }
    } while (choice != 4);
}
            
