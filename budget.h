#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 50

typedef struct Budget
{
    int id;
    char department[50];
    double allocated;
    double expenditure;
} Budget;

extern Budget budgets[MAX_BUDGETS];
extern int budget_count;

void budgetMenu(void);
void addBudget(void);
void recordExpenditure(void);
void displayBudgets(void);
void displayExceededBudgets(void);
void budSummaryReport(void);

int findDepartment(char name[]);
double getRemaining(int i);
void printBudget(int i);

int getBudgetCount(void);
const Budget *getBudgetArray(void);

#endif
