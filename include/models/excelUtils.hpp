#pragma once
#include <string>
#include <vector>
#include "models/staffAccount.hpp"

using namespace std;

void writeExcel(const string &filename, vector<User> &users);
vector<User> readExcelToVector(const string &filename);
void readExcel(const string &filename);