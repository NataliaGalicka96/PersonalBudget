#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <algorithm>

#include "Income.h"
#include "Markup.h"
#include "IncomesXMLFile.h"
#include "DateOperations.h"

using namespace std;

class IncomeManager
{

    const int ID_CURRENT_USER;
    IncomesXMLFile incomesXMLFile;
    DateOperations dateOperations;


public:
    IncomeManager(string nameOfIncomesFile, int idCurrentUser)
    :incomesXMLFile(nameOfIncomesFile), ID_CURRENT_USER(idCurrentUser)
    {
        incomes=incomesXMLFile.loadIncomesFromFile(ID_CURRENT_USER);
    }

    vector <Income> incomes;
    Income enterDataOfNewIncome();
    void addIncome();


    void showIncomeOfCurrentUser();
    void showDataOfIncome(Income income);

    struct CompareDate;
    void sortIncomesByDateInAscendingOrder(vector <Income> &incomes);

};
#endif // INCOMEMANAGER_H
