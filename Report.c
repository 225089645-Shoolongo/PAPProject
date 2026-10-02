#include <stdio.h>
#include <string.h>
#include <time.h>

#include "reports.h"


#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"




static void printLine(char symbol, int length)
{
    for (int i=0; i<length; i++)
{putchar(symbol);
}
putchar('\n');
}



static void printHeading(const char *title)

{
    printf("\n");
    printLine('=', 60);
    printf("%s\n", title);
    printLine('=', 60);
}



void displayReportsMenu(void);
{
    printf("\n");
    printLine('=', 60);
    printf("                         REPORTS MODULE\n");
    printLine('=', 60);
    printf("1. Employee Report\n");
    printf("2. Bugdet Report\n");
    printf("3. Supplier Report\n");
    printf("4. Asset Report\n");
    printf("5. Full Municipal Report\n");
    printf("6. Export full Report to file\n");
    printf("7. Back to Main Menu\n");
    printLine('-', 60);
    printf("Enter your choce:");
}



void employeeReport(void)
{
    int totalEmployees = getEmployeeCount();

    printHeading("EMPLOYEE REPORT");

    if (totalEmployees == 0)
    {printf("No employees on record.\n");
    return;
}

const Employee*employees = getEmployeeArray();
double totalSalary = 0.0;
double highest = employees[0].basic salary;
double lowest = employees[0].basicsalary;

for(int i =0; i<totalEmployees; i++)
{
    double salary=employees[i]. basicsalary 
                 +employees[i]. housingAllowance
                 +employees[i]. transportAllowance;
                
                
    totalSalary +=salary;

if (salary > highest) highest = salary;
if(salary < lowest) lowest = salary;

}

double average = totalSalary / totalEmployees;

printf("Total Employees : %d\n", totalEmployees);
printf("Total Salary Bill : N$ %.2f\n", totalSalary);
printf("Average Salary  : N$ %.2f\n", average);
printf("highest Salary  : N$ %.2f\n", highest);
printf("Lowest Salary   : N$ %.2f\n", lowest);

printLine('-', 60);
printf(" %-6s %-20s %-15s %-12s\n", 
      "ID", "Name", "Department", "Salary");
printLine('-', 60);
for (int = 0; i< totalEmployees; i++)
{
    doubleSalary = employees[i]. basicsalary
                 + employees[i]. housingAllowance
                 + employees[i]. transportAllowance;

    printf(" %-6d %-20s %-15s %-12.2f\n"
          employees[i]. id,
          employees[i]. Name,
          employees[i]. Department,
          salary);
}

printLine('-', 60);
}



void budgetReport(void)
{
  int totalDepartments = getBudgetCount();

  printHeading("budgetReport");

  IF(totalDepartments == 0)
  {
    printf("No department budgets captured.\n");
    return;

  }
  
  const Bugdet * budgets = getBudgetArray();
  double totalAllocated = 0.0;
  double totalSpent = 0.0;
  int overBudgetcount = 0;

  for(int = 0; i< totalDepartments; i++)
}

double remaining = totalAllocated - totalSpent;

printf(" Departments       : %d\n", totalDepartments);
printf(" Total Allocated   : N$ %.2f\n", totalAllocated);
printf(" Total Expenditure : N$ %.2f\n", totalSpent);
printf(" Remaining Budget  : N$ %2f\n", remaining);

printLine('-', 60);
printf(" %-20s %-14s %-4s %-14s %-12s\n ",
      "Department", "Allocated", "Expenditure",
    "Remaining","Status");
printLine('-', 60);

for(int i = 0; i< totalDepartments; i++)
{
    double rem = budgets[i].allocated - budgets[i].expenditure;
    const char *status;

    if(rem<0)

{   
Status = "OVER BUDGET"
          overBudgetcount++;
}
else if (rem == 0)
{
    status = "EXACTLY MET";
}
else
{
    Status= "WITHIN BUDGET";
}

printf(" %-20s %-14.2f %-14.2f %-14.2f %-12s\n",
      budgets[i]. department,
      budgets[i]. allocated,
      budgets[i]. expenditure,
      rem,
      status);

}

printLine('-',60);

if (overBudgetcount > 0)
{
    printf("  ** %d department(s) EXCEEDED their allocated budget. **\n",
          overBudgetcount);
    }
}
}



