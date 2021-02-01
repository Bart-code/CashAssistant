#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include "Expense.h"
#include "FileXml.h"
#include <vector>

using namespace std;

class ExpensesFile : public FileXml
{
    CMarkup expensesFile;

public:
    ExpensesFile();
    void addExpenseToFile( Expense , int);
    void loadExpensesFromFile(  vector <Expense> * , int );
};


#endif
