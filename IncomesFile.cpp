#include "IncomesFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

IncomesFile::IncomesFile()
{
    incomesFile = initFile("incomesFile");
}

void IncomesFile::addIncomeToFile( Income * income, int userId )
{
    incomesFile.ResetPos();
    incomesFile.FindElem();
    incomesFile.IntoElem();
    incomesFile.AddElem( "Income" );
    incomesFile.FindElem();
    incomesFile.IntoElem();
    incomesFile.AddElem( "UserId" , userId );
    incomesFile.AddElem( "Date" , AuxiliaryMethods::convertIntegerToString( income -> getDate() ) );
    incomesFile.AddElem( "Item" , income -> getItem() );
    incomesFile.AddElem( "Amount" , AuxiliaryMethods::convertIntegerToString( income -> getAmount() ));
    incomesFile.Save( "incomesFile.xml" );
}
