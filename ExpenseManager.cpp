#include "ExpenseManager.h"


void ExpenseManager::addExpense()
{
    Expense expense;

    system("cls");

    cout<<" >>>> ADD NEW EXPENSE <<<< "<<endl<<endl;

    expense=enterDataOfNewExpense();

    expenses.push_back(expense);

    expensesXMLFile.saveExpenseToFile(expense);

}

Expense ExpenseManager::enterDataOfNewExpense()
{
    Expense expense;

    expense.setExpenseId(expensesXMLFile.downloadIdOfLastExpense()+1);

    expense.setUserId(ID_CURRENT_USER);

    cout<<"Is it expense from today? If yes, enter 'y', if no, enter 'n'."<<endl;
    char character;
    cin>>character;

    if(character=='y')
    {
        expense.setDate(dateOperations.getCurrentDay());
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
           expense.setDate(newDateText);


    }

    cout<<"Enter source of expense (for example: flat, restaurant, food, transport): ";
    string source;
    cin.sync();
    getline(cin>>ws,source);
    expense.setItem(source);

    cout<<"Enter amount of expense: ";
    float amount=0;
    string amountString="";
    cin.sync();
    cin>>amountString;

    amount=atof(AuxiliaryMethods::changeCommaToDot(amountString).c_str());
    expense.setAmount(amount);

    cin.sync();
    cout<<"Expense has been added!"<<endl;
    system("pause");

 return expense;
}

void ExpenseManager::showExpenseOfCurrentUser()
{
    system("cls");
    if(!expenses.empty())
    {

        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            showDataOfExpense(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "There is no expense!" << endl << endl;
    }
    system("pause");
}

void ExpenseManager::showDataOfExpense(Expense expense)
{
    cout << endl << "Id: " << expense.getExpenseId() << endl;
    cout << "Date: " << expense.getDate() << endl;
    cout << "Item: " << expense.getItem() << endl;
    cout << "Amount: " << expense.getAmount() << endl;

}
struct ExpenseManager::CompareDate
{
    bool operator()(Expense &first, Expense &second)
    {
        return first.getDate() < second.getDate();
    }
} myObjectToSortVector;

void ExpenseManager::sortExpensesByDateInAscendingOrder(vector <Expense> &expenses)
{
    sort(expenses.begin(), expenses.end(), myObjectToSortVector);
}
