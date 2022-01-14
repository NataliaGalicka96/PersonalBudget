#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = enterDataOfNewUser();

    users.push_back(user);

    usersXMLFile.saveUserToXMLFile(user);

    cout<<endl<<"An account has been created!"<<endl<<endl;

    Sleep(2000);
}

User UserManager::enterDataOfNewUser()
{
    User user;

    user.setId(downloadIdOfNewUser());

    string name, surname, login, password;
    system("cls");

    cout<<" >>>>  USER REGISTRATION  <<<< "<<endl<<endl;
    cout<<"Enter your name: ";
    cin>>name;
    user.setName(name);
    cout<<"Enter your surname: ";
    cin>>surname;
    user.setSurname(surname);

    do
    {
        cout<<"Enter your login: ";
        cin>>login;
        user.setLogin(login);
    }
    while(loginExists(user.getLogin())==true);

    cout<<"Enter your password: ";
    cin>>password;
    user.setPassword(password);

    return user;
}

int UserManager::downloadIdOfNewUser()
{
    if(users.empty()==true)
        return 1;
    else
        return users.back().getId()+1;
}

bool UserManager::loginExists(string login)
{
    for(int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin()==login)
        {
            cout<<"There is a login with this name. Please enter a different login! "<<endl;
            return true;
        }
    }
    return false;
}

int UserManager::userLogging()
{
    User user;
    string login="", password="";

    system("cls");

    cout<<">>>> USER LOGGING <<<<"<<endl;

    cout<<endl<<"Enter your login: ";
    cin>>login;

    vector<User>::iterator itr=users.begin();

    while(itr!=users.end())
    {
        if(itr->getLogin()==login)
        {
            for(int amountOfTrial=3; amountOfTrial>0; amountOfTrial--)
            {
                cout<<"Enter your password. You have "<<amountOfTrial<<" more tries. ";
                cin>>password;

                if(itr->getPassword()==password)
                {
                    idCurrentUser=itr->getId();
                    cout<<endl<<"You have successfully logged in to your account!"<<endl<<endl;
                    Sleep(2000);
                    return idCurrentUser;
                }
            }
            cout<<"Incorrect password. Try later!"<<endl;
            Sleep(3000);
            return 0;

        }
        itr++;
    }
    cout<<"There is no user with this login!"<<endl;
    system("pause");
    return 0;
}

void UserManager::changePasswordOfLoggedInUser()
{
    system("cls");
    string newPassword;
    cout<<"Enter new password: ";
    cin>>newPassword;

    for (vector<User>::iterator itr=users.begin(); itr!=users.end(); itr++)
    {
        if (itr->getId()==idCurrentUser)
        {
            itr->setPassword(newPassword);
            usersXMLFile.saveNewPasswordToFile(newPassword,idCurrentUser);

            cout<<"Password has been changed!"<<endl<<endl;
            system("pause");
        }
    }
}


char UserManager::selectOptionFromMainMenu()
{
    char choice;
    system("cls");
    cout<<" >>>> MAIN MENU <<<< "<<endl;
    cout<<"----------------------"<<endl;
    cout<<"1. User registration"<<endl;
    cout<<"2. User logging"<<endl;
    cout<<"9. Exit"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"Your choice: ";
    cin>>choice;

    return choice;
}
char UserManager::selectOptionFromUserMenu()
{
    char choice;
    system("cls");
    cout<<" >>>> USER MENU <<<< "<<endl;
    cout<<"----------------------"<<endl;
    cout<<"1. Add income. "<<endl;
    cout<<"2. Add expense. "<<endl;
    cout<<"3. Show balance from current month. "<<endl;
    cout<<"4. Show balance from previous month. "<<endl;
    cout<<"5. Show balance from selected period. "<<endl;
    cout<<"----------------------"<<endl;
    cout<<"6. Change password. "<<endl;
    cout<<"7. Sign out. "<<endl;
    cout<<"----------------------"<<endl;
    cout<<"Your choice: ";
    cin>>choice;

    return choice;

}
int UserManager::downloadIdOfLoggedInUser()
{
    return idCurrentUser;
}

int UserManager::userLogout()
{
    idCurrentUser=0;
}

bool UserManager::checkUserLoggedIn()
{
    if(idCurrentUser>0)
        return true;
    else
        return false;
}
