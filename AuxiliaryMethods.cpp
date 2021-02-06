#include "AuxiliaryMethods.h"
#include <string>
#include <sstream>
#include <string>

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

string AuxiliaryMethods::loadLine()
{
    string line = "";
    getline(cin, line);
    return line;
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

bool AuxiliaryMethods::isDateCorrect( string date)
{
    int datePart;
    int maxDate = getLastDayDateCurrentMonth();
    int dateInteger;
    int daysMaxCount;

    if(date.length()!=10)
    {
        cout<<"The date has incorrect format"<<endl;
        return false;
    }
    if(date[4] != '-' || date[7] != '-')
    {
        cout<<"The date has incorrect format"<<endl;
        return false;
    }
    dateInteger = getIntegerDateFromString( date );
    daysMaxCount = getDaysCountSelectedMonth( date );

    if( dateInteger > maxDate || dateInteger < 20000101)
    {
        cout<<"The date has incorrect format"<<endl;
        return false;
    }
    datePart=convertStringToInteger(date.substr(5,2));
    if(datePart>12 || datePart < 1)
    {
        cout<<"The date has incorrect format"<<endl;
        return false;
    }

    datePart=convertStringToInteger(date.substr(8,2));
    if(datePart>daysMaxCount || datePart < 1)
    {
        cout<<"The date has incorrect format"<<endl;
        return false;
    }
    return true;
}

int AuxiliaryMethods::getDaysCountSelectedMonth( string date )
{

    int years=convertStringToInteger(date.substr(0,4));
    int month=convertStringToInteger(date.substr(5,2));

    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) return 31;
    else if(month==4||month==6||month==9||month==11) return 30;
    else if(month==2 && (years % 4) == 0) return 29;
    else if(month==2 && (years % 4) != 0) return 28;
    else return 0;
}

int AuxiliaryMethods::getLastDayDateCurrentMonth( void )
{
    string date = getCurrentDateTime();
    string daysCountCurrentMonth = AuxiliaryMethods::convertIntegerToString( getDaysCountSelectedMonth( date ) );
    int dateInteger;
    date = date.replace(8,2, daysCountCurrentMonth);
    dateInteger = getIntegerDateFromString(date);
    return dateInteger;
}

string AuxiliaryMethods::getCurrentDateTime( void )
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

    return buf;
}

string AuxiliaryMethods::enterDate( void )
{
    string dateString;
    char userChoiceOption;

    cout << endl << "With current date ? (y / n): ";
    while(true)
    {
        cin >> userChoiceOption;
        if( userChoiceOption == 'y' || userChoiceOption == 'Y')
        {
            dateString = AuxiliaryMethods::getCurrentDateTime();
            return dateString;
        }
        else if( userChoiceOption == 'n' || userChoiceOption == 'N' )
        {
            while ( true )
            {
               cout << endl << "Enter date (yyyy-mm-dd format): ";
               cin >> dateString;
               if ( AuxiliaryMethods::isDateCorrect( dateString ) ) return dateString;
               else
               {
                   cout << endl << "Try again ? (y / n): ";
                   while (true )
                   {
                       cin >> userChoiceOption;
                       if( userChoiceOption == 'y' || userChoiceOption == 'Y') break;
                       else if( userChoiceOption == 'n' || userChoiceOption == 'N' ) return "";
                       else cout << "Incorect option ! Enter 'y' or 'n' character: ";
                   }

               }
            }
        }
        else cout << "Incorect option ! Enter 'y' or 'n' character";
    }
}

string AuxiliaryMethods::changeCommaToDot( string withComma)
{
    int wordLenhgt = withComma.length();
    if( ! withComma.empty() )
    {
        for( int i=0 ; i < wordLenhgt ; i++)
        {
            if( withComma[i] == ',')
            {
                withComma[i] = '.';
                return withComma;
            }
        }
    }
    return withComma;
}

float AuxiliaryMethods::convertStringToFloat( string wordToConvert)
{
    float convertedFloat;
    int n = wordToConvert.length();
    char char_array[n + 1];

    strcpy(char_array, wordToConvert.c_str());
    convertedFloat = atof( char_array );
    return convertedFloat;
}

string AuxiliaryMethods::convertFloatToString( float wordToConvert )
{
    ostringstream ss;
    ss << wordToConvert;
    string str = ss.str();
    return str;
}
