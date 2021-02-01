#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager
{
    vector <User> users;
    UsersFile usersFile;
    int loggedUserId;

public:
    UserManager();
    void registration( void );
    int getNewUserId( void );
    bool loginAlreadyExist( string );
    void loadUsersFromFile( void );
    void showAllUsers( void );
    int logIn( void );
    int getLoggedUserId ( void );
    void setLoggedUserId ( int );
    void changePassword( void );

};


#endif
