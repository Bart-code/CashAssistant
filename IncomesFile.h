#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include "Income.h"
#include "FileXml.h"

using namespace std;

class IncomesFile : public FileXml
{
     CMarkup incomesFile;

public:
    IncomesFile();
    void addIncomeToFile( Income * );


};


#endif
