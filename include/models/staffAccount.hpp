#pragma once
#include <string>

using namespace std;

class User {
private :
    string userName;
    string userPass;
    string fullName;
    string gender;
    int age;

public :
    User(string userName, string userPass, string fullName, string gender, int age);
    string getUserName() const;
    string getUserPass() const;
    string getUserFullName() const;
    string getUserGender() const;
    int getUserAge() const;

    void setUserName(string userName);
    void setUserPass(string userPass);
    void setUserFullName(string fullName);
    void setUserGender(string gender);
    void setUserAge(int age);
};