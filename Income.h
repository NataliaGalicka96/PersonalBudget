#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    int day;
    int month;
    int year;
    string dateText;
    string item;
    float amount;

public:
    Income(int incomeId=0, int userId=0, int day=0, int month=0, int year=0, string dateText="", string item="", float amount=0)
    {
        this->incomeId=incomeId;
        this->userId=userId;
        this->day=day;
        this->month=month;
        this->year=year;
        this->dateText=dateText;
        this->item=item;
        this->amount=amount;
    }
    int getIncomeId();
    int getUserId();
    int getDay();
    int getMonth();
    int getYear();
    string getDateText();
    string getItem();
    float getAmount();

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    void setDateText(string newDateText);
    void setItem(string newItem);
    void setAmount(float newAmount);
};
#endif // INCOME_H
