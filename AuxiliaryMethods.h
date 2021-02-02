#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <time.h>
#include "windows.h"
#include <string>

using namespace std;

class AuxiliaryMethods
{

public:
    static string convertIntegerToString( int );
    static int convertStringToInteger( string );
    static string loadLine();
    static int getIntegerDateFromString( string );
    static string getStringDateFromInteger( int );
    static bool isDateCorrect( string );
    static int getDaysCountSelectedMonth( string );
    static int getLastDayDateCurrentMonth( void );
    static string getCurrentDateTime( void );
    static string enterDate( void );
    static string changeCommaToDot( string );
    static float convertStringToFloat( string );
    static string convertFloatToString( float );

};

#endif
