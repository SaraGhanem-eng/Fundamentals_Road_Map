#pragma once 
#include <iostream>
#include<iomanip>
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std ;


class clsFindClientScreen : protected clsScreen
{

private :

    static void _PrintClient (clsBankClient Client) 
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

public :

   static void ShowFindCLientScreen ()
   {
    clsScreen::_DrawScreenHeader("\t  Find Client Screen");

    cout << "Please enter Account Number ? " ;
    string AccountNumber = clsInputValidate::ReadString() ;
    
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
      cout << "Account Number is not Found .. Choose another one " ;
      AccountNumber =  clsInputValidate::ReadString();

    }
    
    clsBankClient Client = clsBankClient::Find(AccountNumber);

    if (!Client.IsEmpty())
    {
    cout << "\nClient Is Found :-)\n" ; 
    }
    else 
    {
        cout << "\nClient Is Not Found :-(\n";
    }

    _PrintClient(Client);

   }
};