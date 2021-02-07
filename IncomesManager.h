#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "IncomesFile.h"

using namespace std;

class IncomesManager
{
    vector <Income> incomes;
    IncomesFile incomesFile;

public:

    IncomesManager( int );

    void addIncome( int );
    void showAllIncomes( void );
    void showChosenIncomes( vector<Income> * vectorToShow );
    vector <Income> selectIncomesBetweenBateBorders( int , int );
    void showSortedIncomesBetweenDateBorders( int , int );
    float sumIncomesAmountsBetweenDateBorders( int , int );
    vector <Income> sortIncomesVector( vector <Income> );
};

#endif