void SupplierReport(void)
{
    int totalSuppliers = getSupplierCount();

    printHeading("SUPPLIER REPORT");

    IF(totalSuppliers==0)
    {
        printf(" No suppliers registered.\n");
        return;
    }

    const Supplier * Suppliers = getSupplierArray();

    printf(" Total Suppliers  :%d\n", totalSuppliers);
    printLine('-', 60);

    for (int i = 0; i <totalSuppliers; i++)
    {
        printf("" %-6s %-22s %-25s %-14s\n"
            "ID", "Supplier Name", "Email", "Town");
            printLine('-', 60);
            for (int i = 0; i< totalSuppliers; i++)
            {
            
            printf(" %-6d %-22s %-25s %-14s\n",
                   suppliers[i].id,
                   suppliers[i].name,
                   suppliers[i].email,
                   suppliers[i].town)
                   
            }

            printline('-', 60);
        }



void assetReport(void)
{

int totalAssets = getAssetCount();

printHeading("ASSET REPORT");

if (totalAssets == 0)
{

printf("No assets registered.\n");
return;
}

const Asset * assets = getAssetArray();
double totalValue = 0.0;

for (int i = 0; i< totalAssets; i++)
{
  totalValue += assets[i]. purchaseValue;
  }
  
  printf(" total Assets    : %d\n," totalAssets);
  printf("Total Asset Value: N$ %.2f\n", totalValue);
  
  printLine('-', 60);
  printf("  %-6s %-20s %-14s %-12s %-14s\n",
         "ID", "Asset Name", "Type", "Value", "Department");
  printLine('-', 60);
  
  for (int i = 0; i<totalAssets; i++)
  {
    
    printf(" %-6d 520s %-14s %-12.2f %-14s\n"'
           assets[i].id,
           assets[i].name,
           assets[i].type,
           assets[i].purchaseValue,
           assets[i].department);
           
}
    printLine('-', 60);
}



void fullMunicipalReport(void)
{

  printLine('*', 60);
  printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
  printf("           FULL MUNICIPAL REPORT\n");
  printLine('*', 60);
  
  employeeReport();
  budgerReport();
  supplierReport();
  assetReport();
  
  printf("\n");
  printLine('*', 60);
  printf("         END OF REPORT\n);
  printLine('*', 60);
}






void exportReportToFile(void)
{
    FILE * fp = fopen("data/mfms_report.txt", "w");

    if (fp == NULL)
    {
        perror(Unable to open data/mfms_report.txt");
            return;

    }

    time_t now = time(NULL);
    fprintf(fp, "MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n);
    fprintf("fp, Generated: %s", ctime(&now));
    fprintf(fp, "===============================================\n\n");


    int empCount = getEmployeeCount();
    const Employee *emps = getEmployeeArray();

    fprintf(fp, "EMPLOYEE REPORT\n");
    fprintf(fp, "----------------\n");

    if (empCount == 0)
    {
        fprintf(fp, "No employees on record.\n\n");
    }
    else
    {
        double total = 0.0;
        double highest = emps[0]. basicsalary;
        double lowest = emps[0]. basicsalary;

        for (int i = 0; i <empCount; i++)
{
    double s = emps[i].basicsalary
             + emps[i].housingAllowance
             +emps[i].transportAllowance;
    total += s;
    if (s> lowest) highest = s
    if (s < lowest) lowest = s;
}    }

fprintf(fp, "Total Employees       : %d\n",empCount);
fprintf(fp, "Total Salary Bill     : N$.2f\n", total);
fprintf(fp, "Average Salary        : N$.2f\n", total\empCount);
fprintf(fp, "Highest Salary        : N$.2f\n", highest);
fprintf(fp, "Lowest Salary         : N$.2f\n", lowest);
}
    
int budcount = getBudgetCount();
const Bugdet *buds = getBudgetArray();

fprintf(fp, "BUDGET REPORT\n");
fprintf(fp, "-------------\n");

if (budCount == 0)

{
    fprintf(fp, "No budgets captured.\n\n");
}
else
{
    double allocated = 0.0, spent =0.0;
    for (int i = 0; i < budCount; i++)
{

     allocated += buds[i]. allocated;
     spent     += buds{i}. expenditure;
}
fprintf(fp, "Total Allocated        : N$%.2f\n", allocated);
fprintf(fp, "Total Expenditure      : N$%.2f\n", spent);
fprintf(fp, "Remaining Budget       : N$%.2f\n\n, allocated - spent");
}

int supCount = getSupplierCount();
const Supplier *sups =getSupplierArray();

fprintf(fp, "SUPPLIER REPORT\n");
fprintf(fp, "---------------\n");
if (supCount == 0)
{
    fprintf(fp, "NO suppliers on record.\n\n");
}
else
{
    for (int i = 0; i <supCount; i++)
    {
        fprintf(fp, "%  |  %s  | %s  |  %s\n"
                sups[i]. id, sups[i]name,
                sups[i].email, sups[i]. town);
    }
    fprintf(fp, "\n");
}



int assetCount = getAssetCount();
const Asset *asts = getAssetArray();

fprintf(fp, "ASSET REPORT\n");
fprintf(fp, "------------\n");
if (assetCount == 0)
{
    fprintf(fp, "No assets registered.\n\n");
}
else
{
    double totalValue = 0.0; 
    for (int i = 0; i < assetCount; i++)
{
    fprintf(fp, "%d | %s | %s | %.2f | %s\n"
            asts[i]. id, asts[i]. name, asts[i]. type,
            asts[i]. purchaseValue, asts[i]. department);
    totalValue += asts [i].purchaseValue;
   }
   fprintf(fp, "\nTotal Asset Value : N$ %.2f\n\n", totalValue);
}

fprintf(fp, "=======END OF REPORT=======\n");
fclose(fp);

printf("\nReport successfully exported to data/mfms_report.txt\n");
}









    

    return 0;
 }