#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

#include <iostream>
#include <ctime>
#include "AuxiliaryMethods.h"

using namespace std;

class DateOperations
{

public:


    string getCurrentDay();
    bool checkIfTheDateIsCorrect(string dateText);
    int getDayFromDate(string date);
    int getMonthFromDate(string date);
    int getYearFromDate(string date);
    int returnNumberOfDaysInMonth(int month, int year);
};
#endif // DATEOPERATIONS_H
