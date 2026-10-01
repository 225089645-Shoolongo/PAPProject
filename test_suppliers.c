#include <stdio.h>
#include "suppliers.h"       /* ← only the HEADER, not the .c file */

int main(void)
{
    Supplier suppliers[MAX_SUPPLIERS];
    int count = 0;
    int choice;

    do {
        printf("\n===== SUPPLIER TEST MENU =====\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addSupplier(suppliers, &count); break;
            case 2: displaySuppliers(suppliers, count); break;
            case 3: searchSupplier(suppliers, count); break;
            case 0: printf("Goodbye.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}