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
       // income.setDateText(getCurrentDay());
    }
    else if(character=='n')
    {
        cout<<"Enter date in format yyyy-mm-dd: ";
        string newDateText="";
        cin.sync();
        cin>>newDateText;
        //sprawdzenie czy data ma prawdilowy format
        income.setDateText(newDateText);
    }

    cout<<"Enter source of income (for example: salary, interest on deposit): ";
    string source;
    cin.sync();
    cin>>source;
    income.setItem(source);

    cout<<"Enter amount of income: ";
    float amount;
    cin>>amount;
    income.setAmount(amount);

 return income;
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

    if((month<10)&&(day>10))
        currentDay=yearString+"-"+"0"+monthString+"-"+dayString;
    if((month>10)&&(day<10))
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
