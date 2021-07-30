#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <string>

#include "Markup.h"
#include "XMLFile.h"
#include "User.h"
#include "SupportingMethods.h"

using namespace std;

class UsersFile :public XMLFile {

    User getUserData(string userDataSeparatedByVerticalDashes);
    string replaceUserDataWithLineWithVerticalDashes(User user);

public:

    UsersFile(string usersFilename) : XMLFile(usersFilename) {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void saveAllUsersToFile(vector<User> users);
};

#endif // USERSFILE_H
