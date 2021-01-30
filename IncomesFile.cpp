#include "IncomesFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

IncomesFile::IncomesFile()
{
    incomesFile = initFile("incomesFile");
}

void IncomesFile::addIncomeToFile( Income income, int userId )
{
    string dateString = AuxiliaryMethods::getStringDateFromInteger( income.getDate() );
    incomesFile.ResetPos();
    incomesFile.FindElem();
    incomesFile.IntoElem();
    incomesFile.AddElem( "Income" );
    incomesFile.FindElem();
    incomesFile.IntoElem();
    incomesFile.AddElem( "UserId" , AuxiliaryMethods::convertIntegerToString( userId ) );
    incomesFile.AddElem( "Date" , dateString );
    incomesFile.AddElem( "Item" , income.getItem() );
    incomesFile.AddElem( "Amount" , AuxiliaryMethods::convertIntegerToString( income.getAmount() ));
    incomesFile.Save( "incomesFile.xml" );
}

void IncomesFile::loadIncomesFromFile(  vector <Income> * incomesVector , int loggedUserId )
{
    Income currentIncome;
    string userId, dateString, amountString;
    int dateInteger = 0;
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
            dateInteger = AuxiliaryMethods::getIntegerDateFromString( dateString );
            currentIncome.setDate( dateInteger );
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
