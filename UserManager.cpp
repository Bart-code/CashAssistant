#include "UserManager.h"



using namespace std;

UserManager::UserManager()
{

}

void UserManager::registration( void )
{
    User newUser;
    string userName, userSurname, userLogin, userPassword;

    newUser.setId( getNewUserId() );
    cout << "Enter your name : ";
    cin >> userName;
    newUser.setName( userName );
    cout << "Enter your surname : ";
    cin >> userSurname;
    newUser.setSurname( userSurname );
    cout << "Enter your login : ";
    cin >> userLogin;
    while( loginAlreadyExist( userLogin ) )
    {
        cout<< "That login already exist !" << endl << "Chose another login: ";
        cin >> userLogin;
    }
    newUser.setLogin( userLogin );
    cout << "Enter your password : ";
    cin >> userPassword;
    newUser.setPassword( userPassword );
    users.push_back( newUser );
    usersFile.addUserToFile( newUser );
}

int UserManager::getNewUserId( void )
{
    if( users.empty() ) return 1;
    else
    {
        vector<User>::iterator itr = users.end();
        itr--;
        int newId = (*itr).getId();
        newId++;
        cout << newId;
        return newId;
    }
}

bool UserManager::loginAlreadyExist( string userLogin )
{
   vector<User>::iterator itr = users.begin();
   vector<User>::iterator endItr = users.end();

   for( itr ; itr != endItr ; itr++ )
   {
       if( userLogin == (*itr).getLogin() ) return true;
   }
   return false;
}
