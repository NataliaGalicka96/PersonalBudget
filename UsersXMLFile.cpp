#include "UsersXMLFile.h"

void UsersXMLFile::saveUserToXMLFile(User user)
{
    CMarkup xmlSaveToFile;

    bool fileExists = xmlSaveToFile.Load(XMLFile::downloadXMLFileName());

    if (!fileExists)
    {
        xmlSaveToFile.AddElem("Users");
    }

    xmlSaveToFile.FindElem();
    xmlSaveToFile.IntoElem();
    xmlSaveToFile.AddElem("User");
    xmlSaveToFile.IntoElem();
    xmlSaveToFile.AddElem("UserId", AuxiliaryMethods::convertIntToString(user.getId()));
    xmlSaveToFile.AddElem("UserName", user.getName());
    xmlSaveToFile.AddElem("UserSurname", user.getSurname());
    xmlSaveToFile.AddElem("UserLogin", user.getLogin());
    xmlSaveToFile.AddElem("UserPassword", user.getPassword());

    xmlSaveToFile.Save(XMLFile::downloadXMLFileName());

    cout<<endl;
}

vector <User> UsersXMLFile::loadUsersFromXMLFile()
{
    vector <User> users;
    User user;
    CMarkup xml;

    bool fileExist = xml.Load(XMLFile::downloadXMLFileName());
    if (!fileExist)
    {
        cout<<"XML file is empty!"<<endl;
    }

    xml.FindElem("Users");
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();

        xml.FindElem("UserId");
        user.setId(atoi(xml.GetData().c_str()));

        xml.FindElem("UserName");
        user.setName(xml.GetData());

        xml.FindElem("UserSurname");
        user.setSurname(xml.GetData());

        xml.FindElem("UserLogin");
        user.setLogin(xml.GetData());

        xml.FindElem("UserPassword");
        user.setPassword(xml.GetData());

        xml.OutOfElem();

        users.push_back(user);

    }

    return users;

}

void UsersXMLFile::saveNewPasswordToFile(string newPassword, int idCurrentUser)
{
    CMarkup xml;

    bool fileExists = xml.Load(XMLFile::downloadXMLFileName());

    if (!fileExists)
    {
        cout << "XML file is empty!" << endl;
    }

    xml.FindElem("Users");
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        if (atoi(xml.GetData().c_str()) == idCurrentUser)
        {
            xml.FindElem("UserPassword");
            xml.RemoveElem();
            xml.AddElem("UserPassword", newPassword);
            break;
        }
        xml.OutOfElem();
    }
    xml.Save(XMLFile::downloadXMLFileName());
}

