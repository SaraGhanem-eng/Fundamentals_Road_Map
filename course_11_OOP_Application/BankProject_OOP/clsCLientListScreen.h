#pragma once 
#include <iostream> 
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std ;

class clsClientListScreen : protected clsScreen
{
  
private :

static void PrintClientRecordLine (clsBankClient Client )
{
    cout << setw(8) << "" << left ;
    cout << "| " << setw(15) << left << Client.AccountNumber() ;
    cout << "| " << setw(20) << left << Client.FullName() ;
    cout << "| " << setw(20) << left << Client.Phone() ;
    cout << "| " << setw(20) << left << Client.Email() ;
    cout << "| " << setw(10) << left << Client.PinCode() ;
    cout << "| " << setw(12) << left << Client.AccountBalance() ;

}
public :
static void ShowClientsList ()
{
    vector <clsBankClient> _vClients =clsBankClient::GetClientsList();
    string Title = "\t  Clients List Screen" ;
    string SubTitle = "\t    (" + to_string(_vClients.size()) + " Client (s).";
    clsScreen::_DrawScreenHeader(Title , SubTitle);

    cout << setw(8) << "" << left << "\n\t\t\t\t\tClient List (" << _vClients.size() << ") Client(s).";
    cout << "\n\t________________________________________________________________________";
    cout << "___________________________________\n" << endl;
    cout << setw(8) << "" << left ;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(20) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n\t________________________________________________________________________";
    cout << "___________________________________\n" << endl;

    if (_vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient &Client : _vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n\t______________________________________________________________________";
    cout << "_____________________________________\n" << endl;

}

};