#ifndef USERSFILE_H
#define USERSFILE_H

#include "FileXml.h"
#include "User.h"

using namespace std;

class UsersFile : public FileXml
{
    CMarkup usersFile;

public:
    UsersFile();
    void addUserToFile( User );
};

#endif
