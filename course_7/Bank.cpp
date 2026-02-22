#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientFileName = "Client.txt" ;
enum enMainMenuScreenItems {ShowClientList = 1 , AddNewClients = 2 , DeleteClient = 3 , UpdateClientInfo = 4
    , FindClient =5 ,Transactions = 6 , Exit = 7  };
enum enTransactionsItems {Deposit = 1 , Withdraw =2 , TotalBalances = 3 , MainMenu = 4  };
struct sClient
{
    string AccountNumber = " " ;
    string PinCode = " ";
    string Name = " " ;
    string Phone = " " ;
    double AccountBalance = 0 ;
    bool MarkForDelete = false ;
};
string ReadAccountNum () {
    string AccountNum ;
    cout << "\nPlease enter Account number ? " ;
    getline (cin >> ws , AccountNum) ;
    return AccountNum ;
}
void ClearScreen() {
    for (int i = 0; i < 100; i++)
        cout << "\n";
}
vector <string> SplitString(string s , string delim = "#//#" )
{
    vector <string> vstring ;
    string word ;
    short pos = 0 ;
    while ((pos = s.find(delim)) != string::npos)
    {
        word = s.substr(0,pos);
        if (word != "")
        {
            vstring.push_back(word);
        }
        s.erase(0,pos + delim.length());

    }
    if (s != "")
    {
        vstring.push_back(s) ;
    }

    return vstring ;
}
string ConvertDataToLine (sClient client , string delimiter = "#//#" )
{
    string ClientLine = "" ;

    ClientLine+= client.AccountNumber + delimiter ;
    ClientLine+= client.PinCode + delimiter ;
    ClientLine+= client.Name+ delimiter ;
    ClientLine+= client.Phone+ delimiter ;
    ClientLine+= to_string(client.AccountBalance) ;

    return ClientLine ;

}
void AddClientToFile ( string FileName , string ClientLine )
{
    fstream MyFile ;
    MyFile.open(FileName ,ios::out | ios::app );

    if (MyFile.is_open())
    {
        MyFile << ClientLine << endl;
        MyFile.close() ;

    }

}
sClient ReadAndStorNewClientData ()
{

    sClient client ;
    cout << " enter Account Number ? " ;
    getline(cin >> ws , client.AccountNumber );

    cout << " enter Account PinCode ? " ;
    getline (cin , client.PinCode);

    cout << " enter Name ? " ;
    getline (cin , client.Name );

    cout << " enter your phone number ? " ;
    getline (cin , client.Phone);

    cout << " enter your account balance ? ";
    cin >> client.AccountBalance;

    return client ;

}
sClient ConvertLineToStruct (string line , string delimiter = "#//#")
{
    sClient client ;
    vector <string> vClientData ;
    vClientData = SplitString(line , delimiter );

    client.AccountNumber = vClientData[0] ;
    client.PinCode = vClientData[1] ;
    client.Name = vClientData[2] ;
    client.Phone = vClientData[3] ;
    client. AccountBalance = stod(vClientData[4]) ;

    return client ;

}
vector <sClient> LoadClientsDataFromFile (string FileName )
{
    fstream MyFile ;
    MyFile.open(FileName , ios :: in );

    vector <sClient> clients ;

    if (MyFile.is_open())
    {
        string line ;
        sClient clien ;
        while (getline (MyFile , line ))
        {
            clien = ConvertLineToStruct(line);
            clients.push_back(clien) ;
        }
        MyFile.close();
    }
    return clients ;

}
void LoadClientDataToFile (string FileName , vector <sClient> &clients )
{
    fstream MyFile ;
    MyFile.open(FileName , ios::out );
    string line ;

    if (MyFile.is_open())
    {
        for (sClient &c : clients )
        {
            if (c.MarkForDelete != true )
            {
                MyFile << ConvertDataToLine(c) << endl;
            }

        }
        MyFile.close() ;
    }


}
bool SearchClientByAccountNumber (string AccountNum , sClient &client,  vector <sClient> &vClient )
{

    for (sClient &c : vClient)
    {
        if (c.AccountNumber == AccountNum)
        {
            client = c ;
            return true ;
        }

    }
    return false ;
}
bool IsClientAlreadyExist (string AccountNum , vector <sClient> &vClients )
{

   for ( sClient &c : vClients )
   {
       if (c.AccountNumber == AccountNum)
       {
           return true ;

       }

   }
    return false ;


}
void AddOneClientToFile ( vector< sClient > &vClients)
{

    sClient NewClient ;
    cout << "\nPlease enter Account number  ? " ;
    getline(cin >> ws , NewClient.AccountNumber)  ;

    while (IsClientAlreadyExist(NewClient.AccountNumber , vClients))
    {
        cout << "Client with [ " << NewClient.AccountNumber << " ] already exists , Enter Another account number ? ";
        getline(cin >> ws , NewClient.AccountNumber);
    }
    cout << "Please enter Account PinCode ? " ;
    getline (cin , NewClient.PinCode);

    cout << "Please enter Name ? " ;
    getline (cin , NewClient.Name );

    cout << "Please enter your phone number ? " ;
    getline (cin , NewClient.Phone);

    cout << "Please enter your account balance ? ";
    cin >> NewClient.AccountBalance;


    vClients.push_back(NewClient);

    AddClientToFile(  ClientFileName , ConvertDataToLine(NewClient));
    cout << "\n Client is added successfully \n";

}
void AddingNewClientsScreen(vector< sClient > &vClients)
{
    cout << "\n\n______________________________________" << endl;
    cout << "           Add New Client Screen          " << endl;
    cout << "______________________________________\n" << endl;
    cout << "Adding New Client : \n ";

    bool AddMore = 0 ;

    do {
         AddOneClientToFile(vClients);
         cout << "Do you need to add more clients ? YES [ 1 ] , NO [ 0 ] " << endl;
         cin >> AddMore;


       } while (AddMore);

}
void ShowMainMenuScreen ()
{
    cout <<   "\n\n===============================================" << endl;
    cout <<   "               Main Menu Screen               " << endl;
    cout <<   "==============================================="  << endl;
    cout <<   "       [ 1 ] Show Client List   " << endl;
    cout <<   "       [ 2 ] Add New Client     " << endl;
    cout <<   "       [ 3 ] Delete Client      " << endl;
    cout <<   "       [ 4 ] Update Client Info " << endl;
    cout <<   "       [ 5 ] Find Client        " << endl;
    cout <<   "       [ 6 ] Transactions        " << endl;
    cout <<   "       [ 7 ] Exit               " << endl;
    cout <<   "===============================================" << endl;
    cout <<   "Choose what do you want to choose [ 1 to 7 ] ? "<< endl;

}
void PrintHeaderOfClientsShow (int NumOfClients )
{
    cout << "_______________________________________________________________________________________________________" << endl;
    printf("                         Client List ( %d ) Client (s)                              "
       , NumOfClients ) ;
    cout << "\n_______________________________________________________________________________________________________" << endl ;
    cout << " | " << left << setw(15) << "Account Number";
    cout << " | " << left  << setw(10) << "Pin Code" ;
    cout << " | " << left  << setw (40) << "Client Name";
    cout << " | " << left << setw (12) << "Phone";
    cout << " | " << left << setw (12) << "Balance" ;
    cout << endl;
    cout << "_______________________________________________________________________________________________________" << endl;

}
void PrintOneClientInMainMenu ( sClient &client )
{
    cout << " | " << left   << setw(15) << client.AccountNumber;
    cout << " | " << left   << setw(10) << client.PinCode ;
    cout << " | " << left   << setw (40) << client.Name;
    cout << " | " << left   << setw (12) << client.Phone;
    cout << " | " << left   << setw (12) << client.AccountBalance ;


}
void PrintOneClientInBalanceMenu (sClient &client)
{
    cout << " | " << left   << setw(15) << client.AccountNumber;
    cout << " | " << left   << setw (40) << client.Name;
    cout << " | " << left   << setw (12) << client.AccountBalance ;

}
void PrintClientsShow (vector <sClient> &vClients )
{

    PrintHeaderOfClientsShow( vClients.size() );

    if (vClients.size() == 0 )
    {
        cout << "No clients available in the system ... "<< endl;
    }
    else
    {
        for (sClient &client : vClients)
        {
            PrintOneClientInMainMenu(client);
            cout << endl;
        }
    }
    cout << "\n_______________________________________________________________________________________________________" << endl;
}
void MarkClientToBeDeletedByAccountNumber (string AccountNumber , vector <sClient> &clients )
{
    sClient client ;
    for (sClient &c : clients )
    {
        if (c.AccountNumber == AccountNumber )
        {
            c.MarkForDelete = true ;
            break ;
        }
    }

}
void PrintClientCard (sClient client )
{
    cout << "\nThe following is the client details    : " << endl;
    cout << "_______________________________________" << endl;
    cout << "Account Number   : " << client.AccountNumber << endl;
    cout << "Account Pincode  : " << client.PinCode << endl;
    cout << "Name             : " << client.Name << endl;
    cout << "Phone            : " << client.Phone << endl;
    cout << "Account Balance  : " << client.AccountBalance << endl;
    cout << "_______________________________________" << endl;

}
void DeleteClientByAccountNumber (string AccountNumber , vector <sClient> &vClients  )
{
    sClient found ;
    if (SearchClientByAccountNumber (AccountNumber ,  found , vClients) )
    {
        PrintClientCard(found);
        bool del = 1  ;


        cout << "\n Are you sure that you want to delete this client ?? Yes [ 1 ] , NO [ 0 ]  " ;
        cin >> del ;

        if (del)
        {
             MarkClientToBeDeletedByAccountNumber(AccountNumber , vClients );
             LoadClientDataToFile(ClientFileName , vClients );
             vClients = LoadClientsDataFromFile(ClientFileName);

            cout << "\n client is deleted successfully "<< endl;
        }
        else
            cout << " \n Client is Not deleted \n " ;
    }
    else
        cout <<"\nClient With account number ( " << AccountNumber << " ) is Not found " << endl;
}
void DeletingClientsShow (vector<sClient> &vClients)
{
    cout << "\n_______________________________________" << endl;
    cout << "            Delete Client Screen          "<< endl;
    cout << "_______________________________________" << endl;

    bool DeleteMore = 0 ;
    do
    {
        string AccountNumber = ReadAccountNum() ;
        DeleteClientByAccountNumber(AccountNumber , vClients );

        cout << "\n\nDo you need to delete more clients ? YES [ 1 ] , NO [ 0 ] " ;
        cin >> DeleteMore ;



    }   while (DeleteMore) ;


}
sClient ReadClientInformationWithAccountNumber (string accountNum)
{
    sClient c ;
    cout << "\n replinishing your account information \n"<< endl;
    cout << "Enter your pin code : " ;
    getline(cin >> ws , c.PinCode)  ; // to get rid of white spaces .

    cout << "Enter your name : " ;
    getline(cin , c.Name) ;

    cout << "Enter your phone : " ;
    getline (cin , c.Phone) ;

    cout << "Enter your account balance : " ;
    cin >> c.AccountBalance ;


    c.AccountNumber = accountNum ;

    return c ;
}
sClient GetExistClientInfoWithAccountNumber (string AccountNumber , vector <sClient> &vClients )
{
  sClient FoundClient ;

    for (sClient &c : vClients )
    {
       if (c.AccountNumber == AccountNumber)
       {
           FoundClient = c ;
           break ;

       }

    }
    return FoundClient ;
}
vector<sClient> UpdateClientsDataAfterEdit (string accountNum, sClient &client , vector <sClient> &vClients )
{

    for (sClient &c : vClients) // By ref to make sure that the client record is updated .
    {
        if (c.AccountNumber == accountNum)
        {
            c = client ;
            break;
        }
    }

    return vClients ;
}
void UpdateUserInformationByAccountNumber  (string accountNum , vector <sClient> &clients )
{
    sClient clientToUpdate ;

    if (SearchClientByAccountNumber(accountNum , clientToUpdate , clients))
    {
        bool ask = 1 ;
        cout << "\nAre you sure that you want to change this account information ? YES [ 1 ] , NO [ 0 ] " << endl;
        cin >> ask ;

        if (ask)
        {
            PrintClientCard(clientToUpdate);
            clientToUpdate = ReadClientInformationWithAccountNumber(accountNum);
            clients = UpdateClientsDataAfterEdit(accountNum , clientToUpdate , clients ) ;
            LoadClientDataToFile(ClientFileName, clients);

            cout << "\n Client with ( " << accountNum << " ) has been updated successfully \n" << endl;
        }
        else
        {
            cout << "\n Ok .. account information is not updated \n" << endl;

        }
    }
    else
    {
        cout << "\nsorry .. the account with ( " << accountNum << " ) is not found" << endl;
    }
}
void UpdateClientInfoScreen (vector<sClient> & vClients )
{
    cout << "\n_______________________________________" << endl;
    cout << "         Update Client Info Screen           "<< endl;
    cout << "_______________________________________" << endl;

    bool UpdateAgain = 0 ;
    do {
         UpdateUserInformationByAccountNumber (ReadAccountNum(), vClients);
         cout << "Do you want to update another client ? YES [ 1 ] , NO [ 0 ] " ;
         cin >> UpdateAgain ;

        } while (UpdateAgain);


}
void FindClientShow (vector <sClient > & vClients)
{
    cout << "\n_______________________________________" << endl;
    cout << "            Find Client Screen          "<< endl;
    cout << "_______________________________________" << endl;

    sClient Found ;

    if (SearchClientByAccountNumber(ReadAccountNum() , Found , vClients))
    {
        PrintClientCard(Found);
    }
    else
    {
        cout << "\n Sorry .. This client is not found " <<endl;
    }

}
double DepositMoney (string AccountNumber , vector <sClient> &vClients , double deposit )
{

    for (sClient &c : vClients)
    {
        if (c.AccountNumber == AccountNumber )
        {
            c.AccountBalance += deposit ;
            return c.AccountBalance ;
        }
    }
return -1 ;

}
double WithdrawMoney (string AccountNumber , vector <sClient> &vClients , double Whithdraw )
{

    for (sClient &c : vClients)
    {
        if (c.AccountNumber == AccountNumber )
        {
            c.AccountBalance -= Whithdraw ;
            return c.AccountBalance ;
        }
    }
    return -1 ;

}
void MakeDeposition (string AccountNumber , vector <sClient> &vClients )
{

    double deposit = 0 ;
    cout << "\nPlease enter deposit amount " ;
    cin >> deposit ;

    bool sure = 0 ;
    cout << "\nAre you sure you want to perform this transaction ? YES [ 1 ] , NO [ 0 ] " ;
    cin >> sure ;

    if (sure)
    {
        double NewBalance = DepositMoney(AccountNumber , vClients , deposit );
        cout << "\nDone successfully  ..  New balance is "  << NewBalance<< endl;
    }
    else
    {
        cout << "\nDeposit is not added .. " << endl;
    }


}
double GetAccountBalance (string AccountNumber , vector <sClient> &vClients )
{
   for (sClient &c : vClients)
   {
       if (c.AccountNumber == AccountNumber )
       {
           return c.AccountBalance ;
       }
   }
    return -1 ;

}
void MakeWithdraw (string AccountNumber , vector <sClient> &vClients )
{
    double Withdraw = 0 ;
    cout << "\nPlease enter Withdraw amount ? ";
    cin >>Withdraw ;

    double LastAccountBalance = GetAccountBalance( AccountNumber , vClients);

    while ( LastAccountBalance < Withdraw)
    {
        cout <<"Amount exceeds the balance , you can withdraw up to :  "<< LastAccountBalance << endl;
        cout << "Please enter another Withdraw amount ? ";
        cin >> Withdraw ;
    }

    bool sure = 0 ;
    cout << "Are your sure you want to perform this transaction ? " ;
    cin >> sure ;

    if (sure)
    {

        double NewBalance = WithdrawMoney(AccountNumber , vClients , Withdraw );
        cout << "\nDone successfully  ..  New balance is "  << NewBalance<< endl;
    }
    else
    {
        cout << "\nTransaction is not performed .. " << endl;
    }

}
void MakeOneDepositionProcess ( vector <sClient > & vClients)
{
    string AccountNumber = ReadAccountNum() ;
    sClient client ;

    while (!IsClientAlreadyExist(AccountNumber , vClients))
    {
        cout << "Client with [ " << AccountNumber << " ] does not exist .. ";
        AccountNumber = ReadAccountNum() ;
    }

    client = GetExistClientInfoWithAccountNumber(AccountNumber , vClients);
    PrintClientCard(client) ;

    MakeDeposition(AccountNumber , vClients ) ;
    LoadClientDataToFile(ClientFileName , vClients );
}
void MakeOneWithdrawingProcess (vector < sClient> &vClients )
{
    string AccountNumber = ReadAccountNum() ;
    sClient client ;

    while (!IsClientAlreadyExist(AccountNumber , vClients))
    {
        cout << "Client with [ " << AccountNumber << " ] does not exist .. ";
        AccountNumber = ReadAccountNum() ;
    }

    client = GetExistClientInfoWithAccountNumber(AccountNumber , vClients);
    PrintClientCard(client) ;
    MakeWithdraw(AccountNumber , vClients );
    LoadClientDataToFile(ClientFileName , vClients) ;

}
void DepositScreen( vector <sClient > & vClients)
{
    cout << "\n_______________________________________" << endl;
    cout << "              Deposit Screen                           "<< endl;
    cout << "_______________________________________" << endl;
    MakeOneDepositionProcess (vClients);

}
void WithDrawScreen (vector <sClient > & vClients)
{
    cout << "\n_______________________________________"<< endl;
    cout << "              WithDraw Screen            "<< endl;
    cout << "_______________________________________"  << endl;
    MakeOneWithdrawingProcess(vClients);

}
void ShowTotalBalanceScreen (vector <sClient > &vClients )
{
    cout << "_______________________________________________________________________________________________________" << endl;
    printf("                         Balances List ( %d ) Client (s)                              "
       , vClients.size() ) ;
    cout << "\n_______________________________________________________________________________________________________" << endl ;
    cout << " | " << left << setw(15) << "Account Number";
    cout << " | " << left  << setw (40) << "Client Name";
    cout << " | " << left << setw (12) << "Balance" ;
    cout << endl;
    cout << "_______________________________________________________________________________________________________" << endl;


    if (vClients.size() == 0 )
    {
        cout << "No clients available in the system ... "<< endl;
    }
    else
    {
        for (sClient &client : vClients)
        {
            PrintOneClientInBalanceMenu(client);
            cout << endl;
        }
    }
    cout << "\n_______________________________________________________________________________________________________" << endl;


}
void ShowTransactionMenuScreen ()
{
    cout <<   "\n\n===============================================" << endl;
    cout <<   "              Transactions Menu Screen               " << endl;
    cout <<   "==============================================="  << endl;
    cout <<   "       [ 1 ] Deposit   " << endl;
    cout <<   "       [ 2 ] Withdraw     " << endl;
    cout <<   "       [ 3 ] Total Balances      " << endl;
    cout <<   "       [ 4 ] Main Menu " << endl;
    cout <<   "===============================================" << endl;
    cout <<   "Choose what do you want to choose [ 1 to 4 ] ? "<< endl;

}
void StartTransactionScreen (vector <sClient> &vClients )
{
  short Choose = 0 ;
    do {
        ClearScreen();
        ShowTransactionMenuScreen ();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> Choose ;


        if (Choose == enTransactionsItems::Deposit)
        {
             DepositScreen( vClients );

        }
        else if (Choose == enTransactionsItems::Withdraw)
        {
            WithDrawScreen(vClients);
        }
        else if (Choose == enTransactionsItems::TotalBalances)
        {
            ShowTotalBalanceScreen (vClients);
        }
        else if (Choose == enTransactionsItems::MainMenu)
        {
            return ;
        }
        else
        {
            cout << "\nWrong validation .. Try again ..\n";
        }

            cout << "\nPress any key to go back to Transition Menu ... \n" ;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get() ;



    }while (Choose != enTransactionsItems::MainMenu);


}
void StartApp ()
{
    vector<sClient>vClients = LoadClientsDataFromFile(ClientFileName);

    short Choose = 0 ;
   do {
       ClearScreen();
       ShowMainMenuScreen ();
       cin >> Choose ;

       if (Choose == enMainMenuScreenItems::ShowClientList)
       {
           PrintClientsShow ( vClients );

       }
       else if (Choose == enMainMenuScreenItems::AddNewClients)
       {
           AddingNewClientsScreen(vClients);
       }
       else if (Choose == enMainMenuScreenItems::DeleteClient)
       {
           DeletingClientsShow (vClients);
       }
       else if (Choose == enMainMenuScreenItems::UpdateClientInfo)
       {
           UpdateClientInfoScreen ( vClients );
       }
       else if (Choose == enMainMenuScreenItems::FindClient)
       {
           FindClientShow (vClients) ;
       }
       else if (Choose == enMainMenuScreenItems::Transactions)
       {
           StartTransactionScreen(vClients);
       }
       else if (Choose == enMainMenuScreenItems::Exit)
       {
         cout << "Exiting the program ...." ;

       }
       else
       {
           cout << "\n Invalid Choice .. Try again .. "<< endl;

       }


       if (Choose != enMainMenuScreenItems::Exit)
       {
           cout << "\nPress any key to go back to Main Menue ... \n" ;
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
           cin.get() ;
       }

      }while ( Choose != enMainMenuScreenItems::Exit );



}
int main()
{

    StartApp();
    return 0 ;

}