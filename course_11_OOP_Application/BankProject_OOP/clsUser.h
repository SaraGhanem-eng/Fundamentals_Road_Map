#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsDate.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsString.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsUtil.h"


class clsUser : public clsPerson 
{
public : struct stLoginRegisterRecord;

private:

enum enMode { EmptyMode = 0 , UpdateMode = 1 , AddNewMode = 2 } ;

enMode _Mode ;

string _UserName ;
string _Password ;
int _Permissions = 0 ;

bool _MarkedForDelete = false;


string _GetLoginLine (string delim = "#//#")
{

string Line = "" ;

Line += clsDate::DateToString(clsDate::GetSystemDate()) + " - ";
Line += clsDate::GetSystemTimeString() + delim ;
Line += UserName() + delim ;
Line += clsUtil::EncryptText(Password()) + delim ;
Line += to_string(Permissions()) + delim ;

return Line ;
}

static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line , string Seperator = "#//#")
{

stLoginRegisterRecord LoginRegisterRecord ;

vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);

LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
LoginRegisterRecord.Password = clsUtil::DecryptText (LoginRegisterDataLine[2]);
LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

return LoginRegisterRecord;
}

static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
{
    vector <string> vUserData;
    vUserData = clsString::Split(Line, Seperator);

    return clsUser (enMode::UpdateMode , vUserData[0], vUserData[1], vUserData[2],
        vUserData[3], vUserData[4],clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));

}

static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
{

        string UserRecord = "";
        UserRecord += User.FirstName() + Seperator;
        UserRecord += User.LastName() + Seperator;
        UserRecord += User.Email() + Seperator;
        UserRecord += User.Phone() + Seperator;
        UserRecord += User.UserName() + Seperator;
        UserRecord += clsUtil::EncryptText(User.Password())+ Seperator;
        UserRecord += to_string(User.Permissions());

        return UserRecord;

}

static  vector <clsUser> _LoadUsersDataFromFile()
{

    vector <clsUser> vUsers;

    fstream MyFile;
    MyFile.open("Users.oop.txt", ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            clsUser User = _ConvertLinetoUserObject(Line);
            vUsers.push_back(User);
        }

        MyFile.close();

        }
        return vUsers;

}

