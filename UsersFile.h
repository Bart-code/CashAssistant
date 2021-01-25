#ifndef USERSFILE_H
#define USERSFILE_H

#include "FileXml.h"
#include "User.h"
#include <vector>

using namespace std;

class UsersFile : public FileXml
{
    CMarkup usersFile;

public:
    UsersFile();
    void addUserToFile( User );
    void loadUsersFromFile( vector <User> * );
};

#endif
