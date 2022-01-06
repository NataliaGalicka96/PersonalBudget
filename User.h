#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string name;
    string surname;
    string login;
    string password;

public:
    User(int id=0, string name="", string surname="", string login="", string password="")
    {
        this->id=id;
        this->name=name;
        this->surname=surname;
        this->login=login;
        this->password=password;
    }

    void setId(int newId);
    void setName(string newName);
    void setSurname(string newSurname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();
};
#endif // USER_H
