#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    string date;
    string item;
    double amount;
    int day;
    int month;
    int year;



public:
    Income(int incomeId=0, int userId=0, int day=0, int month=0, int year=0, string date="", string item="", double amount=0)
    {
        this->incomeId=incomeId;
        this->userId=userId;
        this->day=day;
        this->month=month;
        this->year=year;
        this->date=date;
        this->item=item;
        this->amount=amount;
    }
    int getIncomeId();
    int getUserId();
    int getDay();
    int getMonth();
    int getYear();
    string getDate();
    string getItem();
    double getAmount();

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
};
#endif // INCOME_H
