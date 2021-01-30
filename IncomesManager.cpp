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
    string item, dateString;
    char userChoiceOption;
    int dateInteger, amount;

    dateString = enterDate();
    if( dateString == "" ) return;
    cout << "Enter describe of income: ";
    cin >> item;
    cout << "Enter income amount: ";
    cin >> amount;
    dateInteger = AuxiliaryMethods::getIntegerDateFromString( dateString );
    newIncome.setDate( dateInteger );
    newIncome.setItem( item );
    newIncome.setAmount( amount );

    incomes.push_back( newIncome );
    incomesFile.addIncomeToFile( newIncome, userId );
}

string IncomesManager::enterDate( void )
{
    string dateString;
    char userChoiceOption;

    cout << endl << "With current date ? (y / n): ";
    while(true)
    {
        cin >> userChoiceOption;
        if( userChoiceOption == 'y' || userChoiceOption == 'Y')
        {
            dateString = AuxiliaryMethods::getCurrentDateTime();
            return dateString;
        }
        else if( userChoiceOption == 'n' || userChoiceOption == 'N' )
        {
            while ( true )
            {
               cout << endl << "Enter date of income (yyyy-mm-dd format): ";
               cin >> dateString;
               if ( AuxiliaryMethods::isDateCorrect( dateString ) ) return dateString;
               else
               {
                   cout << endl << "Try again ? (y / n): ";
                   while (true )
                   {
                       cin >> userChoiceOption;
                       if( userChoiceOption == 'y' || userChoiceOption == 'Y') break;
                       else if( userChoiceOption == 'n' || userChoiceOption == 'N' ) return "";
                       else cout << "Incorect option ! Enter 'y' or 'n' character: ";
                   }

               }
            }
        }
        else cout << "Incorect option ! Enter 'y' or 'n' character";
    }
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

