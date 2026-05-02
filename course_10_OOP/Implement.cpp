#include <iostream> 
#include "clsDeveloper.h"
using namespace std;

int main ()
{
    clsDeveloper Dev1 (10 , "Sara" , "Ghannem" , "sara@.com" , 
        "0100288439" , "ENG" , "4" , 50000 , "C++");
        
        Dev1.PrintInfo();
        clsPerson person (3 , "Sara" , "Ghanem" , "gmail.com" , "019823012");
        person.SendEmail("welcom" , "hope you are fine ");
}