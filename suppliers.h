#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

extern int supplierIDs[MAX_SUPPLIERS];
extern char supplierNames[MAX_SUPPLIERS][100];
extern char supplierEmails[MAX_SUPPLIERS][100];
extern char supplierPhones[MAX_SUPPLIERS][30];
extern char supplierTowns[MAX_SUPPLIERS][50];
extern int supplierCount;

int supplierReadNumber(void);
int supplierReadText(char text[], int size);
int supplierIsBlank(char text[]);
void supplierPrint(int i);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void searchSupplierByName(void);

#endif