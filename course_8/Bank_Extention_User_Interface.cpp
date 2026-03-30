#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientFileName = "Client.txt" ;
const string UserFileName = "Users.txt" ;

enum enMainMenuScreenItems {  ShowClientList = 1 , AddNewClients = 2 , DeleteClient = 3 , UpdateClientInfo = 4
    , FindClient = 5 ,Transactions = 6 , ManageUsers = 7 , Logout = 8  };

enum enTransactionsItems {Deposit = 1 , Withdraw =2 , TotalBalances = 3 , MainMenuFromTransaction = 4  };

enum enManageUserScreenItems { ListUsers = 1 , AddNewUser = 2 , DeleteUser = 3 ,
                              UpdateUser = 4 , FindUserItem = 5 , MainMenuFromUser = 6 };

enum enPermissonsAccess { AllPermissions = -1 , ShowClientLestAccess = 1 , AddNewClientAccess = 2,
                          DeleteClientAccess = 4, UpdateClientAccess = 8, 
                          FindClientAccess = 16, TransactionsAccess = 32, ManageUsersAccess = 64 };

struct sClient
{
    string AccountNumber = " " ;
    string PinCode = " ";
    string Name = " " ;
    string Phone = " " ;
    double AccountBalance = 0 ;
    bool MarkForDelete = false ;
};

struct sUser
{
  string UserName ;
  string passowrd ;
  short Permessions = 0 ;
  bool MarkForDelete = false ;
};

sUser CurrentUser ; // global variabl 

bool CheckAccessPermission (enPermissonsAccess permession )
{
    if (CurrentUser.Permessions == enPermissonsAccess::AllPermissions)
    return true ;

    return  ((permession & CurrentUser.Permessions) == permession);
    
}

