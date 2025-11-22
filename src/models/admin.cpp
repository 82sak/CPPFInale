#include "models/admin.hpp"
#include <iostream>

using namespace std;

#define RESET   "\033[0m"
#define BLUE   "\033[34m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define BOLD    "\033[1m"

void displayAdminPage(){
    cout << GREEN << BOLD <<"\t\t\t=================================\n";
    cout << GREEN << BOLD << "\t\t\t|      WELCOME TO ADMIN PANEL   |\n";
    cout << GREEN << BOLD << "\t\t\t=================================\n";
    cout << BLUE << BOLD << "\t\t\t1. Menu Management\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t2. Staff Management\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t3. Sales Summary\n" << RESET;
    cout << RED  << BOLD << "\t\t\t0. Exit\n" << RESET;
}
void displayMenuManagementPage(){
    cout << GREEN << BOLD <<" \t\t\t=====================================\n";
    cout << GREEN << BOLD << "\t\t\t|      WELCOME TO MENU MANAGEMENT   |\n";
    cout << GREEN << BOLD << "\t\t\t=====================================\n";
    cout << BLUE << BOLD << "\t\t\t1. Add new Products\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t2. Update Product\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t3. Delete Products\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t4. Show all Products\n" << RESET;
    cout << RED  << BOLD << "\t\t\t0. Exit\n" << RESET;
}
void displayStaffManagementPage(){
    cout << GREEN << BOLD <<"\t\t\t=======================================\n";
    cout << GREEN << BOLD << "\t\t\t|      WELCOME TO STAFF MANAGEMENT   |\n";
    cout << GREEN << BOLD << "\t\t\t======================================\n";
    cout << BLUE << BOLD << "\t\t\t1. Add new Staff Accounts\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t2. Update Staff Information\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t3. Delete Staff Accounts\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t4. Show all Staff Information\n" << RESET;
    cout << RED  << BOLD << "\t\t\t0. Exit\n" << RESET;
}