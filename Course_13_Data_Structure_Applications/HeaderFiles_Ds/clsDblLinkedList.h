#include <iostream>

using namespace std ;


template <class T >
class clsDblLinkedList 
{
protected:
int _Size = 0 ;

public:
  // sub class 
   class Node
   {
    public:

     T _value ;
     Node* _next ;
     Node* _prev ;
   };

Node* head = NULL ;

void PrintList ()
{
  if (head == NULL )
  {
   cout << "\nLinkedList Is Empty ! \n";
   return ;
  }

  Node* current = head ;

  while (current != NULL )
  {
   cout << current->_value << "  " ;
   current = current->_next ;
  }
  cout << endl;

}

Node* Find (T Value)
{
  if (head == NULL )
  {
   return NULL ;
  }

  Node* current = head ;

  while (current != NULL )
  {
    if (current->_value == Value)
    {
      return current ;
    }
    current = current->_next ;
  }
  return NULL ;
}

void InsertAtBeginning (T Value)
{
  Node* NewNode = new Node ;
  NewNode->_value = Value ; 
  NewNode->_prev = NULL ;
  NewNode->_next = head ;

  if (head != NULL )
  {
   head->_prev = NewNode ;
  }
   head = NewNode ;
   _Size++;
}

void InsertAtEnd(T Value)
{
   Node* NewNode = new Node ;
   NewNode->_next = NULL ;
   NewNode->_value = Value ;

  if (head == NULL )
  {
    head = NewNode ;
    NewNode->_prev = NULL ;
  }
  else 
  {
   Node *LastNode = head ;

   while (LastNode->_next != NULL)
   {
      LastNode = LastNode->_next ;
   }
   LastNode->_next = NewNode ;
   NewNode->_prev = LastNode ;
  }
   _Size++;
}

void InsertAfter (Node* node , T Value )
{
  if (head == NULL || node == NULL )
  {
    return ;
  }
  
  Node* NewNode = new Node ;

  NewNode->_value = Value ;
  NewNode->_prev = node ;
  NewNode->_next = node->_next ;

  if (node->_next != NULL )
  {
   node->_next->_prev = NewNode ;
  }
   
  node->_next = NewNode ;
   _Size++;

}

void InsertAfter (int index , T Value )
{

   Node* newNode =  GetNode(index);
   if (newNode != NULL )
   {
      InsertAfter(newNode , Value );
   }
}

void DeleteFirstNode()
{
  if (head == NULL )
  {
   cout << "\nLinkedList is empty \n" ;
   return ;
  }

   Node *temp = head ;
   head = head->_next ;

   if (head != NULL )
   {
      head->_prev = NULL ;
   }

   delete temp ;
   _Size--;
}

void DeleteLastNode ()
{
if (head == NULL )
{
   cout << "\nLinkedList is empty \n" ;
   return ;
}
if (head->_next == NULL )
{
   delete head ;
   head = NULL ;
}
else 
{
 Node* Last = head ;

 while (Last->_next != NULL )
 {
   Last = Last->_next ;
 }
 Last->_prev->_next = NULL ;
 delete Last ;
} 

 _Size--;
}

void DeleteNode (Node* &NodeToDelete )
{
if (head == NULL || NodeToDelete == NULL  )
{
   return ;
}

if (NodeToDelete == head )
{
   head = NodeToDelete->_next ;
   if (head != NULL )
   {
      head->_prev = NULL ;
   }
}

else if (NodeToDelete->_next == NULL )
{
   NodeToDelete->_prev->_next = NULL ;
}
else 
{
NodeToDelete->_prev->_next = NodeToDelete->_next ;
NodeToDelete->_next->_prev = NodeToDelete->_prev ;
}
 delete NodeToDelete ;
 NodeToDelete = NULL ;
  _Size--;

}

int Size()
{
  return _Size ;
}

bool IsEmpty ()
{
  return  (_Size == 0 ? true : false ) ;
   
}

void Clear()
{
  while (_Size > 0 )
  {
   DeleteFirstNode();
  }
  
} 

void Reverse ()
{

 Node* current = head ;
 Node* temp = NULL ;
 while (current != NULL )
 {
   temp = current->_next;
   current->_next = current->_prev ;
   current->_prev = temp ;
   head = current;
   current = temp ;
 }


}

Node* GetNode (int index)
{
   if (index >= _Size || index < 0 )
   {
      cout << "\nindex does not exist\n";
      return NULL ;
   }
   
   Node* current = head ;
   index-- ;
   while(index >= 0 && current != NULL )
   {
     current = current->_next ;
     index-- ;
   }
   return current ;
}

T GetItem (int index)
{

    Node* ItemNode = GetNode(index) ;

    if (ItemNode == NULL )
    return 0 ;
    else 
    return ItemNode->_value ;

}

bool UpdateItem (int index , T value )
{
   Node* ItemNode = GetNode(index) ;
   if (ItemNode == NULL )
   {
      return false ;
   }
   else 
   {
      ItemNode->_value = value ;
      return true ;
   }
}

};
