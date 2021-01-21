#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    int date, amount;
    string item;

public:

    void setDate( int );
    void setAmount( int);
    void setItem( string );
    int getDate( void );
    int getAmount( int );
    string getItem( void );

};

#endif
