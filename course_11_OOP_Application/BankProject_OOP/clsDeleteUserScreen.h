#pragma once 

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"

using namespace std ;

class clsDeleteUserScreen : protected clsScreen 
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

public:
 
static void ShowDeleteUserScreen()
{
clsScreen::_DrawScreenHeader("\tDelete User Screen");

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

char Sure = 'n';
cout << "\nAre you sure you want to delete this user ? [ Y / y ]" ;
cin >> Sure ;

if (Sure == 'y' || Sure == 'Y')
{

    if (User.Delete())
    {
      cout << "\n\nUser Deleted Successfully :-) \n" ;
      _PrintUser(User) ;
    }
    else 
    {
        cout << "\nError .. User was not deleted \n";
    }

}
else 
{
    cout << "\n\nUser Is Not Deleted ";
}





}


};


