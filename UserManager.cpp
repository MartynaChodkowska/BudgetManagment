#include "UserManager.h"

void UserManager::registerUser() {

    User user = giveNewUserData();

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "account has been created" << endl << endl;
    system("pause");
}

User UserManager::giveNewUserData() {
    User user;

    user.setId(getNewUserId());

    string name;
    cout << "please enter your name: ";
    cin >> name;
    user.setName(name);

    string secondname;
    cout << "please enter your secondname: ";
    cin >> secondname;
    user.setSecondname(secondname);

    string login;
    do {
        cout << "please enter your login: ";
        cin >> login;
        user.setLogin(login);

    } while (isLoginExists(user.getLogin()) == true);

    string password;
    cout << "please enter your password: ";
    cin >> password;
    user.setPassword(password);



    return user;
}

bool UserManager::isLoginExists(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Sorry - this login already exists. Please choose another one: " << endl;
            return true;
        }
    }
    return false;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else {
        return users.back().getId()+1;
    }
}

void UserManager::displayAllUsers() {
    for (vector<User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        cout << itr->getId() << endl;
        cout << itr->getLogin() << endl;
    }
}
