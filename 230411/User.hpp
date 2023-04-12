#ifndef __USER_H__
#define __USER_H__
#include <string>
using std::string;

class User {

    string username, password;
    bool isLoggedIn;

public:

    User(const string& username, const string& password) : username{username}, password{password} {};

    void login() {

        if (isLoggedIn) throw "User is already logged in!";
        isLoggedIn = true;

    }

    void logout() {

        if (!isLoggedIn) throw "User is not logged in!";
        isLoggedIn = false;

    }

    string getUsername() const {

        return username;

    }

    string getPassword() const {

        return password;

    }

};

#endif // __USER_H__