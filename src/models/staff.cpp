#include "models/staff.hpp"
#include <iostream>

using namespace std;

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

void displayStaffPage(){
    cout << GREEN << BOLD << "\t\t\t=================================\n";
    cout << GREEN << BOLD << "\t\t\t|      WELCOME TO STAFF PANEL   |\n";
    cout << GREEN << BOLD << "\t\t\t=================================\n";
    cout << BLUE << BOLD << "\t\t\t1. Show Menu\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t2. Show Receipt\n" << RESET;
    cout << RED  << BOLD << "\t\t\t0. Exit\n" << RESET;
}