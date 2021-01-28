#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
        int date, amount;
        string item;

public:
    Income()
    : date( 0 ),
    amount( 0 ),
    item( "Nic" )
    {

    }
    void setDate( int );
    void setAmount( int);
    void setItem( string );
    int getDate( void );
    int getAmount( void );
    string getItem( void );

};


#endif
