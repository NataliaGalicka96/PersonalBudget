#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include "Income.h"
#include "Markup.h"
#include "IncomesXMLFile.h"

using namespace std;

class IncomeManager
{

    const int ID_CURRENT_USER;
    vector <Income> incomes;
    IncomesXMLFile incomesXMLFile;


public:
    IncomeManager(string nameOfIncomesFile, int idCurrentUser)
    :incomesXMLFile(nameOfIncomesFile), ID_CURRENT_USER(idCurrentUser)
    {
        incomes=incomesXMLFile.loadIncomesFromFile();
        //wczytaj adresatow zalogowanego uzytkownika
    }
    void addIncome();
    Income enterDataOfNewIncome();


    string getCurrentDay();
    string convertIntToString(int number);
    bool checkIfTheDateIsCorrect(string dateText);
    int getDayFromDate(string date);
    int getMonthFromDate(string date);
    int getYearFromDate(string date);
    int returnNumberOfDaysInMonth(int month, int year);
    int convertStringToInt(string number);

};
#endif // INCOMEMANAGER_H
