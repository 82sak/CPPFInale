#include <windows.h>
#include "models/menuManagement.hpp"
#include "models/menuInfo.hpp"
#include "models/excelUtils.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <conio.h>
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

#define RESET "\033[0m"
#define PRIMARY "\033[38;5;147m"   // Soft purple
#define SECONDARY "\033[38;5;189m" // Light lavender
#define ACCENT "\033[38;5;213m"    // Pink accent
#define TEXT_COLOR "\033[38;5;255m"      // White TEXT_COLOR
#define MUTED "\033[38;5;245m"     // Gray muted
#define SUCCESS "\033[38;5;120m"   // Mint green
#define ERROR_COLOR "\033[38;5;210m"     // Coral red
#define WARNING "\033[38;5;222m"   // Peach
#define BOLD "\033[1m"
#define DIM "\033[2m"

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

string maskingPassword(){
    string password = "";
    char ch;
    
    while (true) {
        ch = _getch();  // Read character without displaying it
        
        if (ch == 13) {  // Enter key (ASCII 13)
            cout << endl;
            break;
        }
        else if (ch == 8) {  // Backspace key (ASCII 8)
            if (!password.empty()) {
                password.pop_back();  // Remove last character
                cout << "\b \b";  // Move back, print space, move back again
            }
        }
        else {
            password += ch;  // Add character to password
            cout << '*';     // Display asterisk
        }
    }
    
    return password;
}

