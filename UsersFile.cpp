#include "UsersFile.h"

void UsersFile::addUserToFile(User user) {
    CMarkup xmlFile;
    xmlFile.Load(getFilename());

    if (!xmlFile.FindElem("USERS")) {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("USERS");
    }
    xmlFile.IntoElem();
    xmlFile.AddElem("USER");
    xmlFile.IntoElem();
    xmlFile.AddElem("USERID", to_string(user.getId()));
    xmlFile.AddElem("LOGIN", user.getLogin());
    xmlFile.AddElem("PASSWORD", user.getPassword());
    xmlFile.AddElem("NAME", user.getName());
    xmlFile.AddElem("SECONDNAME", user.getSecondname());
    xmlFile.OutOfElem();

    xmlFile.Save(getFilename());
}

vector<User> UsersFile::loadUsersFromFile() {
    vector <User> usersVector;
    User user;
    CMarkup xmlFile;

    xmlFile.Load(getFilename());
    xmlFile.ResetMainPos();

    if (xmlFile.FindElem("USERS")) {
        xmlFile.IntoElem();
        while(xmlFile.FindElem("USER")) {
            xmlFile.IntoElem();

            xmlFile.FindElem("USERID");
            int userId = atoi(MCD_2PCSZ(xmlFile.GetData()));

            xmlFile.FindElem("LOGIN");
            string userLogin = xmlFile.GetData();

            xmlFile.FindElem("PASSWORD");
            string userPassword = xmlFile.GetData();

            xmlFile.FindElem("NAME");
            string userName = xmlFile.GetData();

            xmlFile.FindElem("SECONDNAME");
            string userSecondname = xmlFile.GetData();

            user.setId(userId);
            user.setLogin(userLogin);
            user.setPassword(userPassword);
            user.setName(userName);
            user.setSecondname(userSecondname);
            usersVector.push_back(user);

            xmlFile.OutOfElem();
        }
    }
    return usersVector;
}

void UsersFile::saveAllUsersToFile(vector<User> users) {
    CMarkup xmlFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    clearFile();

    xmlFile.Load(getFilename());

    if (!xmlFile.FindElem("USERS")) {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("USERS");
    }
    for (vector<User>::iterator itr = users.begin(); itr != users.end(); itr ++) {
        xmlFile.IntoElem();
        xmlFile.AddElem("USER");
        xmlFile.IntoElem();
        xmlFile.AddElem("USERID", to_string(itr->getId()));
        xmlFile.AddElem("LOGIN", itr->getLogin());
        xmlFile.AddElem("PASSWORD", itr->getPassword());
        xmlFile.AddElem("NAME", itr->getName());
        xmlFile.AddElem("SECONDNAME", itr->getSecondname());
        xmlFile.OutOfElem();
    }
    xmlFile.Save(getFilename());
}

void UsersFile::clearFile(){
 CMarkup xmlfile;
 xmlfile.Load(getFilename());

 xmlfile.ResetMainPos();
 while (xmlfile.FindElem()){
    xmlfile.RemoveElem();
 }
  xmlfile.Save(getFilename());
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

