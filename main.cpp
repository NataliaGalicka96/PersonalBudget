#include <iostream>

#include "PersonalBudget.h"


using namespace std;

int main()
{

    PersonalBudget personalBudget("Users.xml","Incomes.xml", "Expenses.xml");

    char choice;

    while(true)
    {
        if(personalBudget.downloadIdOfLoggedInUser()==0)
        {

            choice=personalBudget.selectOptionFromMainMenu();
            switch(choice)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout<<endl<<"There is no such option on the menu!"<<endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice=personalBudget.selectOptionFromUserMenu();

            switch(choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showIncomeOfCurrentUser();
                break;
            case '4':
                personalBudget.showExpenseOfCurrentUser();
                break;
            case '5':
                break;
            case '6':
                personalBudget.changePasswordOfLoggedInUser();
                break;
            case '7':
                personalBudget.userLogout();
                break;

            }

        }

    }
    return 0;
}






