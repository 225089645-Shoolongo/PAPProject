#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

/* Prototypes of the functions called from this file (they are defined in the module files) */
void employeeMenu(void);
void budgetMenu(void);
void assetMenu(void);
void displayReportsMenu(void);

int  supplierReadNumber(void);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void searchSupplierByName(void);

/* The supplier module has no menu of its own, so the supplier menu lives here. */
static void supplierMenu(void)
{
    int choice = 0;

    do
    {
        printf("\n=== SUPPLIER MANAGEMENT ===\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier by ID\n");
        printf("4. Search Supplier by Name\n");
        printf("5. Return to Main Menu\n");
        printf("Enter choice: ");

        if (!readInt(&choice))
        {
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
            case 1: addSupplier(); break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier(); break;
            case 4: searchSupplierByName(); break;
            case 5: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid choice! Please enter 1-5.\n");
        }
    } while (choice != 5);
}

void displayMainMenu(void)
{
    printf("\n=======================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("=======================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main(void)
{
    int choice;

    while (1)
    {
        displayMainMenu();

        if (!readInt(&choice))
        {
            printf("Invalid selection! Enter a number.\n");
            continue;
        }

        switch (choice)
        {
            case 1: employeeMenu(); break;
            case 2: budgetMenu(); break;
            case 3: supplierMenu(); break;
            case 4: assetMenu(); break;
            case 5: displayReportsMenu(); break;
            case 6:
                printf("\nExiting Municipal Financial Management System. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid option! Select between 1 and 6.\n");
        }
    }

    return 0;
}
