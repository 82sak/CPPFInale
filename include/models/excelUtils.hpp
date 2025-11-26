#pragma once
#include <string>
#include <vector>
#include "models/staffAccount.hpp"
#include "models/menuInfo.hpp"
#include "models/orderInfo.hpp"

using namespace std;

void writeExcelToStaffInfo(const string &filename, vector<User> &users);
vector<User> readExcelFromStaffInfoToVector(const string &filename);
void readExcel(const string &filename);

void writeExcelToMenuInfo(const string &filename, vector<Product> &products);
vector<Product> readExcelFromMenuInfoToVector(const string &filename);

void writeExcelToOrderInfo(const string &filename, vector<Order> &orders);
vector<Order> readExcelFromOrderInfoToVector(const string &filename);
