
#include <iostream>
#include "../HeaderFiles_Ds/clsMyString.h"

using namespace std ;

int main()
{
    clsMyString S1 ;
    
    S1.SetValue("");
    cout << "\nS1 = " << S1.Value() << endl;

    S1.SetValue("Sara1");
    cout << "\nS1 = " << S1.Value() << endl;  

    S1.SetValue("Sara2");
    cout << "\nS1 = " << S1.Value() << endl;

    S1.SetValue("Sara3");
    cout << "\nS1 = " << S1.Value() << endl;

    cout << "\nUndo : " << endl;
    cout << "_________________\n\n";


    S1.Undo();
    cout << "\nS1 After undo = " << S1.Value() << endl;  //sara2

    S1.Undo();
    cout << "\nS1 After undo = " << S1.Value() << endl;  // sara1

    S1.Undo();
    cout << "\nS1 After undo = " << S1.Value() << endl; // empty 


    cout << "\nRedo : " << endl;
    cout << "_________________\n\n";

    S1.Redo();
    cout << "\nS1 After Redo = " << S1.Value() << endl;  //sara2

    S1.Redo();
    cout << "\nS1 After Redo = " << S1.Value() << endl;  // sara1

    S1.Redo();
    cout << "\nS1 After Redo = " << S1.Value() << endl; // empty 

}