void PrintDenyMessage()
{
    cout << "\n_______________________________________" << endl;
    cout << "Access Denied! " << endl;
    cout << "You do not have permission to do this." << endl;
    cout << "Please contact your Admin." << endl;
    cout << "\n_______________________________________" << endl;
    
    cout << "\n\nPress Enter key to go back to Main Menu... \n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

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

string ReadPassword ()
{
    string passowrd ;
    cout << "Enter passowrd ? ";
    getline (cin >> ws , passowrd);
    return passowrd;
}

string ReadUsername ()
{
    string username ;
    cout << "Enter username ? " ;
    getline(cin >> ws , username);
    return username ;
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

string ConverUserDataToLine (sUser user , string delimiter = "#//#")
{
    string UserLine = "" ;

    UserLine += user.UserName + delimiter ;
    UserLine += user.passowrd + delimiter ;
    UserLine += to_string (user.Permessions) + delimiter;
    
    return UserLine ;
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

void AddUserToFile ( string UserFileName , string UserLine )
{
    fstream MyFile2 ;
    MyFile2.open( UserFileName ,ios::out | ios::app );

    if (MyFile2.is_open())
    {
        MyFile2 << UserLine  << endl;
        MyFile2.close() ;

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

sUser ConvertUserLineToStruct (string line , string delimiter = "#//#")
{
    sUser User ;
    vector <string> vUsersData ;
    vUsersData = SplitString(line , delimiter );

    
    User.UserName = vUsersData[0] ;
    User.passowrd = vUsersData[1] ;
    User.Permessions = stoi (vUsersData[2]) ;


    return User ;

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

vector <sUser> LoadUserDataFromFileToVector (string FileName)
{

    fstream MyFile2 ;
    MyFile2.open(FileName , ios :: in);

    vector <sUser> vUsers ;

    if (MyFile2.is_open())
    {
        string line ;
        sUser user ;

        while (getline(MyFile2 , line ))
        {
         user = ConvertUserLineToStruct(line);
         vUsers.push_back(user);
        }
        MyFile2.close();

    }
    return vUsers ;
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

void LoadUserDataToFile (string FileName , vector <sUser> & vUsers )
{
    fstream MyFile2 ;
    MyFile2.open(FileName , ios::out );
    string line ;

    if (MyFile2.is_open())
    {
        for (sUser &c : vUsers )
        {
           if (c.MarkForDelete != true )
            {
                MyFile2 << ConverUserDataToLine(c) << endl;
            }
          
        }
          MyFile2.close() ;
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

bool IsUserAlreadyExist (string UserName , vector <sUser> &vUsers )
{

    for (sUser c : vUsers)
    {
     if (UserName == c.UserName )
     {
        return true ;
     }

    }
    return false ;
}

bool FindUser(string UserName , vector <sUser> &vUsers , sUser &user)
{
    for (sUser c : vUsers)
    {
     if (UserName == c.UserName )
     {
        user = c ;
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

    AddClientToFile(  ClientFileName , ConvertClientDataToLine(NewClient));
    cout << "\n Client is added successfully \n";

}

int ReadUserPermissions ()
{
  int permissions = 0 ;
  char access = 'y';


  cout << "\nDo you want ot give full access ? Y/N ";
  cin >> access ;
  if (access == 'y' || access == 'Y')
  {
    return -1 ;
  }
  cout << "\nDo you want to give access to : " << endl;

  cout << "\nShow Client List ? Y/N " ;
  cin >> access ;
  if (access == 'y' || access == 'Y')
  {
    permissions = permissions | enPermissonsAccess::ShowClientLestAccess ;
  }
  
  cout << "\nAdd New Client ? Y/N " ;
  cin >> access ;
  if (access == 'y' || access == 'Y')
  {
    permissions = permissions | enPermissonsAccess::AddNewClientAccess ;
  }

  cout << "\nDelete Client ? Y/N " ;
  cin >> access ;
  if (access == 'y' || access == 'Y')
  {
    permissions = permissions | enPermissonsAccess::DeleteClientAccess ;
  }
  
  cout << "\nUpdate Client ? Y/N " ;
  cin >> access ;
  if (access == 'y' || access == 'Y')
  {
    permissions = permissions | enPermissonsAccess::UpdateClientAccess ;
  }

  cout << "\nFind Client ? Y/N " ;
  cin >> access ;
  if (access == 'y' || access == 'Y')
  {
    permissions = permissions | enPermissonsAccess::FindClientAccess ;
  }

  cout << "\nTransactions ? Y/N " ;
  cin >> access ;
  if (access == 'y' || access == 'Y')
  {
    permissions = permissions | enPermissonsAccess::TransactionsAccess ;
  }

  cout << "\nManage Users ? Y/N " ;
  cin >> access ;
  if (access == 'y' || access == 'Y')
  {
    permissions = permissions | enPermissonsAccess::ManageUsersAccess ;
  }

  return permissions;
}

void AddOneUserToFile (vector <sUser> &vUsers )
{
   sUser user ;
    
   string username = ReadUsername();
   while (IsUserAlreadyExist( username ,vUsers))
   {
    cout << "\nUser with [ " << username << " ] already exist , ";
    username = ReadUsername();
   }
   string passowrd = ReadPassword() ;
   user.UserName = username;
   user.passowrd = passowrd;
   user.Permessions = ReadUserPermissions();
   

   vUsers.push_back(user);
   AddUserToFile(UserFileName , ConverUserDataToLine(user));
   

}

void AddingNewClientsScreen(vector< sClient > &vClients)
{
    if (!CheckAccessPermission(enPermissonsAccess::AddNewClientAccess))
    {
      PrintDenyMessage();
      return ;
    }
    

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

void AddingNewUsersScreen (vector < sUser > &vUser )
{
    cout << "\n\n______________________________________" << endl;
    cout << "           Add New Users Screen          " << endl;
    cout << "______________________________________\n" << endl;
    cout << "Adding New Users : \n ";

    char AddMore = 'y' ;
        do {
         AddOneUserToFile(vUser);
         cout << "\nUser added successfully , Do you need to add more clients ? Y/N " << endl;
         cin >> AddMore;

       } while (AddMore == 'y' || AddMore == 'Y');

}

void ShowATMMainMenuScreen ()
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
    cout <<   "       [ 7 ] Manage Users        " << endl;        
    cout <<   "       [ 8 ] Logout        " << endl;
    cout <<   "===============================================" << endl;
    cout <<   "Choose what do you want to choose [ 1 to 8 ] ? "<< endl;

}

void ShowManageUsersMenuScreen ()
{
        cout <<   "\n\n===============================================" << endl;
    cout <<   "             Manage User Menu Screen               " << endl;
    cout <<   "==============================================="  << endl;
    cout <<   "       [ 1 ] List Users       " << endl;
    cout <<   "       [ 2 ] Add New User     " << endl;
    cout <<   "       [ 3 ] Delete User      " << endl;
    cout <<   "       [ 4 ] Update User      " << endl;
    cout <<   "       [ 5 ] Find user        " << endl;
    cout <<   "       [ 6 ] Main Menu        " << endl;
    cout <<   "===============================================" << endl;
    cout <<   "Choose what do you want to choose [ 1 to 6 ] ? "<< endl;
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

void PrintHeaderOfUserList (short NumberOfUsers )
{
    cout << "_______________________________________________________________________________________________________" << endl;
    printf("                         Users List ( %d ) User (s)                              "
       , NumberOfUsers ) ;
    cout << "\n_______________________________________________________________________________________________________" << endl ;
    cout << " | " << left << setw(40) << "User Name";
    cout << " | " << left  << setw(20) << "User Password" ;
    cout << " | " << left  << setw(10) << "User Permettions" ;
    cout << endl << endl;


}

void PrintOneUserInManageUsersMenu (sUser &user )
{
    cout << " | " << left   << setw(40) << user.UserName;
    cout << " | " << left   << setw(20) << user.passowrd ;
    cout << " | " << left   << setw (10) << user.Permessions;
}

void PrintOneClientInMainMenu ( sClient &client )
{
    cout << " | " << left   << setw(15) << client.AccountNumber;
    cout << " | " << left   << setw(10) << client.PinCode ;
    cout << " | " << left   << setw (40) << client.Name;
    cout << " | " << left   << setw (12) << client.Phone;
    cout << " | " << left   << setw (12) << client.AccountBalance ;


}

double PrintOneClientInBalanceMenu (sClient &client)
{
    cout << " | " << left   << setw(15) << client.AccountNumber;
    cout << " | " << left   << setw (40) << client.Name;
    cout << " | " << left   << setw (12) << client.AccountBalance ;
    return client.AccountBalance ;

}

void PrintClientsShow (vector <sClient> &vClients )
{
    if (!CheckAccessPermission(enPermissonsAccess::ShowClientLestAccess))
    {
      PrintDenyMessage();
      return ;
    }

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

void PrintUsersShow (vector <sUser> &vUsers )
{
   PrintHeaderOfUserList(vUsers.size());
    
    if (vUsers.size() == 0 )
    {
        cout << "No Users Available in the system ... " << endl;
    }
    else 

    {  
       for ( sUser &user  : vUsers)
       {
       PrintOneUserInManageUsersMenu(user);
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

void MarkUserToBeDeletedByUserName (string username , vector < sUser > &vUsers)
{
    for (sUser &user : vUsers )
    {
     if (username == user.UserName)
     {
        user.MarkForDelete = true ;
        break;
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

void PrintUserCard (sUser user )
{
    cout << "\nThe following is the user details    : " << endl;
    cout << "_______________________________________" << endl;
    cout << "User Name    : " << user.UserName << endl;
    cout << "Passowrd     : " << user.passowrd << endl;
    cout << "Permissions  : " << user.Permessions << endl;
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
             vClients = LoadClientsDataFromFileToVector(ClientFileName);

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
    if (!CheckAccessPermission(enPermissonsAccess::DeleteClientAccess))
    {
      PrintDenyMessage();
      return ;
    }
    

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

void DeleteUserByUserName (string username , vector <sUser> &vUsers)
{
   sUser user ;

    if (FindUser(username , vUsers , user  ))
    {
        if (username == "Admin")
        {
            cout << "\n\nAdmin can Not be deleted .. " << endl;
            return ;
        }

     char sure ;   
     PrintUserCard(user);
     cout << "\n\nAre you sure you want to delete this user ? Y/N" ;
     cin >> sure ;

     if (sure == 'y' || sure == 'Y')
     {
        MarkUserToBeDeletedByUserName(username , vUsers);
        LoadUserDataToFile(UserFileName , vUsers);

     }
     else 
     {
        cout << "\n\nUser is Not deleted .. " << endl;
     }
    }
    else 
    {
        cout << "\nUser with [ "<< username << " ] is not found .. " << endl;
    }
}

void DeletUserScreen (vector < sUser > &vUsers)
{

    cout << "\n_______________________________________" << endl;
    cout << "            Delete User Screen          "<< endl;
    cout << "_______________________________________" << endl;


    char DeleteMore ;
     
    do{   
        
         string username = ReadUsername() ;
         DeleteUserByUserName(username , vUsers );

         cout << "\n\n Do you want to delete another user ? Y/N " ;
         cin >> DeleteMore ;

    } while ( DeleteMore == 'y' || DeleteMore == 'Y');
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

sUser ReadUserInfoToUpdate (string username )
{
  sUser user ;

  user.UserName = username ;
  user.passowrd = ReadPassword();
  user.Permessions = ReadUserPermissions();

  return user ;
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

vector<sUser> UpdateUsersDataAfterEdit (string UserName, sUser &user , vector <sUser> &vUsers )
{

    for (sUser &c : vUsers) // By ref to make sure that the User record is updated .
    {
        if (c.UserName == UserName)
        {
            c = user ;
            break;
        }
    }

    return vUsers ;
}

void UpdateClientInformationByAccountNumber  (string accountNum , vector <sClient> &clients )
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

void UpdateUserInformationByUserName (vector <sUser> &vUsers )
{
    sUser user ;
    string username = ReadUsername();


    if (FindUser(username , vUsers , user ))
    {
       char sure ;
       PrintUserCard(user);
       cout << "\nAre you sure you want to update this user ? ";
       cin >> sure ;

       if (sure == 'Y' || sure == 'y')
       {
         user = ReadUserInfoToUpdate(username);
         vUsers = UpdateUsersDataAfterEdit(username , user , vUsers);
         LoadUserDataToFile(UserFileName, vUsers);

        cout << "\nUser with ( " << username << " ) Usuername has been updated successfully \n" << endl;

       }

    }
    else 
    {
        cout << "\nUser with [ " << username << " ] is not found ";
    }


}

void UpdateClientInfoScreen (vector<sClient> & vClients )
{
    if (!CheckAccessPermission(enPermissonsAccess::UpdateClientAccess))
    {
      PrintDenyMessage();
      return ;
    }
    

    cout << "\n_______________________________________" << endl;
    cout << "         Update Client Info Screen           "<< endl;
    cout << "_______________________________________" << endl;

    bool UpdateAgain = 0 ;
    do {
         UpdateClientInformationByAccountNumber (ReadAccountNum(), vClients);
         cout << "Do you want to update another client ? YES [ 1 ] , NO [ 0 ] " ;
         cin >> UpdateAgain ;

        } while (UpdateAgain);


}

void UpdateUserInfoScreen (vector <sUser> &vUsers)
{
    cout << "\n_______________________________________" << endl;
    cout << "        Update User Info Screen           "<< endl;
    cout << "_______________________________________" << endl;

    char UpdateAgain = 0 ;
    do {
        
         UpdateUserInformationByUserName(vUsers);

         cout << "Do you want to update another User ? Y/N " ;
         cin >> UpdateAgain ;
        } while (UpdateAgain == 'y' || UpdateAgain == 'Y');



}

void FindClientShow (vector <sClient > & vClients)
{
    if (!CheckAccessPermission(enPermissonsAccess::FindClientAccess))
    {
      PrintDenyMessage();
      return ;
    }
    

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

void FindUserShow (vector <sUser> &vUsers)
{
    cout << "\n_______________________________________" << endl;
    cout << "            Find Client Screen          "<< endl;
    cout << "_______________________________________" << endl;

    sUser user ;
    string username = ReadUsername();
    while (!FindUser(username, vUsers , user ))
    {
        cout << "\nUser with [ " << username << " ] is not exist .. Try another user name ";
        getline(cin >> ws , username );
    }

    PrintUserCard(user);

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
    printf("                         Balances List ( %zu ) Client (s)                              "
       , vClients.size() ) ;
    cout << "\n_______________________________________________________________________________________________________" << endl ;
    cout << " | " << left << setw(15) << "Account Number";
    cout << " | " << left  << setw (40) << "Client Name";
    cout << " | " << left << setw (12) << "Balance" ;
    cout << endl;
    cout << "_______________________________________________________________________________________________________" << endl;

    long double TotalBalances = 0 ;
    if (vClients.size() == 0 )
    {
        cout << "No clients available in the system ... "<< endl;
    }
    else
    {
        

        for (sClient &client : vClients)
        {
            TotalBalances += PrintOneClientInBalanceMenu(client);
            cout << endl;
        }
    }
    cout << "\n_______________________________________________________________________________________________________\n" << endl;
    cout << "Total Balances of all Bank accounts is : " << TotalBalances << endl;

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

void StartTransactionScreen(vector<sClient>& vClients)
 {

    if (!CheckAccessPermission(enPermissonsAccess::TransactionsAccess))
    {
      PrintDenyMessage();
      return ;
    }
    
    short Choose = 0;

    do {
        ClearScreen();
        ShowTransactionMenuScreen();
        cin >> Choose;

        if (Choose == enTransactionsItems::Deposit) {
            ClearScreen();
            DepositScreen(vClients);
        }
        else if (Choose == enTransactionsItems::Withdraw) {
            ClearScreen();
            WithDrawScreen(vClients);
        }
        else if (Choose == enTransactionsItems::TotalBalances) {
            ClearScreen();
            ShowTotalBalanceScreen(vClients);
        }
        else if (Choose == enTransactionsItems::MainMenuFromTransaction) {
            ClearScreen();
            return; 
        }
        else {
            cout << "\nInvalid Choice .. Try again ..\n";
        }

       
        cout << "\n\nPress Enter key to go back to Transactions Menu... ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

    } while (Choose != enTransactionsItems::MainMenuFromTransaction );
}

void StarUsersManageMenueScreen ()
{
    if (!CheckAccessPermission(enPermissonsAccess::ManageUsersAccess))
    {
      PrintDenyMessage();
      return ;
    }
    

  short Choose = 0 ; 
  vector <sUser> vUsers = LoadUserDataFromFileToVector(UserFileName);
  do
  {
    

   ClearScreen();
   ShowManageUsersMenuScreen();

   cin >> ws >> Choose ;

   if (Choose == enManageUserScreenItems::ListUsers)
   {
    ClearScreen();
    PrintUsersShow(vUsers);
   }
   else if (Choose == enManageUserScreenItems::AddNewUser)
   {
     ClearScreen();
     AddingNewUsersScreen(vUsers);
   }
   else if (Choose == enManageUserScreenItems::DeleteUser )
   {
     ClearScreen();
     DeletUserScreen(vUsers);
   }
   else if (Choose == enManageUserScreenItems::UpdateUser)
   {
       ClearScreen();
       UpdateUserInfoScreen(vUsers);
   }
   else if (Choose == enManageUserScreenItems::FindUserItem)
   {
       ClearScreen();
       FindUserShow(vUsers);
   }
   else if (Choose == enManageUserScreenItems::MainMenuFromUser)
   {
    return ;
   }
   else 
   {
    cout << "\nInvalid Choice .. Try again ..\n";
   }
   
    cout << "\nPress any key to go back to Manage Users Menu Screen ... \n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();


  } while (Choose != enManageUserScreenItems::MainMenuFromUser);
}

bool IsValidUserForLogin (vector <sUser> & vUsers , string username , string passowrd  )
{
   for (sUser &c :vUsers )
   {
    if (c.passowrd == passowrd && c.UserName == username )
    {
        CurrentUser = c ;
        return true ;
    }
   }
   return false ;
}

void StartApp() 
{
    
    vector<sClient> vClients = LoadClientsDataFromFileToVector(ClientFileName);
    

    short Choose = 0;

    do {
        ClearScreen();
        ShowATMMainMenuScreen();
        cin >> ws >> Choose;

        if (Choose == enMainMenuScreenItems::ShowClientList) {
                ClearScreen();
                PrintClientsShow(vClients);
        }
        else if (Choose == enMainMenuScreenItems::AddNewClients) {
            ClearScreen();
            AddingNewClientsScreen(vClients);
        }
        else if (Choose == enMainMenuScreenItems::DeleteClient) {
            ClearScreen();
            DeletingClientsShow(vClients);
        }
        else if (Choose == enMainMenuScreenItems::UpdateClientInfo) {
            ClearScreen();
            UpdateClientInfoScreen(vClients);
        }
        else if (Choose == enMainMenuScreenItems::FindClient) {
            ClearScreen();
            FindClientShow(vClients);
        }
        else if (Choose == enMainMenuScreenItems::Transactions) {
            ClearScreen();
            StartTransactionScreen(vClients);
        }
        else if (Choose == enMainMenuScreenItems::ManageUsers){
            ClearScreen();
            StarUsersManageMenueScreen();
        }
        else if (Choose == enMainMenuScreenItems::Logout) {
           
            CurrentUser.UserName = "";
            CurrentUser.passowrd = "";
            CurrentUser.Permessions = 0;
            CurrentUser.MarkForDelete = false;

            ClearScreen();
            break;
        }
        else {
            cout << "\nInvalid Choice .. Try again .. " << endl;
        }

        
        if (Choose != enMainMenuScreenItems::Logout && Choose != enMainMenuScreenItems::Transactions && 
            Choose != enMainMenuScreenItems::ManageUsers ) {
            cout << "\nPress Enter key to go back to Main Menu... \n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    
    } while (Choose != enMainMenuScreenItems::Logout);
}

void Login ()
{

    bool loginFailed = false ;

    do{
       
    ClearScreen();

    cout << "\n_______________________________________"<< endl;
    cout << "              Login Screen            "<< endl;
    cout << "_______________________________________"  << endl;
    vector<sUser> vUsers = LoadUserDataFromFileToVector(UserFileName);

    if (loginFailed)
    {
        cout << "\nInvalid Username / Passowrd !\n" ;
    }

    string username = ReadUsername();
    string passowrd = ReadPassword(); 
    


        if ( IsValidUserForLogin(vUsers , username , passowrd))
        {
            loginFailed = false ;
            StartApp();
        
        }
        else 
        {
            loginFailed = true ;
        }
    


} while (1);
}

int main()
{
    Login();
    return 0 ;

}