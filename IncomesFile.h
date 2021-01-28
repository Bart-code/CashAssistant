#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include "Income.h"
#include "FileXml.h"
#include <vector>

using namespace std;

class IncomesFile : public FileXml
{
     CMarkup incomesFile;

public:
    IncomesFile();
    void addIncomeToFile( Income , int);
    void loadIncomesFromFile(  vector <Income> * , int );

};


#endif
