#pragma once 

#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsString.h"

class clsFincCurrency : protected clsScreen 
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

static short _ReadFindOption ()
{
  short option ;
  cout << "\nFind By : [1] Code , [2] Country ";
  option = clsInputValidate::ReadShortNumber() ;
  

  while (option != 1 && option != 2 )
  {
    cout << "\nInvalid Option ! Choose Either [1] or [2] ";
    option =  clsInputValidate::ReadDblNumber();
  }
  return option ;
}

static string _ReadCurrencyCode ()
{
    string CurrencyCode ;
    cout << "\nPlease Enter Currency Code ? ";
    CurrencyCode = clsInputValidate::ReadString();
    
    return CurrencyCode; 

}

static string _ReadCountryName ()
{
  string CountryName ;
  cout << "\nPlase Enter Country Name ";
  CountryName = clsInputValidate::ReadString();

  return CountryName ;

}

static void _ShowResutlt (clsCurrency Currency )
{

     if (!Currency.IsEmpty()) 
     {
        cout << "\nCurrency Is Found :-) \n";
        _PrintCurrencyCard(Currency);
     }
     else
     {
        cout << "\nCurrency Is Not Found :-( \n";
     }

}
public :

static void ShowFindCurrencyScreen ()
{
  clsScreen::_DrawScreenHeader("\tFind Currency Screen");
  
  short option = _ReadFindOption() ; 

  if (option == 1 )
  {
     string CurrencyCode = _ReadCurrencyCode() ;
     clsCurrency Currency = clsCurrency::FindByCode (CurrencyCode);
     _ShowResutlt(Currency);

  }
  else if (option == 2 )
  {

     string Country = _ReadCountryName() ;
     clsCurrency Currency = clsCurrency::FindByCountry (Country);
    _ShowResutlt(Currency);

  }
 


}


};