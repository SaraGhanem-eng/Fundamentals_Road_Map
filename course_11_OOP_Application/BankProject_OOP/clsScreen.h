#pragma once 
#include <iostream> 

using namespace std ;

class clsScreen 
{
public:

  static void _DrawScreenHeader (string Title, string SubTitle = "" )
  {
    cout << "\n\n\t\t\t\t\t______________________________________\n" << endl;
    cout << "        \t\t\t\t  " << Title << endl;
    if (SubTitle != "")
    {
      cout << "        \t\t\t\t  " << SubTitle << endl;
    }
    cout << "\t\t\t\t\t______________________________________" << endl<< endl << endl;
    
  }
};
