#include "AuxiliaryMethods.h"

string AuxiliaryMethods::changeCommaToDot(string amount)
{
    string przecinek=",";
    size_t pozycja=amount.find(przecinek);
    if(pozycja!=string::npos)
        amount.replace(pozycja,1,".");

    return amount;
}

int AuxiliaryMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertDoubleToString (double number)
{
    ostringstream os;
    os << number;
    string stringOut = os.str();
    return stringOut;
}
