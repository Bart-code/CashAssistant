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

};

#endif
