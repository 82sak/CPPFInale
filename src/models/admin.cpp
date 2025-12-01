#include "models/admin.hpp"
#include <iostream>
#include <windows.h>

using namespace std;

#define RESET "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BOLD "\033[1m"

void displayAdminPage()
{
    cout << BLUE << BOLD << "                                     ▟▀▙═══════════════════════════════════════════════════════════════╗" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << GREEN << "              ✨ WELCOME TO ADMIN PANEL ✨" << RESET << BLUE << BOLD << "                      ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ╠═══════════════════════════════════════════════════════════════▟▀▙" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "             🧩  1. Menu Management" << RESET << BLUE << BOLD << "                             ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "             👥  2. Staff Management" << RESET << BLUE << BOLD << "                            ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "             📊  3. Sales Summary" << RESET << BLUE << BOLD << "                               ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << RED << "             🌀  0. Exit" << RESET << BLUE << BOLD << "                                        ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ╚════════════════════════════════════════════════════════════════╝" << RESET << endl;
}

void displayMenuManagementPage()
{
    cout << BLUE << BOLD << "                                     ▟▀▙═══════════════════════════════════════════════════════════════╗" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << GREEN << "                   🍔 MENU MANAGEMENT 🍔" << RESET << BLUE << BOLD << "                        ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ╠═══════════════════════════════════════════════════════════════▟▀▙" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "             ➕  1. Add new Products" << RESET << BLUE << BOLD << "                            ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "             ✏️   2. Update Product" << RESET << BLUE << BOLD << "                              ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "             ❌  3. Delete Products" << RESET << BLUE << BOLD << "                             ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "             📋  4. Show all Products" << RESET << BLUE << BOLD << "                           ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << RED << "             🌀  0. Exit" << RESET << BLUE << BOLD << "                                        ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ╚════════════════════════════════════════════════════════════════╝" << RESET << endl;
}

void displayStaffManagementPage()
{
    cout << BLUE << BOLD << "                                     ▟▀▙═══════════════════════════════════════════════════════════════╗" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << GREEN << "             👥 WELCOME TO STAFF MANAGEMENT 👥" << RESET << BLUE << BOLD << "                  ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ╠═══════════════════════════════════════════════════════════════▟▀▙" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "             ➕  1. Add new Staff Accounts" << RESET << BLUE << BOLD << "                      ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "             ✏️   2. Update Staff Information" << RESET << BLUE << BOLD << "                    ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "             ❌  3. Delete Staff Accounts" << RESET << BLUE << BOLD << "                       ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "             📋  4. Show all Staff Information" << RESET << BLUE << BOLD << "                  ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << RED << "             🌀  0. Exit" << RESET << BLUE << BOLD << "                                        ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ╚════════════════════════════════════════════════════════════════╝" << RESET << endl;
}

void displaySalesSummary()
{
    cout << BLUE << BOLD << "                                     ▟▀▙═══════════════════════════════════════════════════════════════╗" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << GREEN << "                     📊 SALES SUMMARY 📊" << RESET << BLUE << BOLD << "                        ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ╠═══════════════════════════════════════════════════════════════▟▀▙" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "                      1. 1 Day" << RESET << BLUE << BOLD << "                                     ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "                      2. 1 Week" << RESET << BLUE << BOLD << "                                    ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << YELLOW << "                      3. 1 Month" << RESET << BLUE << BOLD << "                                   ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ║" << RED << "                     🌀  0. Exit" << RESET << BLUE << BOLD << "                                   ║" << RESET << endl;
    cout << BLUE << BOLD << "                                      ╚════════════════════════════════════════════════════════════════╝" << RESET << endl;
}