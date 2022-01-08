#ifndef USERSXMLFILE_H
#define USERXMLFILE_H

#include <iostream>
#include <vector>
#include <sstream>


#include "User.h"
#include "Markup.h"
#include "XMLFile.h"

using namespace std;

class UsersXMLFile : public XMLFile
{


public:
    UsersXMLFile(string nameOfUsersFile):XMLFile(nameOfUsersFile){
    };

    void saveUserToXMLFile(User user);
    vector <User> loadUsersFromXMLFile();
    string convertIntToString(int number);
    void saveNewPasswordToFile(string newPassword, int idCurrentUser);


};
#endif // USERSXMLFILE_H
