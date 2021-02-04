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
    vector <Expense> selectExpensesBetweenBateBorders( int , int );
    void showSortedExpensesBetweenDateBorders( int , int );
    int sumExpensesAmountsBetweenDateBorders( int , int );
    vector <Expense> sortExpensesVector( vector <Expense> );
    void showChosenExpenses( vector<Expense> * );
};

#endif
