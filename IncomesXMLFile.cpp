#include "IncomesXMLFile.h"

int IncomesXMLFile::downloadIdOfLastIncome()
{
    CMarkup xml;
    int idOfLastIncome = 0;

    bool fileExists = xml.Load(XMLFile::downloadXMLFileName());

    if (!fileExists)
        return 0;
    else
    {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("IncomeID");
            idOfLastIncome = atoi(xml.GetElemContent().c_str());
            xml.OutOfElem();
        }
    }
    return idOfLastIncome;
}

void IncomesXMLFile::saveIncomeToFile(Income income)
{
    CMarkup xml;
    string amount;
    bool fileExists = xml.Load(XMLFile::downloadXMLFileName());
    if (!fileExists)
    {
        xml.AddElem("Incomes");
    }


    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeID", income.getIncomeId() );
    xml.AddElem("UserID",income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item",income.getItem());
    amount=AuxiliaryMethods::convertDoubleToString(income.getAmount());
    xml.AddElem("IncomeAmount",amount);



    xml.Save(XMLFile::downloadXMLFileName());
    cout<<"Save income to XML file!"<<endl;
}

vector <Income> IncomesXMLFile::loadIncomesFromFile(int idCurrentUser)
{
    vector <Income> incomes;
    Income income;
    CMarkup xml;

    bool fileExist = xml.Load(XMLFile::downloadXMLFileName());

    if (!fileExist)
    {
        cout<<"File is empty!"<<endl;
    }

    xml.FindElem("Incomes");
    xml.IntoElem();
    while(xml.FindElem("Income"))
    {
        xml.IntoElem();

        xml.FindElem("UserID");

        if(idCurrentUser==atoi(xml.GetData().c_str()))
        {
            xml.ResetMainPos();
            xml.IntoElem(); //inside user
            xml.FindElem("IncomeID");
            income.setIncomeId(atoi(xml.GetData().c_str()));
            xml.ResetMainPos();


            xml.FindElem("UserID");
            income.setUserId(atoi(xml.GetData().c_str()));

            xml.FindElem("Date");
            income.setDate(xml.GetData());

            xml.FindElem("Item");
            income.setItem(xml.GetData());

            xml.FindElem("IncomeAmount");
            income.setAmount(atof(xml.GetData().c_str()));

            incomes.push_back(income);
        }

        xml.OutOfElem();

    }
    return incomes;
}
