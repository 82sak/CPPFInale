#include "models/staffManagement.hpp"
#include "models/excelUtils.hpp"
#include "models/staffAccount.hpp"
#include <iostream>
#include <vector>
#include <conio.h>
// #include <tabulate/table.hpp>

using namespace std;
// using namespace tabulate;

// Modern color scheme
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

void addNewStaffAccount()
{
    string filename = "../../data/staffInfo.xlsx";
    vector<User> users = readExcelFromStaffInfoToVector(filename);

    string userName;
    string userPass;
    string fullName;
    string gender;
    int age;

    system("cls");
    cout << "\n\n";
    cout << PRIMARY << "     ╔════════════════════════════════════════════════════════════════╗\n";
    cout << PRIMARY << "     ║                                                                ║\n";
    cout << PRIMARY << "     ║  " << BOLD << ACCENT << "               📁  Add New Staff Account 📁" << RESET << PRIMARY << "                   ║\n";
    cout << PRIMARY << "     ║                                                                ║\n";
    cout << PRIMARY << "     ╚════════════════════════════════════════════════════════════════╝\n";
    cout << RESET << "\n";

    cin.ignore();
    cout << "     " << ACCENT << "Enter Staff's account Name : " << RESET;
    getline(cin, userName);
    cout << "     " << ACCENT << "Enter Staff's account Password : " << RESET;
    getline(cin, userPass);
    cout << "     " << ACCENT << "Enter Staff Full Name : " << RESET;
    getline(cin, fullName);
    cout << "     " << ACCENT << "Enter Staff Gender : " << RESET;
    getline(cin, gender);
    cout << "     " << ACCENT << "Enter Staff Age : " << RESET;
    cin >> age;

    users.emplace_back(userName, userPass, fullName, gender, age);
    writeExcelToStaffInfo(filename, users);

    cout << "\n     " << SUCCESS << BOLD << "✅ Staff account added successfully!\n"
         << RESET;
    cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
}

void updateStaffAccount()
{
    string filename = "../../data/staffInfo.xlsx";
    vector<User> users = readExcelFromStaffInfoToVector(filename);

    string updateName;
    string newUserFullName;
    string newUserGender;
    int newUserAge;

    system("cls");
    cout << "\n\n";
    cout << PRIMARY << "     ╔════════════════════════════════════════════════════════════════╗\n";
    cout << PRIMARY << "     ║                                                                ║\n";
    cout << PRIMARY << "     ║  " << BOLD << ACCENT << "              🪄  Update Staff Account 🪄" << RESET << PRIMARY << "                       ║\n";
    cout << PRIMARY << "     ║                                                                ║\n";
    cout << PRIMARY << "     ╚════════════════════════════════════════════════════════════════╝\n";
    cout << RESET << "\n";

    cin.ignore();
    cout << "     " << ACCENT << "Enter Staff's account Name to Update : " << RESET;
    getline(cin, updateName);

    bool found = false;
    for (auto &user : users)
    {
        if (user.getUserName() == updateName)
        {
            found = true;
            cout << "\n     " << SUCCESS << BOLD << "User found!\n"
                 << RESET;
            cout << "     " << SECONDARY << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
                 << RESET;
            cout << "     " << ACCENT << "Name: " << TEXT << user.getUserFullName() << RESET << "\n";
            cout << "     " << ACCENT << "Gender: " << TEXT << user.getUserGender() << RESET << "\n";
            cout << "     " << ACCENT << "Age: " << TEXT << user.getUserAge() << RESET << "\n";
            cout << "     " << SECONDARY << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
                 << RESET;
            cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
            cin.get();

            system("cls");
            cout << "\n\n";
            cout << PRIMARY << "     ╔════════════════════════════════════════════════════════════════╗\n";
            cout << PRIMARY << "     ║                                                                ║\n";
            cout << PRIMARY << "     ║  " << BOLD << ACCENT << "              🌙 Enter New Details 🌙" << RESET << PRIMARY << "                         ║\n";
            cout << PRIMARY << "     ║                                                                ║\n";
            cout << PRIMARY << "     ╚════════════════════════════════════════════════════════════════╝\n";
            cout << RESET << "\n";

            cout << "     " << ACCENT << "Enter Staff Full Name : " << RESET;
            getline(cin, newUserFullName);
            cout << "     " << ACCENT << "Enter Staff Gender : " << RESET;
            getline(cin, newUserGender);
            cout << "     " << ACCENT << "Enter Staff Age : " << RESET;
            cin >> newUserAge;

            user.setUserFullName(newUserFullName);
            user.setUserGender(newUserGender);
            user.setUserAge(newUserAge);

            writeExcelToStaffInfo(filename, users);
            cout << "\n     " << SUCCESS << BOLD << "✅ Staff account updated successfully!\n"
                 << RESET;
            cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
            cin.ignore();
            cin.get();
            break;
        }
    }
    if (!found)
    {
        cout << "\n     " << ERROR << BOLD << "User not found!\n"
             << RESET;
        cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
        cin.get();
    }
}

