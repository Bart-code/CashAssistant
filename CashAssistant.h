#ifndef CASHASSISTANT_H
#define CASHASSISTANT_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class CashAssistant
{
    UserManager userManager;

public:
    CashAssistant();
    void showUserMenu( void );
    void registration( void );
    void showAllUsers( void );
    void logIn( void );

};

#endif
