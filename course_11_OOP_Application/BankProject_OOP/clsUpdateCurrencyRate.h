#pragma once 

#include <iostream> 
#include "clsScreen.h"
#include "clsCurrency.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
using namespace std ;

class clsUpdatCurrencyRate : protected clsScreen
{
    
private :
static void _PrintCurrencyCard(clsCurrency Currency )
{
    cout << "\n\nCurrency Card : \n" << endl;
    cout << "________________________________\n" << endl;
    cout << "Country  : " << Currency.Country() << endl;
    cout << "Code     : " << Currency.CurrencyCode() << endl;
    cout << "Name     : " << Currency.CurrencyName() << endl;
    cout << "Rate(1$) : " << Currency.Rate() << endl << endl ;
    cout << "________________________________\n\n" << endl;
}

static string _ReadCurrencyCode ()
{
    string CurrencyCode ;
    cout << "\nPlease Enter Currency Code ? ";
    CurrencyCode = clsInputValidate::ReadString();
    
    return CurrencyCode; 

}

static void _UpdateRate (clsCurrency &Currency)
{

     float Rate ;
     cout << "\n\nUpdate Currency Rate : " << endl;
     cout << "__________________________" << endl;
     cout << "\nEnter New Rate ";
     cin >> Rate ;

     Currency.UpdateRate(Rate);
     cout << "\nCurrency Rate Updated Successfully :-) \n";

}

public :

static void ShowUpdateCurrencyRateScreen()
{
 clsScreen::_DrawScreenHeader("\t Update Currency Screen") ;
 
 string CurrencyCode = _ReadCurrencyCode();
 clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

 if (!Currency.IsEmpty())
 {
    
   _PrintCurrencyCard(Currency);
   
   char sure = 'n' ;
   cout << "\nAre you sure you want to update the rate of the currency ? y/n ";
   cin >> sure ;


   if (sure == 'Y' || sure == 'y')
   {
    _UpdateRate(Currency)  ;
   }
   else 
   {
    cout << "\nCurrency Rate is not updated .. ";
   }

   _PrintCurrencyCard(Currency);
 }
 else 
 {
    cout << "\nCurrency With ( "<< CurrencyCode <<  " ) Is Not Exist ! \n ";
 }
  
  

}
};