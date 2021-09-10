#include "UserManager.h"

void UserManager::registerUser() {

    User user = giveNewUserData();

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "your account has been created" << endl << endl;
    system("pause");
}

void UserManager::loggedInUserPasswordChange() {
    string newPassword = "";
    cout << "enter new password: ";
    newPassword = SupportingMethods::loadLine();
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == loggedInUserId) {
            users[i].setPassword(newPassword);
            cout << "your password has been changed" << endl << endl;
            system("pause");
        }
    }
    usersFile.saveAllUsersToFile(users);
}

void UserManager::logInUser() {
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = SupportingMethods::loadLine();


    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int tryNumber = 3; tryNumber > 0; tryNumber--) {
                cout << "Enter password. There is " << tryNumber << " attempts left: ";
                password = SupportingMethods::loadLine();

                if (users[i].getPassword() == password) {
                    cout << endl << "you are logged in" << endl << endl;
                    system("pause");
                    loggedInUserId = users[i].getId();
                    return;
                }
            }
            cout << "You have entered wrong password 3 times. Try again later." << endl;
            system("pause");
            return;
        }
    }
    cout << "There is no user with this login. Please try again.." << endl << endl;
    system("pause");
    return;
}

void UserManager::logOutUser() {
    loggedInUserId = 0;
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

bool UserManager::isUserLoggedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}