bool adminAuth()
{
    int attempts = 3;

    while (attempts > 0)
    {
        system("cls");
        cout << "\n\n";
        cout << PRIMARY << "     ╔════════════════════════════════════════════════════════════════╗\n";
        cout << PRIMARY << "     ║                                                                ║ \n";
        cout << PRIMARY << "     ║   " << BOLD << ACCENT << "                    🪛  ADMIN LOGIN 🪛" << RESET << PRIMARY << "                         ║ \n";
        cout << PRIMARY << "     ║                                                                ║ \n";
        cout << PRIMARY << "     ╚════════════════════════════════════════════════════════════════╝\n";
        cout << RESET << "\n";
        cout << YELLOW << "     " << "Attempts remaining: " << (attempts == 1 ? RED : YELLOW) << attempts << RESET << "\n\n";

        string userName;
        string userPass;

        cin.ignore();
        cout << "     " << RED << "Enter Username: " << RESET;
        getline(cin, userName);
        cout << "     " << RED << "Enter Password: " << RESET;
        userPass = maskingPassword();

        bool found = false;
        if (userName == "admin" && userPass == "password")
        {
            found = true;
            cout << GREEN << BOLD << "\n     " << "Login successful!\n"
                 << RESET;
            cout << YELLOW << "     " << "Press Enter to continue..." << RESET;
            cin.get();
            return true;
        }
        if (!found)
        {
            attempts--;
            if (attempts > 0)
            {
                cout << "\n     " << RED << BOLD << "Invalid username or password!\n"
                     << RESET;
                cout << "     " << YELLOW << "Attempts remaining: " << (attempts == 1 ? RED : YELLOW) << attempts << RESET << "\n";
                cout << "     " << MUTED << "Press Enter to try again..." << RESET;
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

inline string getCurrentTimestamp() {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    
    stringstream ss;
    ss << put_time(localtime(&now_time), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
void showSummaryOneDay()
{
    string filename = "../../data/orderInfo.xlsx";
    vector<Order> orders = readExcelFromOrderInfoToVector(filename);

    system("cls");
     cout << "\n\n";
     cout << PRIMARY << "                   ╔════════════════════════════════════════════════════════════════╗\n";
     cout << PRIMARY << "                   ║                                                                ║\n";
     cout << PRIMARY << "                   ║  " << BOLD << ACCENT << "                       24-Hours Report" << RESET << PRIMARY << "                        ║\n";
     cout << PRIMARY << "                   ║                                                                ║\n";
     cout << PRIMARY << "                   ╚════════════════════════════════════════════════════════════════╝\n";
     cout << RESET << "\n";

    if (orders.empty())
    {
          cout << "     " << ERROR_COLOR << "No orders found!\n"
               << RESET;
          cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
          cin.ignore();
          cin.get();
          return;
    }

     string today = getCurrentTimestamp().substr(0, 10);
    
    auto yesterday_time = chrono::system_clock::now() - chrono::hours(24);
    time_t yesterday_time_t = chrono::system_clock::to_time_t(yesterday_time);
    stringstream ss;
    ss << put_time(localtime(&yesterday_time_t), "%Y-%m-%d");
    string yesterday = ss.str();
    
    cout << "     " << SECONDARY << "From " << yesterday << " to " << today << endl;
    cout << "     " << SECONDARY << "────────────────────────────────────────────────────────\n";
    
    int count = 0;
    float totalTax = 0;
    float total = 0;

    for(const auto &order : orders) {
        string orderDate = order.getItemOrderTimestamp().substr(0, 10);
        
        if(orderDate == yesterday || orderDate == today) {
            count++;
            float price = order.getItemOrderPrice() * order.getItemOrderAmount();
            float tax = (order.getItemOrderPrice() / 10) * order.getItemOrderAmount();
            total += price;
            totalTax += tax;
            
            cout << "         "<< TEXT_COLOR << count << ". " << order.getItemOrderName() << RESET
                 << SECONDARY << " - $" << price << endl;
        }
    }
    cout << "     " << PRIMARY << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
                    << RESET;
    cout << BLUE << BOLD << "        SubTotal: " << SUCCESS << BOLD "$" << total << "\n" << RESET;
    cout << BLUE << BOLD << "        Tax     : " << SUCCESS << BOLD << "$" << totalTax << "\n" << RESET;
    cout << BLUE << BOLD << "        Total   : " << SUCCESS << BOLD << "$" << total + totalTax << "\n";

    cout << MUTED << "\nPress Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
}

void showSummaryOneWeek()
{
   string filename = "../../data/orderInfo.xlsx";
    vector<Order> orders = readExcelFromOrderInfoToVector(filename);

    system("cls");
     cout << "\n\n";
     cout << PRIMARY << "                   ╔════════════════════════════════════════════════════════════════╗\n";
     cout << PRIMARY << "                   ║                                                                ║\n";
     cout << PRIMARY << "                   ║  " << BOLD << ACCENT << "                         7-Day Report" << RESET << PRIMARY << "                         ║\n";
     cout << PRIMARY << "                   ║                                                                ║\n";
     cout << PRIMARY << "                   ╚════════════════════════════════════════════════════════════════╝\n";
     cout << RESET << "\n";

    if (orders.empty())
    {
          cout << "     " << ERROR_COLOR << "No orders found!\n"
               << RESET;
          cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
          cin.ignore();
          cin.get();
          return;
    }

     string today = getCurrentTimestamp().substr(0, 10);
    
    auto weekAgo = chrono::system_clock::now() - chrono::hours(168);
    time_t weekAgo_t = chrono::system_clock::to_time_t(weekAgo);
    stringstream ss;
    ss << put_time(localtime(&weekAgo_t), "%Y-%m-%d");
    string week = ss.str();
    
    cout << "     " << SECONDARY << "From " << week << " to " << today << endl;
    cout << "     " << SECONDARY << "────────────────────────────────────────────────────────\n";
    
    int count = 0;
    float totalTax = 0;
    float total = 0;

    for(const auto &order : orders) {
        string orderDate = order.getItemOrderTimestamp().substr(0, 10);
        
        if(orderDate >= week || orderDate <= today) {
            count++;
            float price = order.getItemOrderPrice() * order.getItemOrderAmount();
            float tax = (order.getItemOrderPrice() / 10) * order.getItemOrderAmount();
            total += price;
            totalTax += tax;
            
            cout << "         "<< TEXT_COLOR << count << ". " << order.getItemOrderName() << RESET
                 << SECONDARY << " - $" << price << endl;
        }
    }
    cout << "     " << PRIMARY << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
                    << RESET;
    cout << BLUE << BOLD << "        SubTotal: " << SUCCESS << BOLD "$" << total << "\n" << RESET;
    cout << BLUE << BOLD << "        Tax     : " << SUCCESS << BOLD << "$" << totalTax << "\n" << RESET;
    cout << BLUE << BOLD << "        Total   : " << SUCCESS << BOLD << "$" << total + totalTax << "\n";

    cout << MUTED << "\nPress Enter to continue..." << RESET;
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