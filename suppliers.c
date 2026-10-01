#include <stdio.h>     
#include <string.h>     
#include "suppliers.h"  

void addSupplier(Supplier suppliers[], int *count)
{
    int id, i, exists;
    char tempName[100];
    char tempEmail[100];
    char tempTelephone[30];
    char tempTown[50];

    if (*count >= MAX_SUPPLIERS)
    {
        printf("\nSupplier limit reached. Cannot add more suppliers.\n");
        return;
    }

    printf("\n========== ADD SUPPLIER ==========\n");

    printf("Enter Supplier ID: ");
    scanf("%d", &id);
    getchar();

    if (id <= 0)
    {
        printf("\nError: Supplier ID must be a positive number.\n");
        return;
    }

    exists = 0;
    for (i = 0; i < *count; i++)
    {
        if (suppliers[i].supplierID == id)
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
    fgets(tempName, sizeof(tempName), stdin);
    tempName[strcspn(tempName, "\n")] = '\0';

    if (strlen(tempName) == 0)
    {
        printf("\nError: Supplier name cannot be empty.\n");
        return;
    }

    printf("Enter Email: ");
    fgets(tempEmail, sizeof(tempEmail), stdin);
    tempEmail[strcspn(tempEmail, "\n")] = '\0';

    if (strlen(tempEmail) == 0)
    {
        printf("\nError: Email cannot be empty.\n");
        return;
    }

    printf("Enter Telephone Number: ");
    fgets(tempTelephone, sizeof(tempTelephone), stdin);
    tempTelephone[strcspn(tempTelephone, "\n")] = '\0';

    if (strlen(tempTelephone) == 0)
    {
        printf("\nError: Telephone number cannot be empty.\n");
        return;
    }

    printf("Enter Town/Location: ");
    fgets(tempTown, sizeof(tempTown), stdin);
    tempTown[strcspn(tempTown, "\n")] = '\0';

    if (strlen(tempTown) == 0)
    {
        printf("\nError: Town/Location cannot be empty.\n");
        return;
    }

    suppliers[*count].supplierID = id;
    strcpy(suppliers[*count].name,      tempName);
    strcpy(suppliers[*count].email,     tempEmail);
    strcpy(suppliers[*count].telephone, tempTelephone);
    strcpy(suppliers[*count].town,      tempTown);

    (*count)++;

    printf("\nSupplier added successfully!\n");
}

void displaySuppliers(Supplier suppliers[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo suppliers have been registered.\n");
        return;
    }

    printf("\n================ SUPPLIER LIST ================\n");

    for (i = 0; i < count; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID     : %d\n", suppliers[i].supplierID);
        printf("Supplier Name   : %s\n", suppliers[i].name);
        printf("Email           : %s\n", suppliers[i].email);
        printf("Telephone       : %s\n", suppliers[i].telephone);
        printf("Town/Location   : %s\n", suppliers[i].town);
        printf("-----------------------------------------------\n");
    }
}

void searchSupplier(Supplier suppliers[], int count)
{
    int searchID;
    int i;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo suppliers have been registered.\n");
        return;
    }

    printf("\n========== SEARCH SUPPLIER ==========\n");
    printf("Enter Supplier ID to search: ");
    scanf("%d", &searchID);

    for (i = 0; i < count; i++)
    {
        if (suppliers[i].supplierID == searchID)
        {
            printf("\nSupplier found!\n");
            printf("Supplier ID     : %d\n", suppliers[i].supplierID);
            printf("Supplier Name   : %s\n", suppliers[i].name);
            printf("Email           : %s\n", suppliers[i].email);
            printf("Telephone       : %s\n", suppliers[i].telephone);
            printf("Town/Location   : %s\n", suppliers[i].town);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nSupplier with ID %d was not found.\n", searchID);
    }
}