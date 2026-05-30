#pragma once 

#include <iostream> 
#include <iomanip>
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsUtil.h"

using namespace std ;

class clsTransactionsScreen : protected clsScreen 
{

private :



enum enTransactionsMenuOptions {eDeposit = 1 , eWithdraw = 2 , eTotalBalances = 3 , eTransfer = 4 , eTransferLog = 5 ,  eTrMainMenu = 6 };

static void _GoBackToMainMenu ()
{
    cout << setw(37) << left << "" << "\n\tPress [ Enter ] to Main Menue ... \n" ;
    cin.ignore(numeric_limits<streamsize> :: max(), '\n') ;
    cin.get() ;
        
    ShowTransactionsMenu() ;
        
}

static void _ShowDepositScreen ()
{
  clsDepositScreen::ShowDepositScreen();
}

static void _ShowWithDrawScreen ()
{
  clsWithdrawScreen::ShowWithdrawScreen();
}

static void _ShowTatalBalanceScreen()
{
  clsTotalBalancesScreen::ShowTotalBalancesScreen();
}

static void _ShowTransferScreen()
{
  clsTransferScreen::ShowTransferScreen();
}

static void _ShowTransferLog()
{
  clsTransferLogScreen::ShowTransferLogScreen();
}

static void PerformTransactionsMenuOptions (enTransactionsMenuOptions Option)
{
    switch (Option)
    {
    case enTransactionsMenuOptions::eDeposit:
    {
       clsUtil::ResetScreen();
       _ShowDepositScreen();
       _GoBackToMainMenu ();  
      break;  
    }
    
    case enTransactionsMenuOptions::eWithdraw:
    {
        clsUtil::ResetScreen();
        _ShowWithDrawScreen();
        _GoBackToMainMenu (); 
      break;  
    }

    case enTransactionsMenuOptions::eTotalBalances: 
    {
       clsUtil::ResetScreen();
       _ShowTatalBalanceScreen();
       _GoBackToMainMenu (); 
       break;  
    }

    case enTransactionsMenuOptions::eTransferLog:
    {
       clsUtil::ResetScreen();
       _ShowTransferLog();
       _GoBackToMainMenu (); 
       break;  
    }

    case enTransactionsMenuOptions::eTransfer: 
    {
       clsUtil::ResetScreen();
       _ShowTransferScreen();
       _GoBackToMainMenu (); 
       break;  
    }

    case enTransactionsMenuOptions::eTrMainMenu:
    {
      //cout << "do nothing untill we handle it ";
        
    }
    
    default:
        break;
    }

}

static short ReadTransactionsMenuOption ()
{
    
        short Choice = 1 ;
        cout << setw(37) << left << "" << "Choose what do you want to do ? [ 1 to 6 ]" ;
        cin >> Choice ;
        while (Choice < 1 || Choice > 6 )
        {
            cout <<  "Enter Number between 1 to 6 ? \n";
            Choice = clsInputValidate::ReadIntNumberBetween(1 , 5 , "Enter Number between 1 to 6 ? \n" );
        }
        return Choice ;

}

public :

void static ShowTransactionsMenu ()
{
    if (!CheckAccessRights(clsUser::enPermissions::PTransactions))
    {
      return ;
    }

    clsUtil::ResetScreen() ;
    clsScreen::_DrawScreenHeader("\t Transactios Menu Screen") ;

        cout << setw(37) << left << ""  << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t   Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log .\n";
        cout << setw(37) << left << "" << "\t[6] MainMenu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        PerformTransactionsMenuOptions((enTransactionsMenuOptions) ReadTransactionsMenuOption());
}




};