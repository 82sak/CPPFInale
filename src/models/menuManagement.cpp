#include "models/menuManagement.hpp"
#include "models/menuInfo.hpp"
#include "models/excelUtils.hpp"
#include <iostream>
#include <vector>
#include <windows.h>
#define _HAS_STD_BYTE 0

using namespace std;

// Color definitions
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define BOLD "\033[1m"

void addNewProduct()
{
    string filename = "../../data/productInfo.xlsx";
    vector<Product> products = readExcelFromMenuInfoToVector(filename);

    string itemName;
    float itemPrice;
    int itemAmount;
    string itemCategory;

    system("cls");
    cout << BLUE << BOLD
         << "╔════════════════════════════════════════════════════════════════╗\n";
    cout << BLUE << BOLD
         << "║                     🛍️  ADD NEW PRODUCT  🛍️                      ║\n";
    cout << BLUE << BOLD
         << "╚════════════════════════════════════════════════════════════════╝\n"
         << RESET;
    cout << endl;

    cin.ignore();
    cout << RED << "Enter Product Name : " << RESET;
    getline(cin, itemName);
    cout << RED << "Enter Product Price : " << RESET;
    cin >> itemPrice;
    cout << RED << "Enter Product Amount : " << RESET;
    cin >> itemAmount;
    cin.ignore();
    cout << RED << "Enter Product Category : " << RESET;
    getline(cin, itemCategory);

    products.emplace_back(itemName, itemPrice, itemAmount, itemCategory);
    writeExcelToMenuInfo(filename, products);

    cout << GREEN << BOLD << "\n✅ Product added successfully!\n"
         << RESET;
    cout << YELLOW << "Press Enter to continue..." << RESET;
    cin.get();
}

void updateProduct()
{
    string filename = "../../data/productInfo.xlsx";
    vector<Product> products = readExcelFromMenuInfoToVector(filename);

    string updateName;
    string newitemName;
    float newItemPrice;
    int newItemAmount;
    string newItemCategory;

    system("cls");
    cout << BLUE << BOLD
         << "╔════════════════════════════════════════════════════════════════╗\n";
    cout << BLUE << BOLD
         << "║                     📦  UPDATE PRODUCT 📦                      ║\n";
    cout << BLUE << BOLD
         << "╚════════════════════════════════════════════════════════════════╝\n"
         << RESET;
    cout << endl;

    cin.ignore();
    cout << RED << "Enter Product Name to Update : " << RESET;
    getline(cin, updateName);

    bool found = false;
    for (auto &product : products)
    {
        if (product.getItemName() == updateName)
        {
            found = true;
            cout << GREEN << BOLD << "\nProduct found!\n"
                 << RESET;
            cout << CYAN << "Product Name : " << RESET << YELLOW << product.getItemName() << RESET << endl;
            cout << CYAN << "Product Price : " << RESET << YELLOW << product.getItemPrice() << RESET << endl;
            cout << CYAN << "Product Amount : " << RESET << YELLOW << product.getItemAmount() << RESET << endl;
            cout << CYAN << "Product Category : " << RESET << YELLOW << product.getItemCategory() << RESET << endl;
            cout << YELLOW << "Press Enter to continue..." << RESET;
            cin.get();

            system("cls");
            cout << BLUE << BOLD
                 << "╔════════════════════════════════════════════════════════════════╗\n";
            cout << BLUE << BOLD
                 << "║                🔖  ENTER NEW DETAILS  🔖                      ║\n";
            cout << BLUE << BOLD
                 << "╚════════════════════════════════════════════════════════════════╝\n"
                 << RESET;
            cout << endl;

            cout << RED << "Enter Product Name : " << RESET;
            getline(cin, newitemName);
            cout << RED << "Enter Product Price : " << RESET;
            cin >> newItemPrice;
            cout << RED << "Enter Product Amount : " << RESET;
            cin >> newItemAmount;
            cin.ignore();
            cout << RED << "Enter Product Category : " << RESET;
            getline(cin, newItemCategory);

            product.setItemName(newitemName);
            product.setItemPrice(newItemPrice);
            product.setItemAmount(newItemAmount);
            product.setItemCategory(newItemCategory);

            writeExcelToMenuInfo(filename, products);
            cout << GREEN << BOLD << "\n✅ Product updated successfully!\n"
                 << RESET;
            cout << YELLOW << "Press Enter to continue..." << RESET;
            cin.get();
            break;
        }
    }
    if (!found)
    {
        cout << RED << BOLD << "\nProduct not found!\n"
             << RESET;
        cout << YELLOW << "\nPress Enter to continue..." << RESET;
        cin.get();
    }
}

