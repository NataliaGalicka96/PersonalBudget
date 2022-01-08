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
    //xml.AddElem("Day", income.incomeDate);
   // xml.AddElem("Month","12");
   // xml.AddElem("Year","2015");
    xml.AddElem("DateText", income.getDateText());
    xml.AddElem("Item",income.getItem());
    xml.AddElem("IncomeAmount",income.getAmount());


    xml.Save(XMLFile::downloadXMLFileName());
    cout<<"Save income to XML file!"<<endl;
}
vector <Income> IncomesXMLFile::loadIncomesFromFile()
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

        xml.FindElem("IncomeId");
        income.setIncomeId(atoi(xml.GetData().c_str()));

        xml.FindElem("UserId");
        income.setUserId(atoi(xml.GetData().c_str()));

        xml.FindElem("DateText");
        income.setDateText(xml.GetData());

        xml.FindElem("Item");
        income.setItem(xml.GetData());

        xml.FindElem("IncomeAmount");
        income.setAmount(atof(xml.GetData().c_str()));


        xml.OutOfElem();

        incomes.push_back(income);

    }
    return incomes;

}
