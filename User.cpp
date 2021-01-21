#include "User.h"

using namespace std;

void User::setId( int newId)
{
    id = newId;
}

void User::setName( string newName )
{
    name = newName;
}

void User::setSurname( string newSurname )
{
    surname = newSurname;
}

void User::setLogin( string newLogin)
{
    login = newLogin;
}

void User::setPassword( string newPassword )
{
    password = newPassword;
}

int User::getId( void )
{
    return id;
}

string User::getName( void )
{
    return name;
}

string User::User::getSurname( void )
{
   return surname;
}

string User::getLogin( void )
{
    return login;
}

string User::getPassword( void )
{
    return password;
}
