#pragma once 
#include <iostream>
#include<iomanip>

#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std ;

class clsDeleteCLientScreen : private clsScreen 
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

static void ShowDeleteClinetScreen ()
{
clsScreen::_DrawScreenHeader("\tDelete Client Screen ");

 string AccountNumber = "" ;
 cout << "Enter the Account Number for the Account you want to delete ?";
 AccountNumber = clsInputValidate::ReadString();

 while (!clsBankClient::IsClientExist(AccountNumber))
 {
    cout << "Account Number is not exist .. Choose andother one " << endl;
    AccountNumber = clsInputValidate::ReadString() ;
 }

 clsBankClient Client =clsBankClient::Find(AccountNumber);
 _PrintClient(Client) ;

 cout << "\nAre you sure you want to delete this client ? Y/N " ;
 char Answer ;
 cin >> Answer ;

 if (Answer == 'Y' || Answer == 'y')
 {
    if (Client.clsBankClient::Delete())
    {
        cout << "\nClient is Deleted successfully \n" << endl;
        _PrintClient(Client);
    }
    else 
    {
        cout << "\nError .. Client Was Not Deleted \n" ;
    }
 }


 
}

};