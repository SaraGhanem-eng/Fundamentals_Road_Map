#include <iostream> 
#include "/Users/saraghanem/Documents/Road_map_projects/Libs/clsString.h"
using namespace std;


class clsPerson 
{

private :

string _FullName ;
string _PhoneNumber ;
class clsAddress 
{
private :

    string _AddressLine1 ;
    string _AddressLine2 ;
    string _City ;
    string _Country ;

public :

    clsAddress(string AddressLine1 , string AdressLine2 , string City , string Country )
    {
        _AddressLine1 = AddressLine1;
        _AddressLine2 = AdressLine2 ;
        _City = City ;
        _Country = Country ;
    }

    void Print ()
    {
        cout << "Full Address : " << endl;
        cout << _AddressLine1 << endl;
        cout << _AddressLine2 << endl;
        cout << _City << endl;
        cout << _Country << endl;

    }

   void setAddressLine1(string AddressLine1 )
   {
     _AddressLine1 = AddressLine1 ;
   }

      void setAddressLine2(string AddressLine2 )
   {
     _AddressLine2 = AddressLine2 ;
   }

      void setCity(string City )
   {
     _City = City ;
   }

      void setCountry(string Country )
   {
     _Country = Country ;
   }

   string getAddressLine1 ()
   {
    return _AddressLine1 ;
   }

      string getAddressLine2 ()
   {
    return _AddressLine2 ;
   }

      string getCity ()
   {
    return _City ;
   }

      string getCountry ()
   {
    return _Country ;
   }

};

public : 

    void setFullName(string FullName )
    {
      _FullName = FullName ;
    }

   string getFullName ()
   {
    return _FullName ;
   }

    void setPhoneNumber (string PhoneNumber )
   {
     _PhoneNumber = PhoneNumber ;
   }

    string getPhoneNumber ()
   {
    return _PhoneNumber ;
   }

   clsAddress Address ;

clsPerson(string FullName , string PhoneNumber , string AddressLine1 , string AddressLine2 , string City , string Country )
:Address(AddressLine1 , AddressLine2 , Country , City)
{
  _FullName = FullName ;
  _PhoneNumber = PhoneNumber ;
  Address = clsAddress (AddressLine1, AddressLine2 , City , Country);

}

void Print ()
{
    cout << "\nFull Info : " << endl;
    cout << "\nFullName      : " << getFullName() << endl;
    cout << "Phone Number  : " << getPhoneNumber() << endl;
    cout << "Address Line1 : " << Address.getAddressLine1() << endl;
    cout << "Address Line2 : " << Address.getAddressLine2() << endl;
    cout << "City          : " << Address.getCity() << endl;
    cout << "Country       : " << Address.getCountry() << endl;
}
};

int main ()
{
   clsString string1 ;
   string1.SetValue("Sara Alaa");
   cout << "Number of capital litters " << string1.CountCapitalLetters() << endl;
   cout << clsString::CountVowels("SAra Alaa");

    return 0 ;
}
