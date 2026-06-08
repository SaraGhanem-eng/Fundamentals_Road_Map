#include <iostream>
#include "../HeaderFiles_Ds/clsDblLinkedList.h"

using namespace std ;

int main ()
{

    clsDblLinkedList  <int> MydblLinkedList ;


    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);
    
    MydblLinkedList.PrintList();
    MydblLinkedList.InsertAfter(4 , 6);
    MydblLinkedList.PrintList();
    



    

}