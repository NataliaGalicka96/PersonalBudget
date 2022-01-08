#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H

#include <iostream>
#include <vector>

#include "XMLFile.h"
#include "Income.h"
#include "Markup.h"

using namespace std;

class IncomesXMLFile : public XMLFile
{
    int idOfLasIncome;


public:
    IncomesXMLFile(string nameOfIncomesFile):XMLFile(nameOfIncomesFile)
    {
        idOfLasIncome=0;
    };

    int downloadIdOfLastIncome();
    vector <Income> loadIncomesFromFile();
    void saveIncomeToFile(Income income);
};
#endif // INCOMESXMLFILE_H
