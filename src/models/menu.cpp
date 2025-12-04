#include "models/menu.hpp"
#include "models/menuManagement.hpp"
#include "models/menuInfo.hpp"
#include "models/excelUtils.hpp"
#include "models/orderInfo.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

#define RESET "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BOLD "\033[1m"
#define PURPLE "\033[35m"
#define GRAY "\033[90m"

#define PRIMARY CYAN
#define ACCENT YELLOW
#define TEXT RESET
#define ERROR RED
#define MUTED "\033[38;5;245m"
#define DIM "\033[2m"

void displayMenuPage()
{
     cout << "\n\n";
     cout << PRIMARY << "                                      ╔════════════════════════════════════════════════════════════════╗\n";
     cout << PRIMARY << "                                      ║  " << BOLD << ACCENT << "                 🍽️  WELCOME TO MENU 🍽️" << RESET << PRIMARY << "                         ║\n";
     cout << PRIMARY << "                                      ╠════════════════════════════════════════════════════════════════╣\n";
     cout << PRIMARY << "                                      ║   " << ACCENT << "                📋  1. " << TEXT << "Menu" << RESET << PRIMARY << "                                  ║\n";
     cout << PRIMARY << "                                      ║   " << ACCENT << "                🛒  2. " << TEXT << "Cart" << RESET << PRIMARY << "                                  ║\n";
     cout << PRIMARY << "                                      ║   " << ERROR << "                🌀  0. " << TEXT << "Exit" << RESET << PRIMARY << "                                  ║\n";
     cout << PRIMARY << "                                      ╚════════════════════════════════════════════════════════════════╝\n";
     cout << RESET;
}

void displayCategory()
{
     cout << "\n\n";
     cout << PRIMARY << "                                      ╔════════════════════════════════════════════════════════════════╗\n";
     cout << PRIMARY << "                                      ║  " << BOLD << ACCENT << "                  🗂️  CATEGORIES MENU 🗂️" << RESET << PRIMARY << "                        ║\n";
     cout << PRIMARY << "                                      ╠════════════════════════════════════════════════════════════════╣\n";
     cout << PRIMARY << "                                      ║   " << ACCENT << "                   🍔  1. " << TEXT << "Food" << RESET << PRIMARY << "                               ║\n";
     cout << PRIMARY << "                                      ║   " << ACCENT << "                   🥤  2. " << TEXT << "Drinks" << RESET << PRIMARY << "                             ║\n";
     cout << PRIMARY << "                                      ║   " << ERROR << "                   🌀  0. " << TEXT << "Exit" << RESET << PRIMARY << "                               ║\n";
     cout << PRIMARY << "                                      ╚════════════════════════════════════════════════════════════════╝\n";
     cout << RESET;
}

vector<string> orderName;
vector<float> orderPrice;
vector<int> orderAmount;
vector<string> orderCategory;

