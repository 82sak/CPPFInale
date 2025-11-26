#include <xlnt/xlnt.hpp>
#include "models/excelUtils.hpp"
#include <iostream>

void writeExcelToStaffInfo(const string &filename, vector<User> &users){
    xlnt::workbook wb;
    auto ws = wb.active_sheet();
    ws.title("sheet1");

    ws.cell("A1").value("userName");
    ws.cell("B1").value("userPass");
    ws.cell("C1").value("fullName");
    ws.cell("D1").value("Gender");
    ws.cell("E1").value("Age");

    int row = 2;
    for(auto &user : users){
        ws.cell("A" + to_string(row)).value(user.getUserName());
        ws.cell("B" + to_string(row)).value(user.getUserPass());
        ws.cell("C" + to_string(row)).value(user.getUserFullName());
        ws.cell("D" + to_string(row)).value(user.getUserGender());
        ws.cell("E" + to_string(row)).value(user.getUserAge());
        row++;
    }
    wb.save(filename);
    // cout << "File saved! \n";
}
vector<User> readExcelFromStaffInfoToVector(const string &filename){
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
        string fullName = row[2].to_string();
        string gender   = row[3].to_string();
        int age   = stoi(row[4].to_string());
        users.emplace_back(userName, userPass, fullName, gender, age);
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

void writeExcelToMenuInfo(const string &filename, vector<Product> &products){
    xlnt::workbook wb;
    auto ws = wb.active_sheet();
    ws.title("sheet1");

    ws.cell("A1").value("productName");
    ws.cell("B1").value("productPrice");
    ws.cell("C1").value("productAmount");
    ws.cell("D1").value("productCategory");


    int row = 2;
    for(auto &product : products){
        ws.cell("A" + to_string(row)).value(product.getItemName());
        ws.cell("B" + to_string(row)).value(product.getItemPrice());
        ws.cell("C" + to_string(row)).value(product.getItemAmount());
        ws.cell("D" + to_string(row)).value(product.getItemCategory());

        row++;
    }
    wb.save(filename);
    // cout << "File saved! \n";
};
vector<Product> readExcelFromMenuInfoToVector(const string &filename){
    vector<Product> products;
    xlnt::workbook wb;

    try{
        wb.load(filename);
    } catch (...) {
        cout << "file couldn't open! ";
        return products;
    }

    auto ws = wb.active_sheet();
    for(auto row : ws.rows(false)){
        if(row[0].to_string() == "productName") continue;

        string itemName = row[0].to_string();
        float itemPrice = stof(row[1].to_string());
        int  itemAmount = stoi(row[2].to_string());
        string itemCategory = row[3].to_string();

        products.emplace_back(itemName, itemPrice, itemAmount, itemCategory);
    }
    return products;
};

void writeExcelToOrderInfo(const string &filename, vector<Order> &orders){
    xlnt::workbook wb;
    auto ws = wb.active_sheet();
    ws.title("sheet1");

    ws.cell("A1").value("productOrderName");
    ws.cell("B1").value("productOrderPrice");
    ws.cell("C1").value("productOrderAmount");
    ws.cell("D1").value("productOrderCategory");
    ws.cell("E1").value("productOrderTimestamp");


    int row = 2;
    for(auto &order : orders){
        ws.cell("A" + to_string(row)).value(order.getItemOrderName());
        ws.cell("B" + to_string(row)).value(order.getItemOrderPrice());
        ws.cell("C" + to_string(row)).value(order.getItemOrderAmount());
        ws.cell("D" + to_string(row)).value(order.getItemOrderCategory());
        ws.cell("E" + to_string(row)).value(order.getItemOrderTimestamp());

        row++;
    }
    wb.save(filename);
    // cout << "File saved! \n";
};
vector<Order> readExcelFromOrderInfoToVector(const string &filename){
vector<Order> orders;
    xlnt::workbook wb;

    try{
        wb.load(filename);
    } catch (...) {
        cout << "file couldn't open! ";
        return orders;
    }

    auto ws = wb.active_sheet();
    for(auto row : ws.rows(false)){
        if(row[0].to_string() == "productOrderName") continue;

        string itemOrderName = row[0].to_string();
        float itemOrderPrice = stof(row[1].to_string());
        int  itemOrderAmount = stoi(row[2].to_string());
        string itemOrderCategory = row[3].to_string();
        string itemOrderTimestamp = row[4].to_string();


        orders.emplace_back(itemOrderName, itemOrderPrice, itemOrderAmount, itemOrderCategory, itemOrderTimestamp);
    }
    return orders;
};
