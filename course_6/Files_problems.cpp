

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;
struct sClient
{
    string AccountNumber = " " ;
    string PinCode = " ";
    string Name = " " ;
    string Phone = " " ;
    double AccountBalance = 0 ;
    bool MarkForDelete = false ;
};

const string ClientFileName = "Clients.txt";
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
sClient ReadAndStorNewClientData ()
{
    sClient client ;
    cout << "Please enter Account Number ? " ;
    getline(cin >> ws , client.AccountNumber );

    cout << "Please enter Account PinCode ? " ;
    getline (cin , client.PinCode);

    cout << "Please enter Name ? " ;
    getline (cin , client.Name );

    cout << "Please enter your phone number ? " ;
    getline (cin , client.Phone);

    cout << "Please enter your account balance ? ";
    cin >> client.AccountBalance;

return client ;

}
string ConvertClientDataToLine (sClient client , string delimiter = "#//#" )
{
  string ClientLine = "" ;

    ClientLine+= client.AccountNumber + delimiter ;
    ClientLine+= client.PinCode + delimiter ;
    ClientLine+= client.Name+ delimiter ;
    ClientLine+= client.Phone+ delimiter ;
    ClientLine+= to_string(client.AccountBalance) ;

   return ClientLine ;

}
sClient ConvertClientLineToStruct (string line , string delimiter = "#//#")
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
void PrintClientCard (sClient client )
{
    cout << "\n Client information card \n" << endl;
    cout << "Account Number   : " << client.AccountNumber << endl;
    cout << "Account Pincode  : " << client.PinCode << endl;
    cout << "Name             : " << client.Name << endl;
    cout << "Phone            : " << client.Phone << endl;
    cout << "Account Balance  : " << client.AccountBalance << endl;

}
vector <sClient> LoadClientsDataFromFileToVector (string FileName )
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
            clien = ConvertClientLineToStruct(line);
            clients.push_back(clien) ;
        }
        MyFile.close();
    }
    return clients ;

}
vector <sClient> LoadClientDataFromFile(string FileName)
{
    vector <sClient> clients ;

    fstream MyFile ;
    MyFile.open( FileName  , ios::in);

    if(MyFile.is_open())
    {
        string line ;
        while (getline(MyFile , line ))
        {
            clients.push_back( ConvertClientLineToStruct(line));
        }

        MyFile.close() ;

    }
    return clients ;
}
bool SearchClientByAccountNumber (string AccountNum , sClient &client)
{

    vector <sClient> vClient ;
    vClient = LoadClientDataFromFile(ClientFileName) ;

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
void AddOneClient ()
{

    sClient client ;
    client = ReadAndStorNewClientData() ;
    AddClientToFile(  ClientFileName , ConvertClientDataToLine(client));

}
void AddingNewClientScreenHeader ()
{
  cout << "\n\n______________________________________\n\n" << endl;
  cout << "           Add New Client Screen          \n\n" << endl;
  cout << "\n\n______________________________________\n\n" << endl;
  cout << "Adding New Client : \n\n ";



}
void PrintHeaderOfClientsShow (int NumOfClients )
{
    cout << "_______________________________________________________________________________________________________" << endl;
    printf("                         Client List ( %d ) Client (s)                              "
       , NumOfClients ) ;
   cout << "\n_______________________________________________________________________________________________________" << endl << endl;
   cout << " | " << left << setw(15) << "Account Number";
   cout << " | " << left  << setw(10) << "Pin Code" ;
   cout << " | " << left  << setw (40) << "Client Name";
   cout << " | " << left << setw (12) << "Phone";
   cout << " | " << left << setw (12) << "Balance" ;
    cout << endl;


}
void PrintOneClient ( sClient client )
{
    cout << " | " << left   << setw(15) << client.AccountNumber;
    cout << " | " << left   << setw(10) << client.PinCode ;
    cout << " | " << left   << setw (40) << client.Name;
    cout << " | " << left   << setw (12) << client.Phone;
    cout << " | " << left   << setw (12) << client.AccountBalance ;


}
void PrintClientsShow (vector <sClient> vClients )
{

    PrintHeaderOfClientsShow( vClients.size() );


    for (sClient &client : vClients)
    {
       PrintOneClient(client);
       cout << endl;
    }
    cout << "\n_______________________________________________________________________________________________________" << endl;
}
void LoadClientDataToFile (string FileName , vector <sClient> clients )
{
    fstream MyFile ;
    MyFile.open(FileName , ios::out );
    string line ;

    if (MyFile.is_open())
    {
        for (sClient c : clients )
        {
            if (c.MarkForDelete != true )
            {
                MyFile << ConvertClientDataToLine(c) << endl;
            }

        }
    }
   MyFile.close() ;

}
string ReadAccountNum () {
    string AccountNum ;
    cout << "\nPlease enter account number ? \n" ;
    cin >> AccountNum ;
    return AccountNum ;
}
void FindClientByAccountNumber (string AccountNum)
{
    sClient found ;

  if (SearchClientByAccountNumber(AccountNum, found ))
  {
      cout << "\nClients Account for account number " << AccountNum << " is : \n" << endl;
      PrintClientCard(found);

  }
    else
        cout << "\nSorry .. Client with Account number ( "<< AccountNum<< " ) is Not Found ! "<< endl;


}
void AskToSearchForClientByAN ()
{
    bool search = 1 ;
  do {
          FindClientByAccountNumber(ReadAccountNum());
          cout << "\n\nDo you need to search for another client ? YES [ 1 ] , NO [ 0 ] ";
          cin >> search ;

       } while(search);


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
void DeleteClientByAccountNumber (string AccountNumber , vector <sClient> vClients  )
{
      sClient found ;
      if (SearchClientByAccountNumber (AccountNumber , found ) )
      {
          PrintClientCard(found);
          bool del = 1  ;


          cout << "\n Are you sure that you want to delete this client ?? Yes [ 1 ] , NO [ 0 ]  " ;
          cin >> del ;

          if (del)
          {
              MarkClientToBeDeletedByAccountNumber(AccountNumber , vClients );
              LoadClientDataToFile( ClientFileName , vClients);

              cout << "\n client is deleted successfully "<< endl;
          }
          else
              cout << " \n Client is Not deleted \n " ;
      }
      else
          cout <<"\nClient With account number ( " << AccountNumber << " ) is Not found " << endl;
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
vector<sClient> UpdateClientsDataAfterEdit (string accountNum, sClient &client , vector <sClient> &vClients )
{

    vClients = LoadClientDataFromFile(ClientFileName);

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
void UpdateClientInformationByAccountNumber  (string accountNum , vector <sClient> &clients )
{
    sClient client ;


    if (SearchClientByAccountNumber(accountNum , client ))
    {
        bool ask = 1 ;
        cout << "\nDo you want to change this account information ? YES [ 1 ] , NO [ 0 ] " << endl;
        cin >> ask ;

        if (ask)
        {
            PrintClientCard(client);
            client = ReadClientInformationWithAccountNumber(accountNum);
            clients = UpdateClientsDataAfterEdit(accountNum , client , clients ) ;
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
int main()
{


    AddOneClient ();

    return 0;


}