#include "Expense.h"

int Expense::getExpenseId()
{
    return expenseId;
}
int Expense::getUserId()
{
    return userId;
}

int Expense::getDay()
{
    return day;
}
int Expense::getMonth()
{
    return month;
}
int Expense::getYear()
{
    return year;
}

string Expense::getDate()
{
    return date;
}
string Expense::getItem()
{
    return item;
}
double Expense::getAmount()
{
    return amount;
}

void Expense::setExpenseId(int newExpenseId)
{
    expenseId=newExpenseId;
}
void Expense::setUserId(int newUserId)
{
    userId=newUserId;
}
void Expense::setDay(int newDay)
{
    day=newDay;
}
void Expense::setMonth(int newMonth)
{
    month=newMonth;
}
void Expense::setYear(int newYear)
{
    year=newYear;
}
void Expense::setDate(string newDate)
{
    date=newDate;
}

void Expense::setItem(string newItem)
{
    item=newItem;
}
void Expense::setAmount(double newAmount)
{
    amount=newAmount;
}

