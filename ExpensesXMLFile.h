#ifndef EXPENSESXMLFILE_H
#define EXPENSESXMLFILE_H

#include <iostream>
#include <vector>
#include <sstream>

#include "XMLFile.h"
#include "Expense.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpensesXMLFile : public XMLFile
{
    int idOfLastExpense;

public:
    ExpensesXMLFile(string nameOfExpensesFile):XMLFile(nameOfExpensesFile)
    {
        idOfLastExpense=0;
    }

    int downloadIdOfLastExpense();
    vector <Expense> loadExpensesFromFile(int idCurrentUser);
    void saveExpenseToFile(Expense expense);


};


#endif // EXPENSESXMLFILE_H
