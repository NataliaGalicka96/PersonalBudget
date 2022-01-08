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
string Income::getDateText()
{
    return dateText;
}
string Income::getItem()
{
    return item;
}
float Income::getAmount()
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
void Income::setDateText(string newDateText)
{
    dateText=newDateText;
}
void Income::setItem(string newItem)
{
    item=newItem;
}
void Income::setAmount(float newAmount)
{
    amount=newAmount;
}
