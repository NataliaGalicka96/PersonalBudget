#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <algorithm>

#include "Expense.h"
#include "Markup.h"
#include "ExpensesXMLFile.h"
#include "DateOperations.h"


using namespace std;

class ExpenseManager
{
    const int ID_CURRENT_USER;
    ExpensesXMLFile expensesXMLFile;
    DateOperations dateOperations;

public:
    ExpenseManager(string nameOfExpensesFile, int idCurrentUser)
    :expensesXMLFile(nameOfExpensesFile), ID_CURRENT_USER(idCurrentUser)
    {
        expenses=expensesXMLFile.loadExpensesFromFile(ID_CURRENT_USER);
    }

    vector <Expense> expenses;
    Expense enterDataOfNewExpense();
    void addExpense();

    void showExpenseOfCurrentUser();
    void showDataOfExpense(Expense expense);

    struct CompareDate;
    void sortExpensesByDateInAscendingOrder(vector <Expense> &expenses);
};
#endif // EXPENSEMANAGER_H
