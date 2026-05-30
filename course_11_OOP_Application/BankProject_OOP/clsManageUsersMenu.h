#pragma once 

#include <iostream> 
#include <iomanip>
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUsersScreen.h"
#include "clsFindUserScreen.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsUtil.h"

using namespace std ;

class clsManageUsersMenu : protected clsScreen
{
enum enManageUsersMenuOptions {eListUsers =1 , eAddNewUser = 2 , eDeletUser = 3 ,
     eUpdateUser = 4 , eFindUser = 5 , eUMainMenu = 6 } ;  

static short _ReadUserMenuOption ()  
{
    short Choice = 1 ;
    cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 6 ]" ;
    cin >> Choice ;
    while (Choice < 1 || Choice > 6 )
    {   
        Choice = clsInputValidate::ReadIntNumberBetween(1 , 8 , "Enter Number Between 1 to 6 ");
    }
    return Choice ;  
}
  
static void _GoBackToMnageUsersMenu ()
{
    cout <<  "\nPress [ Enter ] to Go Back To Users Menue ... \n" ;
    cin.ignore(numeric_limits<streamsize> :: max(), '\n') ;
    cin.get() ;
        
    ShowManageUsersMenu() ;
        
    }

static void _ShowUsersListScreen()
{
  clsListUsersScreen::ShowUsersList() ;
}

static void _ShowAddNewUserScreen()
{
  clsAddNewUSerScreen::ShowAddNewUserScreen();
}

static void _ShowDeleteUserScreen()
{
  clsDeleteUserScreen::ShowDeleteUserScreen();
}

static void _ShowUpdateUserScreen ()
{
  clsUpdateUsersScreen::ShowUpdateUsersScreen();
}

static void _ShowFindUserScreen()
{
  clsFindUserScreen::ShowFindUserScreen() ;
}

static void _PerformUserMenuOption (enManageUsersMenuOptions Option) 
{
  switch (Option)
  {

    case enManageUsersMenuOptions::eListUsers:
    {
      clsUtil::ResetScreen();
      _ShowUsersListScreen();
      _GoBackToMnageUsersMenu();
      break;
    }
 

    case enManageUsersMenuOptions::eAddNewUser:
    {
      clsUtil::ResetScreen();  
      _ShowAddNewUserScreen();
      _GoBackToMnageUsersMenu();
      break;
    }

    case enManageUsersMenuOptions::eDeletUser:
    {
      clsUtil::ResetScreen();  
      _ShowDeleteUserScreen();  
      _GoBackToMnageUsersMenu();
      break;
    }

    case enManageUsersMenuOptions::eUpdateUser:
    {
      clsUtil::ResetScreen();  
      _ShowUpdateUserScreen();  
      _GoBackToMnageUsersMenu();
      break;
    }

    case enManageUsersMenuOptions::eFindUser:
    {
      clsUtil::ResetScreen();
      _ShowFindUserScreen();  
      _GoBackToMnageUsersMenu();
      break;
    }

    case enManageUsersMenuOptions::eUMainMenu:
    {
      //Will Asd to Go Back directly to Main Menu
    }
    
  
  default:
    break;
  }
}    





public :

static void ShowManageUsersMenu()
{

    if (!CheckAccessRights(clsUser::enPermissions::PManageUsers))
    {
      return ;
    }

        clsUtil::ResetScreen();
        clsScreen::_DrawScreenHeader("\t   Manage Users Screen");

        cout << setw(37) << left << ""  << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tManage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Users List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformUserMenuOption(enManageUsersMenuOptions(_ReadUserMenuOption()));


}

};