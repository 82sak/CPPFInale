#include "ui/homepage.hpp"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

#define RESET   "\033[0m"
#define BLUE   "\033[34m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define BOLD    "\033[1m"


void homePage(){
    cout << CYAN <<  R"(                      
     _____                       _____            _                        
    /  ___|                     |  ___|          (_)             _     _   
    \ `--.  ___ _ ____   _____  | |__ _ __   __ _ _ _ __   ___ _| |_ _| |_ 
     `--. \/ _ \ '__\ \ / / _ \ |  __| '_ \ / _` | | '_ \ / _ \_   _|_   _|
    /\__/ /  __/ |   \ V /  __/ | |__| | | | (_| | | | | |  __/ |_|   |_|  
    \____/ \___|_|    \_/ \___| \____/_| |_|\__, |_|_| |_|\___|            
                                             __/ |                         
                                            |___/                          
    )" << endl;
    cout << GREEN << BOLD <<"\t\t\t=================================\n";
    cout << GREEN << BOLD << "\t\t\t|      WELCOME TO SERVEENGINE   |\n";
    cout << GREEN << BOLD << "\t\t\t=================================\n";
    cout << BLUE << BOLD << "\t\t\t1. Admin Panel\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t2. Staff Panel\n" << RESET;
    cout << BLUE << BOLD << "\t\t\t3. Menu\n" << RESET;
    cout << RED  << BOLD << "\t\t\t0. Exit\n" << RESET;
}

void loadingScreen() {
    string stages[] = {
        "Initializing system",
        "Loading resources",
        "Preparing interface",
        "Almost ready"
    };
    
    for (const auto& stage : stages) {
        cout << "\n\t\t" << YELLOW << BOLD << stage;
        for (int i = 0; i < 3; i++) {
            cout << "." << flush;
            this_thread::sleep_for(chrono::milliseconds(300));
        }
        cout << " done";
    }
    cout << "\n\n\t\tReady!\n";
    system("cls");
}





