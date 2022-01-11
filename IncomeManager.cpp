#include "IncomeManager.h"

void IncomeManager::addIncome()
{
    Income income;

    system("cls");

    cout<<" >>>> ADD NEW INCOME <<<< "<<endl<<endl;

    income=enterDataOfNewIncome();

    incomes.push_back(income);

    incomesXMLFile.saveIncomeToFile(income);


}

Income IncomeManager::enterDataOfNewIncome()
{
    Income income;

    income.setIncomeId(incomesXMLFile.downloadIdOfLastIncome()+1);

    income.setUserId(ID_CURRENT_USER);

    cout<<"Is it income from today? If yes, enter 'y', if no, enter 'n'."<<endl;
    char character;
    cin>>character;

    if(character=='y')
    {
        income.setDate(getCurrentDay());
    }
    else if(character=='n')
    {
        string newDateText="";
        cout<<"Enter date in format yyyy-mm-dd: ";
        cin.sync();
        cin>>newDateText;
        while(checkIfTheDateIsCorrect(newDateText)==false)
        {

            cout<<"Incorrect date! Enter a date between 2000-01-01 and the last day of the month of the current year."<<endl;
            Sleep(2000);
            system("cls");
            cout<<"Enter date in format yyyy-mm-dd: ";
            cin>>newDateText;
        }

        if(checkIfTheDateIsCorrect(newDateText)==true)
           income.setDate(newDateText);


    }

    cout<<"Enter source of income (for example: salary, interest on deposit): ";
    string source;
    cin.sync();
    getline(cin>>ws,source);
    income.setItem(source);

    cout<<"Enter amount of income: ";
    float amount=0;
    string amountString="";
    cin.sync();
    cin>>amountString;

    amount=atof(changeCommaToDot(amountString).c_str());
    income.setAmount(amount);

    cin.sync();
    cout<<"Income has been added!"<<endl;
    system("pause");

 return income;
}

string IncomeManager::changeCommaToDot(string amount)
{
    string przecinek=",";
    size_t pozycja=amount.find(przecinek);
    if(pozycja!=string::npos)
        amount.replace(pozycja,1,".");

    return amount;
}

string IncomeManager::getCurrentDay()
{
    // current date/time based on current system
    time_t now = time(0);


    tm *ltm = localtime(&now);
    //char* dt = ctime(&now1);


    int year=1900+ltm->tm_year;
    int month=1+ltm->tm_mon;
    int day=ltm->tm_mday;
    string currentDay="";


    string yearString=convertIntToString(year);
    string monthString=convertIntToString(month);
    string dayString=convertIntToString(day);

    if((month<10)&&(day>9))
        currentDay=yearString+"-"+"0"+monthString+"-"+dayString;
    if((month>9)&&(day<10))
        currentDay=yearString+"-"+monthString+"-"+"0"+dayString;
    if((month<10)&&(day<10))
        currentDay=yearString+"-"+"0"+monthString+"-"+"0"+dayString;
    if ((month>10)&&(day>10))
        currentDay=yearString+"-"+monthString+"-"+dayString;

    return currentDay;
}

string IncomeManager::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

bool IncomeManager::checkIfTheDateIsCorrect(string dateText)
{
    string currentDateText = getCurrentDay();

    int currentYear=getYearFromDate(currentDateText);
    int currentMonth=getMonthFromDate(currentDateText);
    int currentDay=getDayFromDate(currentDateText);

    int dateYear=getYearFromDate(dateText);
    int dateMonth = getMonthFromDate(dateText);
    int dateDay=getDayFromDate(dateText);

        if((dateYear==currentYear) && (dateMonth>=1 && dateMonth<=currentMonth)&&(dateDay>=1&&dateDay<=returnNumberOfDaysInMonth(currentMonth,currentYear)))
        {
            return true;
        }
        else if((dateYear<currentYear)&&(dateYear>=2000)&&(dateMonth>=1)&&(dateMonth<=12) && (dateDay>=1 && dateDay<=returnNumberOfDaysInMonth(dateMonth,dateYear)))
        {
            return true;
        }
        else
        return false;

}

int IncomeManager::returnNumberOfDaysInMonth(int month, int year)
{
    if (!month)
    {
        cerr<<"It's not a digit!";
        exit(0);
    }
    int numberOfDays;

    switch(month)

    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        numberOfDays=31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        numberOfDays=30;
        break;

    case 2:
    {

        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
            numberOfDays=29;
        else numberOfDays=28;
    }
    break;


    }
    return numberOfDays;
}

int IncomeManager::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

int IncomeManager::getYearFromDate(string date)
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
int IncomeManager::getMonthFromDate(string date)
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
int IncomeManager::getDayFromDate(string date)
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


void IncomeManager::showIncomeOfCurrentUser()
{
    system("cls");
    if(!incomes.empty())
    {

        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            showDataOfIncome(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "File is empty!" << endl << endl;
    }
    system("pause");
}

void IncomeManager::showDataOfIncome(Income income)
{
    cout << endl << "Id: " << income.getIncomeId() << endl;
    cout << "Date: " << income.getDate() << endl;
    cout << "Item: " << income.getItem() << endl;
    cout << "Amount: " << income.getAmount() << endl;

}
