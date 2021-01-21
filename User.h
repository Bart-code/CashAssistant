#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string name, surname, login, password;

public:

    void setId( int );
    void setName( string );
    void setSurname( string );
    void setLogin( string );
    void setPassword( string );

    int getId( void );
    string getName( void );
    string getSurname( void );
    string getLogin( void );
    string getPassword( void );


};

#endif
