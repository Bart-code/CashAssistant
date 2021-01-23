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

public:
    UserManager();

};


#endif
