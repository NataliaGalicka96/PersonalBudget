#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    int expenseId;
    int userId;
    string date;
    string item;
    double amount;
    int day;
    int month;
    int year;


public:
    Expense(int expenseId=0, int userId=0, int day=0, int month=0, int year=0, string date="", string item="", double amount=0)
    {
        this->expenseId=expenseId;
        this->userId=userId;
        this->day=day;
        this->month=month;
        this->year=year;
        this->date=date;
        this->item=item;
        this->amount=amount;
    }

    int getExpenseId();
    int getUserId();
    int getDay();
    int getMonth();
    int getYear();
    string getDate();
    string getItem();
    double getAmount();

    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
};
#endif // EXPENSE_H
