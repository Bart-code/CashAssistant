#ifndef CASHASSISTANT_H
#define CASHASSISTANT_H

#include <iostream>
#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"

using namespace std;

class CashAssistant
{
    UserManager userManager;
    IncomesManager * incomesManager;
    ExpensesManager * expensesManager;
    int loggedUserId;

public:
    CashAssistant();
    void showUserMenu( void );
    void registration( void );
    void showAllUsers( void );
    void logIn( void );
    void showLoggedUserMenu( void );
    bool isUserLogged( void );
    void addIncome();
    void showAllLoadedIncomes( void );
    void addExpense();
    void showAllLoadedExpenses( void );
    void incomesExpencesManagersInit( void );
    void logout ( void );


};

#endif
