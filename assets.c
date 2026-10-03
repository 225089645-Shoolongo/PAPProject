#include <stdio.h>
#include <string.h>
#include "assets.h"

#define MAX_ASSETS 100

typedef struct
{
    char assetID[20];
    char assetName[50];
    char assetType[30];
    double purchaseValue;
    char department[50];
    char condition[30];
} Asset;

static Asset assets[MAX_ASSETS];
static int assetCount = 0;


/* Clears unwanted characters from keyboard input */
static void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}


/* Reads text including spaces */
static void readLine(char text[], int size)
{
    if (fgets(text, size, stdin) != NULL)
    {
        text[strcspn(text, "\n")] = '\0';
    }
}


/* Add a new municipal asset */
void addAsset(void)
{
    int i;

    if (assetCount >= MAX_ASSETS)
    {
        printf("\nAsset storage is full.\n");
        return;
    }

    printf("\n===== ADD ASSET =====\n");

    printf("Enter Asset ID: ");
    readLine(assets[assetCount].assetID,
             sizeof(assets[assetCount].assetID));

    if (strlen(assets[assetCount].assetID) == 0)
    {
        printf("Asset ID cannot be empty.\n");
        return;
    }

    /* Check if Asset ID already exists */
    for (i = 0; i < assetCount; i++)
    {
        if (strcmp(assets[i].assetID,
                   assets[assetCount].assetID) == 0)
        {
            printf("Asset ID already exists.\n");
            return;
        }
    }

    printf("Enter Asset Name: ");
    readLine(assets[assetCount].assetName,
             sizeof(assets[assetCount].assetName));

    if (strlen(assets[assetCount].assetName) == 0)
    {
        printf("Asset name cannot be empty.\n");
        return;
    }

    printf("Enter Asset Type: ");
    readLine(assets[assetCount].assetType,
             sizeof(assets[assetCount].assetType));

    printf("Enter Purchase Value: N$");

    if (scanf("%lf", &assets[assetCount].purchaseValue) != 1)
    {
        printf("Invalid purchase value.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (assets[assetCount].purchaseValue < 0)
    {
        printf("Purchase value cannot be negative.\n");
        return;
    }

    printf("Enter Department: ");
    readLine(assets[assetCount].department,
             sizeof(assets[assetCount].department));

    printf("Enter Condition (Good/Fair/Poor): ");
    readLine(assets[assetCount].condition,
             sizeof(assets[assetCount].condition));

    assetCount++;

    printf("\nAsset added successfully.\n");
}


/* Display all registered assets */
void displayAssets(void)
{
    int i;

    printf("\n=============== ASSET REGISTER ===============\n");

    if (assetCount == 0)
    {
        printf("No assets have been registered.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("----------------------------------------\n");
        printf("Asset ID       : %s\n", assets[i].assetID);
        printf("Asset Name     : %s\n", assets[i].assetName);
        printf("Asset Type     : %s\n", assets[i].assetType);
        printf("Purchase Value : N$%.2f\n",
               assets[i].purchaseValue);
        printf("Department     : %s\n", assets[i].department);
        printf("Condition      : %s\n", assets[i].condition);
    }
}


/* Search for an asset */
void searchAsset(void)
{
    char search[50];
    int i;
    int found = 0;

    printf("\n===== SEARCH ASSET =====\n");

    if (assetCount == 0)
    {
        printf("No assets have been registered.\n");
        return;
    }

    printf("Enter Asset ID or Asset Name: ");
    readLine(search, sizeof(search));

    for (i = 0; i < assetCount; i++)
    {
        if (strcmp(search, assets[i].assetID) == 0 ||
            strcmp(search, assets[i].assetName) == 0)
        {
            printf("\nAsset found.\n");
            printf("----------------------------------------\n");
            printf("Asset ID       : %s\n", assets[i].assetID);
            printf("Asset Name     : %s\n", assets[i].assetName);
            printf("Asset Type     : %s\n", assets[i].assetType);
            printf("Purchase Value : N$%.2f\n",
                   assets[i].purchaseValue);
            printf("Department     : %s\n", assets[i].department);
            printf("Condition      : %s\n", assets[i].condition);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Asset not found.\n");
    }
}


/* Asset Management submenu */
void assetMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("          ASSET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Return to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Enter a number from 1 to 4.\n");
            clearInputBuffer();
            choice = 0;
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
            case 1:
                addAsset();
                break;

            case 2:
                displayAssets();
                break;

            case 3:
                searchAsset();
                break;

            case 4:
                printf("Returning to Main Menu...\n");
                break;

            default:
                printf("Invalid choice. Please choose 1 to 4.\n");
        }

    } while (choice != 4);
}
