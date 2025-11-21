#include "models/user.hpp"

User::User(string userName, string userPass) : userName(userName), userPass(userPass){}

string User::getUserName() const{
    return userName;
};
string User::getUserPass() const{
    return userPass;
};
void User::setUserName(string userName){
    this->userName = userName;
};
void User::setUserPass(string userPass){
    this->userPass = userPass;
};