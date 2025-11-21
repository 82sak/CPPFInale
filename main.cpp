#include <iostream>
#include <vector>
#include "ui/homepage.hpp"
#include "models/admin.hpp"
#include "models/menu.hpp"
#include "models/staff.hpp"
#include "models/user.hpp"
#include "models/excelUtils.hpp"
 
using namespace std;
int main(){
    system("cls");

    string filename = "../../data/userInfo.xlsx";
    vector<User> users = readExcelToVector(filename);

    loadingScreen();
    
    while(true){
        system("cls");
        int option;
        homePage();
        
        cout << "Choose an Option : ";
        cin >> option;
        
        if(option == 0){
            break;
        }
        switch(option){
            case 1:{
                // addmin function
                while(true){
                    system("cls");
                    int option;
                    displayAdminPage();

                    cout << "Choose an option : ";
                    cin >> option;
                    if(option == 0){
                        break;
                    }
                    switch (option){
                        case 1:{
                            while(true){
                                system("cls");
                                int option;
                                displayMenuManagementPage();
                                cout << "Choose an option : ";
                                cin >> option;
                                if(option == 0){
                                    break;
                                }
                                while(true){
                                    switch (option)
                                    {
                                    case 1:{
                                        
                                    }
                                        /* code */
                                        break;
                                    
                                    default:
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2: {
                            while(true){
                                system("cls");
                                int option;
                                displayStaffManagementPage();
                                cout << "Choose an option : ";
                                cin >> option;
                                if(option == 0){
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:{
                            //  Sales summary
                            break;
                        }
                        
                        default:
                            break;
                    }
                }
                break;
            }
            case 2:{
                // staff function
                while(true){
                    system("cls");
                    int option;
                    
                    displayStaffPage();
                    cout << "Choose an option : ";
                    cin >> option;
                    if(option == 0){
                        break;
                    }
                }
                break;
            }
            case 3:{
                // menu function
                while(true){
                    system("cls");
                    int option;
                    
                    displayMenuPage();
                    cout << "Choose an option : ";
                    cin >> option;
                    if(option == 0){
                        break;
                    }
                }
                // string userName;
                // string userPass;
                // cout << "add user : ";
                // cin >> userName;
                // cout << "add pass : ";
                // cin >> userPass;

                // users.emplace_back(userName, userPass);
                // writeExcel(filename, users);

                break;
            }
            default :{
                cout << "Invalide option";
            }
        }
    }
    

    return 0;
}