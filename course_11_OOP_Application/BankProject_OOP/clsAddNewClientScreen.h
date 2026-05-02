#pragma once 
#include <iostream>
#include<iomanip>
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std ;

class clsAddNewClientScreen : protected clsScreen 
{

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


static void AddNewClient ()
{

   clsScreen::_DrawScreenHeader("\t  Add New Client Screen");

   string AccountNumber ;
   
   cout << "Please enter your Account Number ?" ;
   AccountNumber = clsInputValidate::ReadString() ;

   while (clsBankClient::IsClientExist(AccountNumber))
   {
    cout << "This Account Number is already Exist .. Choose another one " ;
    AccountNumber =  clsInputValidate::ReadString();

   }

   clsBankClient Client = clsBankClient::_GetAddNewClientObject (AccountNumber);
   _ReadClientInfo(Client);

   clsBankClient::enSaveResults SaveResults ;
   SaveResults = Client.Save() ;

   switch (SaveResults)
   {

    case clsBankClient::enSaveResults::svSucceeded :
    {   
        cout << "\nAccount Added Successfully :)\n";
        _PrintCLient(Client);
        break;
    }
    case clsBankClient::enSaveResults::svFailedEmptyObject :
    {
        cout << "\nAccount was not saved because it is empty \n" ;
        break ;
    }
    case clsBankClient::enSaveResults::svFailedAccountNumberExist :
    {
        cout << "\nAccount was not saved because Account number was not exist \n" ;
    }

   }


}    
};