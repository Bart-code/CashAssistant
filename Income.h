#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
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
