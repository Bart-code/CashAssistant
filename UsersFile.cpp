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
