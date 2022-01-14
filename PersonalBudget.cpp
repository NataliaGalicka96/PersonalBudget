#include "PersonalBudget.h"

void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}

int PersonalBudget::userLogging()
{
    userManager.userLogging();
    if(userManager.checkUserLoggedIn())
    {
        incomeManager = new IncomeManager(NAME_INCOMES_FILE, userManager.downloadIdOfLoggedInUser());
        expenseManager = new ExpenseManager(NAME_EXPENSES_FILE, userManager.downloadIdOfLoggedInUser());
    }
}

void PersonalBudget::changePasswordOfLoggedInUser()
{
    userManager.changePasswordOfLoggedInUser();
}

int PersonalBudget::downloadIdOfLoggedInUser()
{
    userManager.downloadIdOfLoggedInUser();
}

int PersonalBudget::userLogout()
{
    userManager.userLogout();
}

char PersonalBudget::selectOptionFromUserMenu()
{
    userManager.selectOptionFromUserMenu();
}

char PersonalBudget::selectOptionFromMainMenu()
{
    userManager.selectOptionFromMainMenu();
}

void PersonalBudget::addIncome()
{
    incomeManager = new IncomeManager(NAME_INCOMES_FILE,userManager.downloadIdOfLoggedInUser());
    incomeManager -> addIncome();
}

void PersonalBudget::showIncomeOfCurrentUser()
{
    incomeManager->showIncomeOfCurrentUser();
}

void PersonalBudget::addExpense()
{
    expenseManager = new ExpenseManager (NAME_EXPENSES_FILE,userManager.downloadIdOfLoggedInUser());
    expenseManager -> addExpense();
}

void PersonalBudget::showExpenseOfCurrentUser()
{
    expenseManager->showExpenseOfCurrentUser();
}

void PersonalBudget::showBalanceFromCurrentMonth()
{
    string currentDate=dateOperations.getCurrentDay();
    vector <Income> incomesToSort;
    vector <Expense> expensesToSort;

    int currentMonth=dateOperations.getMonthFromDate(currentDate);
    int currentYear=dateOperations.getYearFromDate(currentDate);

        for (int i = 0; i < incomeManager->incomes.size(); i++)
        {
            if (currentMonth==dateOperations.getMonthFromDate(incomeManager->incomes[i].getDate())
                    && currentYear==dateOperations.getYearFromDate(incomeManager->incomes[i].getDate()))
            {
                incomesToSort.push_back(incomeManager->incomes[i]);
            }
        }

    incomeManager->sortIncomesByDateInAscendingOrder(incomesToSort);

        for (int i = 0; i < expenseManager->expenses.size(); i++)
        {
            if (currentMonth==dateOperations.getMonthFromDate(expenseManager->expenses[i].getDate())
                    && currentYear==dateOperations.getYearFromDate(expenseManager->expenses[i].getDate()))
            {
                expensesToSort.push_back(expenseManager->expenses[i]);
            }
        }

    expenseManager->sortExpensesByDateInAscendingOrder(expensesToSort);

    system("cls");
    cout<<"Balance from current month:"<<endl<<endl;

    showBalance(incomesToSort, expensesToSort);
}

void PersonalBudget::showBalance(vector <Income> &incomesToBalance, vector <Expense> &expensesToBalance)
{
    cout << "Incomes: " << endl;

    if(!incomesToBalance.empty())
    {
        for (int i = 0; i < incomesToBalance.size(); i++)
        {
            cout<<fixed<<setprecision(2);
            cout<<"Date: "<<incomesToBalance[i].getDate()<<" Item: "<<incomesToBalance[i].getItem()<< " Amount: "
                 <<incomesToBalance[i].getAmount()<<" zl."<<endl;
        }
    }
    else
        cout<<"No incomes at the selected time!"<<endl;

    cout << endl;
    cout << "Expenses: " << endl;

    if(!expensesToBalance.empty())
    {
        for (int i = 0; i < expensesToBalance.size(); i++)
        {
            cout<<fixed<<setprecision(2);
            cout <<"Date: "<<expensesToBalance[i].getDate()<<" Item: "<<expensesToBalance[i].getItem()<<" Amount: "
                 <<expensesToBalance[i].getAmount()<<" zl."<< endl;
        }
    }
    else
        cout<<"No expenses at the selected time!"<<endl;

    cout << endl;

    double sumOfIncomes = 0;
    double sumOfExpenses = 0;

    for (int i = 0; i < incomesToBalance.size(); i++)
    {
        sumOfIncomes += incomesToBalance[i].getAmount();
    }

    for (int i = 0; i < expensesToBalance.size(); i++)
    {
        sumOfExpenses += expensesToBalance[i].getAmount();
    }
    cout<<fixed<<setprecision(2);
    cout<< "Total incomes: " << sumOfIncomes << " zl." <<endl;
    cout<< "Total expenses: " << sumOfExpenses << " zl." <<endl;

    double differenceBetweendIncomesAndExpenses = sumOfIncomes - sumOfExpenses;

    cout<<fixed<<setprecision(2);
    cout<< "Difference: " << differenceBetweendIncomesAndExpenses << " zl." <<endl <<endl;
    system("pause");
}

