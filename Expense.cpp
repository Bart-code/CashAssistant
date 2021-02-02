#include "Expense.h"

using namespace std;

void Expense::setDate( int newDate)
{
    date = newDate;
}

void Expense::setAmount( float newAmount)
{
    amount = newAmount;
}

void Expense::setItem( string newItem )
{
    item = newItem;
}

int Expense::getDate( void )
{
    return date;
}

float Expense::getAmount( void )
{
    return amount;
}

string Expense::getItem( void )
{
    return item;
}
