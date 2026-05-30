#include <iostream>
#include "clsLoginScreenMenu.h"

using namespace std;


int main()
{
   while (true)
   { 
    if  (!clsLoginScreenMenu::ShowLoginScreen() )
    {
      break;
    }
   }
}