static void _SaveUsersDataToFile(vector <clsUser> vUsers)
{

    fstream MyFile;
    MyFile.open("Users.oop.txt", ios::out); //overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (clsUser U : vUsers)
        {
            if (U.MarkedForDeleted() == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = _ConverUserObjectToLine(U);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

}

void _Update()
{
    vector <clsUser> _vUsers;
    _vUsers = _LoadUsersDataFromFile();

    for (clsUser& U : _vUsers)
    {
        if (U.UserName() == UserName())
        {
            U = *this;
            break;
        }

    }

    _SaveUsersDataToFile(_vUsers);

}

void _AddNew()
{

    _AddDataLineToFile(_ConverUserObjectToLine(*this));
}

void _AddDataLineToFile(string  stDataLine)
{
    fstream MyFile;
    MyFile.open("Users.oop.txt", ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }

}

static clsUser _GetEmptyUserObject()
{
    return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
}

public :


enum enPermissions { eAll = -1 , PClientList = 1 , PAddNewClient = 2 , PDeleteClient = 4 , PUpdateClient = 8 
, PFindClient = 16 , PTransactions = 32 , PManageUsers = 64 , PLoginRegister = 128 };

struct stLoginRegisterRecord 
{
  string DateTime ;
  string UserName ;
  string Password ;
  int Permissions ;
};

clsUser(enMode Mode , string FirstName , string LastName , string Email , string Phone 
    , string UserName , string Passowrd , int Permissions ) : clsPerson(FirstName , LastName , Phone , Email )
{
  _Mode = Mode ;
  _UserName = UserName ;
  _Password = Passowrd ;
  _Permissions = Permissions ;

}

void SetUserName (string UserName )
{
    _UserName = UserName ;
}

string UserName()
{
    return _UserName ;
}

void SetPassword (string Password )
{
    _Password = Password ;
}

string Password ()
{
    return _Password ;
}

void SetPermissions (int Permission)
{
    _Permissions = Permission ;
}

int Permissions()
{
    return _Permissions;
}

bool MarkedForDeleted()
{
    return (_MarkedForDelete);
}

bool IsEmpty ()
{
    return (_Mode == enMode::EmptyMode);
}

static clsUser Find (string UserName )
{
    
    fstream MyFile ;
    MyFile.open("Users.oop.txt" , ios :: in );

    if (MyFile.is_open())
    {
      
        string Line;
        while (getline(MyFile, Line))
        {
            clsUser User = _ConvertLinetoUserObject(Line);
            if (User.UserName() == UserName )
            {
                MyFile.close();
                return User;
            }
        }

        MyFile.close();
        
    }

  return _GetEmptyUserObject() ;
}

static clsUser Find (string UserName , string Password )
{
    
    fstream MyFile ;
    MyFile.open("Users.oop.txt" , ios :: in );

    if (MyFile.is_open())
    {
      
        string Line;
        while (getline(MyFile, Line))
        {
            clsUser User = _ConvertLinetoUserObject(Line);
            if (User.UserName() == UserName && User.Password() == Password )
            {
                MyFile.close();
                return User;
            }
        }

        MyFile.close();
        
    }
    return _GetEmptyUserObject();

}

static bool IsUserExist(string UserName)
{

    clsUser User = clsUser::Find(UserName);
    return (!User.IsEmpty());
}

enum enSaveResults {svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 } ;

enSaveResults Save ()
{
    switch (_Mode )
    {
    case enMode::UpdateMode:
    { 
        _Update();
        return enSaveResults::svSucceeded ;
        
        break;
    }
    
    case enMode::AddNewMode:
    {
        if (!IsUserExist(_UserName))
        {
          _AddNew() ;
          _Mode = enMode::UpdateMode ;
          return enSaveResults::svSucceeded;
        }
        else 
        {
            return enSaveResults::svFaildUserExists ;
        }
    }

    case enMode::EmptyMode:
    {
      if (IsEmpty())
      {
        return enSaveResults::svFaildEmptyObject;
      }

    }

    default:
    return enSaveResults::svFaildEmptyObject ;
    break;
    }

}

bool Delete()
{
    vector <clsUser> _vUsers;
    _vUsers = _LoadUsersDataFromFile();

    for (clsUser& U : _vUsers)
    {
        if (U.UserName() == _UserName)
        {
            U._MarkedForDelete = true;
            break;
        }

    }

    _SaveUsersDataToFile(_vUsers);
    *this = _GetEmptyUserObject();

    return true;

}

static clsUser GetAddNewUserObject(string UserName)
{
    return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
}

static vector <clsUser> GetUsersList()
{
    return _LoadUsersDataFromFile();
}

static vector <stLoginRegisterRecord> GetLoginRegisterList ()
{

    vector <stLoginRegisterRecord> vLoginRegisterRecord ;

    fstream MyFile ;
    MyFile.open("LoginRegister.txt" , ios::in );


    if( MyFile.is_open())
    {
        string Line ;
        stLoginRegisterRecord LoginRegisterRecord ;

        while (getline(MyFile , Line ))
        {
           LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);
           vLoginRegisterRecord.push_back(LoginRegisterRecord);
        }
        MyFile.close();
    }
    return vLoginRegisterRecord ;
}

bool CheckAccessPermission (enPermissions Permission )
{
    if ( this->Permissions() == enPermissions::eAll)
    {
        return true ;
    }
    if ((Permission & (this->_Permissions)) == Permission )
    return true ;
    
    else 
    return false ;

}

void LoadUserToRegisterFile () 
{

  fstream MyFile ;
  MyFile.open("LoginRegister.txt" , ios::out | ios::app );

  if (MyFile.is_open())
  {
    MyFile << _GetLoginLine() << endl ;
    MyFile.close();
  }


}


};