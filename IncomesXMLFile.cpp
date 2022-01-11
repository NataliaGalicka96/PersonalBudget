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
    amount=convertDoubleToString(income.getAmount());
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

string IncomesXMLFile::convertDoubleToString (double number)
{
    ostringstream os;
    os << number;
    string stringOut = os.str();
    return stringOut;
}


int IncomesXMLFile::getYearFromDate(string date)
{
    string stringYear;
    string stringMonth;
    string stringDay;
    int year;
    int month;
    int day;
    string dateWithoutDash="";


    for (int i=0; i<=date.length(); i++)
    {

        if((date[i]!='-')&&(i!=10))
        {
            dateWithoutDash+=date[i];
        }
    }

    stringYear=dateWithoutDash.substr(0,4);
    stringMonth=dateWithoutDash.substr(4,2);
    stringDay=dateWithoutDash.substr(7,2);

    year=convertStringToInt(stringYear);
    month=convertStringToInt(stringMonth);
    day=convertStringToInt(stringDay);

    return year;
}
int IncomesXMLFile::getMonthFromDate(string date)
{
    string stringYear;
    string stringMonth;
    string stringDay;
    int year;
    int month;
    int day;
    string dateWithoutDash="";


    for (int i=0; i<=date.length(); i++)
    {

        if((date[i]!='-')&&(i!=10))
        {
            dateWithoutDash+=date[i];
        }
    }

    stringYear=dateWithoutDash.substr(0,4);
    stringMonth=dateWithoutDash.substr(4,2);
    stringDay=dateWithoutDash.substr(7,2);


    year=convertStringToInt(stringYear);
    month=convertStringToInt(stringMonth);
    day=convertStringToInt(stringDay);

    return month;
}
int IncomesXMLFile::getDayFromDate(string date)
{
    string stringYear;
    string stringMonth;
    string stringDay;
    int year;
    int month;
    int day;
    string dateWithoutDash="";


    for (int i=0; i<=date.length(); i++)
    {

        if((date[i]!='-')&&(i!=10))
        {
            dateWithoutDash+=date[i];
        }
    }

    stringYear=dateWithoutDash.substr(0,4);
    stringMonth=dateWithoutDash.substr(4,2);
    stringDay=dateWithoutDash.substr(6,2);

    year=convertStringToInt(stringYear);
    month=convertStringToInt(stringMonth);
    day=convertStringToInt(stringDay);

    return day;
}
int IncomesXMLFile::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
