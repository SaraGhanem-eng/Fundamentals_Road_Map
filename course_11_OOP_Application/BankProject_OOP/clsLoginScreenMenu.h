#pragma once 

#include <iostream>
#include <fstream>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsDate.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsInputValidation.h"
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsUtil.h"

class clsLoginScreenMenu : protected clsScreen
{

private :


static bool _Login()
{

    bool LoginFailed = false ;
    string UserName , Passowrd ;

    int LoginTimes = 3 ;
    do
    {
        if (LoginFailed)
        {
            cout << "\nInvalid UserName / Passowrd !\n";
            cout << "You have " << LoginTimes - 1 << " Trial(s) to login .\n" ;
            LoginTimes-- ;
        }

        if (LoginTimes == 0 )
        { 
            cout << "\nYou are Looked after 3 failed Trials !\n\n";
            return false ;
        }

        cout << "\nEnter UserName ? ";
        UserName = clsInputValidate::ReadString();

        cout << "\nEnter Password ? " ;
        Passowrd = clsInputValidate::ReadString();

        CurrentUser = clsUser::Find(UserName , Passowrd);
 
        LoginFailed = CurrentUser.IsEmpty();
        


    } while (LoginFailed && LoginTimes > 0) ;
    

    CurrentUser.LoadUserToRegisterFile();
    clsMainScreen::ShowMainMenu(); 
    
    return true; 

}

public :

static bool ShowLoginScreen()
{
 
     
    clsUtil::ResetScreen();
    clsScreen::_DrawScreenHeader("\t     Login Screen");
    return  _Login();

}


};