#pragma once 

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"

using namespace std ;

class clsFindUserScreen : protected clsScreen
{
private:

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

public :

static void ShowFindUserScreen()
{
clsScreen::_DrawScreenHeader("\t   Find User Screen");

    string UserName ;
    cout << "Please Entet User name ?" ;
    UserName = clsInputValidate::ReadString();

    while (!clsUser::IsUserExist(UserName))
    {
      cout << "\nUser Name is Not found .. Choose another one " ;
      UserName = clsInputValidate::ReadString();
    }

    clsUser User = clsUser::Find(UserName);

    if (!User.IsEmpty())
    {
       cout << "\nUser is Found Successfully :-) \n";
    }
    else 
    {
        cout << "\nUser Not Found :-(\n";
    }
    _PrintUser(User);

}

};