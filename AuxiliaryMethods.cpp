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
