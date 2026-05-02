#pragma once 
#include <iostream>
#include<iomanip>
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std ;

class clsUpdateClientScreen : protected clsScreen
{
private :

    static void _PrintCLient (clsBankClient Client) 
    {
        cout << "\nClient Card:";
        cout << "\n_________________________";
        cout << "\nFirstName   : " << Client.FirstName();
        cout << "\nLastName    : " << Client.LastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email();
        cout << "\nPhone       : " << Client.Phone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode();
        cout << "\nBalance     : " << Client.AccountBalance();
        cout << "\n_________________________\n";

    }

    static void _ReadClientInfo (clsBankClient &Client )
    {
     
    cout << "\nEnter FirstName : " ;
    Client.SetFirstName(clsInputValidate::ReadString());

    cout << "\nEnter LastName : " ;
    Client.SetLastName(clsInputValidate::ReadString());

    cout << "\nEnter Email : " ;
    Client.SetEmail(clsInputValidate::ReadString());

    cout << "\nEnter Phone : " ;
    Client.SetPhone(clsInputValidate::ReadString());

    cout << "\nEnter PinCode : " ;
    Client.SetPinCode(clsInputValidate::ReadString());

    cout << "\nEnter Account Balance : ";
    Client.SetAccountBalance(clsInputValidate::ReadDblNumber());

    }


public :


    static  void ShowUpdateClientScreen ()
   {

    clsScreen::_DrawScreenHeader("\tUpdate Client Screen") ;

    string AccountNumber ;
    cout << "\nPlease Enter client Acoount Numebr " ;
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is Not found .. Choose another one ";
        AccountNumber = clsInputValidate::ReadString() ;

    }

   clsBankClient Client = clsBankClient::Find(AccountNumber);
   _PrintCLient(Client) ;

   cout << "\nUpdate Client Info : " << endl;
   cout << "__________________________________" << endl;
   _ReadClientInfo(Client);
   cout << "__________________________________" << endl;


   clsBankClient::enSaveResults SaveResult ;
   SaveResult = Client.Save();

   switch (SaveResult)
   {
   case clsBankClient::enSaveResults::svSucceeded :
   {
    cout << "\nAccount updated successfully " << endl;
    _PrintCLient(Client) ;
    break;
   }

   case clsBankClient::enSaveResults::svFailedEmptyObject :
   { 
    cout << "\nError .. Account wasnot save because it is empty " << endl;
    default:
    break;
    }

   }

   }


};