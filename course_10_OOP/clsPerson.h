#pragma once
#include <iostream> 
using namespace std;


class clsPerson 
{

   private :
   int _ID = 0 ;
   string _FirstName ;
   string _LastName ;
   string _FullName ;
   string _GMail ;
   string _PhoneNumber ;
   

   public :
   

   clsPerson(int ID , string FirstName , string LastName ,  string GMail , string PhoneNumber )
   {
     _ID = ID ;
     _FirstName = FirstName;
     _LastName = LastName ;
     _FullName = _FirstName + " " + _LastName ;
     _GMail = GMail ;
     _PhoneNumber = PhoneNumber ;
    
   }



   int GetId ()
   {
    return _ID;
   }

   void setGmail (string Gmail)
   {
    _GMail = Gmail ;
    
   }

   string GetGmail ()
   {
     return _GMail;
   }
  
    void setFirstName (string FirstName)
   {
    _FirstName = FirstName ;
    
   }

   string GetFirstName ()
   {
     return _FirstName;
   }


    void setLastName (string LastName)
   {
    _LastName = LastName ;
    
   }

   string GetLastName ()
   {
     return _LastName;
   }

    void setFullName (string FullName)
   {
    _FullName= FullName ;
    
   }

   string GetFullName ()
   {
     return _FullName;
   }

    void setPhoneNumber (string PhoneNumber)
   {
    _PhoneNumber = PhoneNumber ;
    
   }

   string GetPhoneNumber ()
   {
     return _PhoneNumber;
   }

   void PrintInfo ()
   {
    cout << "\nInfo : " << endl << endl;
    cout << "_______________________" << endl;
    cout << "ID        : " << _ID << endl;
    cout << "FirstName : " << _FirstName << endl;
    cout << "LastName  : " << _LastName << endl;
    cout << "FullName  : " << GetFullName()<< endl;
    cout << "Email     : " << _GMail << endl;
    cout << "Phone     : " << _PhoneNumber << endl;
    cout << "_______________________" << endl << endl; 

   }
  //simulation 
  
  void SendEmail (string Subject , string Body )
  {
   cout << "\nThe Following Message sent successfully to email : " << _GMail << endl;
   cout << "Subject : " << Subject << endl;
   cout << "Body    : " << Body << endl << endl ;

  }

  void SendSMS (string Message )
  {
    cout << "\nThe Following SMS sent successfully to Phone : " << _PhoneNumber << endl;
    cout << "Body    : " << Message << endl << endl ;
  }
};