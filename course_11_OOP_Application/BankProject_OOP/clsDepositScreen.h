#pragma once 

#include <iostream> 
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"

using namespace std;

class clsDepositScreen : protected clsScreen 
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

static double _ReadDepositAmount ()    
{
    double Amount = 0 ;

    do 
    {
      cout << "\n\nEnter Deposit Amount ?";
      Amount = clsInputValidate::ReadDblNumber();

    } while (Amount < 0 );

    return Amount ;
}

public :

static void ShowDepositScreen ()
{
    clsScreen::_DrawScreenHeader("\t    Deposit Screen") ;

    string AccountNumber ;
    cout << "\nPlease Enter client Acoount Numebr " ;
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is Not found .. Choose another one ";
        AccountNumber = clsInputValidate::ReadString() ;

    }
    clsBankClient Client = clsBankClient::Find(AccountNumber);

    _PrintCLient(Client);

    double DepsitAmount = _ReadDepositAmount();

    char sure ;
    cout << "\nAre you sure you want to perform this transaction ? ";
    cin >> sure ;

    if (sure == 'y' || sure == 'Y')
    {
     Client.Deposit(DepsitAmount) ;
     cout << "\nAmount Deposited successfully ." << endl;
     cout << "New Balance is " << Client.AccountBalance() << endl;
    }
    else 
    {
     cout << "\nOperation Was Cancelled \n";
    }



}



};