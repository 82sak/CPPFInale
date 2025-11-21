#include "models/menu.hpp"
#include <iostream>

using namespace std;

#define RESET   "\033[0m"
#define BLUE   "\033[34m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define BOLD    "\033[1m"

void displayMenuPage(){
    cout << GREEN << BOLD << "\t\t\t=================================\n";
    cout << GREEN << BOLD << "\t\t\t|          WELCOME TO MENU      |\n";
    cout << GREEN << BOLD << "\t\t\t=================================\n";
    cout << BLUE << BOLD << "\t\t\t1. Menu\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t2. Cart\n" << RESET;
    cout << RED  << BOLD << "\t\t\t0. Exit\n" << RESET;
}