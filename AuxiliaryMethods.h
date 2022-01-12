#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static string changeCommaToDot(string amount);
    static string convertDoubleToString (double number);
};
#endif // AUXILIARYMETHODS_H
