#include "ExpensesXMLFile.h"

int ExpensesXMLFile::downloadIdOfLastExpense()
{
    CMarkup xml;
    int idOfLastExpense = 0;

    bool fileExists = xml.Load(XMLFile::downloadXMLFileName());

    if (!fileExists)
        return 0;
    else
    {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem("ExpenseID");
            idOfLastExpense = atoi(xml.GetElemContent().c_str());
            xml.OutOfElem();
        }
    }
    return idOfLastExpense;
}

void ExpensesXMLFile::saveExpenseToFile(Expense expense)
{
    CMarkup xml;
    string amount;
    bool fileExists = xml.Load(XMLFile::downloadXMLFileName());
    if (!fileExists)
    {
        xml.AddElem("Expenses");
    }


    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseID", expense.getExpenseId() );
    xml.AddElem("UserID",expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item",expense.getItem());
    amount=AuxiliaryMethods::convertDoubleToString(expense.getAmount());
    xml.AddElem("ExpenseAmount",amount);



    xml.Save(XMLFile::downloadXMLFileName());
    cout<<"Save expense to XML file!"<<endl;
}

vector <Expense> ExpensesXMLFile::loadExpensesFromFile(int idCurrentUser)
{
    vector <Expense> expenses;
    Expense expense;
    CMarkup xml;

    bool fileExist = xml.Load(XMLFile::downloadXMLFileName());

    if (!fileExist)
    {
        cout<<"File is empty!"<<endl;
    }

    xml.FindElem("Expenses");
    xml.IntoElem();
    while(xml.FindElem("Expense"))
    {
        xml.IntoElem();

        xml.FindElem("UserID");

        if(idCurrentUser==atoi(xml.GetData().c_str()))
        {
            xml.ResetMainPos();
            xml.IntoElem(); //inside user
            xml.FindElem("ExpenseID");
            expense.setExpenseId(atoi(xml.GetData().c_str()));
            xml.ResetMainPos();


            xml.FindElem("UserID");
            expense.setUserId(atoi(xml.GetData().c_str()));

            xml.FindElem("Date");
            expense.setDate(xml.GetData());

            xml.FindElem("Item");
            expense.setItem(xml.GetData());

            xml.FindElem("ExpenseAmount");
            expense.setAmount(atof(xml.GetData().c_str()));

            expenses.push_back(expense);
        }

        xml.OutOfElem();

    }
    return expenses;
}
