#include <iostream>
#include "../Libs/DateLib.h"

using namespace std;



int main ()
{
  DateProblems::stDate date ;
  cout << DateProblems::DateFormat(date);
  DateProblems::PrintMonthCalindar(2026 , 3);
}