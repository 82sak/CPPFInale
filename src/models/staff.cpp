#include <iostream>
#include <vector>
#include "models/staff.hpp"
#include "models/admin.hpp"
#include "models/menuManagement.hpp"
#include "models/menuInfo.hpp"
#include "models/excelUtils.hpp"

using namespace std;

#define RESET "\033[0m"
#define PRIMARY "\033[38;5;147m"   // Soft purple
#define SECONDARY "\033[38;5;189m" // Light lavender
#define ACCENT "\033[38;5;213m"    // Pink accent
#define TEXT "\033[38;5;255m"      // White text
#define MUTED "\033[38;5;245m"     // Gray muted
#define SUCCESS "\033[38;5;120m"   // Mint green
#define ERROR "\033[38;5;210m"     // Coral red
#define WARNING "\033[38;5;222m"   // Peach
#define BOLD "\033[1m"
#define DIM "\033[2m"

void displayStaffPage()
{
     cout << "\n\n";
     cout << PRIMARY << "                                      ╔════════════════════════════════════════════════════════════════╗\n";
     cout << PRIMARY << "                                      ║  " << BOLD << ACCENT << "              💼 WELCOME TO STAFF PANEL 💼" << RESET << PRIMARY << "                    ║\n";
     cout << PRIMARY << "                                      ╠════════════════════════════════════════════════════════════════╣\n";
     cout << PRIMARY << "                                      ║   " << ACCENT << "             📜  1. " << TEXT << "Show Menu" << RESET << PRIMARY << "                                ║\n";
     cout << PRIMARY << "                                      ║   " << ACCENT << "             🧾  2. " << TEXT << "Show Receipt" << RESET << PRIMARY << "                             ║\n";
     cout << PRIMARY << "                                      ║   " << ERROR << "             🛑  0. " << TEXT << "Exit" << RESET << PRIMARY << "                                     ║\n";
     cout << PRIMARY << "                                      ╚════════════════════════════════════════════════════════════════╝\n";
     cout << RESET;
}

void showMenu()
{
     string filename = "../../data/productInfo.xlsx";
     vector<Product> products = readExcelFromMenuInfoToVector(filename);

     system("cls");
     cout << "\n\n";
     cout << PRIMARY << "                                      ╔════════════════════════════════════════════════════════════════╗\n";
     cout << PRIMARY << "                                      ║  " << BOLD << ACCENT << "                     🧃 ALL PRODUCTS 🧃" << RESET << PRIMARY << "                       ║\n";
     cout << PRIMARY << "                                      ╚════════════════════════════════════════════════════════════════╝\n";
     cout << RESET << "\n";

     if (products.empty())
     {
          cout << "     " << ERROR << "No Product Found!\n"
               << RESET;
     }
     else
     {
          int count = 1;
          for (const auto &product : products)
          {
               cout << "\n     " << SUCCESS << BOLD << "[" << count << "] " << RESET;
               cout << ACCENT << "Product Name     : " << TEXT << product.getItemName() << RESET << "\n";
               cout << "         " << ACCENT << "Product Price    : " << SUCCESS << "$" << product.getItemPrice() << RESET << "\n";
               cout << "         " << ACCENT << "Product Amount   : " << SECONDARY << product.getItemAmount() << RESET << "\n";
               cout << "         " << ACCENT << "Product Category : " << PRIMARY << product.getItemCategory() << RESET << "\n";
               count++;
          }
          cout << "\n     " << WARNING << BOLD << "Total Products : " << TEXT << products.size() << RESET << "\n";
     }

     cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
     cin.ignore();
     cin.get();
}

void showReceipt()
{
     string filename = "../../data/orderInfo.xlsx";
     vector<Order> orders = readExcelFromOrderInfoToVector(filename);

     system("cls");
     cout << "\n\n";
     cout << PRIMARY << "                                      ╔════════════════════════════════════════════════════════════════╗\n";
     cout << PRIMARY << "                                      ║  " << BOLD << ACCENT << "                🧲 ORDERS BY TRANSACTION 🧲" << RESET << PRIMARY << "                   ║\n";
     cout << PRIMARY << "                                      ╚════════════════════════════════════════════════════════════════╝\n";
     cout << RESET << "\n";

     if (orders.empty())
     {
          cout << "     " << ERROR << "No orders found!\n"
               << RESET;
          cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
          cin.ignore();
          cin.get();
          return;
     }

     string currentTimestamp = "";
     float transactionTotal = 0;
     int transactionNum = 0;

     for (const auto &order : orders)
     {
          if (order.getItemOrderTimestamp() != currentTimestamp)
          {
               if (!currentTimestamp.empty())
               {
                    cout << "         " << MUTED << "───────────────────────────────────────\n"
                         << RESET;
                    cout << "         " << ACCENT << "Transaction Total: " << SUCCESS << BOLD << "$" << transactionTotal << RESET << "\n";
                    cout << "     " << PRIMARY << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
                         << RESET;
                    cout << "\n";
               }

               transactionNum++;
               currentTimestamp = order.getItemOrderTimestamp();
               transactionTotal = 0;

               cout << "     " << ACCENT << BOLD << "Transaction " << transactionNum << RESET << "\n";
               cout << "     " << SECONDARY << "Time: " << TEXT << currentTimestamp << RESET << "\n";
               cout << "     " << SECONDARY << "────────────────────────────────────────────────────────\n"
                    << RESET;
          }

          float subtotal = order.getItemOrderPrice() * order.getItemOrderAmount();
          transactionTotal += subtotal;

          cout << "         " << TEXT << order.getItemOrderName()
               << " " << MUTED << "(" << order.getItemOrderCategory() << ")" << RESET << "\n";
          cout << "         " << SECONDARY << "$" << order.getItemOrderPrice()
               << " x " << order.getItemOrderAmount()
               << " = " << SUCCESS << BOLD << "$" << subtotal << RESET << "\n";
     }

     if (!currentTimestamp.empty())
     {
          cout << "         " << MUTED << "───────────────────────────────────────\n"
               << RESET;
          cout << "         " << ACCENT << "Transaction Total: " << SUCCESS << BOLD << "$" << transactionTotal << RESET << "\n";
          cout << "     " << PRIMARY << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
               << RESET;
     }

     cout << "\n     " << ACCENT << BOLD << "Total Transactions: " << TEXT << transactionNum << RESET << "\n";
     cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
     cin.ignore();
     cin.get();
}