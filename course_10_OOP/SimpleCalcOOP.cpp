#include <iostream> 
using namespace std;


class clsCalculator 
{
    private:

  
  double _LastResult = 0;
  double _LastNumber = 0 ;
  double _PreviousResult = 0 ;
  string _LastOperation = "Clear" ;

  enum _enLastOperation  {enAdd = 1 , enSubstraction = 2 , enDivition = 3 , enMultiplication = 4 , enClear = 5 , enCancelLastOP = 6};
  
   string _GetLastOperation (_enLastOperation OP)
   {
    if (OP == _enLastOperation::enAdd)
    return "Adding";

    else if (OP == _enLastOperation::enMultiplication)
    return "Multiplying" ;

    else if (OP == _enLastOperation::enDivition)
    return "Dividing" ;

    else if (OP == _enLastOperation::enSubstraction)
    return "Substracting";

    else if (OP == _enLastOperation::enCancelLastOP)
    return "Canceling Last Operation ";

    else 
    return "Clear" ;

   }

   public:
   
   void Clear ()
   {
    _LastResult = 0 ;
    _PreviousResult = _LastResult ;
    _LastNumber = 0 ;
    _LastOperation = _GetLastOperation(_enLastOperation::enClear);
   }

   

   void Add (double Number )
   {
     _LastNumber = Number ;
     _PreviousResult = _LastResult ;
     _LastResult += Number ; 
     _LastOperation = _GetLastOperation(_enLastOperation::enAdd);
   }

   void Substract (double Number )
   {
    _LastNumber = Number ;
    _PreviousResult = _LastResult ;
    _LastResult -= Number ;
    _LastOperation = _GetLastOperation(_enLastOperation::enSubstraction);
   }
  
   void Multiplication (double Number)
   {
    _LastNumber = Number ;
    _PreviousResult = _LastResult ;
    _LastResult *= Number ;
    _LastOperation = _GetLastOperation(_enLastOperation::enMultiplication);
   }

   void Divition (double Number)
   {
    if (Number == 0 ) 
    {
        Number = 1 ;
    }
     _LastNumber = Number ;
     _PreviousResult = _LastResult ;
     _LastResult /= Number ;
     _LastOperation = _GetLastOperation(_enLastOperation::enDivition);
   }

   void PrintResult ()
   {
    cout << "\nResult After " << _LastOperation << " " << _LastNumber << " is : " << _LastResult << endl;
   }

   void CancelLastResult ()
   {
    _LastNumber = 0 ;
    _LastResult = _PreviousResult;
    _LastOperation = _GetLastOperation(_enLastOperation::enCancelLastOP);
    
   }

};

int main()
{
   clsCalculator Calcultator1 ;
   Calcultator1.Clear();

   Calcultator1.Add(10);
   Calcultator1.PrintResult();

   Calcultator1.Multiplication(10);
   Calcultator1.PrintResult();

   Calcultator1.CancelLastResult();
   Calcultator1.PrintResult();


    
}