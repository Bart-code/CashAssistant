#include "IncomesManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

IncomesManager::IncomesManager( int userId)
{
    incomesFile.loadIncomesFromFile( &incomes , userId );
}

void IncomesManager::addIncome( int userId)
{
    Income newIncome;
    string item;
    int date, amount;
    cout << "Enter date of income: ";
    cin >> date;
    cout << "Enter describe of income: ";
    cin >> item;
    cout << "Enter income amount: ";
    cin >> amount;
    newIncome.setDate( date );
    newIncome.setItem( item );
    newIncome.setAmount( amount );

    incomes.push_back( newIncome );
    incomesFile.addIncomeToFile( newIncome, userId );
}

void IncomesManager::showAllIncomes( void )
{
   vector<Income>::iterator itr = incomes.begin();
   vector<Income>::iterator endItr = incomes.end();

   for( itr ; itr != endItr ; itr++ )
   {
       cout << endl << "Date: " << (*itr).getDate() << endl;
       cout << "Item" << (*itr).getItem() << endl;
       cout << "Amount" << (*itr).getAmount() << endl << endl;
   }

   system("pause");
}

