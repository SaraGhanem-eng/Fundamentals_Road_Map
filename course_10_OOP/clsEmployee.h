#pragma once
#include <iostream> 
#include "clsPerson.h"
using namespace std;

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
