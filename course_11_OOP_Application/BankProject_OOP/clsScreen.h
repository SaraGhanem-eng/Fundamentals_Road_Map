#pragma once 
#include <iostream> 
#include "clsUser.h"
#include "Global.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsDate.h"

using namespace std ;

class clsScreen 
{
public:



  static void _DrawScreenHeader (string Title, string SubTitle = "" )
  {
      clsDate Date = clsDate::GetSystemDate();
      string SDate = clsDate::DateToString(Date);

    cout << "\n\n\t\t\t\t\t______________________________________\n" << endl;
    cout << "        \t\t\t\t  " << Title << endl;
    if (SubTitle != "")
    {
      cout << "        \t\t\t\t  " << SubTitle << endl;
    }
    cout << "\t\t\t\t\t______________________________________" << endl<< endl ;
    cout << "\t\t\t\t\tUser :" << CurrentUser.UserName() << endl;
    cout << "\t\t\t\t\t" << SDate << endl<< endl << endl;

    
  }

  static bool CheckAccessRights (clsUser::enPermissions Permission )
  {
    if (CurrentUser.CheckAccessPermission(Permission))
    {
      return true ;
    }
    else 
    {
      cout << "\n\n\t\t\t\t\t______________________________________\n" << endl;
      cout << "\t\t\t\t\t  Access Denied ! Contact Your Admin \n";
      cout << "\t\t\t\t\t______________________________________" << endl<< endl << endl; 
      return false ;
    }
  }


};
