#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H

#include <iostream>
#include <vector>
#include <sstream>


#include "XMLFile.h"
#include "Income.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

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

};
#endif // INCOMESXMLFILE_H
