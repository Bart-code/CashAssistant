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
    cout << "2. Registration" << endl << endl;
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

