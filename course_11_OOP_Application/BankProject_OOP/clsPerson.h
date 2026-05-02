#pragma once 
#include<iostream>
#include<string>
using namespace std ;
class clsPerson
{
 private:

 string _FirstName = "";
 string _LastName = "";
 string _Phone = "";
 string _Email = "";

public :
clsPerson(string FirstName , string LastName , string Phone , string Email )
{
 _FirstName = FirstName ;
 _LastName = LastName ;
 _Phone = Phone ;
 _Email = Email ;

}

void SetFirstName (string FirstName )
{
  _FirstName = FirstName ;
}

string FirstName()
{
  return _FirstName ;
}


void SetLastName (string LastName )
{
  _LastName = LastName ;
}

string LastName()
{
  return _LastName ;
}

void SetPhone (string Phone )
{
  _Phone = Phone ;
}

string Phone()
{
  return _Phone;
}

void SetEmail (string Email)
{
 _Email = Email ;
}

string Email ()
{
  return _Email ;
}


string FullName ()
{
  return _FirstName + " " + _LastName ;
}
};