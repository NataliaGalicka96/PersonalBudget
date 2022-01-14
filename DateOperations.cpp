#include "DateOperations.h"

string DateOperations::getCurrentDay()
{
    // current date/time based on current system
    time_t now = time(0);

    tm *ltm = localtime(&now);
    //char* dt = ctime(&now1);

    int year=1900+ltm->tm_year;
    int month=1+ltm->tm_mon;
    int day=ltm->tm_mday;

    string currentDay="";

    currentDay=getDateText(day, month, year);

    return currentDay;
}

string DateOperations::getDateText(int day, int month, int year)
{
    string dateString="";

    string yearString=AuxiliaryMethods::convertIntToString(year);
    string monthString=AuxiliaryMethods::convertIntToString(month);
    string dayString=AuxiliaryMethods::convertIntToString(day);

    if((month<10)&&(day>9))
        dateString=yearString+"-"+"0"+monthString+"-"+dayString;
    if((month>9)&&(day<10))
        dateString=yearString+"-"+monthString+"-"+"0"+dayString;
    if((month<10)&&(day<10))
        dateString=yearString+"-"+"0"+monthString+"-"+"0"+dayString;
    if ((month>10)&&(day>10))
        dateString=yearString+"-"+monthString+"-"+dayString;

    return dateString;

}

bool DateOperations::checkIfTheDateIsCorrect(string dateText)
{
    string currentDateText = getCurrentDay();

    int currentYear=getYearFromDate(currentDateText);
    int currentMonth=getMonthFromDate(currentDateText);
    int currentDay=getDayFromDate(currentDateText);

    int dateYear=getYearFromDate(dateText);
    int dateMonth = getMonthFromDate(dateText);
    int dateDay=getDayFromDate(dateText);

        if((dateYear==currentYear) && (dateMonth>=1 && dateMonth<=currentMonth)&&(dateDay>=1&&dateDay<=returnNumberOfDaysInMonth(currentMonth,currentYear)))
        {
            return true;
        }
        else if((dateYear<currentYear)&&(dateYear>=2000)&&(dateMonth>=1)&&(dateMonth<=12) && (dateDay>=1 && dateDay<=returnNumberOfDaysInMonth(dateMonth,dateYear)))
        {
            return true;
        }
        else
        return false;

}

int DateOperations::returnNumberOfDaysInMonth(int month, int year)
{
    if (!month)
    {
        cerr<<"It's not a digit!";
        exit(0);
    }
    int numberOfDays;

    switch(month)

    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        numberOfDays=31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        numberOfDays=30;
        break;

    case 2:
    {

        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
            numberOfDays=29;
        else numberOfDays=28;
    }
    break;


    }
    return numberOfDays;
}


int DateOperations::getYearFromDate(string date)
{
    string stringYear;
    string stringMonth;
    string stringDay;
    int year;
    int month;
    int day;
    string dateWithoutDash="";


    for (int i=0; i<=date.length(); i++)
    {

        if((date[i]!='-')&&(i!=10))
        {
            dateWithoutDash+=date[i];
        }
    }

    stringYear=dateWithoutDash.substr(0,4);
    stringMonth=dateWithoutDash.substr(4,2);
    stringDay=dateWithoutDash.substr(7,2);

    year=AuxiliaryMethods::convertStringToInt(stringYear);
    month=AuxiliaryMethods::convertStringToInt(stringMonth);
    day=AuxiliaryMethods::convertStringToInt(stringDay);

    return year;
}
int DateOperations::getMonthFromDate(string date)
{
    string stringYear;
    string stringMonth;
    string stringDay;
    int year;
    int month;
    int day;
    string dateWithoutDash="";


    for (int i=0; i<=date.length(); i++)
    {

        if((date[i]!='-')&&(i!=10))
        {
            dateWithoutDash+=date[i];
        }
    }

    stringYear=dateWithoutDash.substr(0,4);
    stringMonth=dateWithoutDash.substr(4,2);
    stringDay=dateWithoutDash.substr(7,2);


    year=AuxiliaryMethods::convertStringToInt(stringYear);
    month=AuxiliaryMethods::convertStringToInt(stringMonth);
    day=AuxiliaryMethods::convertStringToInt(stringDay);

    return month;
}
int DateOperations::getDayFromDate(string date)
{
    string stringYear;
    string stringMonth;
    string stringDay;
    int year;
    int month;
    int day;
    string dateWithoutDash="";


    for (int i=0; i<=date.length(); i++)
    {

        if((date[i]!='-')&&(i!=10))
        {
            dateWithoutDash+=date[i];
        }
    }

    stringYear=dateWithoutDash.substr(0,4);
    stringMonth=dateWithoutDash.substr(4,2);
    stringDay=dateWithoutDash.substr(6,2);

    year=AuxiliaryMethods::convertStringToInt(stringYear);
    month=AuxiliaryMethods::convertStringToInt(stringMonth);
    day=AuxiliaryMethods::convertStringToInt(stringDay);

    return day;
}

int DateOperations::convertDateFromStringToInt(string dateText)
{
    int dateWithoutDashInt=0;
    string dateWithoutDash="";


    for (int i=0; i<=dateText.length(); i++)
    {
        if((dateText[i]!='-')&&(i!=10))
        {
            dateWithoutDash+=dateText[i];
        }
    }

    dateWithoutDashInt=AuxiliaryMethods::convertStringToInt(dateWithoutDash);

    return dateWithoutDashInt;
}
