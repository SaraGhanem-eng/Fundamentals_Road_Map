#pragma once 

#include <iostream>
#include "clsScreen.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculatorScreen.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsUtil.h"

class clsCurrencyExchangeScreen : protected clsScreen 
{
private :

enum enCurrencyExchangeMenuOption {eCurrencyList = 1 , eFindCurrency = 2 , eUpdateRate = 3 
    , eCurrencyCalculator = 4 , eMainMenu = 5 } ;

static short _ReadCurrencyExchangeMenuOption ()
{
        short Choice = 1 ;
        cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 5 ]" ;
        cin >> Choice ;
        while (Choice < 1 || Choice > 5 )
        {
            Choice = clsInputValidate::ReadIntNumberBetween(1 , 5 , "Enter Number between 1 to 5 ? \n" );
        }
        return Choice ;    
}    

static void _GoBackToCurrencyMenu ()
{
    cout <<  "\n\nPress [ Enter ] to Currency Menu ... \n" ;
    cin.ignore(numeric_limits<streamsize> ::max() , '\n' );
    cin.get() ;
        
    ShowCurrencyExchangeScreen() ;
        
}

static void _ShowCurrenciesList()
{
  clsCurrencyListScreen::ShowCurrenciesListScreen();
}

static void _ShowFindCurrencyScreen ()
{
  clsFincCurrency::ShowFindCurrencyScreen();
}

static void _ShowUpdateCurrencyScreen()
{
  clsUpdatCurrencyRate::ShowUpdateCurrencyRateScreen();
}

static void _ShowCurrencyCalculatorScreen()
{
  clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
}

static void _PerformCurrencyExchangeMenuOption(enCurrencyExchangeMenuOption Option)
{


  switch (Option)
  {

  case eCurrencyList:
  {
   clsUtil::ResetScreen();
   _ShowCurrenciesList();
   _GoBackToCurrencyMenu();
   break;
  }  

  case eFindCurrency:
  {
   clsUtil::ResetScreen(); 
   _ShowFindCurrencyScreen();
   _GoBackToCurrencyMenu();
   break;
  } 

  case eCurrencyCalculator:
  {
   clsUtil::ResetScreen(); 
   _ShowCurrencyCalculatorScreen();
   _GoBackToCurrencyMenu();
   break;
  } 

  case eUpdateRate:
  {
   clsUtil::ResetScreen(); 
   _ShowUpdateCurrencyScreen();
   _GoBackToCurrencyMenu();
   break;
  } 

  case eMainMenu:
  {
   clsUtil::ResetScreen(); 
   break;
  } 
  
  default:
    break;
  }
}
public :

static void ShowCurrencyExchangeScreen ()
{
    clsUtil::ResetScreen();

    clsScreen::_DrawScreenHeader("    Currency Exchange Main Menu");

    cout << setw(37) << left << ""  << "===========================================\n";
    cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] Currencies List.\n";
    cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
    cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
    cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
    cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
    cout << setw(37) << left << "" << "===========================================\n";
    _PerformCurrencyExchangeMenuOption(enCurrencyExchangeMenuOption (_ReadCurrencyExchangeMenuOption()));

}
};