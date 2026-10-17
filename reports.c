#include <stdio.h>
#include "reports.h"
#include "Employee.h"
#include "Budget.h"
#include "suppliers.h"
#include "assets.h"

void employeeReport(void) {
    if (empCount == 0) { printf("\nNo employees recorded.\n"); return; }
    double total = 0, highest = -1, lowest = 1e18;
    int hi = 0, lo = 0;
    for (int i = 0; i < empCount; i++) {
        double net = employees[i].netSalary;
        total += net;
        if (net > highest) { highest = net; hi = i; }
        if (net < lowest)  { lowest  = net; lo = i; }
    }
    printf("\n===== EMPLOYEE REPORT =====\n");
    printf("Total Employees : %d\n", empCount);
    printf("Average Salary  : N$%.2f\n", total / empCount);
    printf("Highest Salary  : N$%.2f (%s)\n", highest, employees[hi].name);
    printf("Lowest Salary   : N$%.2f (%s)\n", lowest,  employees[lo].name);
}

void budgetReport(void) {
    int count = getBudgetCount();
    const Budget *buds = getBudgetArray();

    if (count == 0) { printf("\nNo budget records.\n"); return; }
    double tA = 0, tE = 0;
    printf("\n===== BUDGET REPORT =====\n");
    printf("%-15s %-15s %-15s %-15s %s\n", "Department","Allocated","Expenditure","Remaining","Status");
    for (int i = 0; i < count; i++) {
        double rem = buds[i].allocated - buds[i].expenditure;
        tA += buds[i].allocated;
        tE += buds[i].expenditure;
        printf("%-15s N$%-14.2f N$%-14.2f N$%-14.2f %s\n",
               buds[i].department, buds[i].allocated, buds[i].expenditure,
               rem, (rem >= 0) ? "WITHIN BUDGET" : "OVER BUDGET");
    }
    printf("\nTotal Allocated  : N$%.2f\n", tA);
    printf("Total Expenditure: N$%.2f\n", tE);
    printf("Total Remaining  : N$%.2f\n", tA - tE);
    printf("\nDepartments exceeding budget:\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (buds[i].expenditure > buds[i].allocated) {
            printf("  - %s (over by N$%.2f)\n", buds[i].department, buds[i].expenditure - buds[i].allocated);
            found = 1;
        }
    }
    if (!found) printf("  None\n");
}

void supplierReport(void) {
    if (supplierCount == 0) { printf("\nNo suppliers registered.\n"); return; }
    printf("\n===== SUPPLIER REPORT =====\n");
    printf("%-6s %-20s %-25s %-15s %s\n", "ID","Name","Email","Phone","Town");
    for (int i = 0; i < supplierCount; i++)
        printf("%-6d %-20s %-25s %-15s %s\n", supplierIDs[i], supplierNames[i], supplierEmails[i], supplierPhones[i], supplierTowns[i]);
}

void assetReport(void) {
    int count = getAssetCount();
    const Asset *asts = getAssetArray();

    if (count == 0) { printf("\nNo assets registered.\n"); return; }
    double total = 0;
    printf("\n===== ASSET REPORT =====\n");
    printf("%-6s %-20s %-12s %-15s %-15s %s\n", "ID","Name","Type","Value","Department","Condition");
    for (int i = 0; i < count; i++) {
        printf("%-6s %-20s %-12s N$%-14.2f %-15s %s\n",
               asts[i].assetID, asts[i].assetName, asts[i].assetType, asts[i].purchaseValue, asts[i].department, asts[i].condition);
        total += asts[i].purchaseValue;
    }
    printf("\nTotal asset value: N$%.2f\n", total);
}

void displayReportsMenu(void) {
    int choice;
    do {
        printf("\n--- REPORTS ---\n");
        printf("1. Employee Report\n2. Budget Report\n3. Supplier Report\n4. Asset Report\n5. Back\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) { while (getchar() != '\n'); choice = 0; }
        switch (choice) {
            case 1: employeeReport(); break;
            case 2: budgetReport(); break;
            case 3: supplierReport(); break;
            case 4: assetReport(); break;
            case 5: printf("Returning...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}