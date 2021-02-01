#include "ExpensesManager.h"

using namespace std;

ExpensesManager::ExpensesManager( int userId)
{
    expensesFile.loadExpensesFromFile( &expenses , userId );
}

void ExpensesManager::addExpense( int userId)
{
    Expense newExpense;
    string item, dateString;
    char userChoiceOption;
    int dateInteger, amount;

    dateString = AuxiliaryMethods::enterDate();
    if( dateString == "" ) return;
    cout << "Enter describe of Expense: ";
    cin >> item;
    cout << "Enter Expense amount: ";
    cin >> amount;
    dateInteger = AuxiliaryMethods::getIntegerDateFromString( dateString );
    newExpense.setDate( dateInteger );
    newExpense.setItem( item );
    newExpense.setAmount( amount );

    expenses.push_back( newExpense );
    expensesFile.addExpenseToFile( newExpense, userId );
}


void ExpensesManager::showAllExpenses( void )
{
   vector<Expense>::iterator itr = expenses.begin();
   vector<Expense>::iterator endItr = expenses.end();
   string dateString = "";

   for( itr ; itr != endItr ; itr++ )
   {
       dateString = AuxiliaryMethods::getStringDateFromInteger( (*itr).getDate() );
       cout << endl << "Date: " << dateString << endl;
       cout << "Item: " << (*itr).getItem() << endl;
       cout << "Amount: " << (*itr).getAmount() << endl << endl;
   }

   system("pause");
}
