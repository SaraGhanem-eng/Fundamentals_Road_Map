#include <iostream>
#include "../HeaderFiles_Ds/clsDynamicArray.h"

using namespace std ;

int main()
{
    clsDynamicArray <int> MyDynamicArr (5);

    MyDynamicArr.SetItem(0 , 10 );
    MyDynamicArr.SetItem(1 , 20 );
    MyDynamicArr.SetItem(2 , 30 );
    MyDynamicArr.SetItem(3 , 40 );
    MyDynamicArr.SetItem(4 , 50 );
    MyDynamicArr.printList();
    cout << "Size : " << MyDynamicArr.Size() << endl;

    MyDynamicArr.InsertAt(4 , 500 );
    MyDynamicArr.printList();
 

    



}