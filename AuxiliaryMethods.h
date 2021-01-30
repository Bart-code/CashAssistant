#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <time.h>
#include "windows.h"

using namespace std;

class AuxiliaryMethods
{

public:
    static string convertIntegerToString( int );
    static int convertStringToInteger( string );
    static int getIntegerDateFromString( string );
    static string getStringDateFromInteger( int );
    static bool isDateCorrect( string );
    static int getDaysCountSelectedMonth( string );
    static int getLastDayDateCurrentMonth( void );
    static string getCurrentDateTime( void );

};

#endif