void PersonalBudget::showBalanceFromPreviousMonth()
{
    string currentDate=dateOperations.getCurrentDay();
    vector <Income> incomesToSort;
    vector <Expense> expensesToSort;

    int currentMonth=dateOperations.getMonthFromDate(currentDate);
    int currentYear=dateOperations.getYearFromDate(currentDate);
    int previousMonth=0;
    int previousYear=0;

    if(currentMonth==1)
    {
        previousMonth=12;
        previousYear=currentYear-1;
    }
    else
    {
        previousMonth=currentMonth-1;
        previousYear=currentYear;
    }

        for (int i = 0; i < incomeManager->incomes.size(); i++)
        {
            if (previousMonth==dateOperations.getMonthFromDate(incomeManager->incomes[i].getDate())
                    && previousYear==dateOperations.getYearFromDate(incomeManager->incomes[i].getDate()))
            {
                incomesToSort.push_back(incomeManager->incomes[i]);
            }
        }

    incomeManager->sortIncomesByDateInAscendingOrder(incomesToSort);


        for (int i = 0; i < expenseManager->expenses.size(); i++)
        {
            if (previousMonth==dateOperations.getMonthFromDate(expenseManager->expenses[i].getDate())
                    && previousYear==dateOperations.getYearFromDate(expenseManager->expenses[i].getDate()))
            {
                expensesToSort.push_back(expenseManager->expenses[i]);
            }
        }

    expenseManager->sortExpensesByDateInAscendingOrder(expensesToSort);

    system("cls");
    cout<< "Balance from previous month:" <<endl<<endl;

    showBalance(incomesToSort, expensesToSort);
}
void PersonalBudget::showBalanceFromSelectedPeriod()
{

    vector <Income> incomesToSort;
    vector <Expense> expensesToSort;
    string startDate="";
    string endDate="";

    cout<<"What period do you want to see the balance sheet?"<<endl;
    cout<<"Enter start date(enter date in format yyyy-mm-dd): ";
    cin>>startDate;

    while(dateOperations.checkIfTheDateIsCorrect(startDate)==false)
        {
            cout<<"Incorrect date! Enter a date between 2000-01-01 and the last day of the month of the current year."<<endl;
            cout<<"Enter date in format yyyy-mm-dd: ";
            cin>>startDate;
        }

    cout<<"Enter end date(enter date in format yyyy-mm-dd): ";
    cin>>endDate;

    while(dateOperations.checkIfTheDateIsCorrect(endDate)==false)
        {
            cout<<"Incorrect date! Enter a date between 2000-01-01 and the last day of the month of the current year."<<endl;
            cout<<"Enter date in format yyyy-mm-dd: ";
            cin>>endDate;
        }

    int startDateInteger=dateOperations.convertDateFromStringToInt(startDate);
    int endDateInteger=dateOperations.convertDateFromStringToInt(endDate);


        for (int i = 0; i < incomeManager->incomes.size(); i++)
        {
            int day = dateOperations.getDayFromDate(expenseManager->expenses[i].getDate());
            int month = dateOperations.getMonthFromDate(expenseManager->expenses[i].getDate());
            int year = dateOperations.getYearFromDate(expenseManager->expenses[i].getDate());

            string dayFromVector="";

            dayFromVector=dateOperations.getDateText(day, month, year);

            int dateFromVector = dateOperations.convertDateFromStringToInt(dayFromVector);


            if (startDateInteger <= dateFromVector && endDateInteger >= dateFromVector)
            {
                incomesToSort.push_back(incomeManager->incomes[i]);
            }
        }


    incomeManager->sortIncomesByDateInAscendingOrder(incomesToSort);


        for (int i = 0; i < expenseManager->expenses.size(); i++)
        {
            int day = dateOperations.getDayFromDate(expenseManager->expenses[i].getDate());
            int month = dateOperations.getMonthFromDate(expenseManager->expenses[i].getDate());
            int year = dateOperations.getYearFromDate(expenseManager->expenses[i].getDate());

            string dayFromVector="";

            dayFromVector=dateOperations.getDateText(day, month, year);

            int dateFromVector = dateOperations.convertDateFromStringToInt(dayFromVector);

            if (startDateInteger <= dateFromVector && endDateInteger >= dateFromVector)
            {
                expensesToSort.push_back(expenseManager->expenses[i]);
            }
        }


    expenseManager->sortExpensesByDateInAscendingOrder(expensesToSort);

    system("cls");
    cout << "Balance from: " << startDate <<" - " << endDate << endl << endl;

    showBalance(incomesToSort, expensesToSort);
}

