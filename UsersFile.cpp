#include "UsersFile.h"

void UsersFile::addUserToFile(User user) {
    string lineWithUserData = "";
    fstream textFile;
    textFile.open(getFilename().c_str(), ios::app);

    if (textFile.good() == true) {
        lineWithUserData = replaceUserDataWithLineWithVerticalDashes(user);

        if (isFileEmpty() == true) {
            textFile << lineWithUserData;
        } else {
            textFile << endl << lineWithUserData ;
        }
    } else
        cout << "I cannot open the file " << getFilename() << " and save the data in it." << endl;
    textFile.close();
}

vector<User> UsersFile::loadUsersFromFile() {
    vector <User> usersVector;
    User user;
    fstream textFile;
    string userDataSeparetedByVerticalDashes = "";

    textFile.open(getFilename().c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, userDataSeparetedByVerticalDashes)) {
            user = getUserData(userDataSeparetedByVerticalDashes);
            usersVector.push_back(user);
        }
        textFile.close();
    }
    return usersVector;
}

void UsersFile::saveAllUsersToFile(vector<User> users){
fstream textFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(getFilename().c_str(), ios::out);

    if (textFile.good() == true) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            lineWithUserData = replaceUserDataWithLineWithVerticalDashes(*itr);

            if (itr == itrEnd) {
                textFile << lineWithUserData;
            } else {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
    } else {
        cout << "The file cannot be opened " << getFilename() << endl;
    }
    textFile.close();

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

