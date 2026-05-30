#pragma once 

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"

using namespace std ;

class clsUpdateUsersScreen : protected clsScreen 
{

private :

static void _PrintUser(clsUser User )
{

    cout << "\nUser Card :";
    cout << "\n_________________________";
    cout << "\nFirstName   : " << User.FirstName();
    cout << "\nLastName    : " << User.LastName();
    cout << "\nFull Name   : " << User.FullName();
    cout << "\nEmail       : " << User.Email();
    cout << "\nPhone       : " << User.Phone();
    cout << "\nUser Name   : " << User.UserName();
    cout << "\nPassword    : " << User.Password();
    cout << "\nPermissions : " << User.Permissions();
    cout << "\n_________________________\n";

}

static void _ReadUserInfo (clsUser & User )
{
    cout << "\nUpdat User Info "<< endl;
    cout << "__________________________\n" ; 
    cout << "\nEnter First Name : " ;
    User.SetFirstName(clsInputValidate::ReadString());

    cout << "\nEnter Last Name : " ;
    User.SetLastName(clsInputValidate::ReadString());

    cout << "\nEnter Email : " ;
    User.SetEmail(clsInputValidate::ReadString());

    cout << "\nEnter Phone : ";
    User.SetPhone(clsInputValidate::ReadString()) ;

    cout << "\nEnter Passowrd : " ;
    User.SetPassword(clsInputValidate::ReadString()) ;

    cout << "\nEnter Permissions : " ;
    User.SetPermissions(_ReadPermissionsToSet()) ;
}

static int _ReadPermissionsToSet ()
{
    int Permissions = 0 ;
    char Answer = 'n';

    
    cout << "\n\nDo you want to give full access ? [ Y / N ]" ;
    cin >> Answer ;
    if (Answer == 'Y' || Answer == 'y')
    {
        return -1 ;
    } 
    cout << "\n\nDo You want to give access to : \n" ;

    cout << "\nShow Client List ? Y/N ";
    cin >> Answer ;

    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += clsUser::enPermissions::PClientList ;
    }
    

    cout << "\nAdd New Client ? Y/N ";
    cin >> Answer ;

    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += clsUser::enPermissions::PAddNewClient ;
    }

    cout << "\nDelete Client ? Y/N ";
    cin >> Answer ;

    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += clsUser::enPermissions::PDeleteClient ;
    }

    cout << "\nUpdate Client ? Y/N ";
    cin >> Answer ;

    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += clsUser::enPermissions::PUpdateClient ;
    }


    cout << "\nFind Client ? Y/N ";
    cin >> Answer ;

    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += clsUser::enPermissions::PFindClient ;
    }

    cout << "\nTransactions ? Y/N ";
    cin >> Answer ;

    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += clsUser::enPermissions::PTransactions ;
    }
 
    cout << "\nManage Users ? Y/N ";
    cin >> Answer ;

    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += clsUser::enPermissions::PManageUsers ;
    }


    cout << "\nLogin Register ? Y/N ";
    cin >> Answer ;

    if (Answer == 'Y' || Answer == 'y')
    {
        Permissions += clsUser::enPermissions::PLoginRegister ;
    }
    return Permissions ;
}

public :

static void ShowUpdateUsersScreen ()
{
    clsScreen::_DrawScreenHeader("\tUpdate User Screen");

    string UserName ;
    cout << "Please Entet User name ?" ;
    UserName = clsInputValidate::ReadString();

    while (!clsUser::IsUserExist(UserName))
    {
      cout << "\nUser Name is Not found .. Choose another one " ;
      UserName = clsInputValidate::ReadString();
    }

    clsUser User = clsUser::Find(UserName);

    _PrintUser(User);

    char sure = 'n';

    cout << "\nAre you sure you want to update this user ? ";
    cin >> sure ;

    if (sure == 'y' || sure == 'Y')
    {
      _ReadUserInfo(User);

      
      clsUser::enSaveResults  SaveResult ;
      SaveResult = User.Save();
  
      switch (SaveResult)
      {
      case clsUser::svSucceeded:
      {
        cout << "\nUser Updated Successfully :-)\n" ;
        break;
      }  
      
      case clsUser::svFaildEmptyObject:
      {
        cout << "\nError .. Failed to Save (Empty User) :-( \n";
        _PrintUser(User); 
      }
      
      default:
        break;
      }

    }
    else 
    {
        cout << "\nUser is not updated \n";
    }

}



};