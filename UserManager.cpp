#include "UserManager.h"
#include "AuxiliaryMethods.h"

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
    cin.ignore( 1000, '\n' );
    userName = AuxiliaryMethods::loadLine();
    newUser.setName( userName );
    cout << "Enter your surname : ";
    userSurname = AuxiliaryMethods::loadLine();
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

void UserManager::loadUsersFromFile( void )
{
    usersFile.loadUsersFromFile( &users );
}

void UserManager::showAllUsers( void )
{
   vector<User>::iterator itr = users.begin();
   vector<User>::iterator endItr = users.end();

   for( itr ; itr != endItr ; itr++ )
   {
       cout << (*itr).getId() << endl;
       cout << (*itr).getName() << endl;
       cout << (*itr).getSurname() << endl;
       cout << (*itr).getLogin() << endl;
       cout << (*itr).getPassword() << endl;
   }
}

int UserManager::logIn( void )
{
    string login = "", password = "";;
    system("cls");
    cout << "Logging" << endl;
    cout << "-----------------------------" << endl << endl;
    cout << "Enter your login:" << endl;
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if ((*itr).getLogin() == login)
        {
            for (int triesCount = 3; triesCount > 0; triesCount--)
            {
                cout << "Enter password. Tries left: " << triesCount << ": ";
                cin >> password;

                if ((*itr).getPassword() == password)
                {
                    cout << endl << "Login succes !." << endl << endl;
                    system("pause");
                    loggedUserId = (*itr).getId();
                    return loggedUserId;
                }
                else cout << "Wrong password !"<<endl;
            }
            cout << "Wrong password entered 3 times !" << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "No users with this login" << endl << endl;
    system("pause");
    return 0;
}

int UserManager::getLoggedUserId( void )
{
    return loggedUserId;
}

void UserManager::setLoggedUserId( int userId )
{
    loggedUserId = 0;
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << "Enter new password: ";
    cin >> newPassword;
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == loggedUserId)
        {
            itr -> setPassword( newPassword );
            cout << "Password was changed" << endl << endl;
            system("pause");
            usersFile.changePassword( itr -> getId() , newPassword);
            break;
        }
    }
}


































