#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include "Expense.h"
#include "ExpensesFile.h"
#include <vector>
#include "AuxiliaryMethods.h"

using namespace std;

class ExpensesManager
{
    vector <Expense> expenses;
    ExpensesFile expensesFile;

public:

    ExpensesManager( int );
    void addExpense( int );
    void showAllExpenses( void );
};

#endif
