#pragma once 

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"

class clsAddNewUSerScreen : protected clsScreen
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

static void ShowAddNewUserScreen ()
{

    clsScreen::_DrawScreenHeader("\t   Add New User Screen");

    cout << "Enter the User Name ? " ;
    string UserName = clsInputValidate::ReadString();

    while (clsUser::IsUserExist(UserName))
    {
      cout << "UserName is already Used .. Choose another one ";
      UserName =  clsInputValidate::ReadString();
    }

    clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

    _ReadUserInfo(NewUser);

    _PrintUser(NewUser);

    clsUser::enSaveResults Result ;

    Result = NewUser.Save();

    switch (Result)
    {
    case clsUser::enSaveResults::svSucceeded :
    {
        cout << "\nUser Saved Successfully :-) \n";
        break;
    }
    case clsUser::enSaveResults::svFaildUserExists :
    {
        cout << "\nError .. User was not saved because UserName is Used ! \n";
        break ;
    }
        
    case clsUser::enSaveResults::svFaildEmptyObject :
    {
        cout << "Error .. User was not saved because it is Empty \n";
    }
        
    
    default:
        break;
    }

     
     
   

    
}




};