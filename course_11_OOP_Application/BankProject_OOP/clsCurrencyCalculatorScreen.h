#pragma once 

#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsUtil.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"

class clsCurrencyCalculatorScreen : protected clsScreen 
{
private :

static void _PrintCurrencyCard(clsCurrency Currency , string Title )
{
    cout << "\n" << Title << endl;
    cout << "________________________________\n" << endl;
    cout << "Country  : " << Currency.Country() << endl;
    cout << "Code     : " << Currency.CurrencyCode() << endl;
    cout << "Name     : " << Currency.CurrencyName() << endl;
    cout << "Rate(1$) : " << Currency.Rate() << endl << endl ;
    cout << "________________________________\n\n" << endl;
}

static clsCurrency _GetCurrencyRecord (short CRNum = 1 )
{
    string CurrencyCode ;
    cout << "\nPlease Enter Currency " << CRNum <<  " Code " ;
    CurrencyCode = clsInputValidate::ReadString();
     
    clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

    while (Currency.IsEmpty())
    {
        cout << "\nCurrency with this code does not exist .. enter another code ";
        CurrencyCode = clsInputValidate::ReadString();
        Currency = clsCurrency::FindByCode(CurrencyCode);
        
    }
    return Currency ;

}

static double _ReadAmount ()
{
    double Amount ;
    cout << "\nEnter Amount to exchange : " ;
    Amount = clsInputValidate::ReadDblNumber();
    return Amount ;
}

static void _PrintCalculationsResult (clsCurrency Currency1 , clsCurrency Currency2 , double Amount )
{


    _PrintCurrencyCard(Currency1 ,"Convert From : " );
    cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " 
    << Currency1.ConvertToUSD(Amount) << " USD " << endl << endl ;


    if (Currency2.CurrencyCode() == "USD")
    {
      return ;
    }

    cout << "\n\nConverting From USD to : \n" << endl;
    _PrintCurrencyCard(Currency2 ,"To : " );

    cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " 
    << Currency1.ConvertToOtherCurrency(Amount , Currency2) << " " << Currency2.CurrencyCode() << endl << endl ;
    
}

public :
 
 static void ShowCurrencyCalculatorScreen()
 {
    
    char sure = 'n';
    do 
    {

      clsUtil::ResetScreen() ;  
      clsScreen::_DrawScreenHeader("\tCurrency Calculator Screen");


      clsCurrency Currency1 = _GetCurrencyRecord(1);
      clsCurrency Currency2 = _GetCurrencyRecord(2);
      double Amount = _ReadAmount();
      _PrintCalculationsResult(Currency1 , Currency2 , Amount );

      cout << "\n\nDo You Want to perform another calculation ? [Y/N] " ;
      cin >> sure ;
    } while (sure == 'y' || sure == 'Y');



 }

};