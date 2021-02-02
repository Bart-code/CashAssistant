#include "Income.h"

using namespace std;

void Income::setDate( int newDate)
{
    date= newDate;
}

void Income::setAmount( float newAmount)
{
    amount = newAmount;
}

void Income::setItem( string newItem )
{
    item = newItem;
}

int Income::getDate( void )
{
    return date;
}

float Income::getAmount( void )
{
    return amount;
}

string Income::getItem( void )
{
    return item;
}

