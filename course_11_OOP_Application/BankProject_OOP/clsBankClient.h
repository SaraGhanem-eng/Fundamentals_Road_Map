#pragma once 
#include <iostream>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsString.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsUtil.h"


using namespace std ;

class clsBankClient : public clsPerson 
{
private :


enum enMode { EmptyMode = 0 , UpdateMode = 1 , AddNewMode = 2};
enMode _Mode ;

string _AccountNumber ;
string _PinCode ;
double _AccountBalance ;
bool _MarkForDelete = false ;

static clsBankClient _GetEmptyClientObject ()
{
   return clsBankClient(enMode::EmptyMode , "" , "" , "" , "" , "" , "" ,  0) ;
}

static clsBankClient _ConvertLineToClientObject (string line , string delim = "#//#")
{
  vector <string> vClientDate ;
  vClientDate = clsString::Split(line , delim ) ;

  return clsBankClient (enMode::UpdateMode , vClientDate[0] , vClientDate[1] , 
    vClientDate[2] , vClientDate[3] , vClientDate[4] , vClientDate[5]  , stod(vClientDate[6]) ) ;

}

static string _ConvertClientObjectToLine (clsBankClient &Client , string delim = "#//#" )
{
        string stClientRecord = "";
        stClientRecord += Client.FirstName() + delim;
        stClientRecord += Client.LastName() + delim;
        stClientRecord += Client.Phone() + delim;
        stClientRecord += Client.Email() + delim;
        stClientRecord += Client.AccountNumber() + delim;
        stClientRecord += Client.PinCode() + delim;
        stClientRecord += to_string(Client.AccountBalance());

        return stClientRecord;
}

static vector <clsBankClient> _LoadClientsDataFromFile ()
{
  vector < clsBankClient> _vClients ;
  fstream MyFile ;

  MyFile.open("Clients.oop.txt" , ios::in ) ;

  if (MyFile.is_open())
  {
    string Line ;

    while (getline (MyFile , Line ))
    {
      clsBankClient Client =  _ConvertLineToClientObject(Line) ;

      _vClients.push_back(Client);
    }

    MyFile.close() ;

  }
return _vClients ;
    
}

static void _SaveClientsDataToFile (vector < clsBankClient > &vClients )
{
  fstream MyFile ;
  MyFile.open("Clients.oop.txt" , ios::out ) ;  //overwrite 

  string DataLine ;

  if (MyFile.is_open())
  {
    for (clsBankClient &c : vClients )
    {
        if (!c._MarkForDelete)
        { 
        DataLine = _ConvertClientObjectToLine(c) ;
        MyFile << DataLine << endl ;
        }
    }
    MyFile.close();
  }


}

static void _AddDataLineToFile (string Line )
{
        fstream MyFile;
        MyFile.open("Clients.oop.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << Line << endl;

            MyFile.close();
        }
 
}

void _Update()
{
   vector <clsBankClient> _vClients ;
   _vClients = _LoadClientsDataFromFile() ;

   for (clsBankClient &c : _vClients)
   {
      if (c.AccountNumber() == AccountNumber())
      {
         c = *this ;
         break ;
      }

   }

  _SaveClientsDataToFile(_vClients) ;
}

void _AddNew()
{
  _AddDataLineToFile (_ConvertClientObjectToLine(*this));
}


public :
// Important to set Mode as a Parameter curtial for new objects 

clsBankClient(enMode Mode , string FirstName , string LastName , string Phone , string Email ,
    string AccountNumber , string Pincode , double AccountBalance)
     : clsPerson(FirstName , LastName , Phone , Email )
{
    _PinCode = Pincode ;
    _AccountNumber = AccountNumber ;
    _AccountBalance = AccountBalance ;
    _Mode = Mode ;
}

//to set Mode .. private member .
bool IsEmpty ()
{
    return (_Mode == enMode::EmptyMode );
}

// Acc Number has read Only property .
string AccountNumber ()
{
    return _AccountNumber ;
}

void SetPinCode (string PinCode )
{
    _PinCode = PinCode ;
}

string PinCode ()
{
    return _PinCode ;
}

void SetAccountBalance (double AccountBalance )
{
    _AccountBalance = AccountBalance ;
}

double AccountBalance ()
{
    return _AccountBalance ;
}

static clsBankClient Find (string AccountNumber )
{
    
    fstream MyFile ;
    MyFile.open("Clients.oop.txt" , ios::in ) ;
    if (MyFile.is_open())
    {
        string Line ;

        while (getline( MyFile ,Line ))
        {
          clsBankClient Client = _ConvertLineToClientObject(Line);
          
          if (Client.AccountNumber() == AccountNumber )
          {
            MyFile.close();
            return Client ;
          }
        }
        MyFile.close() ;
    }
  return _GetEmptyClientObject() ;
}

static clsBankClient Find (string AccountNumber , string PinCode)
{
    
    fstream MyFile ;
    MyFile.open("Clients.oop.txt" , ios::in ) ;

    if (MyFile.is_open())
    {
        string Line ;

        while (getline( MyFile ,Line ))
        {
          clsBankClient Client = _ConvertLineToClientObject(Line);
          
          if (Client.AccountNumber() == AccountNumber && Client.PinCode() == PinCode)
          {
            MyFile.close();
            return Client ;
          }
        }
        MyFile.close() ;
    }
  return _GetEmptyClientObject() ;
}

static bool IsClientExist (string AccountNumber )
{
    clsBankClient Client1 = clsBankClient::Find(AccountNumber) ;
    return ( !Client1.IsEmpty() );

}  

static vector<clsBankClient> GetClientsList ()
{
    return _LoadClientsDataFromFile() ;
}

bool Delete ()
{
    vector <clsBankClient> vClients = _LoadClientsDataFromFile() ;

    for (clsBankClient &c : vClients )
    {
        if (c.AccountNumber() == AccountNumber())
        {
            c._MarkForDelete = true ;
            break ;
        }
    }
    _SaveClientsDataToFile(vClients);
    *this = _GetEmptyClientObject() ;

    return true ;

}

static double GetTotalBalances ()
{
    vector <clsBankClient> vClients = GetClientsList() ;
    
    double TotalBalance = 0 ;
    for (clsBankClient &Client : vClients  )
    {
       TotalBalance += Client.AccountBalance() ;

    }
   return TotalBalance ;
}

enum enSaveResults {svFailedEmptyObject = 0  , svSucceeded = 1 ,svFailedAccountNumberExist = 2 } ;

enSaveResults Save ()
{
    switch (_Mode)
    {
    case enMode::EmptyMode :
    {
        return enSaveResults::svFailedEmptyObject ;
        break;
    }

    case enMode::UpdateMode :
    { 
       _Update();
       return enSaveResults::svSucceeded ;  
       break ;
    }
 

    case enMode::AddNewMode :
    {
        if (IsClientExist(AccountNumber()))
        {
            return enSaveResults::svFailedAccountNumberExist ;
        }
        else 
        {
          _AddNew();
          _Mode = enMode::UpdateMode ;
          return enSaveResults::svSucceeded ;
        }  
      break ;
    }

    }
}

static clsBankClient _GetAddNewClientObject(string AccountNumber )
{
   return clsBankClient (enMode::AddNewMode , "" , "" , "" , "" , AccountNumber , "" ,  0);
}

void Deposit (double Amount )
{
    _AccountBalance += Amount ;
    Save();
}

bool Withdraw (double Amount )
{
    if (Amount <= _AccountBalance)
    { 
       _AccountBalance -= Amount ;
       Save();
       return true ;
    }  
    else 
    {
        return false ;
    }
}



};