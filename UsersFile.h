#ifndef USERSFILE_H
#define USERSFILE_H

//#include <iostream>
#include "FileXml.h"

using namespace std;

class UsersFile : public FileXml
{
    CMarkup usersFile;

public:
    UsersFile();

};

#endif
