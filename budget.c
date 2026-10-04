#include <stdio.h>
#include <string.h>
#include "budget.h"

Budget budgets[MAX_BUDGETS];
int budget_count = 0;


static void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}


static void readLine(char text[], int size)
{
    if (fgets(text, size, stdin) != NULL)
    {
        text[strcspn(text, "\n")] = '\0';
    }
}


int findDepartment(char name[])
{
    int i;

    for (i = 0; i < budget_count; i++)
    {
        if (strcmp(budgets[i].department, name) == 0)
        {
            return i;
        }
    }

    return -1;
}


double getRemaining(int i)
{
    return budgets[i].allocated - budgets[i].expenditure;
}


void printBudget(int i)
{
    double remaining = getRemaining(i);

    printf("\nDepartment: %s\n", budgets[i].department);
    printf("Budget ID: %d\n", budgets[i].id);
    printf("Allocated Budget: N$%.2f\n", budgets[i].allocated);
    printf("Expenditure: N$%.2f\n", budgets[i].expenditure);
    printf("Remaining Budget: N$%.2f\n", remaining);

    if (remaining < 0)
    {
        printf("Status: OVER BUDGET\n");
    }
    else if (remaining == 0)
    {
        printf("Status: EXACTLY MET\n");
    }
    else
    {
        printf("Status: WITHIN BUDGET\n");
    }
}


void addBudget(void)
{
    int id;
    int i;
    int duplicate;
    char department[50];
    double allocated;

    if (budget_count >= MAX_BUDGETS)
    {
        printf("\nBudget storage is full.\n");
        return;
    }

    printf("\n===== ADD DEPARTMENT BUDGET =====\n");


    while (1)
    {
        printf("Enter budget ID: ");

        if (scanf("%d", &id) != 1)
        {
            printf("Invalid ID. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        duplicate = 0;

        for (i = 0; i < budget_count; i++)
        {
            if (budgets[i].id == id)
            {
                duplicate = 1;
            }
        }

        if (duplicate == 1)
        {
            printf("That ID already exists. Try again.\n");
        }
        else
        {
            break;
        }
    }

    while (1)
    {
        printf("Enter department name: ");
        readLine(department, sizeof(department));

        if (strlen(department) == 0)
        {
            printf("Department name cannot be empty.\n");
        }
        else if (findDepartment(department) != -1)
        {
            printf("That department already has a budget.\n");
        }
        else
        {
            break;
        }
    }

    while (1)
    {
        printf("Enter allocated budget (N$): ");

        if (scanf("%lf", &allocated) != 1)
        {
            printf("Invalid amount. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (allocated <= 0)
        {
            printf("Budget must be greater than zero.\n");
        }
        else
        {
            break;
        }
    }

    budgets[budget_count].id = id;
    strcpy(budgets[budget_count].department, department);
    budgets[budget_count].allocated = allocated;
    budgets[budget_count].expenditure = 0;

    budget_count++;

    printf("\nBudget added successfully!\n");
}


/* Add money spent to a department */
void recordExpenditure(void)
{
    char department[50];
    double amount;
    int i;

    if (budget_count == 0)
    {
        printf("\nNo budgets found. Add a department budget first.\n");
        return;
    }

    printf("\n===== RECORD EXPENDITURE =====\n");

    printf("Enter department name: ");
    readLine(department, sizeof(department));

    i = findDepartment(department);

    if (i == -1)
    {
        printf("Department not found.\n");
        return;
    }


    while (1)
    {
        printf("Enter expenditure amount (N$): ");

        if (scanf("%lf", &amount) != 1)
        {
            printf("Invalid amount. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (amount < 0)
        {
            printf("Expenditure cannot be negative.\n");
        }
        else
        {
            break;
        }
    }

    budgets[i].expenditure = budgets[i].expenditure + amount;

    printf("\nExpenditure recorded successfully!\n");

    printBudget(i);

    if (getRemaining(i) < 0)
    {
        printf("\nWARNING: Department has exceeded its budget!\n");
    }
}


/* Show all budgets */
void displayBudgets(void)
{
    int i;

    if (budget_count == 0)
    {
        printf("\nNo budgets found.\n");
        return;
    }

    printf("\n===== BUDGET INFORMATION =====\n");

    for (i = 0; i < budget_count; i++)
    {
        printBudget(i);
    }
}


void displayExceededBudgets(void)
{
    int i;
    int found = 0;

    if (budget_count == 0)
    {
        printf("\nNo budgets found.\n");
        return;
    }

    printf("\n===== DEPARTMENTS OVER BUDGET =====\n");

    for (i = 0; i < budget_count; i++)
    {
        if (getRemaining(i) < 0)
        {
            printBudget(i);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNo department has exceeded its budget.\n");
    }
}


void budSummaryReport(void)
{
    int i;
    double totalAllocated = 0;
    double totalExpenditure = 0;

    if (budget_count == 0)
    {
        printf("\nNo budgets found.\n");
        return;
    }

    printf("\n===== BUDGET SUMMARY =====\n");

    for (i = 0; i < budget_count; i++)
    {
        totalAllocated = totalAllocated + budgets[i].allocated;
        totalExpenditure = totalExpenditure + budgets[i].expenditure;
    }

    printf("Total allocated budget: N$%.2f\n", totalAllocated);
    printf("Total expenditure: N$%.2f\n", totalExpenditure);
    printf("Remaining budget: N$%.2f\n", totalAllocated - totalExpenditure);
}


int getBudgetCount(void)
{
    return budget_count;
}

const Budget *getBudgetArray(void)
{
    return budgets;
}


void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n===== BUDGET MANAGEMENT =====\n");
        printf("1. Add department budget\n");
        printf("2. Record expenditure\n");
        printf("3. Display budgets\n");
        printf("4. Show departments over budget\n");
        printf("5. Budget summary\n");
        printf("6. Back to main menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice. Please enter a number.\n");
            clearInputBuffer();
            choice = 0;
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
            case 1:
                addBudget();
                break;

            case 2:
                recordExpenditure();
                break;

            case 3:
                displayBudgets();
                break;

            case 4:
                displayExceededBudgets();
                break;

            case 5:
                budSummaryReport();
                break;

            case 6:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please enter 1-6.\n");
        }

    } while (choice != 6);
}
