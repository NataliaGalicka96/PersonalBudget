#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    DateOperations dateOperations;

    const string NAME_INCOMES_FILE;
    const string NAME_EXPENSES_FILE;

public:
    PersonalBudget(string nameOfUsersFile, string nameOfIncomesFile, string nameOfExpensesFile):
        userManager(nameOfUsersFile), NAME_INCOMES_FILE(nameOfIncomesFile), NAME_EXPENSES_FILE(nameOfExpensesFile)
    {
        incomeManager=NULL;
        expenseManager=NULL;
    };
    ~PersonalBudget()
    {
      delete incomeManager;
      incomeManager=NULL;
      delete expenseManager;
      expenseManager=NULL;
    };

    void userRegistration();
    int userLogging();
    int downloadIdOfLoggedInUser();
    void changePasswordOfLoggedInUser();
    int userLogout();

    char selectOptionFromUserMenu();
    char selectOptionFromMainMenu();

    void addIncome();
    void showIncomeOfCurrentUser();

    void addExpense();
    void showExpenseOfCurrentUser();

    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSelectedPeriod();
    void showBalance(vector <Income> &incomesToBalance, vector <Expense> &expenseToBalance);


};
#endif // PERSONALBUDGET_H
