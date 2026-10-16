#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "utils.h"

#define MAX_EMPLOYEES 100

typedef struct {
    int id;                    // Sequential numeric ID starting from 1
    char name[STR_LEN];
    char dob[STR_LEN];         // Date of Birth (YYYY-MM-DD)
    char department[STR_LEN];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double netSalary;
} Employee;

extern Employee employees[MAX_EMPLOYEES];
extern int empCount;

double calculateNetSalary(double basic, double housing, double transport);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void employeeSubMenu(void);

#endif
