#pragma once 

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
class clsTransferScreen : protected clsScreen 
{

private:

static void _PrintCLientCard (clsBankClient &Client )
{
   cout << "\n\n\nCLient Card : " ;
   cout << "\n_______________________________";
   cout << "\nFull Name   : " << Client.FullName() ;
   cout << "\nAcc. Number : " << Client.AccountNumber() ;
   cout << "\nBalance     : " << Client.AccountBalance() ;
   cout << "\n_______________________________";

}
static double _ReadAmount (clsBankClient ClientSource )
{
    double Amount ;
    cout << "\n\nEnter Transfer Amount ";
    Amount = clsInputValidate::ReadDblNumber();

    while (Amount > ClientSource.AccountBalance())
    {
      cout << "\nAmount Exeeds the available balance ! Enter another amount ";
      Amount = clsInputValidate::ReadDblNumber();
    }

    return Amount ;
}
public :

static void ShowTransferScreen()
{
clsScreen::_DrawScreenHeader("\tTransfer Screen");

double Amount = 0 ;
string AcctNumTransferFrom ;
string AccNumTransferTo ;


cout << "\nPlease Enter Account Number To Transfer From : ";
cin.ignore();
getline (cin , AcctNumTransferFrom) ;

while (!clsBankClient::IsClientExist(AcctNumTransferFrom))
{
cout << "\nAccount Number is not Exist .. Please enter another Account Number ";
getline (cin , AcctNumTransferFrom) ;
}
clsBankClient ClientFrom = clsBankClient::Find(AcctNumTransferFrom) ;
_PrintCLientCard(ClientFrom);


cout << "\n\n\nPlease Enter Account Number To Transfer To : ";
getline (cin , AccNumTransferTo) ;

while (!clsBankClient::IsClientExist(AccNumTransferTo))
{
cout << "Account Number is not Exist .. Please enter another Account Number ";
getline (cin , AccNumTransferTo) ;

}
clsBankClient ClientTo = clsBankClient::Find(AccNumTransferTo) ;
_PrintCLientCard(ClientTo);


Amount = _ReadAmount(ClientFrom);

char sure = 'n' ;

cout << "\nAre you sure that you want to implement this transfer ? " ;
cin >> sure ;

if (sure == 'y' || sure == 'Y')
{
     if (ClientFrom.Transfer(Amount , ClientTo ))
     {
        cout << "\nTransaction is Performed Successfully ";
    
     }
     else 
     {
        cout << "\nTransfer Failed ";
     }

     _PrintCLientCard(ClientFrom);
     _PrintCLientCard(ClientTo);

}
else 
{
    cout << "\nTransaction is not performed ";
}
}



};