void deleteProduct()
{
    string filename = "../../data/productInfo.xlsx";
    vector<Product> products = readExcelFromMenuInfoToVector(filename);

    string deleteProductInfo;

    system("cls");
    cout << BLUE << BOLD
         << "╔════════════════════════════════════════════════════════════════╗\n";
    cout << BLUE << BOLD
         << "║                     🎨  DELETE PRODUCT 🎨                      ║\n";
    cout << BLUE << BOLD
         << "╚════════════════════════════════════════════════════════════════╝\n"
         << RESET;
    cout << endl;

    cin.ignore();
    cout << RED << "Enter Product Name to Delete : " << RESET;
    getline(cin, deleteProductInfo);

    bool found = false;
    for (auto it = products.begin(); it != products.end(); it++)
    {
        if (it->getItemName() == deleteProductInfo)
        {
            found = true;
            products.erase(it);
            cout << GREEN << BOLD << "\nProduct deleted successfully!\n"
                 << RESET;
            break;
        }
    }
    if (!found)
    {
        cout << RED << BOLD << "\nProduct not found!\n"
             << RESET;
    }
    writeExcelToMenuInfo(filename, products);
    cout << YELLOW << "\nPress Enter to continue..." << RESET;
    cin.get();
}

void showAllProduct()
{
    string filename = "../../data/productInfo.xlsx";
    vector<Product> products = readExcelFromMenuInfoToVector(filename);

    system("cls");
    cout << BLUE << BOLD
         << "╔════════════════════════════════════════════════════════════════╗\n";
    cout << BLUE << BOLD
         << "║                       🧃 ALL PRODUCT 🧃                        ║\n";
    cout << BLUE << BOLD
         << "╚════════════════════════════════════════════════════════════════╝\n"
         << RESET;

    if (products.empty())
    {
        cout << RED << "No product found!" << RESET << endl;
    }
    else
    {
        int count = 1;
        for (const auto &product : products)
        {
            cout << MAGENTA << BOLD << "[" << count << "]" << RESET;
            cout << CYAN << "    Product Name : " << RESET << YELLOW << product.getItemName() << RESET << endl;
            cout << CYAN << "    Product Price : " << RESET << GREEN << product.getItemPrice() << RESET << endl;
            cout << CYAN << "    Product Amount : " << RESET << MAGENTA << product.getItemAmount() << RESET << endl;
            cout << CYAN << "    Product Category : " << RESET << BLUE << product.getItemCategory() << RESET << endl;
            cout << endl;
            count++;
        }
        cout << BLUE << BOLD
             << "══════════════════════════════════════════════════════════════════\n"
             << RESET;
        cout << GREEN << BOLD << "Total Product : " << products.size() << RESET << endl;
    }
    cout << BLUE << BOLD
         << "══════════════════════════════════════════════════════════════════\n"
         << RESET;
    cout << YELLOW << "\nPress Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
}

