#include "UsersFile.h"

void UsersFile::addUserToFile(User user) {
    string lineWithUserData = "";
    fstream xmlFile;
    xmlFile.open(getFilename().c_str(), ios::app);

    if (xmlFile.good() == true) {
        lineWithUserData = replaceUserDataWithLineWithVerticalDashes(user);

        if (isFileEmpty() == true) {
            xmlFile << lineWithUserData;
        } else {
            xmlFile << endl << lineWithUserData ;
        }
    } else
        cout << "I cannot open the file " << getFilename() << " and save the data in it." << endl;
    xmlFile.close();
}

vector<User> UsersFile::loadUsersFromFile() {
    vector <User> usersVector;
    User user;
    fstream xmlFile;
    string userDataSeparetedByVerticalDashes = "";

    xmlFile.open(getFilename().c_str(), ios::in);

    if (xmlFile.good() == true) {
        while (getline(xmlFile, userDataSeparetedByVerticalDashes)) {
            user = getUserData(userDataSeparetedByVerticalDashes);
            usersVector.push_back(user);
        }
        xmlFile.close();
    }
    return usersVector;
}

void UsersFile::saveAllUsersToFile(vector<User> users){
fstream xmlFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    xmlFile.open(getFilename().c_str(), ios::out);

    if (xmlFile.good() == true) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            lineWithUserData = replaceUserDataWithLineWithVerticalDashes(*itr);

            if (itr == itrEnd) {
                xmlFile << lineWithUserData;
            } else {
                xmlFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
    } else {
        cout << "The file cannot be opened " << getFilename() << endl;
    }
    xmlFile.close();

}

User UsersFile::getUserData(string userDataSeparetedByVerticalDashes) {
    User user;
    string singleUserData = "";
    int numberOfSingleUserData = 1;

    for (int signPosition = 0; signPosition < userDataSeparetedByVerticalDashes.length(); signPosition++) {
        if (userDataSeparetedByVerticalDashes[signPosition] != '|') {
            singleUserData += userDataSeparetedByVerticalDashes[signPosition];
        } else {
            switch(numberOfSingleUserData) {
            case 1:
                user.setId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setName(singleUserData);
                break;
            case 3:
                   user.setSecondname(singleUserData);
                break;
            case 4:
                user.setLogin(singleUserData);
                break;
            case 5:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            numberOfSingleUserData++;
        }
    }
    return user;
}

string UsersFile::replaceUserDataWithLineWithVerticalDashes(User user) {
    string lineWithUserData = "";

    lineWithUserData += SupportingMethods::conversionFromIntToString(user.getId())+ '|';
    lineWithUserData += user.getName() + '|';
    lineWithUserData += user.getSecondname() + '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

