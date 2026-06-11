#pragma once 

#include <iostream>
using namespace std ;

template < class T> 
class clsDynamicArray 
{
protected:
int _Size = 0 ;
T* _TempArray ;

public :
T* MyDynamicArr ;

clsDynamicArray(int size = 0 )  
{
   if (size < 0 )
   size = 0 ;

  _Size = size ;
   MyDynamicArr = new T[ _Size ];
}

~clsDynamicArray()
{
    delete[] MyDynamicArr ;
}

bool  SetItem(int index , T Item )
{
    if (index < 0 || index >= _Size )
    return false ;

    MyDynamicArr[index] = Item ;
    return true ;

}

int Size()
{
    return _Size ;
}

bool IsEmpty()
{
   return  (_Size == 0 ? true : false );
}

void printList ()
{
    if (_Size == 0 || MyDynamicArr == NULL )
    {
        cout << "\nArray is empty\n";
        return ;
    }
   
    for (int i = 0 ; i < _Size ; i++ )
    {
        cout << MyDynamicArr[i] << "   " ;
    }
}

void Resize(int NewSize )
{
   if (NewSize < 0 )
   {
    NewSize = 0 ;
   }

    _TempArray = new T [NewSize] ;

   int ElementsToCopy = (NewSize < _Size ? NewSize : _Size) ;

   for (int i = 0 ; i < ElementsToCopy; i++ )
   {
     _TempArray[i] = MyDynamicArr[i];
   }
   delete[] MyDynamicArr ;
   MyDynamicArr = _TempArray ;
   _Size = NewSize ;
   

}

void Clear ()
{
  delete [] MyDynamicArr ;
  _Size = 0 ;
  MyDynamicArr = nullptr ;
}

void Reverse ()
{
    if (_Size <= 1 ) return ;

   _TempArray = new T [_Size] ;
    int size = _Size -1 ;

   for (int i = size ; i >= 0 ; i--)
   {
    _TempArray[_Size - i - 1] = MyDynamicArr[i] ;
   }
   delete[] MyDynamicArr ;
   MyDynamicArr = _TempArray ;

}

T GetItem (int index)
{
  if (index < 0 || index >= _Size)
  {
    cout << "\nItem does not exist \n";
    return 0 ;
  }
  return MyDynamicArr[index] ;
}

bool DeleteItemAt(int index)
{
    if (index < 0 || index > (_Size - 1))
    {
        return false ;
    }
    int NewSize = _Size -1 ;
    T* _TempArray = new T [NewSize] ;

    int count = 0 ;
    for (int i = 0 ; i < _Size ; i++ )
    {
        if (i == index)
        {
         continue; 
        }

      _TempArray[count] = MyDynamicArr[i] ;
      count ++ ;
    }
    delete[] MyDynamicArr ;
    MyDynamicArr = _TempArray ;
    _Size = NewSize ; 
    _TempArray = nullptr ;
    return true ;
}

bool DeleteFirstItem()
{
  if (_Size == 0 )
  {
    return false ;
  }

   DeleteItemAt(0);
   return true ;
}

bool DeleteLastItem()
{
  if (_Size == 0 )
  {
    return false ;
  }

   DeleteItemAt(_Size-1);
   return true ;
}

int Find (T value )
{
   for (int i = 0 ; i < _Size ; i++ )
   {
     if (value == MyDynamicArr[i])
     {
        return i ;
     }
   }
   
   return -1 ;
}

bool DeleteItem(T value )
{
  int index = Find(value)  ;
  
  if (index == -1 )
  {
    return false ;
  }
  DeleteItemAt(index);
  return true ;

}

bool InsertAt (int index , T value )
{
   if ( index > _Size || index < 0 ) return false;

  _TempArray = new T[ _Size + 1] ;

   for (int i = 0 ; i < _Size ; i++ )
   {
    if (i < index ) 
    _TempArray[i] = MyDynamicArr[i] ;

    if (i >= index )
    _TempArray[i+1] = MyDynamicArr[i];
   }
  _TempArray[index] = value ; 
  delete[] MyDynamicArr ;
  MyDynamicArr = _TempArray ;
  _Size++ ;
  _TempArray = nullptr ;
  return true ;

}

void InsertAtBeginning (T value )
{
   InsertAt(0 , value ) ;

}

void InsertAtEnd(T value )
{
  InsertAt(_Size , value );
}

bool InsertBefor (int index , T value )
{
    if (index < 1 )
  return InsertAt(0 , value) ;
    else 
  return InsertAt(index - 1 , value ) ;
}

bool InsertAfter (int index , T value )
{ 
  if( index >= _Size)
  return InsertAt(_Size , value ) ;
  else 
  return InsertAt(index + 1 , value ) ;
}
};