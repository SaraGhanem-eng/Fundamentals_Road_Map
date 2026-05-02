
#pragma once
#include <iostream> 
#include "clsEmployee.h"
using namespace std;

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


