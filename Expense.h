#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    int date;
    float amount;
    string item;

public:

    void setDate( int );
    void setAmount( float);
    void setItem( string );
    int getDate( void );
    float getAmount( void );
    string getItem( void );

};

#endif
