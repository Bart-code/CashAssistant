#include "IncomesManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

IncomesManager::IncomesManager( void )
{

}

void IncomesManager::addIncome( int userId)
{
    Income newIncome;
    string date, item, amount;
    cout << "Enter date of income: ";
    cin >> date;
    cout << "Enter describe of income: ";
    cin >> item;
    cout << "Enter income amount: ";
    cin >> amount;
    newIncome.setDate( AuxiliaryMethods::convertStringToInteger( date ) );
    newIncome.setItem( item );
    newIncome.setAmount( AuxiliaryMethods::convertStringToInteger( amount ) );
    incomes.push_back( newIncome );
    incomesFile.addIncomeToFile( &newIncome, userId );

}
