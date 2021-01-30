#include "AuxiliaryMethods.h"
#include <string>
#include <sstream>

using namespace std;


string AuxiliaryMethods::convertIntegerToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInteger(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

int AuxiliaryMethods::getIntegerDateFromString(string dateInString)
{
    string someString=dateInString.erase(4,1);
    someString=someString.erase(6,1);
    return convertStringToInteger(someString);
}

string AuxiliaryMethods::getStringDateFromInteger( int date)
{
    string dateString, years, months, days;
    dateString = convertIntegerToString( date );
    years = dateString.substr(0,4);
    months = dateString.substr(4,2);
    days = dateString.substr(6,2);
    dateString = years + "-" + months + "-" + days;
    return dateString;
}
