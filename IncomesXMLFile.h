#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H

#include <iostream>
#include <vector>
#include <sstream>


#include "XMLFile.h"
#include "Income.h"
#include "Markup.h"

using namespace std;

class IncomesXMLFile : public XMLFile
{
    int idOfLastIncome;


public:
    IncomesXMLFile(string nameOfIncomesFile):XMLFile(nameOfIncomesFile)
    {
        idOfLastIncome=0;
    };

    int downloadIdOfLastIncome();
    vector <Income> loadIncomesFromFile(int idCurrentUser);
    void saveIncomeToFile(Income income);

    string convertDoubleToString (double number);

    vector <Income> loadAllUserIncomes(/*int idCurrentUser*/);

    int getDayFromDate(string date);
    int getMonthFromDate(string date);
    int getYearFromDate(string date);
    int convertStringToInt(string number);

};
#endif // INCOMESXMLFILE_H
