#pragma once 

#include <iostream>
#include "clsMyStack.h"

using namespace std ;

class clsMyString
{
protected :

string _value ;
clsMyStack <string> _OriginalStack ;
clsMyStack <string> _HistoryStack ;

public :

string Value ()
{
    return _value ;
}

void SetValue (string val )
{
    _value = val ;
    _OriginalStack.push(val);
}

void Undo ()
{
if (!_OriginalStack.IsEmpty())
{
  _HistoryStack.push(_OriginalStack.Top()) ;   
  _OriginalStack.pop();
  
  if (!_OriginalStack.IsEmpty())
  {
    _value = _OriginalStack.Top();
  }
  else 
  {
    _value = "" ;
  }
}
}

void Redo ()
{
if (!_HistoryStack.IsEmpty())
{
  _OriginalStack.push(_HistoryStack.Top());    
  _value= _HistoryStack.Top();
  _HistoryStack.pop();

}
}
};