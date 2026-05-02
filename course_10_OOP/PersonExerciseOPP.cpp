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

class clsEmployee : public clsPerson 
{

private:
string _Title;
string _Department;
float _Salary;


public:
// اخد ال parameters و هربهم ل class person 
clsEmployee(int ID , string FirstName , string LastName , string Gmail , string PhoneNumber ,
   string Title , string Department , float Salary )

:clsPerson (ID , FirstName , LastName , Gmail , PhoneNumber)
{
_Title = Title ;
_Department = Department ;
_Salary = Salary;
}


void setTitle(string Title)
{
 _Title = Title;
}

string GetTitle()
{
return _Title;
}

void setDepartment(string Department)
{
_Department = Department;
}

string GetDepartment()
{
return _Department;
}

void setSalary(float Salary)
{
_Salary = Salary;
}

float GetSalary()
{
return _Salary;
}

void PrintInfo ()
{
// Overriding : Means rewrite the function to be appropriate 


    cout << "\nInfo : " << endl << endl;
    cout << "_______________________" << endl;
    cout << "ID        : " << GetId()<< endl;
    cout << "FirstName : " << GetFirstName() << endl;
    cout << "LastName  : " << GetLastName() << endl;
    cout << "FullName  : " << GetFullName()<< endl;
    cout << "Email     : " << GetGmail() << endl;
    cout << "Phone     : " << GetPhoneNumber() << endl;
    cout << "Title     : " << GetTitle()<< endl;
    cout << "Department: " << GetDepartment()<< endl;
    cout << "Salary    : " << GetSalary() << endl;
    cout << "_______________________" << endl << endl; 
}
};

class clsDeveloper : public clsEmployee 
{
  private :
  string _ProgrammingLanguage ;

public :

  clsDeveloper(int ID , string FirstName , string LastName , string Gmail ,
     string PhoneNumber , string Title , string Department , float Salary , string ProgrammingLanguage )
     :clsEmployee(ID , FirstName , LastName , Gmail , PhoneNumber , Title , Department , Salary )
  {
     _ProgrammingLanguage = ProgrammingLanguage ;
  
  }
  void SetProgrammingLanguage (string ProgrammingLanguage )
  {
    _ProgrammingLanguage = ProgrammingLanguage ;
  }

  string GetProgrammingLanguage ()
  {
    return _ProgrammingLanguage ;
  }

  void PrintInfo ()
{
    cout << "\nInfo : " << endl << endl;
    cout << "________________________________" << endl;
    cout << "ID                   : " << GetId()<< endl;
    cout << "FirstName            : " << GetFirstName() << endl;
    cout << "LastName             : " << GetLastName() << endl;
    cout << "FullName             : " << GetFullName()<< endl;
    cout << "Email                : " << GetGmail() << endl;
    cout << "Phone                : " << GetPhoneNumber() << endl;
    cout << "Title                : " << GetTitle()<< endl;
    cout << "Department           : " << GetDepartment()<< endl;
    cout << "Salary               : " << GetSalary() << endl;
    cout << "Programming Language : " << GetProgrammingLanguage() << endl;
    cout << "________________________________" << endl; 
}
};

int main()
{

clsDeveloper Dev1(4 , "Sara" , "Ghanem" , "saragmail.com" , "010029728" , "Engineer" , "55" , 50000 , "C++") ;

cout << Dev1.GetProgrammingLanguage() << endl;


}