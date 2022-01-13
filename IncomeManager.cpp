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
        income.setDate(dateOperations.getCurrentDay());
    }
    else if(character=='n')
    {
        string newDateText="";
        cout<<"Enter date in format yyyy-mm-dd: ";
        cin.sync();
        cin>>newDateText;
        while(dateOperations.checkIfTheDateIsCorrect(newDateText)==false)
        {

            cout<<"Incorrect date! Enter a date between 2000-01-01 and the last day of the month of the current year."<<endl;
            Sleep(2000);
            system("cls");
            cout<<"Enter date in format yyyy-mm-dd: ";
            cin>>newDateText;
        }

        if(dateOperations.checkIfTheDateIsCorrect(newDateText)==true)
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

    amount=atof(AuxiliaryMethods::changeCommaToDot(amountString).c_str());
    income.setAmount(amount);

    cin.sync();
    cout<<"Income has been added!"<<endl;
    system("pause");

 return income;
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
        cout << endl << "There is no incomes!" << endl << endl;
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

struct IncomeManager::CompareDate
{
    bool operator()(Income &first, Income &second)
    {
        return first.getDate() < second.getDate();
    }
} myObjectToSortVector2;

void IncomeManager::sortIncomesByDateInAscendingOrder(vector <Income> &incomes)
{
    sort(incomes.begin(), incomes.end(), myObjectToSortVector2);
}
