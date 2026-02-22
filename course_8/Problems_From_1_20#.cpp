#include <iostream>
#include <string>
#include <cmath>
#include<iomanip>
using namespace std;

struct sDate
{
  short Day = 0 ;
  short Month = 0 ;
  short Year = 0 ;
};

bool IsLeapYear (short YearNumber )
{
return ((YearNumber % 400 == 0 )||( YearNumber % 4 == 0 && YearNumber %100 != 0) );

}

short ReadYear ()
{
    short Year ;
    cout << " Please enter Year  ? " ;
    cin >> Year ;
    return Year ;
}

short ReadMonth ()
{
    short Month ;
    cout << " Please enter month ? " ;
    cin >> Month ;
    return Month ;
}

short ReadDay ()
{
    short DayNumber ;
    cout << " Please enter day number ? ";
    cin >> DayNumber ;
    return DayNumber;
}

short NumberOfDyasInYear (short Year)
{
 return IsLeapYear(Year) ? 366 : 365 ;
}

short NumberOfHoursInYear (short Year )
{
    return NumberOfDyasInYear(Year) * 24 ;
}

int NumberOfMinutesInYear (short Year )
{
    return NumberOfHoursInYear(Year) * 60 ;
}

int NumberOfSecondsInYear (short Year )
{
    return NumberOfMinutesInYear(Year) * 60 ;
}

short NumberOfDaysInMonth (short Year , short Month)
{
   if (Month < 1 || Month > 12 )
   return 0 ; 
   
   short NumberOfDays [12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
   return  (Month == 2) ? (IsLeapYear(Year) ? 29 : 28 ) : NumberOfDays[Month-1] ;
}

short NumberOfHoursInMonth (short Year , short Month )
{
    return NumberOfDaysInMonth(Year , Month ) * 24 ;
}

int NumberOfMinutesInMonth (short Year , short Month )
{
 return NumberOfHoursInMonth(Year , Month ) * 60 ;
}

int NumberOfSecondsInMonth (short Year , short Month )
{
    return NumberOfMinutesInMonth(Year , Month ) * 60 ;
}

short FindDayOrder (short Year , short Month , short Day )
{
    short a , y , m , d ;

    a = (14 - Month ) / 12 ;
    y = Year - a ;
    m = Month + (12 * a ) - 2 ;
    d = (Day + y + (y/4) - (y/100) + (y /400) + ((31 * m ) / 12 )) % 7 ;
    return d ;
   
     
}

string GetDaykName (short DayNumber)
{
 string WeekDays [] = {   "sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "satuday" } ;
 return WeekDays[DayNumber] ;

}

string GetMonthName (short MonthNumber)
{
    string MonthsName [12] = {"Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" ,"Aug" ,
    "Sep" , "Oct" , "Nov" , "Dec" };

    return MonthsName[MonthNumber-1];
}

void PrintMonthCalindar (short Year , short Month)
{
    short firstday = FindDayOrder(Year , Month , 1 ) ;
    short numberofdays = NumberOfDaysInMonth(Year , Month) ;
    
    printf("\n_______________ [ %s ] _____________\n" , GetMonthName(Month).c_str() );
    printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
     
    int j = 0 ;
    for ( j = 0 ; j < firstday ; j ++)
    {
        printf("     ");
        
    }
 

    for (int i = 1 ; i <= numberofdays ; i++ )
    {
        
        printf("%5d" , i );
      

        if ( ++j == 7 )
       {
         printf("\n");
         j = 0 ;
       }
   
    }
    cout << "\n_____________________________________\n\n"<< endl;
}

void PrintYearCalindar (short Year )
{
    printf("\n_____________________________________\n\n");
    printf("           CALENDAR _ [%d]           \n",Year );
    printf("_____________________________________\n\n");
    for (int i = 1 ; i <= 12 ; i ++ )
    {
        PrintMonthCalindar(Year , i ) ;
    
    }
}

short NumberOfPassedDayFromYear (short Year , short Month , short Day)
{
    short NumberOfDays = 0 ;
    for (int i = 1 ; i < Month ; i ++ )
    {
      NumberOfDays+= NumberOfDaysInMonth(Year , i) ;
    }

     NumberOfDays += Day ;

    return NumberOfDays ;
}

sDate ReadFullDate ()
{
  sDate date ;
  date.Day = ReadDay() ;
  date.Month = ReadMonth() ;
  date.Year = ReadYear() ;

  return date ;
}

sDate DateAccordingToNumberOfPassedDays (short PassedDays  , short Year )
{ 
    sDate Date ;
    Date.Year = Year;
    Date.Month = 1 ;

    short ReamaindDays = PassedDays ;
    short MonthDays =0 ;

     while (true)
    {  
        MonthDays = NumberOfDaysInMonth(Year , Date.Month );

        if (MonthDays < ReamaindDays )
        { 
            ReamaindDays -= NumberOfDaysInMonth(Year , Date.Month ) ;
            Date.Month++ ;
        }
        else 
        {
            Date.Day = ReamaindDays ;
            break ;
        }
    }
   return Date ;
}

sDate DateAfterAddingDays (sDate Date , short daysAdded)
{
    short RemainingDays = daysAdded + NumberOfPassedDayFromYear(Date.Year , Date.Month , Date.Day) ;
    Date.Month = 1 ;
    short MonthDay = 0 ;

    while ( true )
    {
        MonthDay = NumberOfDaysInMonth(Date.Year , Date.Month);

        if (RemainingDays > MonthDay )
        {
            RemainingDays -= MonthDay ;
            Date.Month ++ ;

            if (Date.Month > 12)
            {
                Date.Month = 1 ;
                Date.Year ++ ;
            }
        }
        else 
        {
            Date.Day = RemainingDays ;
            break ;
        }
    }

    return Date ;
}

bool IsDate1LessThanDate2 (sDate date1 , sDate date2 )
{
  

    if (date1.Year < date2.Year)
    {
        return true ;
    }
    else if (date1.Year > date2.Year)
    {
        return false ;
    }
    else 
    {
        if (date1.Month < date2.Month )
        {
            return true ;
        }
        else if (date1.Month > date2.Month)
        {
            return false ;
        }
        else 
        {
            if (date1.Day < date2.Month)
            {
                return true ;
            }
            else 
            {
                return false ;
            }

        }
    }


//return (date1.Year < date2.Year) ? true : (date1.Year == date2.Year) ? (date1.Month < date2.Month ) ? true : (date1.Month == date2.Month) ? (date1.Day < date2.Day) : false  : false ;


}

int main ()
{
    sDate Date1 , Date2 ;
    Date1 = ReadFullDate();
    cout << endl;
    Date2 = ReadFullDate() ;

    if( IsDate1LessThanDate2(Date1 , Date2 ) )
    cout << "\nYes , Date1 is less than Date2 " << endl;
    else 
    cout << "\nNo , Date1 is Not less than Date2 " << endl;



return 0;

}