void displayFood()
{
     string filename = "../../data/productInfo.xlsx";
     vector<Product> products = readExcelFromMenuInfoToVector(filename);
     string food = "food";

     system("cls");
     cout << "\n\n";
     cout << BLUE << BOLD
          << "                                      ╔════════════════════════════════════════════════════════════════╗\n";
     cout << BLUE << BOLD
          << "                                      ║                      🍔  FOOD MENU  🍔                         ║\n";
     cout << BLUE << BOLD
          << "                                      ╚════════════════════════════════════════════════════════════════╝\n"
          << RESET;
     cout << endl;

     if (products.empty())
     {
          cout << "                                      " << RED << "⚠️  No product found!" << RESET << endl;
     }
     else
     {
          int count = 1;
          for (const auto &product : products)
          {
               if (product.getItemCategory() == food)
               {
                    cout << "                                      " << YELLOW << BOLD
                         << "╔════════════════════════════════════════════════════════════════╗\n";
                    cout << "                                      " << YELLOW << BOLD << "║" << CYAN << "[" << count << "] " << product.getItemName();
                    int padding = 60 - product.getItemName().length() - to_string(count).length();
                    for (int i = 0; i < padding; i++)
                         cout << " ";
                    cout << YELLOW << " ║\n"
                         << RESET;

                    cout << "                                      " << YELLOW << BOLD << "║ " << GREEN << "💲 Price: $" << fixed << setprecision(2) << product.getItemPrice();
                    padding = 52 - to_string(product.getItemPrice()).length();
                    for (int i = 0; i < padding; i++)
                         cout << " ";
                    cout << YELLOW << "    ║\n"
                         << RESET;

                    cout << "                                      " << YELLOW << BOLD << "║" << GRAY << "📦 Available: " << product.getItemAmount();
                    padding = 50 - to_string(product.getItemAmount()).length();
                    for (int i = 0; i < padding; i++)
                         cout << " ";
                    cout << YELLOW << "║\n"
                         << RESET;

                    cout << "                                      " << YELLOW << BOLD
                         << "╚════════════════════════════════════════════════════════════════╝\n"
                         << RESET;
                    count++;
               }
          }
     }

     string orderItem;
     int amount;
     cout << endl;
     cin.ignore();
     cout << "                                      " << RED << "Enter Food Name to Order : " << RESET;
     getline(cin, orderItem);

     bool found = false;
     for (const auto &product : products)
     {
          if (product.getItemName() == orderItem && product.getItemCategory() == food)
          {
               found = true;
               cout << "                                      " << RED << "Enter Amount : " << RESET;
               cin >> amount;
               if (amount > product.getItemAmount())
               {
                    cout << "\n                                      " << RED << "⚠️  Sorry, only " << product.getItemAmount() << " available"
                         << RESET;
                    cin.ignore();
                    cin.get();
               }
               else
               {
                    orderName.push_back(orderItem);
                    orderPrice.push_back(product.getItemPrice());
                    orderAmount.push_back(amount);
                    orderCategory.push_back(food);
                    cout << "\n                                      " << GREEN << "✓ Added to cart successfully!\n"
                         << RESET;
                    cout << "     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                    cin.ignore();
                    cin.get();
               }
          }
     }
     if (!found)
     {
          cout << "\n                                      " << RED << "⚠️  This item doesn't exist in our restaurant"
               << RESET;
          cin.ignore();
          cin.get();
     }
}

void displayDrink()
{
     string filename = "../../data/productInfo.xlsx";
     vector<Product> products = readExcelFromMenuInfoToVector(filename);
     string drink = "drink";

     system("cls");
     cout << "\n\n";
     cout << PURPLE << BOLD
          << "                                      ╔════════════════════════════════════════════════════════════════╗\n";
     cout << PURPLE << BOLD
          << "                                      ║                     🥤  DRINKS MENU  🥤                        ║\n";
     cout << PURPLE << BOLD
          << "                                      ╚════════════════════════════════════════════════════════════════╝\n"
          << RESET;
     cout << endl;

     if (products.empty())
     {
          cout << "                                      " << RED << "⚠️  No product found!" << RESET << endl;
     }
     else
     {
          int count = 1;
          for (const auto &product : products)
          {
               if (product.getItemCategory() == drink)
               {
                    cout << "                                      " << YELLOW << BOLD
                         << "╔════════════════════════════════════════════════════════════════╗\n";
                    cout << "                                      " << YELLOW << BOLD << "║ " << CYAN << "[" << count << "] " << product.getItemName();
                    int padding = 59 - product.getItemName().length() - to_string(count).length();
                    for (int i = 0; i < padding; i++)
                         cout << " ";
                    cout << YELLOW << " ║\n"
                         << RESET;

                    cout << "                                      " << YELLOW << BOLD << "║ " << GREEN << "💲 Price: $" << fixed << setprecision(2) << product.getItemPrice();
                    padding = 51 - to_string(product.getItemPrice()).length();
                    for (int i = 0; i < padding; i++)
                         cout << " ";
                    cout << YELLOW << "     ║\n"
                         << RESET;

                    cout << "                                      " << YELLOW << BOLD << "║ " << GRAY << "📦 Available: " << product.getItemAmount();
                    padding = 49 - to_string(product.getItemAmount()).length();
                    for (int i = 0; i < padding; i++)
                         cout << " ";
                    cout << YELLOW << "║\n"
                         << RESET;

                    cout << "                                      " << YELLOW << BOLD
                         << "╚════════════════════════════════════════════════════════════════╝\n"
                         << RESET;
                    count++;
               }
          }
     }

     string orderItem;
     int amount;
     cout << endl;
     cin.ignore();
     cout << "                                      " << RED << "Enter Drink Name to Order : " << RESET;
     getline(cin, orderItem);

     bool found = false;
     for (const auto &product : products)
     {
          if (product.getItemName() == orderItem && product.getItemCategory() == drink)
          {
               found = true;
               cout << "                                      " << RED << "Enter Amount : " << RESET;
               cin >> amount;
               if (amount > product.getItemAmount())
               {
                    cout << "\n                                      " << RED << "⚠️  Sorry, only " << product.getItemAmount() << " available"
                         << RESET;
                    cin.ignore();
                    cin.get();
               }
               else
               {
                    orderName.push_back(orderItem);
                    orderPrice.push_back(product.getItemPrice());
                    orderAmount.push_back(amount);
                    orderCategory.push_back(drink);
                    cout << "\n                                      " << GREEN << "✓ Added to cart successfully!\n"
                         << RESET;
                    cout << "     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                    cin.ignore();
                    cin.get();
               }
          }
     }
     if (!found)
     {
          cout << "\n                                      " << RED << "⚠️  This item doesn't exist in our restaurant"
               << RESET;
          cin.ignore();
     }
}

