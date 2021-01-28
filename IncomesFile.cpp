#include "IncomesFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

IncomesFile::IncomesFile()
{
    incomesFile = initFile("incomesFile");
}

void IncomesFile::addIncomeToFile( Income income, int userId )
{
    incomesFile.ResetPos();
    incomesFile.FindElem();
    incomesFile.IntoElem();
    incomesFile.AddElem( "Income" );
    incomesFile.FindElem();
    incomesFile.IntoElem();
    incomesFile.AddElem( "UserId" , AuxiliaryMethods::convertIntegerToString( userId ) );
    incomesFile.AddElem( "Date" , AuxiliaryMethods::convertIntegerToString( income.getDate() ) );
    incomesFile.AddElem( "Item" , income.getItem() );
    incomesFile.AddElem( "Amount" , AuxiliaryMethods::convertIntegerToString( income.getAmount() ));
    incomesFile.Save( "incomesFile.xml" );
}

void IncomesFile::loadIncomesFromFile(  vector <Income> * incomesVector , int loggedUserId )
{
    Income currentIncome;
    string userId, dateString, amountString;
    incomesFile.ResetPos();
    incomesFile.FindElem();
    incomesFile.IntoElem();
    while ( incomesFile.FindElem("Income") )
    {
        incomesFile.IntoElem();
        incomesFile.FindElem("UserId");
        userId = incomesFile.GetData();
        if( AuxiliaryMethods::convertStringToInteger( userId) == loggedUserId )
        {
            incomesFile.FindElem("Date");
            dateString = incomesFile.GetData();
            currentIncome.setDate( AuxiliaryMethods::convertStringToInteger( dateString) );
            incomesFile.FindElem("Item");
            currentIncome.setItem( incomesFile.GetData() );
            incomesFile.FindElem("Amount");
            amountString = incomesFile.GetData();
            currentIncome.setAmount( AuxiliaryMethods::convertStringToInteger( amountString ) );
            incomesVector -> push_back( currentIncome );
        }
        incomesFile.OutOfElem();
    }
}