void deleteStaffAccount()
{
    string filename = "../../data/staffInfo.xlsx";
    vector<User> users = readExcelFromStaffInfoToVector(filename);

    string deleteStaff;

    system("cls");
    cout << "\n\n";
    cout << PRIMARY << "     ╔════════════════════════════════════════════════════════════════╗\n";
    cout << PRIMARY << "     ║                                                                ║\n";
    cout << PRIMARY << "     ║  " << BOLD << ERROR << "                🌑  Delete Staff Account  🌑" << RESET << PRIMARY << "                  ║\n";
    cout << PRIMARY << "     ║                                                                ║\n";
    cout << PRIMARY << "     ╚════════════════════════════════════════════════════════════════╝\n";
    cout << RESET << "\n";

    cin.ignore();
    cout << "     " << ACCENT << "Enter Staff's Name to Delete : " << RESET;
    getline(cin, deleteStaff);

    bool found = false;
    for (auto it = users.begin(); it != users.end(); it++)
    {
        if (it->getUserName() == deleteStaff)
        {
            found = true;
            users.erase(it);
            cout << "\n     " << SUCCESS << BOLD << "Staff's account deleted successfully!\n"
                 << RESET;
            break;
        }
    }
    if (!found)
    {
        cout << "\n     " << ERROR << BOLD << "Staff's account not found!\n"
             << RESET;
    }
    writeExcelToStaffInfo(filename, users);
    cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
    cin.get();
}

// void showAllStaff(const vector<User> &users){
//     Table table;
//     table.add_row({"Staff's Account Name","fullName", "Gender", "Age"});
//     for(const auto &user : users){
//         table.add_row({user.getUserName(), user.getUserFullName(), user.getUserGender(), to_string(user.getUserAge())});
//     }
//     table[0].format().font_style({FontStyle::bold});
//     cout << table << endl;
// };

void showAllStaff()
{
    string filename = "../../data/staffInfo.xlsx";
    vector<User> users = readExcelFromStaffInfoToVector(filename);

    system("cls");
    cout << "\n\n";
    cout << PRIMARY << "     ╔════════════════════════════════════════════════════════════════╗\n";
    cout << PRIMARY << "     ║                                                                ║ \n";
    cout << PRIMARY << "     ║   " << BOLD << ACCENT << "               👥  ALL STAFF ACCOUNTS 👥" << RESET << PRIMARY << "                     ║ \n";
    cout << PRIMARY << "     ║                                                                ║ \n";
    cout << PRIMARY << "     ╚════════════════════════════════════════════════════════════════╝\n";
    cout << RESET << "\n";

    if (users.empty())
    {
        cout << "     " << ERROR << "No staff accounts found!\n"
             << RESET;
    }
    else
    {
        int count = 1;
        for (const auto &user : users)
        {
            cout << "     " << SUCCESS << BOLD << "[" << count << "] " << TEXT << user.getUserFullName() << RESET << "\n";
            cout << "         " << ACCENT << "Username: " << SECONDARY << user.getUserName() << RESET << "\n";
            cout << "         " << ACCENT << "Gender: " << SECONDARY << user.getUserGender() << RESET << "\n";
            cout << "         " << ACCENT << "Age: " << SECONDARY << user.getUserAge() << RESET << "\n";
            cout << "\n";
            count++;
        }
        cout << "     " << WARNING << BOLD << "Total Staff: " << TEXT << users.size() << RESET << "\n";
    }

    cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
}
inline string maskingPassword(){
    string password = "";
    char ch;
    
    while (true) {
        ch = _getch(); 
        
        if (ch == 13) { 
            cout << endl;
            break;
        }
        else if (ch == 8) {
            if (!password.empty()) {
                password.pop_back(); 
                cout << "\b \b"; 
            }
        }
        else {
            password += ch;  
            cout << '*'; 
        }
    }
    
    return password;
}

bool staffAuth()
{
    string filename = "../../data/staffInfo.xlsx";
    vector<User> users = readExcelFromStaffInfoToVector(filename);

    int attempts = 3;

    while (attempts > 0)
    {
        system("cls");
        cout << "\n\n";
        cout << PRIMARY << "     ╔════════════════════════════════════════════════════════════════╗\n";
        cout << PRIMARY << "     ║                                                                ║ \n";
        cout << PRIMARY << "     ║   " << BOLD << ACCENT << "                    🪛  STAFF LOGIN 🪛" << RESET << PRIMARY << "                         ║ \n";
        cout << PRIMARY << "     ║                                                                ║ \n";
        cout << PRIMARY << "     ╚════════════════════════════════════════════════════════════════╝\n";
        cout << RESET << "\n";
        cout << "     " << WARNING << "Attempts remaining: " << (attempts == 1 ? ERROR : WARNING) << attempts << RESET << "\n\n";

        string userName;
        string userPass;

        cin.ignore();
        cout << "     " << ACCENT << "Enter Username: " << RESET;
        getline(cin, userName) ;
        cout << "     " << ACCENT << "Enter Password: " << RESET;
        userPass = maskingPassword();

        // Check if credentials match any staff
        bool found = false;
        for (const auto &user : users)
        {
            if (user.getUserName() == userName && user.getUserPass() == userPass)
            {
                found = true;
                cout << "\n     " << SUCCESS << BOLD <<"Login successful!\n"
                     << RESET;
                cout << "     " << TEXT << "Welcome🤖, " << ACCENT << user.getUserFullName() << TEXT << "!\n"
                     << RESET;
                cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                cin.get();
                return true; // Login successful
            }
        }

        // If not found
        if (!found)
        {
            attempts--;
            if (attempts > 0)
            {
                cout << "\n     " << ERROR << BOLD << "Invalid username or password!\n"
                     << RESET;
                cout << "     " << WARNING << "Attempts remaining: " << (attempts == 1 ? ERROR : WARNING) << attempts << RESET << "\n";
                cout << "\n     " << MUTED << DIM << "Press Enter to try again..." << RESET;
                cin.get();
            }
            else
            {
                cout << "\n     " << ERROR << BOLD << "✗ Login failed! No attempts remaining.\n"
                     << RESET;
                cout << "\n     " << MUTED << DIM << "Press Enter to return..." << RESET;
                cin.get();
            }
        }
    }

    return false; // Login failed after 3 attempts
}