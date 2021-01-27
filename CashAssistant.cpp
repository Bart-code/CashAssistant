#include "CashAssistant.h"
#include <cstdlib>

using namespace std;

CashAssistant::CashAssistant()
{
    userManager.loadUsersFromFile();
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
   userManager.logIn();
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
    cout << "6. Change password" << endl<<endl;
    cout << "7. Logout" << endl;
}

bool CashAssistant::isUserLogged( void )
{
    if( userManager.getLoggedUserId()) return true;
    return false;
}

void CashAssistant::addIncome( IncomesManager * incomesManager )
{
    incomesManager -> addIncome();
}

