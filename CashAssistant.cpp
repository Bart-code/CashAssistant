#include "CashAssistant.h"
#include <cstdlib>

using namespace std;

CashAssistant::CashAssistant()
{
    userManager.loadUsersFromFile();
    loggedUserId = 0;
}

void CashAssistant::showUserMenu( void )
{
    system("cls");
    cout << "MAIN MENU" << endl;
    cout << "-----------------------------" << endl << endl;
    cout << "1. Sign in" << endl;
    cout << "2. Registration" << endl;
    cout << "3. Show all users" << endl << endl;
    cout << "9. End" << endl << endl;
}

void CashAssistant::registration( void )
{
    userManager.registration();
}

void CashAssistant::showAllUsers( void )
{
    userManager.showAllUsers();
}

void CashAssistant::logIn( void )
{
   loggedUserId = userManager.logIn();
}

void CashAssistant::showLoggedUserMenu( void )
{
    system("cls");
    cout << "USER MENU" << endl;
    cout << "-----------------------------" << endl << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance sheet for current month" << endl;
    cout << "4. Balance sheet for previous month" << endl;
    cout << "5. Balance sheet for the custom period" << endl;
    cout << "6. Change password" << endl;
    cout << "8. Show all incomes" << endl<<endl;
    cout << "7. Logout" << endl;
}

bool CashAssistant::isUserLogged( void )
{
    if( userManager.getLoggedUserId()) return true;
    return false;
}

void CashAssistant::addIncome( void )
{
    incomesManager -> addIncome( userManager.getLoggedUserId());
}

void CashAssistant::showAllLoadedIncomes( void )
{
    incomesManager -> showAllIncomes();
}

void CashAssistant::addExpense( void )
{
    expensesManager -> addExpense( userManager.getLoggedUserId());
}

void CashAssistant::showAllLoadedExpenses( void )
{
    expensesManager -> showAllExpenses();
}

void CashAssistant::incomesExpencesManagersInit( void )
{
    incomesManager = new IncomesManager( loggedUserId );
    expensesManager = new ExpensesManager( loggedUserId );
}

void CashAssistant::logout( void )
{
    loggedUserId = 0;
    userManager.setLoggedUserId ( 0 );
}

void CashAssistant::changePassword( void )
{
    userManager.changePassword();
}

void CashAssistant::balanceSheetForSelectedDateBorders( int downBorder, int topBorder )
{

    float incomesSummaryAmounts, expensesSummaryAmounts;

    cout << endl << "Incomes: " << endl;
    incomesManager -> showSortedIncomesBetweenDateBorders( downBorder, topBorder );
    incomesSummaryAmounts = incomesManager -> sumIncomesAmountsBetweenDateBorders( downBorder, topBorder );


    cout << endl << "Expenses: " << endl;
    expensesManager -> showSortedExpensesBetweenDateBorders( downBorder, topBorder );
    expensesSummaryAmounts = expensesManager -> sumExpensesAmountsBetweenDateBorders( downBorder, topBorder );

    cout << endl << "Summary incomes: " << incomesSummaryAmounts << " zl" <<endl;
    cout << "Summary expenses: " << expensesSummaryAmounts << " zl" <<endl;

    cout << "Different betwen incomes and expenses: " << incomesSummaryAmounts - expensesSummaryAmounts << " zl" <<endl;
    system( "pause");
}

void CashAssistant::balanceSheetForCurrentMonth( void )
{
    string currentDate = AuxiliaryMethods::getCurrentDateTime();
    int downBorder = AuxiliaryMethods::getIntegerDateFromString( currentDate.replace( 8, 10 ,"00"));
    int topBorder = downBorder + AuxiliaryMethods::getDaysCountSelectedMonth( currentDate );
    balanceSheetForSelectedDateBorders( downBorder, topBorder);
}

void CashAssistant::balanceSheetForPreviousMonth( void )
{
    string currentDate = AuxiliaryMethods::getCurrentDateTime();
    string monthFromCurrentDate = currentDate.substr(4,2);

    int downBorder = AuxiliaryMethods::getIntegerDateFromString( currentDate.replace( 8, 10 ,"00")); //20120124
    if( monthFromCurrentDate == "01" )
    {
        downBorder-=8900;
    }
    else
    {
        downBorder-=100;
    }
    int topBorder = downBorder + AuxiliaryMethods::getDaysCountSelectedMonth( currentDate );
    balanceSheetForSelectedDateBorders( downBorder, topBorder);
}

void CashAssistant::balanceSheetForCustomPeriod( void )
{
    string customDownBorder;
    string customTopBorder;

    cout << "Enter down border: ";
    cin >> customDownBorder;
    if( !AuxiliaryMethods::isDateCorrect( customDownBorder ))
    {
        cout << "Wrong date format !" << endl;
        system("pause");
        return;
    }
    cout << "Enter top border: ";
    cin >> customTopBorder;
    if( !AuxiliaryMethods::isDateCorrect( customTopBorder ))
    {
        cout << "Wrong date format !" << endl;
        system("pause");
        return;
    }

    int downBorder = AuxiliaryMethods::getIntegerDateFromString( customDownBorder);
    int topBorder = AuxiliaryMethods::getIntegerDateFromString( customTopBorder);
    balanceSheetForSelectedDateBorders( downBorder, topBorder);
}


