#include "ExpensesFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

ExpensesFile::ExpensesFile()
{
    expensesFile = initFile("expensesFile");
}

void ExpensesFile::addExpenseToFile( Expense expense, int userId )
{
    string dateString = AuxiliaryMethods::getStringDateFromInteger( expense.getDate() );
    expensesFile.ResetPos();
    expensesFile.FindElem();
    expensesFile.IntoElem();
    expensesFile.AddElem( "Expense" );
    expensesFile.FindElem();
    expensesFile.IntoElem();
    expensesFile.AddElem( "UserId" , AuxiliaryMethods::convertIntegerToString( userId ) );
    expensesFile.AddElem( "Date" , dateString );
    expensesFile.AddElem( "Item" , expense.getItem() );
    expensesFile.AddElem( "Amount" , AuxiliaryMethods::convertFloatToString( expense.getAmount() ));
    expensesFile.Save( "expensesFile.xml" );
}

void ExpensesFile::loadExpensesFromFile(  vector <Expense> * expensesVector , int loggedUserId )
{
    Expense currentExpense;
    string userId, dateString, amountString;
    int dateInteger = 0;
    expensesFile.ResetPos();
    expensesFile.FindElem();
    expensesFile.IntoElem();
    while ( expensesFile.FindElem("Expense") )
    {
        expensesFile.IntoElem();
        expensesFile.FindElem("UserId");
        userId = expensesFile.GetData();
        if( AuxiliaryMethods::convertStringToInteger( userId) == loggedUserId )
        {
            expensesFile.FindElem("Date");
            dateString = expensesFile.GetData();
            dateInteger = AuxiliaryMethods::getIntegerDateFromString( dateString );
            currentExpense.setDate( dateInteger );
            expensesFile.FindElem("Item");
            currentExpense.setItem( expensesFile.GetData() );
            expensesFile.FindElem("Amount");
            amountString = expensesFile.GetData();
            currentExpense.setAmount( AuxiliaryMethods::convertStringToFloat( amountString ) );
            expensesVector -> push_back( currentExpense );
        }
        expensesFile.OutOfElem();
    }
}

