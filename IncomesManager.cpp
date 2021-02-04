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
    string item, dateString, amount;
    int dateInteger;

    dateString = AuxiliaryMethods::enterDate();
    if( dateString == "" ) return;
    cout << "Enter describe of income: ";
    cin >> item;
    cout << "Enter income amount: ";
    cin >> amount;
    dateInteger = AuxiliaryMethods::getIntegerDateFromString( dateString );
    newIncome.setDate( dateInteger );
    newIncome.setItem( item );
    amount = AuxiliaryMethods::changeCommaToDot( amount );
    newIncome.setAmount( AuxiliaryMethods::convertStringToFloat( amount ) );

    incomes.push_back( newIncome );
    incomesFile.addIncomeToFile( newIncome, userId );
}

void IncomesManager::showAllIncomes( void )
{
   vector<Income>::iterator itr = incomes.begin();
   vector<Income>::iterator endItr = incomes.end();
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

void IncomesManager::showChosenIncomes( vector<Income> * vectorToShow )
{
   vector<Income>::iterator itr = vectorToShow -> begin();
   vector<Income>::iterator endItr = vectorToShow -> end();
   string dateString = "";

   for( itr ; itr != endItr ; itr++ )
   {
       dateString = AuxiliaryMethods::getStringDateFromInteger( (*itr).getDate() );
       cout << endl << "Date: " << dateString << endl;
       cout << "Item: " << (*itr).getItem() << endl;
       cout << "Amount: " << (*itr).getAmount() << " zl"<< endl << endl;
   }
}

vector <Income> IncomesManager::selectIncomesBetweenBateBorders( int downBorder, int topBorder)
{
    vector <Income> selectedIncomes;
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if( itr -> getDate() >= downBorder && itr -> getDate() <= topBorder )
            selectedIncomes.push_back( *itr );
    }
    return selectedIncomes;
}

vector <Income> IncomesManager::sortIncomesVector( vector <Income> vectorToSort)
{
    Income temp;
    for (vector <Income>::iterator itr1 = vectorToSort.begin(); itr1 != vectorToSort.end(); itr1++)
    {
        for (vector <Income>::iterator itr2 = vectorToSort.begin(); itr2 != (vectorToSort.end() - 1); itr2++)
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

void IncomesManager::showSortedIncomesBetweenDateBorders( int downBorder, int topBorder )
{

    vector <Income> selectedIncomes = selectIncomesBetweenBateBorders(downBorder, topBorder);
    vector <Income> newVect = sortIncomesVector( selectedIncomes );
    showChosenIncomes( &newVect );
}

int IncomesManager::sumIncomesAmountsBetweenDateBorders( int downBorder, int topBorder )
{
    vector <Income> selectedIncomes = selectIncomesBetweenBateBorders(downBorder, topBorder);
    float sumaryAmounts = 0;
    for (vector <Income>::iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++)
    {
        sumaryAmounts += itr -> getAmount();
    }
    return sumaryAmounts;
}
