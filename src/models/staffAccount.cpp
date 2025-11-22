#include "models/staffAccount.hpp"

User::User(string userName, string userPass, string fullName, string gender, int age) : userName(userName), userPass(userPass), fullName(fullName), gender(gender), age(age){}

string User::getUserName() const{
    return userName;
};
string User::getUserPass() const{
    return userPass;
};
string User::getUserFullName() const{
    return fullName;
}
string User::getUserGender() const{
    return gender;
};
int User::getUserAge() const{
    return age;
};
void User::setUserName(string userName){
    this->userName = userName;
};
void User::setUserPass(string userPass){
    this->userPass = userPass;
};
void User::setUserFullName(string fullName){
    this->fullName = fullName;
}
void User::setUserGender(string gender){
    this->gender = gender;
};
void User::setUserAge(int age){
    this->age = age;
};