inline string getCurrentTimestamp()
{
     auto now = chrono::system_clock::now();
     time_t now_time = chrono::system_clock::to_time_t(now);

     stringstream ss;
     ss << put_time(localtime(&now_time), "%Y-%m-%d %H-%M-%S");
     return ss.str();
}

string formatPrice(float price) {
    stringstream ss;
    ss << fixed << setprecision(2) << price;
    return ss.str();
}

void displayCart()
{
     system("cls");
     cout << "\n\n";
     cout << GREEN << BOLD
          << "                                      ╔════════════════════════════════════════════════════════════════╗\n";
     cout << GREEN << BOLD
          << "                                      ║                      🛒  YOUR CART  🛒                         ║\n";
     cout << GREEN << BOLD
          << "                                      ╚════════════════════════════════════════════════════════════════╝\n"
          << RESET;
     cout << endl;

     float price;
     float totalTax = 0;
     float total = 0;
     bool cond = true;
     int padding;

     if (orderName.empty())
     {
          cout << "                                      " << YELLOW << BOLD
               << "╔════════════════════════════════════════════════════════════════╗\n";
          cout << "                                      " << YELLOW << BOLD
               << "║                  Your cart is empty! 📭                        ║\n";
          cout << "                                      " << YELLOW << BOLD
               << "║              Add items from the menu to start                  ║\n";
          cout << "                                      " << YELLOW << BOLD
               << "╚════════════════════════════════════════════════════════════════╝\n"
               << RESET;
          cond = false;
     }
     else
     {
          for (int i = 0; i < orderName.size(); i++)
          {
          cout << "                                      " << YELLOW << BOLD
               << "╔════════════════════════════════════════════════════════════════╗\n";
          

          cout << "                                      " << YELLOW << BOLD << "║ " << CYAN;
          cout << left << setw(62) << orderName[i];
          cout << YELLOW << " ║\n" << RESET;


          stringstream priceLine;
          priceLine << "$ $" << formatPrice(orderPrice[i]) << " × " << orderAmount[i] 
                    << " = $" << formatPrice(orderPrice[i] * orderAmount[i]);
          
          cout << "                                      " << YELLOW << BOLD << "║ " << GREEN;
          cout << left << setw(62) << priceLine.str();
          cout << YELLOW << "  ║\n" << RESET;

          cout << "                                      " << YELLOW << BOLD
               << "╚════════════════════════════════════════════════════════════════╝\n"
               << RESET;
          
          price = orderPrice[i] * orderAmount[i];
          float tax = (orderPrice[i] / 10) * orderAmount[i];
          totalTax += tax;
          total += price;
          }

          cout << endl;
          cout << "                                      " << CYAN << BOLD
               << "╔════════════════════════════════════════════════════════════════╗\n";


          stringstream subTotalLine;
          subTotalLine << "Sub-Total: $" << formatPrice(total);
          cout << "                                      " << CYAN << BOLD << "║ " << YELLOW << BOLD;
          cout << left << setw(62) << subTotalLine.str();
          cout << CYAN << " ║\n" << RESET;


          stringstream taxLine;
          taxLine << "Tax: $" << formatPrice(totalTax);
          cout << "                                      " << CYAN << BOLD << "║ " << YELLOW << BOLD;
          cout << left << setw(62) << taxLine.str();
          cout << CYAN << " ║\n" << RESET;

          stringstream totalLine;
          totalLine << "Total: $" << formatPrice(totalTax + total);
          cout << "                                      " << CYAN << BOLD << "║ " << YELLOW << BOLD;
          cout << left << setw(62) << totalLine.str();
          cout << CYAN << " ║\n" << RESET;

          cout << "                                      " << CYAN << BOLD
               << "╚════════════════════════════════════════════════════════════════╝\n"
               << RESET;
     }

     while (cond)
     {
          int option;
          cout << "                                      " << CYAN << BOLD
               << "╔════════════════════════════════════════════════════════════════╗\n";
          cout << "                                      " << CYAN << BOLD << "║   " << BLUE << "🗑️  1. " << TEXT << "Delete Item" << RESET << PRIMARY << "                                            ║\n"
               << RESET;
          cout << "                                      " << CYAN << BOLD << "║   " << GREEN << "✓  2. " << TEXT << "Confirm Order" << RESET << PRIMARY << "                                          ║\n"
               << RESET;
          cout << "                                      " << CYAN << BOLD << "║   " << RED << "↩️  0. " << TEXT << "Exit" << RESET << PRIMARY << "                                                   ║\n"
               << RESET;
          cout << "                                      " << CYAN << BOLD
               << "╚════════════════════════════════════════════════════════════════╝\n"
               << RESET;
          cout << "                                      " << RED << "Choose an Option : " << RESET;
          cin >> option;

          if (option == 0)
          {
               break;
          }

          switch (option)
          {
          case 1:
          {
               string deleteItem;
               cin.ignore();
               cout << "                                      " << RED << "Enter Item Name to Remove : " << RESET;
               getline(cin, deleteItem);
               bool found = false;
               for (int i = 0; i < orderName.size(); i++)
               {
                    if (orderName[i] == deleteItem)
                    {
                         found = true;
                         orderName.erase(orderName.begin() + i);
                         orderPrice.erase(orderPrice.begin() + i);
                         orderAmount.erase(orderAmount.begin() + i);
                         orderCategory.erase(orderCategory.begin() + i);
                         cout << "\n                                      " << GREEN << "✓ Item removed from cart successfully!\n"
                              << RESET;    
                         break;
                    }
               }
               if (!found)
               {
                    cout << "\n                                      " << RED << "⚠️  Item not found\n"
                         << RESET;
               }
               cond = false;
               break;
          }
          case 2:
          {
               string filename = "../../data/orderInfo.xlsx";
               vector<Order> orders = readExcelFromOrderInfoToVector(filename);

               string productInfo = "../../data/productInfo.xlsx";
               vector<Product> products = readExcelFromMenuInfoToVector(productInfo);
               string timestamp = getCurrentTimestamp();

               for (int i = 0; i < orderName.size(); i++)
               {
                    for (auto &product : products)
                    {
                         if (product.getItemName() == orderName[i])
                         {
                              int newAmount = product.getItemAmount() - orderAmount[i];
                              product.setItemAmount(newAmount);
                              break;
                         }
                    }
                    orders.emplace_back(orderName[i], orderPrice[i], orderAmount[i], orderCategory[i], timestamp);
               }

               writeExcelToOrderInfo(filename, orders);
               writeExcelToMenuInfo(productInfo, products);

               orderName.clear();
               orderPrice.clear();
               orderAmount.clear();
               orderCategory.clear();

               cout << "\n";
               cout << "                                      " << GREEN << BOLD
                    << "╔════════════════════════════════════════════════════════════════╗\n";
               cout << "                                      " << GREEN << BOLD
                    << "║               ✓ Order placed successfully! 🎉                  ║\n";
               cout << "                                      " << GREEN << BOLD << "║" << CYAN << "               📅 Order time:" << timestamp;
               int padding = 35 - timestamp.length();
               for (int j = 0; j < padding; j++)
                    cout << " ";
               cout << GREEN << "║\n"
                    << RESET;
               cout << "                                      " << GREEN << BOLD
                    << "║               Thank you for your order! 😊                     ║\n";
               cout << "                                      " << GREEN << BOLD
                    << "╚════════════════════════════════════════════════════════════════╝\n"
                    << RESET;
               cond = false;
               break;
          }
          default:
          {
               cout << "                                      " << RED << "⚠️  Invalid option\n"
                    << RESET;
               break;
          }
          }
     }

     cout << "\n";
     cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
     cin.ignore();
     cin.get();
}