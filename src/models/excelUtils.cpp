#include <xlnt/xlnt.hpp>
#include "models/excelUtils.hpp"
#include <iostream>

using namespace std;

void writeExcel(const string &filename, vector<User> &users){
    xlnt::workbook wb;
    auto ws = wb.active_sheet();
    ws.title("sheet1");

    ws.cell("A1").value("userName");
    ws.cell("B1").value("userPass");

    int row = 2;
    for(auto &user : users){
        ws.cell("A" + to_string(row)).value(user.getUserName());
        ws.cell("B" + to_string(row)).value(user.getUserPass());
        row++;
    }
    wb.save(filename);
    cout << "File saved! \n";
}
vector<User> readExcelToVector(const string &filename){
    vector<User> users;
    xlnt::workbook wb;

    try{
        wb.load(filename);
    } catch (...) {
        cout << "file couldn't open! ";
        return users;
    }

    auto ws = wb.active_sheet();
    for(auto row : ws.rows(false)){
        if(row[0].to_string() == "userName") continue;

        string userName = row[0].to_string();
        string userPass = row[1].to_string();
        users.emplace_back(userName, userPass);
    }
    return users;
}
void readExcel(const string &filename){
    xlnt::workbook wb;
    wb.load(filename);
    auto ws = wb.active_sheet();

    for(auto row : ws.rows(false)){
        for(auto cell : row){
            cout << cell.to_string() << " ";
        }
        cout << endl;
    }
}