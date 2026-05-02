#pragma once 

#include <iostream> 
#include <iomanip>
#include "clsScreen.h"
#include "clsCLientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsUtil.h"

using namespace std ;

class clsMainScreen : protected clsScreen
{ 
    private :

    enum enMainMenuOptions {eListClients = 1 , eAddNewClient = 2 , eDeleteClient = 3 , eUpdateClient = 4 
        , eFindClient = 5 , eShowTransactionsMenu = 6 , eManageUsers = 7 , eExit = 8 } ;
    
    static short _ReadMainMenuOption ()
    {
        short Choice = 1 ;
        cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 8 ]" ;
        cin >> Choice ;
        while (Choice < 1 || Choice > 8 )
        {
            cout <<  "Enter Number between 1 to 8 ? \n";
            Choice = clsInputValidate::ReadIntNumberBetween(1 , 8 , "Enter Number between 1 to 8 ? \n" );
        }
        return Choice ;

    }    
 
    static void _GoBackToMainMenu ()
    {
        cout << setw(37) << left << "" << "\n\tPress [ Enter ] to Main Menue ... \n" ;
        cin.ignore(numeric_limits<streamsize> :: max(), '\n') ;
        cin.get() ;
        
        ShowMainMenu() ;
        
    }

    static void _ShowAllClientsScreen ()
    {
        clsClientListScreen::ShowClientsList() ;
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::AddNewClient() ;
         
    }
   
    static void _ShowDeleteClientScreen()
    {
        clsDeleteCLientScreen::ShowDeleteClinetScreen();

    }
   
    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen() ;

    }
   
    static void _ShowFindClientScreen()
    {
       clsFindClientScreen::ShowFindCLientScreen() ;

    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenu();
    }

    static void _ShowManageUsersMenue()
    {
        cout << "\nUsers Menue Will be here...\n";

    }

    static void _ShowEndScreen()
    {
       cout << "\nEnd Screen Will be here...\n";

    }

    static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption )
    {
     switch (MainMenuOption)
     {
        
     case enMainMenuOptions::eListClients :
     {
         clsUtil::ResetScreen();
        _ShowAllClientsScreen();
        _GoBackToMainMenu();
        break;
     }

     case enMainMenuOptions::eAddNewClient:
     {
        clsUtil::ResetScreen();
        _ShowAddNewClientsScreen() ;
        _GoBackToMainMenu();
        break;
     }
     case enMainMenuOptions::eFindClient:
     {
        clsUtil::ResetScreen();
        _ShowFindClientScreen() ;
        _GoBackToMainMenu();
        break;
     }

     case enMainMenuOptions::eDeleteClient :
     {
        clsUtil::ResetScreen();
        _ShowDeleteClientScreen() ;
        _GoBackToMainMenu();
        break;
     }

     case enMainMenuOptions::eUpdateClient:
     {
        clsUtil::ResetScreen();
        _ShowUpdateClientScreen() ;
        _GoBackToMainMenu();
        break;
     }

     case enMainMenuOptions::eShowTransactionsMenu :
     {
        clsUtil::ResetScreen();
        _ShowTransactionsMenue();
        _GoBackToMainMenu();
        break;
     }

     case enMainMenuOptions::eManageUsers :
     {
        clsUtil::ResetScreen();
        _ShowManageUsersMenue();
        _GoBackToMainMenu();
        break;
     }

     case enMainMenuOptions::eExit:
    {
        clsUtil::ResetScreen();
        _ShowEndScreen();
                //Login();

                break;
    }
    }

     
    }
   
    public :

    static void ShowMainMenu ()
    {
            clsUtil::ResetScreen();
            _DrawScreenHeader("\t\tMain Screen" );

            cout << setw(37) << left << ""  << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            _PerformMainMenuOption( (enMainMenuOptions)_ReadMainMenuOption()) ;

    }

};