bool adminAuth()
{
    int attempts = 3;

    while (attempts > 0)
    {
        system("cls");
        cout << BLUE << BOLD
             << "╔════════════════════════════════════════════════════════════════╗\n";
        cout << BLUE << BOLD
             << "║                   🖋️  STAFF LOGIN 🖋️                             ║\n";
        cout << BLUE << BOLD
             << "╚════════════════════════════════════════════════════════════════╝\n"
             << RESET;
        cout << YELLOW << "Attempts remaining: " << (attempts == 1 ? RED : YELLOW) << attempts << RESET << "\n\n";

        string userName;
        string userPass;

        cin.ignore();
        cout << RED << "Enter Username: " << RESET;
        getline(cin, userName);
        cout << RED << "Enter Password: " << RESET;
        getline(cin, userPass);

        bool found = false;
        if (userName == "admin" && userPass == "password")
        {
            found = true;
            cout << GREEN << BOLD << "\nLogin successful!\n"
                 << RESET;
            cout << YELLOW << "Press Enter to continue..." << RESET;
            cin.get();
            return true;
        }
        if (!found)
        {
            attempts--;
            if (attempts > 0)
            {
                cout << RED << BOLD << "\n Invalid username or password!\n"
                     << RESET;
                cout << YELLOW << "Attempts remaining: " << (attempts == 1 ? RED : YELLOW) << attempts << RESET << "\n";
                cout << YELLOW << "Press Enter to try again..." << RESET;
                cin.get();
            }
            else
            {
                cout << RED << BOLD << "\n Login failed! No attempts remaining.\n"
                     << RESET;
                cout << YELLOW << "Press Enter to return..." << RESET;
                cin.get();
            }
        }
    }
    return false;
}

void showSummaryOneDay()
{
    string filename = "../../data/orderInfo.xlsx";
    vector<Order> orders = readExcelFromOrderInfoToVector(filename);

    system("cls");
    cout << BLUE << BOLD
         << "╔════════════════════════════════════════════════════════════════╗\n";
    cout << BLUE << BOLD
         << "║                       🌻 1 day 🌻                              ║\n";
    cout << BLUE << BOLD
         << "╠════════════════════════════════════════════════════════════════╣\n"
         << RESET;

    bool found = false;
    for (const auto &order : orders)
    {
        if (order.getItemOrderTimestamp() == "2025-11-27")
        {
            cout << CYAN << order.getItemOrderTimestamp() << RESET << endl;
            found = true;
        }
    }

    if (!found)
    {
         cout << BLUE << BOLD << "║  "
              << RED << "           No orders found for this date."
              << BLUE << BOLD << "                     ║"
              << RESET << "\n";
    }

    cout << BLUE << BOLD
         << "╚════════════════════════════════════════════════════════════════╝\n"
         << RESET;
    cout << YELLOW << "\nPress Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
}

void showSummaryOneWeek()
{
    system("cls");
    cout << BLUE << BOLD
         << "╔════════════════════════════════════════════════════════════════╗\n";
    cout << BLUE << BOLD
         << "║                          🌳 1 week 🌳                          ║\n";
    cout << BLUE << BOLD
         << "╠════════════════════════════════════════════════════════════════╣\n";
    cout << BLUE << BOLD << "║  "
         << MAGENTA << BOLD << "                        Coming Soon!"
         << BLUE << BOLD << "                          ║"
         << RESET << "\n";
    cout << BLUE << BOLD
         << "╚════════════════════════════════════════════════════════════════╝\n"
         << RESET;
    cout << YELLOW << "\nPress Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
}

void showSummaryOneMonth()
{
    system("cls");
    cout << BLUE << BOLD
         << "╔════════════════════════════════════════════════════════════════╗\n";
    cout << BLUE << BOLD
         << "║                            🌈 1 month 🌈                       ║\n";
    cout << BLUE << BOLD
         << "╠════════════════════════════════════════════════════════════════╣\n";
    cout << BLUE << BOLD << "║  "
         << MAGENTA << BOLD << "                          Coming Soon!"
         << BLUE << BOLD << "                        ║"
         << RESET << "\n";
    cout << BLUE << BOLD
         << "╚════════════════════════════════════════════════════════════════╝\n"
         << RESET;
    cout << YELLOW << "\nPress Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
}