#include "models/menuManagement.hpp"
#include "models/menuInfo.hpp"
#include "models/excelUtils.hpp"
#include <iostream>
#include <vector>

using namespace std;

void addNewProduct(){
    string filename = "../../data/productInfo.xlsx";
    vector<Product> products  = readExcelFromMenuInfoToVector(filename);

    string itemName;
    float  itemPrice;
    int   itemAmount;
    string itemCategory;

    cin.ignore();
    cout << "Enter Product Name : ";
    getline(cin, itemName);
    cout << "Enter Product Price : ";
    cin >> itemPrice;
    cout << "Enter Product Amount : ";
    cin >> itemAmount;
    cout << "Enter Product Category : ";
    cin >> itemCategory;

    products.emplace_back(itemName, itemPrice, itemAmount, itemCategory);
    writeExcelToMenuInfo(filename, products);
}

void updateProduct(){
    string filename = "../../data/productInfo.xlsx";
    vector<Product> products  = readExcelFromMenuInfoToVector(filename);

    string updateName;
    string newitemName;
    float  newItemPrice;
    int   newItemAmount;
    string newItemCategory;

    cin.ignore();
    cout << "Enter Product Name to Update : ";
    getline(cin, updateName);

    bool found = false;
    for(auto &product : products){
        if(product.getItemName() == updateName){
            found = true;
            cout << "Product found!\n";
            cout << "Product Name : " << product.getItemName() << endl;
            cout << "Product Price : " << product.getItemPrice() << endl;
            cout << "Product Amount : " << product.getItemAmount() << endl;
            cout << "Product Category : " << product.getItemCategory() << endl;
            cout << "Press Enter to continue...";
            cin.ignore();

            cout << "Enter Product Name : ";
            getline(cin, newitemName);
            cout << "Enter Product Price : ";
            cin >> newItemPrice;
            cout << "Enter Product Amount : ";
            cin >> newItemAmount;
            cout << "Enter Product Category : ";
            cin >> newItemCategory;

            product.setItemName(newitemName);
            product.setItemPrice(newItemPrice);
            product.setItemAmount(newItemAmount);
            product.setItemCategory(newItemCategory);

            writeExcelToMenuInfo(filename, products);
            break;
        }
    }
    if(!found){
        cout << "Product not found!\n";
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
}
void deleteProduct(){
    string filename = "../../data/productInfo.xlsx";
    vector<Product> products  = readExcelFromMenuInfoToVector(filename);

    string deleteProductInfo;

    cin.ignore();
    cout << "Enter Product Name to Delete : ";
    getline(cin, deleteProductInfo);

    bool found = false;
    for(auto it = products.begin(); it != products.end(); it++){
        if(it->getItemName() == deleteProductInfo){
            found = true;
            products.erase(it);
            cout << "Product deleted successfully!\n";
            cin.ignore();
            break;
        }
    }
    if(!found){
        cout << "Product not found!\n";
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    writeExcelToMenuInfo(filename, products);
}
void showAllProduct(){
    string filename = "../../data/productInfo.xlsx";
    vector<Product> products  = readExcelFromMenuInfoToVector(filename);

    system("cls");
    cout << "========== ALL Product ==========\n\n";

    if(products.empty()){
        cout << "No product found!";
    }else{
        int count = 1;
        for(const auto &product : products){
            cout << "[" << count << "]" <<"    Product Name : " << product.getItemName() << endl;
            cout << "    Product Price : " << product.getItemPrice() << endl;
            cout << "    Product Amount : " << product.getItemAmount() << endl;
            cout << "    Product Category : " << product.getItemCategory() << endl;
            count++;
        }
        cout << "Total Product : " << products.size() << endl;
    }
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

bool adminAuth(){
    int attempts = 3;
    
    while(attempts > 0) {
        system("cls");
        cout << "========== STAFF LOGIN ==========\n";
        cout << "Attempts remaining: " << attempts << "\n\n";
        
        string userName;
        string userPass;
        
        cin.ignore();
        cout << "Enter Username: ";
        getline(cin, userName);
        cout << "Enter Password: ";
        getline(cin, userPass);
        
        // Check if credentials match any staff
        bool found = false;
        if(userName == "admin" && userPass == "password"){
            found = true;
            cout << "\n Login successful!\n";
                cout << "Press Enter to continue...";
                cin.get();
                return true;
        }
        if(!found) {
            attempts--;
            if(attempts > 0) {
                cout << "\n Invalid username or password!\n";
                cout << "Attempts remaining: " << attempts << "\n";
                cout << "Press Enter to try again...";
                cin.get();
            } else {
                cout << "\n Login failed! No attempts remaining.\n";
                cout << "Press Enter to return...";
                cin.get();
            }
        }
    }
    return false;
}

void showSummaryOneDay(){
    string filename = "../../data/orderInfo.xlsx";
    vector<Order> orders  = readExcelFromOrderInfoToVector(filename);
    
    system("cls");
    cout << "===== 1 day =====\n";

    
    for(const auto &order : orders){
        cout << order.getItemOrderTimestamp();
        if(order.getItemOrderTimestamp() == "2025-11-27"){
            cout << order.getItemOrderTimestamp();
            break;
        }
    }
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}
void showSummaryOneWeek();
void showSummaryOneMonth();