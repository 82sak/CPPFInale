#pragma once
#include <string>

using namespace std;

class User {
private :
    string userName;
    string userPass;

public :
    User(string userName, string userPass);
    string getUserName() const;
    string getUserPass() const;
    void setUserName(string userName);
    void setUserPass(string userPass);
};