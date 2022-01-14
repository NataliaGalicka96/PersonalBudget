#ifndef USERMANAGER_H
#define USERMANAGAER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UsersXMLFile.h"

using namespace std;

class UserManager
{
    int idCurrentUser;
    vector <User> users;
    UsersXMLFile usersXMLFile;

    User enterDataOfNewUser();
    int downloadIdOfNewUser();
    bool loginExists(string login);

public:

UserManager(string nameOfUsersFile):usersXMLFile(nameOfUsersFile)
{
    idCurrentUser=0;
    users=usersXMLFile.loadUsersFromXMLFile();
}
    void userRegistration();
    int userLogging();
    void changePasswordOfLoggedInUser();
    int downloadIdOfLoggedInUser();
    int userLogout();

    char selectOptionFromUserMenu();
    char selectOptionFromMainMenu();

    bool checkUserLoggedIn();


};
#endif // USERMANAGER_H
