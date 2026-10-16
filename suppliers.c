#include <stdio.h>
#include <string.h>
#include "suppliers.h"

int supplierIDs[MAX_SUPPLIERS];
char supplierNames[MAX_SUPPLIERS][100];
char supplierEmails[MAX_SUPPLIERS][100];
char supplierPhones[MAX_SUPPLIERS][30];
char supplierTowns[MAX_SUPPLIERS][50];
int supplierCount = 0;

int supplierReadNumber(void)
{
    int number;

    if (scanf("%d", &number) != 1)
    {
        while (getchar() != '\n')    
            ;
        return -1;
    }

    while (getchar() != '\n')       
        ;
    return number;
}

int supplierReadText(char text[], int size)
{
    int length;

    text[0] = '\0';
    fgets(text, size, stdin);
    length = strlen(text);

    if (length > 0 && text[length - 1] != '\n')  
    {
        while (getchar() != '\n')
            ;
        return 0;
    }

    text[strcspn(text, "\n")] = '\0';
    return 1;
}

int supplierIsBlank(char text[])
{
    int i;
    int length = strlen(text);

    for (i = 0; i < length; i++)
    {
        if (text[i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

void supplierPrint(int i)
{
    printf("Supplier ID     : %d\n", supplierIDs[i]);
    printf("Supplier Name   : %s\n", supplierNames[i]);
    printf("Email           : %s\n", supplierEmails[i]);
    printf("Telephone       : %s\n", supplierPhones[i]);
    printf("Town/Location   : %s\n", supplierTowns[i]);
}

void addSupplier(void)
{
    int id, i, exists;
    char tempName[100];
    char tempEmail[100];
    char tempPhone[30];
    char tempTown[50];

    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("\nSupplier limit reached. Cannot add more suppliers.\n");
        return;
    }

    printf("\n========== ADD SUPPLIER ==========\n");

    printf("Enter Supplier ID: ");
    id = supplierReadNumber();

    if (id <= 0)
    {
        printf("\nError: Supplier ID must be a positive number.\n");
        return;
    }

    exists = 0;
    for (i = 0; i < supplierCount; i++)
    {
        if (supplierIDs[i] == id)
        {
            exists = 1;
            break;
        }
    }

    if (exists)
    {
        printf("\nError: Supplier ID %d already exists.\n", id);
        return;
    }

    printf("Enter Supplier Name: ");
    if (!supplierReadText(tempName, sizeof(tempName)))
    {
        printf("\nError: Supplier name is too long.\n");
        return;
    }
    if (supplierIsBlank(tempName))
    {
        printf("\nError: Supplier name cannot be empty.\n");
        return;
    }

    printf("Enter Email: ");
    if (!supplierReadText(tempEmail, sizeof(tempEmail)))
    {
        printf("\nError: Email is too long.\n");
        return;
    }
    if (supplierIsBlank(tempEmail))
    {
        printf("\nError: Email cannot be empty.\n");
        return;
    }

    printf("Enter Telephone Number: ");
    if (!supplierReadText(tempPhone, sizeof(tempPhone)))
    {
        printf("\nError: Telephone number is too long.\n");
        return;
    }
    if (supplierIsBlank(tempPhone))
    {
        printf("\nError: Telephone number cannot be empty.\n");
        return;
    }

    printf("Enter Town/Location: ");
    if (!supplierReadText(tempTown, sizeof(tempTown)))
    {
        printf("\nError: Town/Location is too long.\n");
        return;
    }
    if (supplierIsBlank(tempTown))
    {
        printf("\nError: Town/Location cannot be empty.\n");
        return;
    }

    supplierIDs[supplierCount] = id;
    strcpy(supplierNames[supplierCount],  tempName);
    strcpy(supplierEmails[supplierCount], tempEmail);
    strcpy(supplierPhones[supplierCount], tempPhone);
    strcpy(supplierTowns[supplierCount],  tempTown);

    supplierCount++;

    printf("\nSupplier added successfully!\n");
}

void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been registered.\n");
        return;
    }

    printf("\n================ SUPPLIER LIST ================\n");

    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        supplierPrint(i);
        printf("-----------------------------------------------\n");
    }
}

void searchSupplier(void)
{
    int searchID;
    int i;
    int found = 0;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been registered.\n");
        return;
    }

    printf("\n========== SEARCH SUPPLIER BY ID ==========\n");
    printf("Enter Supplier ID to search: ");
    searchID = supplierReadNumber();

    if (searchID <= 0)
    {
        printf("\nError: Supplier ID must be a positive number.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        if (supplierIDs[i] == searchID)
        {
            printf("\nSupplier found!\n");
            supplierPrint(i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nSupplier with ID %d was not found.\n", searchID);
    }
}

void searchSupplierByName(void)
{
    char searchName[100];
    int i;
    int found = 0;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been registered.\n");
        return;
    }

    printf("\n========== SEARCH SUPPLIER BY NAME ==========\n");
    printf("Enter Supplier Name to search: ");

    if (!supplierReadText(searchName, sizeof(searchName)) || supplierIsBlank(searchName))
    {
        printf("\nError: Please enter a valid supplier name.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        if (strcmp(supplierNames[i], searchName) == 0)
        {
            printf("\nSupplier found!\n");
            supplierPrint(i);
            found = 1;
        }
    }

    if (!found)
    {
        printf("\nNo supplier named \"%s\" was found.\n", searchName);
    }
}