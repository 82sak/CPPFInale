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

    cin.ignore();
    cout << "Enter Product Name : ";
    getline(cin, itemName);
    cout << "Enter Product Price : ";
    cin >> itemPrice;
    cout << "Enter Product Amount : ";
    cin >> itemAmount;

    products.emplace_back(itemName, itemPrice, itemAmount);
    writeExcelToMenuInfo(filename, products);
}

void updateProduct(){
    string filename = "../../data/productInfo.xlsx";
    vector<Product> products  = readExcelFromMenuInfoToVector(filename);

    string updateName;
    string newitemName;
    float  newItemPrice;
    int   newItemAmount;

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
            cout << "Press Enter to continue...";
            cin.ignore();

            cout << "Enter Product Name : ";
            getline(cin, newitemName);
            cout << "Enter Product Price : ";
            cin >> newItemPrice;
            cout << "Enter Product Amount : ";
            cin >> newItemAmount;

            product.setItemName(newitemName);
            product.setItemPrice(newItemPrice);
            product.setItemAmount(newItemAmount);

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
    
};
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
};
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
            count++;
        }
        cout << "Total Product : " << products.size() << endl;
    }
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
};