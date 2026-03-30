#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientFileName = "Client.txt" ;

enum enATMMainMenuScreen {eQuickWithdraw = 1 , eNormalWithdraw = 2 ,
     eDeposit = 3 , eCheckBalance = 4 , eLogout = 5};

enum enQuickWithdrawAmount {twenety = 1, fifty = 2, oneHundred = 3, twoHundred = 4,
    fourHundred = 5, sixHundred = 6, eightHundred = 7, 
    oneThousand = 8, Exit = 9}; 

struct sClient
{
    string AccountNumber = " " ;
    string PinCode = " ";
    string Name = " " ;
    string Phone = " " ;
    double AccountBalance = 0 ;
    bool MarkForDelete = false ;
};

sClient CurrentClient ;


string ReadAccountNum () {
    string AccountNum ;
    cout << "\nPlease enter Account number ? " ;
    getline (cin >> ws , AccountNum) ;
    return AccountNum ;
}

string ReadPinCode () {
    string PinCode ;
    cout << "\nPlease enter Pin Code ? " ;
    getline (cin >> ws , PinCode) ;
    return PinCode ;
}

void ClearScreen() 
{
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
                MyFile << ConvertClientDataToLine(c) << endl;
            }

        }
        MyFile.close() ;
    }


}

bool IsValidClientForLogin (vector <sClient> & vClient , string AccountNumber , string PinCode  )
{
   for (sClient &c :vClient )
   {
    if (c.PinCode == PinCode && c.AccountNumber == AccountNumber )
    {
        CurrentClient = c ;
        return true ;
    }
   }
   return false ;
}

void CheckBalanceScreen (vector <sClient> & vClient)
{
    cout <<   "\n\n===============================================" << endl;
    cout <<   "            Check Balance Screen               " << endl;
    cout <<   "==============================================="  << endl;
    
    cout << "\nYour Balance is : " << CurrentClient.AccountBalance << endl << endl; 

}

double WithdrawMoney ( vector <sClient> &vClients , double Whithdraw )
{

    for (sClient &c : vClients)
    {
        if (c.AccountNumber == CurrentClient.AccountNumber)
        {
            c.AccountBalance -= Whithdraw ;
            CurrentClient.AccountBalance = c.AccountBalance;
            return c.AccountBalance ;
        }
    }
    return -1 ;

}

double ChooseQuickWithdrawAmount ()
{
     double Amount = 0 ;
     short Choose ;

     cout << "\nChoose what to do from [1] to [9]" ;
     cin >> Choose ;

    switch (Choose)
    {
    case enQuickWithdrawAmount::twenety:
        Amount = 20 ;
        break;
    
    case enQuickWithdrawAmount::fifty:
        Amount = 50 ;
        break;

    case enQuickWithdrawAmount::oneHundred:
        Amount = 100 ;
        break;

    case enQuickWithdrawAmount::twoHundred:
        Amount = 200 ;
        break;  
        
    case enQuickWithdrawAmount::fourHundred:
        Amount = 400 ;
        break;

    case enQuickWithdrawAmount::sixHundred:
        Amount = 600 ;
        break;

    case enQuickWithdrawAmount::eightHundred:
        Amount = 800 ;
        break;

    case enQuickWithdrawAmount::oneThousand:
        Amount = 1000 ;
        break;
    
    case enQuickWithdrawAmount::Exit:
        return 0 ;

    default:
        break;

    
    }
    return Amount;
}

void PerformQuickWithdraw (vector <sClient> &vClient )
{
    double Withdraw ;
    Withdraw = ChooseQuickWithdrawAmount();

    if (Withdraw==0)
    {
        return ;
    }

    if (Withdraw > CurrentClient.AccountBalance )
    {
        cout << "The amount exceeds your balance .. make another choice " << endl;
        return ;
    }
    char sure ;
    cout << "Are you sure You want to perform this transaction ? Y/N";
    cin >> sure ;
    if (sure == 'y' || sure == 'Y')
    {
      WithdrawMoney(vClient , Withdraw);
      LoadClientDataToFile(ClientFileName , vClient);
      cout << "Done successfully .. New balance is " << CurrentClient.AccountBalance << endl;
    }
    else 
    {
        cout << "\n\nTransaction is Not performed .. " << endl;
    }
    
}

void QuickWithdrawScreen (vector <sClient> &vClient )
{
    cout <<   "\n\n===============================================" << endl;
    cout <<   "             Quick Withdraw                " << endl;
    cout <<   "==============================================="  << endl;
    cout <<   "   [1] 20            [2] 50                 " << endl;
    cout <<   "   [3] 100           [4] 200                " << endl;
    cout <<   "   [5] 400           [6] 800                 " << endl;
    cout <<   "   [7] 600           [8] 1000                 " << endl;
    cout <<   "   [9] Exit                                " << endl;
    cout <<   "==============================================="  << endl;
    cout << "Your Balance is " << CurrentClient.AccountBalance << endl;

    PerformQuickWithdraw(vClient);


}

