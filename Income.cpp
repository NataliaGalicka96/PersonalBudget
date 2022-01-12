#include "Income.h"

int Income::getIncomeId()
{
    return incomeId;
}
int Income::getUserId()
{
    return userId;
}

int Income::getDay()
{
    return day;
}
int Income::getMonth()
{
    return month;
}
int Income::getYear()
{
    return year;
}

string Income::getDate()
{
    return date;
}
string Income::getItem()
{
    return item;
}
double Income::getAmount()
{
    return amount;
}

void Income::setIncomeId(int newIncomeId)
{
    incomeId=newIncomeId;
}
void Income::setUserId(int newUserId)
{
    userId=newUserId;
}

void Income::setDay(int newDay)
{
    day=newDay;
}
void Income::setMonth(int newMonth)
{
    month=newMonth;
}
void Income::setYear(int newYear)
{
    year=newYear;
}
void Income::setDate(string newDate)
{
    date=newDate;
}

void Income::setItem(string newItem)
{
    item=newItem;
}
void Income::setAmount(double newAmount)
{
    amount=newAmount;
}
