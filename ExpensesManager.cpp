#include "ExpensesManager.h"

using namespace std;

ExpensesManager::ExpensesManager( int userId)
{
    expensesFile.loadExpensesFromFile( &expenses , userId );
}

void ExpensesManager::addExpense( int userId)
{
    Expense newExpense;
    string item, dateString, amount;
    int dateInteger;

    dateString = AuxiliaryMethods::enterDate();
    if( dateString == "" ) return;
    cout << "Enter describe of Expense: ";
    cin.ignore( 1000, '\n' );
    item = AuxiliaryMethods::loadLine();
    cout << "Enter Expense amount: ";
    cin >> amount;
    dateInteger = AuxiliaryMethods::getIntegerDateFromString( dateString );
    newExpense.setDate( dateInteger );
    newExpense.setItem( item );
    amount = AuxiliaryMethods::changeCommaToDot( amount );
    newExpense.setAmount( AuxiliaryMethods::convertStringToFloat( amount ) );

    expenses.push_back( newExpense );
    expensesFile.addExpenseToFile( newExpense, userId );

    cout << "Expense added !" << endl;
    Sleep(1000);
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

void ExpensesManager::showChosenExpenses( vector<Expense> * vectorToShow )
{
   vector<Expense>::iterator itr = vectorToShow -> begin();
   vector<Expense>::iterator endItr = vectorToShow -> end();
   string dateString = "";

   for( itr ; itr != endItr ; itr++ )
   {
       dateString = AuxiliaryMethods::getStringDateFromInteger( (*itr).getDate() );
       cout << endl << "Date: " << dateString << endl;
       cout << "Item: " << (*itr).getItem() << endl;
       cout << "Amount: " << (*itr).getAmount() << " zl" << endl << endl;
   }
}

vector <Expense> ExpensesManager::selectExpensesBetweenBateBorders( int downBorder, int topBorder)
{
    vector <Expense> selectedExpenses;
    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if( itr -> getDate() >= downBorder && itr -> getDate() <= topBorder )
            selectedExpenses.push_back( *itr );
    }
    return selectedExpenses;
}

vector <Expense> ExpensesManager::sortExpensesVector( vector <Expense> vectorToSort)
{
    Expense temp;
    for (vector <Expense>::iterator itr1 = vectorToSort.begin(); itr1 != vectorToSort.end(); itr1++)
    {
        for (vector <Expense>::iterator itr2 = vectorToSort.begin(); itr2 != (vectorToSort.end() - 1); itr2++)
        {
            if( itr2 -> getDate() > (itr2 + 1) -> getDate() )
            {
                temp = *(itr2 + 1);
                *(itr2 + 1) = *itr2;
                *itr2 = temp;
            }
        }
    }
    return vectorToSort;
}

void ExpensesManager::showSortedExpensesBetweenDateBorders( int downBorder, int topBorder )
{

    vector <Expense> selectedExpenses = selectExpensesBetweenBateBorders(downBorder, topBorder);
    vector <Expense> newVect = sortExpensesVector( selectedExpenses );
    showChosenExpenses( &newVect );
}

float ExpensesManager::sumExpensesAmountsBetweenDateBorders( int downBorder, int topBorder )
{
    vector <Expense> selectedExpenses = selectExpensesBetweenBateBorders(downBorder, topBorder);
    float sumaryAmounts = 0;
    for (vector <Expense>::iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++)
    {
        sumaryAmounts += itr -> getAmount();
    }
    return sumaryAmounts;
}