void PerformNormalWithdraw (vector <sClient> &vClient)
{

    int Withdraw = 0 ;

    do 
    {
    cout << "\nEnter an amount multiple of 5s " ;
    cin >> Withdraw;

    } while ( Withdraw % 5 != 0);

        if (Withdraw > CurrentClient.AccountBalance )
        {
        cout << "The amount exceeds your balance .. make another choice " << endl;
        return ;
        }

    char sure ;
    cout << "Are you sure You want to perform this transaction ? Y/N";
    cin >> sure ;
    if (sure == 'y' || sure == 'Y')
    {
      WithdrawMoney(vClient ,double(Withdraw));
      LoadClientDataToFile(ClientFileName , vClient);
      cout << "Done successfully .. New balance is " << CurrentClient.AccountBalance << endl;
    }
    else 
    {
        cout << "\n\nTransaction is Not performed .. " << endl;
    }
}

void NormalWithdrawScreen (vector <sClient> &vClient)
{
    cout <<   "\n\n===============================================" << endl;
    cout <<   "            Normal Withdraw Screen               " << endl;
    cout <<   "==============================================="  << endl;

    PerformNormalWithdraw(vClient);

}

void PerformDeposit (vector <sClient> &vClient)
{

    int Deposit = 0 ;

    do 
    {
    cout << "\nEnter a positive Deposit Amount  " ;
    cin >> Deposit;

    } while ( Deposit % 5 != 0);


    char sure ;
    cout << "Are you sure You want to perform this transaction ? Y/N";
    cin >> sure ;
    if (sure == 'y' || sure == 'Y')
    {
      WithdrawMoney(vClient ,double(-Deposit));
      LoadClientDataToFile(ClientFileName , vClient);
      cout << "Done successfully .. New balance is " << CurrentClient.AccountBalance << endl;
    }
    else 
    {
        cout << "\n\nTransaction is Not performed .. " << endl;
    }
}

void DepositScreent (vector <sClient> &vClient )
{
    cout <<   "\n\n===============================================" << endl;
    cout <<   "            Normal Withdraw Screen               " << endl;
    cout <<   "==============================================="  << endl;
    
    PerformDeposit(vClient);

}

void ShowATMMainMenuScreen ()
{
    cout <<   "\n\n===============================================" << endl;
    cout <<   "            ATM Main Menu Screen               " << endl;
    cout <<   "==============================================="  << endl;
    cout <<   "       [ 1 ] Quick Withdraw   " << endl;
    cout <<   "       [ 2 ] Normal Withdraw     " << endl;
    cout <<   "       [ 3 ] Deposit      " << endl;
    cout <<   "       [ 4 ] Check Balance " << endl;
    cout <<   "       [ 5 ] LogOut        " << endl;
    cout <<   "===============================================" << endl;
    cout <<   "Choose what do you want to choose [ 1 to 5 ] ? "<< endl;

}

void StartATMSystem ()
{
  
    vector<sClient> vClients = LoadClientsDataFromFileToVector(ClientFileName);
    

    short Choose = 0;

    do {
        ClearScreen();
        ShowATMMainMenuScreen();
        cin >> ws >> Choose;

switch (Choose) 
{
    case enATMMainMenuScreen::eQuickWithdraw:
        ClearScreen();
        QuickWithdrawScreen(vClients);
        break;

    case enATMMainMenuScreen::eNormalWithdraw:
        ClearScreen();
        NormalWithdrawScreen(vClients);
        break;

    case enATMMainMenuScreen::eDeposit:
        ClearScreen();
        DepositScreent(vClients);
        break;

    case enATMMainMenuScreen::eCheckBalance:
        ClearScreen();
        CheckBalanceScreen(vClients);
        break;

    case enATMMainMenuScreen::eLogout:
        CurrentClient.AccountNumber = "";
        CurrentClient.PinCode = "";
        CurrentClient.AccountBalance = 0;

        ClearScreen();
        break;

    default:

        cout << "\nInvalid Choice .. Try again .. " << endl;
        break;

}

        
        if (Choose != enATMMainMenuScreen::eLogout  ) 
        {
            cout << "\nPress Any key to go back to Main Menu... \n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    
    } while (Choose != enATMMainMenuScreen::eLogout);
}

void Login ()
{

    bool loginFailed = false ;

    do{
       
    ClearScreen();

    cout << "\n_______________________________________"<< endl;
    cout << "              Login Screen            "<< endl;
    cout << "_______________________________________"  << endl;
    vector<sClient> vClient = LoadClientsDataFromFileToVector(ClientFileName);

    if (loginFailed)
    {
        cout << "\nInvalid Account Number / PinCode !\n" ;
    }

    string AccountNumber = ReadAccountNum();
    string PinCode = ReadPinCode(); 
    


        if ( IsValidClientForLogin(vClient , AccountNumber , PinCode))
        {
            loginFailed = false ;
            StartATMSystem();
        
        }
        else 
        {
            loginFailed = true ;
        }
    


} while (1);
}

int main ()
{
  Login();
}