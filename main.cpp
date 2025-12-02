#define _HAS_STD_BYTE 0
#include <windows.h>
#include <iostream>
#include <vector>
#include "ui/homepage.hpp"
#include "models/admin.hpp"
#include "models/menu.hpp"
#include "models/staff.hpp"
#include "models/excelUtils.hpp"
#include "models/staffAccount.hpp"
#include "models/staffManagement.hpp"
#include "models/menuInfo.hpp"
#include "models/menuManagement.hpp"

using namespace std;

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

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    system("cls");

    loadingScreen();

    while (true)
    {
        system("cls");
        int option;
        homePage();

        cout << PRIMARY << "     ╰───➤ " << ACCENT << "Choose an Option : " << RESET;
        cin >> option;

        if (option == 0)
        {
            cout << "\n";
            cout << PRIMARY << "                                      ╭───────────────────────────────────────────────────────────────╮\n";
            cout << PRIMARY << "                                      │                                                               │\n";
            cout << PRIMARY << "                                      │  " << SUCCESS << BOLD << "Thank you for using our system!" << RESET << PRIMARY << "                              │\n";
            cout << PRIMARY << "                                      │  " << MUTED << DIM << "Goodbye!" << RESET << PRIMARY << "                                                     │\n";
            cout << PRIMARY << "                                      │                                                               │\n";
            cout << PRIMARY << "                                      ╰───────────────────────────────────────────────────────────────╯\n";
            cout << RESET << "\n";
            break;
        }
        switch (option)
        {
        case 1:
        {
            // adminAuth
            if (adminAuth())
            {
                while (true)
                {
                    // addmin function
                    system("cls");

                    int option;
                    displayAdminPage();

                    cout << PRIMARY << "     ╰───➤ " << ACCENT << "Choose an option : " << RESET;
                    cin >> option;

                    if (option == 0)
                    {
                        cout << "\n";
                        cout << PRIMARY << "                                      ╭────────────────────────────────────────────────────────────────╮\n";
                        cout << PRIMARY << "                                      │                                                                │\n";
                        cout << PRIMARY << "                                      │  " << WARNING << "Logging out from Admin Panel..." << RESET << PRIMARY << "                               │\n";
                        cout << PRIMARY << "                                      │                                                                │\n";
                        cout << PRIMARY << "                                      ╰────────────────────────────────────────────────────────────────╯\n";
                        cout << RESET;
                        cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    switch (option)
                    {
                    case 1:
                    {
                        // Menu Management
                        while (true)
                        {
                            system("cls");

                            int option;
                            displayMenuManagementPage();
                            cout << PRIMARY << "     ╰───➤ " << ACCENT << "Choose an option : " << RESET;
                            cin >> option;

                            if (option == 0)
                            {
                                cout << "\n";
                                cout << PRIMARY << "                                      ╭─────────────────────────────────────────────────────────────────╮\n";
                                cout << PRIMARY << "                                      │                                                                 │\n";
                                cout << PRIMARY << "                                      │  " << WARNING << "Returning to Admin Panel..." << RESET << PRIMARY << "                                    │\n";
                                cout << PRIMARY << "                                      │                                                                 │\n";
                                cout << PRIMARY << "                                      ╰─────────────────────────────────────────────────────────────────╯\n";
                                cout << RESET;
                                cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                                cin.ignore();
                                cin.get();
                                break;
                            }
                            switch (option)
                            {
                            case 1:
                            {
                                // Add new product
                                addNewProduct();
                                break;
                            }
                            case 2:
                            {
                                // update product
                                updateProduct();
                                break;
                            }
                            case 3:
                            {
                                // delete product
                                deleteProduct();
                                break;
                            }
                            case 4:
                            {
                                // show all product
                                showAllProduct();
                                break;
                            }
                            default:
                            {
                                cout << "\n";
                                cout << PRIMARY << "                                      ╭────────────────────────────────────────────────────────────────╮\n";
                                cout << PRIMARY << "                                      │                                                                │\n";
                                cout << PRIMARY << "                                      │  " << ERROR_COLOR << BOLD << "Invalid option!" << RESET << PRIMARY << "                                               │\n";
                                cout << PRIMARY << "                                      │  " << MUTED << DIM << "Please try again" << RESET << PRIMARY << "                                              │\n";
                                cout << PRIMARY << "                                      │                                                                │\n";
                                cout << PRIMARY << "                                      ╰────────────────────────────────────────────────────────────────╯\n";
                                cout << RESET;
                                cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                                cin.ignore();
                                cin.get();
                                break;
                            }
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        // Staff Management
                        while (true)
                        {
                            system("cls");
                            int option;
                            displayStaffManagementPage();
                            cout << PRIMARY << "     ╰───➤ " << ACCENT << "Choose an option : " << RESET;
                            cin >> option;
                            if (option == 0)
                            {
                                cout << "\n";
                                cout << PRIMARY << "                                      ╭─────────────────────────────────────────────────────────────────╮\n";
                                cout << PRIMARY << "                                      │                                                                 │\n";
                                cout << PRIMARY << "                                      │  " << WARNING << "Returning to Admin Panel..." << RESET << PRIMARY << "                                    │\n";
                                cout << PRIMARY << "                                      │                                                                 │\n";
                                cout << PRIMARY << "                                      ╰─────────────────────────────────────────────────────────────────╯\n";
                                cout << RESET;
                                cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                                cin.ignore();
                                cin.get();
                                break;
                            }
                            switch (option)
                            {
                            case 1:
                            {
                                // addNewStaffAccount();
                                addNewStaffAccount();
                                break;
                            }
                            case 2:
                            {
                                // update staff
                                updateStaffAccount();
                                break;
                            }
                            case 3:
                            {
                                // delete staff
                                deleteStaffAccount();
                                break;
                            }
                            case 4:
                            {
                                // show all staff
                                showAllStaff();
                                break;
                            }
                            default:
                                cout << "\n";
                                cout << PRIMARY << "                                      ╭──────────────────────────────────────────────────────────────────╮\n";
                                cout << PRIMARY << "                                      │                                                                  │\n";
                                cout << PRIMARY << "                                      │  " << ERROR_COLOR << BOLD << "Invalid option!" << RESET << PRIMARY << "                                                 │\n";
                                cout << PRIMARY << "                                      │  " << MUTED << DIM << "Please try again" << RESET << PRIMARY << "                                                │\n";
                                cout << PRIMARY << "                                      │                                                                  │\n";
                                cout << PRIMARY << "                                      ╰──────────────────────────────────────────────────────────────────╯\n";
                                cout << RESET;
                                cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                                cin.ignore();
                                cin.get();
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        //  Sales summary
                        while (true)
                        {
                            system("cls");
                            int option;
                            displaySalesSummary();
                            cout << PRIMARY << "     ╰───➤ " << ACCENT << "Choose an option : " << RESET;
                            cin >> option;
                            if (option == 0)
                            {
                                cout << "\n";
                                cout << PRIMARY << "                                       ╭────────────────────────────────────────────────────────────────╮\n";
                                cout << PRIMARY << "                                       │                                                                │\n";
                                cout << PRIMARY << "                                       │  " << WARNING << "Returning to Admin Panel..." << RESET << PRIMARY << "                                   │\n";
                                cout << PRIMARY << "                                       │                                                                │\n";
                                cout << PRIMARY << "                                       ╰────────────────────────────────────────────────────────────────╯\n";
                                cout << RESET;
                                cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                                cin.ignore();
                                cin.get();
                                break;
                            }
                            switch (option)
                            {
                            case 1:
                            {
                                // 24-hour report
                                showSummaryOneDay();
                                break;
                            }
                            case 2:
                            {
                                // 1week report
                                showSummaryOneWeek();
                                break;
                            }
                            case 3:
                            {
                                // 1month
                                showSummaryOneMonth();
                                break;
                            }
                            default:
                                cout << "\n";
                                cout << PRIMARY << "                              ╭─────────────────────────────────────────────────────────────────╮\n";
                                cout << PRIMARY << "                              │                                                                 │\n";
                                cout << PRIMARY << "                              │  " << ERROR_COLOR << BOLD << "Invalid option!" << RESET << PRIMARY << "                                             │\n";
                                cout << PRIMARY << "                              │  " << MUTED << DIM << "Please try again" << RESET << PRIMARY << "                                            │\n";
                                cout << PRIMARY << "                              │                                                                 │\n";
                                cout << PRIMARY << "                              ╰─────────────────────────────────────────────────────────────────╯\n";
                                cout << RESET;
                                cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                                cin.ignore();
                                cin.get();
                                break;
                            }
                        }
                        break;
                    }
                    default:
                        cout << "\n";
                        cout << PRIMARY << "                                      ╭────────────────────────────────────────────────────────────────╮\n";
                        cout << PRIMARY << "                                      │                                                                │\n";
                        cout << PRIMARY << "                                      │  " << ERROR_COLOR << BOLD << "Invalid option!" << RESET << PRIMARY << "                                               │\n";
                        cout << PRIMARY << "                                      │  " << MUTED << DIM << "Please try again" << RESET << PRIMARY << "                                              │\n";
                        cout << PRIMARY << "                                      │                                                                │\n";
                        cout << PRIMARY << "                                      ╰────────────────────────────────────────────────────────────────╯\n";
                        cout << RESET;
                        cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                }
            }
            break;
        }
        case 2:
        {
            // Auth
            // staff function
            if (staffAuth())
            {
                while (true)
                {
                    system("cls");
                    int option;

                    displayStaffPage();
                    cout << PRIMARY << "     ╰───➤ " << ACCENT << "Choose an option : " << RESET;
                    cin >> option;
                    if (option == 0)
                    {
                        cout << "\n";
                        cout << PRIMARY << "                                 ╭───────────────────────────────────────────────────────────────────╮\n";
                        cout << PRIMARY << "                                 │                                                                   │\n";
                        cout << PRIMARY << "                                 │  " << WARNING << "    Logging out from Staff Panel..." << RESET << PRIMARY << "                              │\n";
                        cout << PRIMARY << "                                 │                                                                   │\n";
                        cout << PRIMARY << "                                 ╰───────────────────────────────────────────────────────────────────╯\n";
                        cout << RESET;
                        cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                    switch (option)
                    {
                    case 1:
                    {
                        // show menu
                        showMenu();
                        break;
                    }
                    case 2:
                    {
                        // show receipt
                        showReceipt();
                        break;
                    }
                    default:
                    {
                        cout << "\n";
                        cout << PRIMARY << "                                      ╭─────────────────────────────────────────────────────────────────╮\n";
                        cout << PRIMARY << "                                      │                                                                 │\n";
                        cout << PRIMARY << "                                      │  " << ERROR_COLOR << BOLD << "Invalid option!" << RESET << PRIMARY << "                                                │\n";
                        cout << PRIMARY << "                                      │  " << MUTED << DIM << "Please try again" << RESET << PRIMARY << "                                               │\n";
                        cout << PRIMARY << "                                      │                                                                 │\n";
                        cout << PRIMARY << "                                      ╰─────────────────────────────────────────────────────────────────╯\n";
                        cout << RESET;
                        cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                        cin.ignore();
                        cin.get();
                    }
                    }
                }
            }
            break;
        }
        case 3:
        {
            // menu function
            while (true)
            {
                system("cls");
                int option;

                displayMenuPage();
                cout << PRIMARY << "     ╰───➤ " << ACCENT << "Choose an option : " << RESET;
                cin >> option;
                if (option == 0)
                {
                    cout << "\n";
                    cout << PRIMARY << "                                        ╭────────────────────────────────────────────────────────────────╮\n";
                    cout << PRIMARY << "                                        │                                                                │\n";
                    cout << PRIMARY << "                                        │  " << WARNING << "Returning to Main Menu..." << RESET << PRIMARY << "                                     │\n";
                    cout << PRIMARY << "                                        │                                                                │\n";
                    cout << PRIMARY << "                                        ╰────────────────────────────────────────────────────────────────╯\n";
                    cout << RESET;
                    cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                    cin.ignore();
                    cin.get();
                    break;
                }
                switch (option)
                {
                case 1:
                {
                    // display category
                    while (true)
                    {
                        system("cls");
                        int option;

                        displayCategory();
                        cout << PRIMARY << "     ╰───➤ " << ACCENT << "Choose an Option : " << RESET;
                        cin >> option;
                        if (option == 0)
                        {
                            cout << "\n";
                            cout << PRIMARY << "                                     ╭─────────────────────────────────────────────────────────────╮\n";
                            cout << PRIMARY << "                                     │                                                             │\n";
                            cout << PRIMARY << "                                     │  " << WARNING << "Returning to Menu..." << RESET << PRIMARY << "                                       │\n";
                            cout << PRIMARY << "                                     │                                                             │\n";
                            cout << PRIMARY << "                                     ╰─────────────────────────────────────────────────────────────╯\n";
                            cout << RESET;          
                            cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                            cin.ignore();
                            cin.get();
                            break;
                        }
                        switch (option)
                        {
                        case 1:
                        {
                            // Food
                            displayFood();
                            break;
                        }
                        case 2:
                        {
                            // drink
                            displayDrink();
                            break;
                        }

                        default:
                            cout << "\n";
                            cout << PRIMARY << "                                     ╭────────────────────────────────────────────────────────────────╮\n";
                            cout << PRIMARY << "                                     │                                                                │\n";
                            cout << PRIMARY << "                                     │  " << ERROR_COLOR << BOLD << "Invalid option!" << RESET << PRIMARY << "                                               │\n";
                            cout << PRIMARY << "                                     │  " << MUTED << DIM << "Please try again" << RESET << PRIMARY << "                                              │\n";
                            cout << PRIMARY << "                                     │                                                                │\n";
                            cout << PRIMARY << "                                     ╰────────────────────────────────────────────────────────────────╯\n";
                            cout << RESET;
                            cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    }
                    break;
                }
                case 2:
                {
                    // cart
                    displayCart();
                    break;
                }
                default:
                    cout << "\n";
                    cout << PRIMARY << "                                      ╭─────────────────────────────────────────────────────────────────╮\n";
                    cout << PRIMARY << "                                      │                                                                 │\n";
                    cout << PRIMARY << "                                      │  " << ERROR_COLOR << BOLD << "Invalid option!" << RESET << PRIMARY << "                                                │\n";
                    cout << PRIMARY << "                                      │  " << MUTED << DIM << "Please try again" << RESET << PRIMARY << "                                               │\n";
                    cout << PRIMARY << "                                      │                                                                 │\n";
                    cout << PRIMARY << "                                      ╰─────────────────────────────────────────────────────────────────╯\n";
                    cout << RESET;
                    cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
                    cin.ignore();
                    cin.get();
                    break;
                }
            }

            break;
        }
        default:
        {
            cout << "\n";
            cout << PRIMARY << "                                     ╭────────────────────────────────────────────────────────────────╮\n";
            cout << PRIMARY << "                                     │                                                                │\n";
            cout << PRIMARY << "                                     │  " << ERROR_COLOR << BOLD << "Invalid option!" << RESET << PRIMARY << "                                            │\n";
            cout << PRIMARY << "                                     │  " << MUTED << DIM << "Please try again" << RESET << PRIMARY << "                                           │\n";
            cout << PRIMARY << "                                     │                                                                │\n";
            cout << PRIMARY << "                                     ╰────────────────────────────────────────────────────────────────╯\n";
            cout << RESET;
            cout << "\n     " << MUTED << DIM << "Press Enter to continue..." << RESET;
            cin.ignore();
            cin.get();
        }
        }
    }

    return 0;
}