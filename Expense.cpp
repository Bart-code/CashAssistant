#include "Expense.h"

using namespace std;

void Expense::setDate( int newDate)
{
    date = newDate;
}

void Expense::setAmount( int newAmount)
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

int Expense::getAmount( int )
{
    return amount;
}

string Expense::getItem( void )
{
    return item;
}
