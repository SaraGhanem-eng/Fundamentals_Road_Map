#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DateProblems 
{
public:

struct stDate
{
  short Day = 0 ;
  short Month = 0 ;
  short Year = 0 ;
};

static bool IsLeapYear (short YearNumber )
{
return ((YearNumber % 400 == 0 )||( YearNumber % 4 == 0 && YearNumber %100 != 0) );

}

static short ReadYear ()
{
    short Year ;
    cout << " Please enter Year  ? " ;
    cin >> Year ;
    return Year ;
}

static short ReadMonth ()
{
    short Month ;
    cout << " Please enter month ? " ;
    cin >> Month ;
    return Month ;
}

static short ReadDay ()
{
    short DayNumber ;
    cout << " Please enter day ? ";
    cin >> DayNumber ;
    return DayNumber;
}

static short NumberOfDyasInYear (short Year)
{
 return IsLeapYear(Year) ? 366 : 365 ;
}

static short NumberOfHoursInYear (short Year )
{
    return NumberOfDyasInYear(Year) * 24 ;
}

static int NumberOfMinutesInYear (short Year )
{
    return NumberOfHoursInYear(Year) * 60 ;
}

static int NumberOfSecondsInYear (short Year )
{
    return NumberOfMinutesInYear(Year) * 60 ;
}

static short NumberOfDaysInMonth (short Year , short Month)
{
   if (Month < 1 || Month > 12 )
   return 0 ; 
   
   short NumberOfDays [12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
   return  (Month == 2) ? (IsLeapYear(Year) ? 29 : 28 ) : NumberOfDays[Month-1] ;
}

static short NumberOfDaysInMonth (stDate date )
{
       if (date.Month < 1 ||date.Month > 12 )
   return 0 ; 
   
   short NumberOfDays [12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
   return  (date.Month == 2) ? (IsLeapYear(date.Year) ? 29 : 28 ) : NumberOfDays[date.Month -1] ;
}

static short NumberOfHoursInMonth (short Year , short Month )
{
    return NumberOfDaysInMonth(Year , Month ) * 24 ;
}

static int NumberOfMinutesInMonth (short Year , short Month )
{
 return NumberOfHoursInMonth(Year , Month ) * 60 ;
}

static int NumberOfSecondsInMonth (short Year , short Month )
{
    return NumberOfMinutesInMonth(Year , Month ) * 60 ;
}

static short FindDayOrderInWeek (stDate date )
{
    short a , y , m , d ;

    a = (14 - date.Month ) / 12 ;
    y = date.Year - a ;
    m = date.Month + (12 * a ) - 2 ;
    d = (date.Day + y + (y/4) - (y/100) + (y /400) + ((31 * m ) / 12 )) % 7 ;

    return d ;
   
     
}

static short FindDayOrderInWeek (short Year , short Month , short Day)
{
        short a , y , m , d ;

    a = (14 - Month ) / 12 ;
    y = Year - a ;
    m = Month + (12 * a ) - 2 ;
    d = (Day + y + (y/4) - (y/100) + (y /400) + ((31 * m ) / 12 )) % 7 ;

    return d ;
}

static string GetDaykName (short DayNumber)
{
 string WeekDays [] = {   "sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "satuday" } ;
 return WeekDays[DayNumber] ;

}

static string GetMonthName (short MonthNumber)
{
    string MonthsName [12] = {"Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" ,"Aug" ,
    "Sep" , "Oct" , "Nov" , "Dec" };

    return MonthsName[MonthNumber-1];
}

static void PrintMonthCalindar (short Year , short Month  )
{
    short firstday = FindDayOrderInWeek(  Year , Month  , 1 ) ;
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

static void PrintYearCalindar (short Year )
{
    printf("\n_____________________________________\n\n");
    printf("           CALENDAR _ [%d]           \n",Year );
    printf("_____________________________________\n\n");
    for (int i = 1 ; i <= 12 ; i ++ )
    {
        PrintMonthCalindar(Year , i ) ;
    
    }
}

static short NumberOfPassedDayFromYear (short Year , short Month , short Day)
{
    short NumberOfDays = 0 ;
    for (int i = 1 ; i < Month ; i ++ )
    {
      NumberOfDays+= NumberOfDaysInMonth(Year , i) ;
    }

     NumberOfDays += Day ;

    return NumberOfDays ;
}

static stDate ReadFullDate ()
{
  stDate date ;
  date.Day = ReadDay() ;
  date.Month = ReadMonth() ;
  date.Year = ReadYear() ;

  return date ;
}

static stDate DateAccordingToNumberOfPassedDays (short PassedDays  , short Year )
{ 
    stDate Date ;
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

static stDate DateAfterAddingDays (stDate Date , short daysAdded)
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

static bool IsDate1BeforDate2 (stDate date1 , stDate date2 )
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
            if (date1.Day < date2.Day)
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

static bool IsDate1EqalsDate2 (stDate date1 , stDate date2 )
{
    return ((date1.Year == date2.Year) && (date1.Month==date2.Month) && (date1.Day == date2.Day )) ? true : false ;
}

static bool IsLastMonthInYear ( stDate date )
{
    return ( date.Month == 12 ) ;
}

static bool IsLastDayInMonth ( stDate date )
{
    return (NumberOfDaysInMonth(date.Year , date.Month ) == date.Day ) ;
}

static void PrintFullDate (stDate date )
{
    cout << endl ;
    cout << date.Day << " / " << date.Month << " / " << date.Year << endl;

}

static stDate IncreaseDateByOneDay (stDate date )
{
    if (IsLastMonthInYear(date) && IsLastDayInMonth(date))
    {
        date.Year ++ ;
        date.Month = 1 ;
        date.Day = 1;
       
    }
    else if (IsLastDayInMonth(date) && (!IsLastMonthInYear(date)) )
    {
        date.Month ++ ;
        date.Day = 1 ;
        
    }
    else 
    {
        date.Day ++ ;
    }

    return date ;
}

static stDate GetSystemDate ()
{
    stDate date ;

    time_t t = time(0) ;
    tm* now = localtime(&t) ;

    date.Year = now->tm_year + 1900 ;
    date.Month = now->tm_mon + 1 ;
    date .Day = now->tm_mday ;

    return date ;
}

static long long GetDiffrenceInDays (stDate date1 ,stDate date2 , bool IncludeLastDay = false )
{
  long long days = 0 ;

  short flag = 1 ;
  if ( !IsDate1BeforDate2(date1 , date2 ) )
  {
    stDate temp ;

    temp = date1 ;
    date1 = date2 ;
    date2 = temp ;
    flag = -1 ;
     
  }


  while (IsDate1BeforDate2(date1 , date2 ))
  {
    days++ ;
    date1 = IncreaseDateByOneDay(date1);
  }


  return IncludeLastDay ? (flag * ++days) : (flag * days);

}

static stDate IncreseDateByXDays (stDate date , int NumberOfDays )
{
    for (int i = 0 ; i < NumberOfDays ; i++ )
    {
        date = IncreaseDateByOneDay(date) ;
    }
    return date ;
}

static stDate IncreaseDateByOneWeek (stDate date )
{
    for (int i = 0 ; i < 7 ; i ++ )
    {
        date = IncreaseDateByOneDay(date);
    }
    return date ;
}

static stDate IncreseDateByXWeeks (stDate date , int NumberOfWeeks )
{
    for (int i = 0 ; i < NumberOfWeeks ; i++ )
    {
        date = IncreaseDateByOneWeek(date);
    }
    return date ;
}

static stDate IncreaseDateByOneMonth (stDate date )
{
 if (date.Month == 12 )
  { 
    date.Month = 1 ;
    date.Year ++ ;
  }
 else 
    date.Month ++ ;

    short NumOfDaysInMonth =  NumberOfDaysInMonth(date.Year , date.Month);

    if (NumOfDaysInMonth < date.Day)
    {
        date.Day = NumOfDaysInMonth ;
    }

    return date ;
 
}

static stDate IncreaseDateByXMonths (stDate date , int NumberOfMonths )
{
    for (int i = 0 ; i < NumberOfMonths ; i++ )
    {
      date = IncreaseDateByOneMonth(date) ;
    }
    return date ;
}

static stDate IncreaseDateByOneYear (stDate date )
{
    date.Year++ ;
    return date ;
}

static stDate IncreaseDateByYears (stDate date , int NumberOfYears )
{
    for (int i = 0 ; i < NumberOfYears ; i++ )
    {
        date = IncreaseDateByOneYear (date);
    }
    return date ;
}

static stDate IncreaseDateByYearsFaster (stDate date , int NumberOfYears )
{
    date.Year += NumberOfYears ;
    return date ;
}

static stDate IncreaseDateByOneDecade (stDate date )
{
    date.Year += 10 ;
    return date ;
}

static stDate IncreseDateByXDecades (stDate date , int NumOfDecades )
{
  for (int i = 0 ; i < NumOfDecades ; i ++)
  {
    date = IncreaseDateByOneDecade (date ) ;
  }
  return date ;
}

static stDate IncreaseDateByXDecadesFaster (stDate date , int NumOfDecades )
{

    date.Year += (10 * NumOfDecades ) ;
    return date ;
}

static stDate IncreaseDateByOneCentury (stDate date)
{
    date.Year += 100 ;
    return date ;
}

static stDate IncreaseDateByOneMillennium (stDate date )
{
    date.Year += 1000 ;
    return date ;
}

static stDate DecreaseDateByOneDay (stDate date )
{
    if (date.Day == 1 && date.Month == 1 )
    {
         date.Day = 31 ;
         date.Year-- ;
         date.Month = 12 ;
    }
    else if (date.Day == 1 && date.Month != 1 )
    {
        date.Month -- ;
        short NumOfDaysInMonth = NumberOfDaysInMonth( date.Year , date.Month);
        date.Day = NumOfDaysInMonth ;
      
    }
    else 
    {
        date.Day -- ;

    }

    return date ;
}

static stDate DecreaseDateByXDays (stDate date , int NumberOfDays )
{
    for (int i = 0 ; i < NumberOfDays ; i++ )
    {
        date = DecreaseDateByOneDay(date);
    }
    return date ;
}

static stDate DecreaseDateByOneWeek (stDate date )
{
    for (int i = 0 ; i < 7 ; i++ )
    {
        date = DecreaseDateByOneDay(date ) ;
    }
    return date ;
}

static stDate DecreaseDateByXWeeks (stDate date , short NumOfWeeks )
{
    for (int i = 0 ; i < NumOfWeeks ; i++ )
    {
        date = DecreaseDateByOneWeek(date ) ;
    }
    return date ;
}

static stDate DecreaseDateByOneMonth (stDate date )
{
    if (date.Month == 1 )
    {
        date.Month = 12 ;
    }
    else 
    {
        date.Month -- ;
    }
    short NumOfDaysInMonth = NumberOfDaysInMonth(date.Year , date.Month );

    if (date.Day > NumOfDaysInMonth )
    {
        date.Day = NumOfDaysInMonth ;
    }
    return date ;
}

static stDate DecreaseDateByXMonths (stDate date , short NumOfMonths )
{
    for (int i = 0 ; i < NumOfMonths ; i ++ )
    {
        date = DecreaseDateByOneMonth (date );
    }
    return date ;
}

static stDate DecreaseDateByOneYear (stDate date )
{
    date.Year -- ;
    return date ;
}

static stDate DecreaseDateByXYearsFaster (stDate date , short NumOfYears )
{
    date.Year -= NumOfYears ;
    return date ;
}

static stDate DecreaseDateByOneDecade (stDate date )
{
    date.Year -= 10 ;
    return date ;
}

static stDate DecreaseDateByXDecades (stDate date , int NumOfDecades )
{
  for (int i = 0 ; i < NumOfDecades ; i ++)
  {
    date = DecreaseDateByOneDecade (date ) ;
  }
  return date ;
}

static stDate DecreaseDateByXDecadesFaster (stDate date , int NumOfDecades )
{

    date.Year -= (10 * NumOfDecades ) ;
    return date ;
}

static stDate DecreaseDateByOneCentury (stDate date)
{
    date.Year -= 100 ;
    return date ;
}

static stDate DecreaseDateByOneMillennium (stDate date )
{
    date.Year -= 1000 ;
    return date ;
}

static bool IsEndOfWeek (stDate date )
{
    short DayOrder = FindDayOrderInWeek(date);
    return ( DayOrder == 6);
}

static bool IsWeekEnd (stDate date )
{
    short DayOrder = FindDayOrderInWeek(date);
    return (DayOrder == 5 || DayOrder ==6 );
}

static bool IsBusinessDay (stDate date )
{
    return (!IsWeekEnd(date));
}

static short DaysUntillEndOfWeek (stDate date )
{
    short DayOrder = FindDayOrderInWeek(date) ;
    return (6 - DayOrder) ;
}

static short DaysUntillEndOfMonth (stDate date )
{
    short lastDayInMonth = NumberOfDaysInMonth(date) ;
    return lastDayInMonth - date.Day ;
}

static short DaysUntillEndOfYear (stDate date )
{
    short NumOfDyasInYear = NumberOfDyasInYear (date.Year);
    short NumOfPassedDays = NumberOfPassedDayFromYear(date.Year , date.Month , date.Day ) ;
    return NumOfDyasInYear - NumOfPassedDays ;
}

static short ActualVacationDate (stDate DateFrom , stDate DateTo )
{
    short VacationDays = 0 ;

   while (!IsDate1EqalsDate2( DateFrom , DateTo ))
   {
     if( IsBusinessDay(DateFrom) )
     {
        VacationDays++ ;
     }
     DateFrom = IncreaseDateByOneDay(DateFrom);
   }
   return VacationDays ;
}

static stDate VacationReturnDate (stDate DateFrom , short vacationDays)
{
    stDate DateTo = DateFrom;

    if (vacationDays <= 0)
    return DateFrom ;


    while (vacationDays > 0 )
    {
      if (IsBusinessDay(DateTo) )
         {
            vacationDays-- ;
         }

         DateTo = IncreaseDateByOneDay(DateTo);
    }
    
    while (IsWeekEnd(DateTo))
    {
        DateTo = IncreaseDateByOneDay(DateTo);
    }

    return DateTo ;
}

static bool IsDate1AfterDate2 (stDate date1 , stDate date2 )
{
    return  (! IsDate1BeforDate2(date1 , date2 ) && !IsDate1EqalsDate2(date1 , date2 ));
}

enum enDateComparison  { enDate1BeforDate2 = -1 , enDate1EqualDate2 = 0 , enDate1AfterDate2 = 1 };

static enDateComparison CompareDates(stDate date1 , stDate date2 )
{
    if (IsDate1EqalsDate2(date1 , date2 ))
    return enDateComparison::enDate1EqualDate2 ;

    else if (IsDate1BeforDate2(date1 , date2 ))
    return enDateComparison::enDate1BeforDate2 ;

    else
    return enDateComparison::enDate1AfterDate2 ;
}

struct stDatePeriod
{
stDate StartDate ;
stDate EndDate ;
};

static stDatePeriod ReadPeriod()
{
stDatePeriod Period;
cout << "\nEnter Start Date:\n";
Period.StartDate = ReadFullDate();
cout << "\nEnter End Date:\n";
Period.EndDate = ReadFullDate();
return Period;
}

static bool IsOverlapDate (stDatePeriod Period1 , stDatePeriod Period2 )
{
  //return  !(IsDate1BeforDate2(Period1.EndDate , Period2.StartDate ) || IsDate1BeforDate2(Period2.EndDate , Period1.StartDate )) ;
  
  return !( CompareDates (Period2.EndDate , Period1.StartDate) == enDateComparison::enDate1BeforDate2 
         || CompareDates (Period2.StartDate , Period1.EndDate) == enDateComparison::enDate1AfterDate2 );
}

static short CalculatePeriodInDays (stDatePeriod Period , bool EndDate = false )
{ /*

   // #ANOTHER SOLUTION#


    short NumOfDays = 0 ;

    while (!IsDate1EqalsDate2(Period.StartDate , Period.EndDate ))
    {
      NumOfDays++ ;
      Period.StartDate = IncreaseDateByOneDay(Period.StartDate);
    }

    return NumOfDays ;
    */

    return GetDiffrenceInDays(Period.StartDate , Period.EndDate , EndDate ) ;
}

static bool IsDateInPeriod (stDatePeriod Period , stDate day )
{
/*
    //#ANOTHER SOLUTION#

    while (!IsDate1EqalsDate2(Period.StartDate , Period.EndDate ))
    {
      if (IsDate1EqalsDate2(Period.StartDate , day) )
      {
        return true ;
      }
      Period.StartDate = IncreaseDateByOneDay(Period.StartDate);
    }

   return false ;
*/


return (!(IsDate1BeforDate2(day , Period.StartDate)) && !(IsDate1AfterDate2(day , Period.EndDate )));
}

static short NumberOfDaysOverlap (stDatePeriod Period1 , stDatePeriod Period2 , bool EndDay = false )
{
  if (IsOverlapDate(Period1 , Period2 ))
  {
    stDatePeriod Overlap ;

    if (CompareDates(Period1.StartDate , Period2.StartDate) == enDateComparison::enDate1BeforDate2)
    Overlap.StartDate = Period2.StartDate ;
    else 
    Overlap.StartDate = Period1.StartDate ;

    if (CompareDates(Period1.EndDate , Period2.EndDate) == enDateComparison::enDate1AfterDate2)
    Overlap.EndDate = Period2.EndDate ;
    else 
    Overlap.EndDate = Period1.EndDate ;

    short PeriodDate = CalculatePeriodInDays(Overlap , EndDay);

    return PeriodDate ;

  }
  else 
  return 0 ;

}

static bool ValidateDate (stDate date )
{


    if (date.Month < 1 || date.Month > 12 )
    return false ;

    if (date.Year < 1 )
    return false ;

   short MaxDay = NumberOfDaysInMonth(date);

    if (date.Day < 1 || date.Day > MaxDay )
    return false ;
    else 
    return true ;

}

static vector <string> SplitString(string s , string delim )
{
    vector <string> vstring ;
    string word ;
    short pos = 0 ;
    while ((pos = s.find(delim)) != string::npos)
    {
        word = s.substr(0,pos);
       if (word != "")
       {
           vstring.push_back(word);
       }
       s.erase(0,pos + delim.length());

    }
if (s != "")
{
     vstring.push_back(s) ;
}

    return vstring ;
}

static stDate StringToDate (string date , string delim = "/")
{
    stDate Date ;
    vector<string> vDate = SplitString(date , delim );
    
    Date.Day = stoi (vDate[0]) ;
    Date.Month = stoi (vDate[1]) ;
    Date.Year = stoi (vDate[2]) ;

    return Date ;
}

static string DateToString (stDate date)
{

    return  to_string(date.Day) + " / " + to_string(date.Month) + " / " + to_string(date.Year) ;

}

static string ReadStringDate ()
{
    string date ; 
    cout << "\nPlease enter date " ;
    cin >> date ;
    return date ;
}

static string ReplaceWordInStringUsingBuiltInFunction ( string s , string StringToReplace , string ReplacedTo )
{
      int pos = s.find(StringToReplace);
      while (pos != string::npos)
      {
          s.replace( pos , StringToReplace.length() , ReplacedTo );
          pos = s.find(StringToReplace);
      }
    return s ;
}

static string DateFormat (stDate date , string Format = "dd / mm / yyyy")
{
    string FormatDay ;
    
    FormatDay = ReplaceWordInStringUsingBuiltInFunction(Format , "dd" , to_string(date.Day));
    FormatDay = ReplaceWordInStringUsingBuiltInFunction(FormatDay , "mm" , to_string(date.Month));
    FormatDay = ReplaceWordInStringUsingBuiltInFunction(FormatDay , "yyyy" , to_string(date.Year)) ;

    return FormatDay ;
}


};