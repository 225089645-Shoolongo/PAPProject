#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_BUDGETS 50
#define MAX_SUPPLIERS 100
#define MAX_ASSETS 100

  
   //Data Structures for Employee, Supplier, Asset, and Budget

struct Employee
{
    int id;
    char name[100];
    char department[50];
    float basicSalary;
    float allowances;
};

struct Budget
{
    int id;
    char department[50];
    float allocated;
    float expenditure;
};

struct Supplier
{
    int id;
    char name[100];
    char email[100];
    char telephone[30];
    char town[50];
    float totalAmount;
};

struct Asset
{
    int id;
    char name[100];
    char type[50];
    float purchaseValue;
    char department[50];
    char condition[30];
};


// ARRAYS
  

struct Employee employees[MAX_EMPLOYEES];
struct Budget budgets[MAX_BUDGETS];
struct Supplier suppliers[MAX_SUPPLIERS];
struct Asset assets[MAX_ASSETS];

int employee_count = 0, supplier_count = 0, asset_count = 0, budget_count = 0;

//Main Menu
void displayMenu() {
    printf("========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

   //Employee Management Functions
  
void addEmployee()
{
    if (employee_count >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        return;
    }

    printf("\n===== ADD EMPLOYEE =====\n");

    printf("Enter employee ID: ");
    scanf("%d", &employees[employee_count].id);

    printf("Enter employee name: ");
    scanf(" %[^\n]", employees[employee_count].name);

    printf("Enter department: ");
    scanf(" %[^\n]", employees[employee_count].department);

    printf("Enter basic salary: ");
    scanf("%f", &employees[employee_count].basicSalary);

    while (employees[employee_count].basicSalary < 0)
    {
        printf("Salary cannot be negative. Enter again: ");
        scanf("%f", &employees[employee_count].basicSalary);
    }

    printf("Enter allowances: ");
    scanf("%f", &employees[employee_count].allowances);

    while (employees[employee_count].allowances < 0)
    {
        printf("Allowances cannot be negative. Enter again: ");
        scanf("%f", &employees[employee_count].allowances);
    }

    employee_count++;

    printf("\nEmployee added successfully!\n");
}


float calculateSalary(struct Employee employee)
{
    return employee.basicSalary + employee.allowances;
}


void displayEmployees()
{
    int i;

    if (employee_count == 0)
    {
        printf("\nNo employees found.\n");
        return;
    }

    printf("\n===== EMPLOYEE LIST =====\n");

    for (i = 0; i < employee_count; i++)
    {
        printf("\nEmployee ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("Allowances: %.2f\n", employees[i].allowances);
        printf("Total Salary: %.2f\n",
               calculateSalary(employees[i]));
    }
}


void searchEmployee()
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter employee ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < employee_count; i++)
    {
        if (employees[i].id == id)
        {
            printf("\nEmployee found!\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Basic Salary: %.2f\n",
                   employees[i].basicSalary);
            printf("Allowances: %.2f\n",
                   employees[i].allowances);
            printf("Total Salary: %.2f\n",
                   calculateSalary(employees[i]));

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nEmployee not found.\n");
    }
} int main()
{
    int choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                printf("Budget Management coming soon.\n");
                break;

            case 3:
                printf("Supplier Management coming soon.\n");
                break;

            case 4:
                printf("Asset Management coming soon.\n");
                break;

            case 5:
                printf("Reports coming soon.\n");
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
