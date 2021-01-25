#include "UsersFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

UsersFile::UsersFile()
{
    usersFile = initFile("usersFile");
}

void UsersFile::addUserToFile( User user)
{
    string idString = AuxiliaryMethods::convertIntegerToString(user.getId());
    usersFile.ResetPos();
    usersFile.FindElem();
    usersFile.IntoElem();
    usersFile.AddElem( "User" );
    usersFile.FindElem();
    usersFile.IntoElem();
    usersFile.AddElem( "Id" , idString );
    usersFile.AddElem( "Name" , user.getName() );
    usersFile.AddElem( "Surname" , user.getSurname() );
    usersFile.AddElem( "Login" , user.getLogin() );
    usersFile.AddElem( "Password" , user.getPassword() );
    usersFile.Save( "usersFile.xml" );
}

void UsersFile::loadUsersFromFile( vector <User> * usersVector)
{
    User currentUser;
    string userId;
    usersFile.ResetPos();
    usersFile.FindElem();
    usersFile.IntoElem();
    while ( usersFile.FindElem("User") )
    {
        usersFile.IntoElem();
        usersFile.FindElem("Id");
        userId = usersFile.GetData();
        currentUser.setId( AuxiliaryMethods::convertStringToInteger( userId ) );
        usersFile.FindElem("Name");
        currentUser.setName( usersFile.GetData() );
        usersFile.FindElem("Surname");
        currentUser.setSurname( usersFile.GetData() );
        usersFile.FindElem("Login");
        currentUser.setLogin( usersFile.GetData() );
        usersFile.FindElem("Password");
        currentUser.setPassword( usersFile.GetData() );
        usersVector -> push_back( currentUser );
        usersFile.OutOfElem();
    }
}






