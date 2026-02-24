 #include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string ReadString ()
{
    string name ;
    cout << "Please enter your string " << endl;
    getline( cin , name );
    return name ;
}
char ReadChar ()
{
    char c ;
    cout << "please enter your char ? " << endl;
    cin >> c ;
    return c ;
}
void PrintFirstLettersOfEveryWorld (string s1)
{
   bool FirstLitter = true ;

    for (int i = 0 ; i < s1.length() ; i++ )
    {
      if (s1 [i] != ' '  &&  FirstLitter )
      {
          cout << s1[i] << endl;
      }
        FirstLitter = (s1[i] == ' ' ? true : false );
    }

}
string ConvertCharacterCaseAtWholeString ( string  s1 )
{

    for (int i = 0 ; i < s1.length() ; i++ )
        {

        if (s1[i] >= 97 && s1[i] <= 122 )
         {
            s1[i] = toupper(s1[i]);
         }

        else if
           (s1[i] >= 62 && s1[i] <= 90 )
         {
            s1[i] = tolower(s1[i]);
         }
    }
  return s1 ;
}
char ConverCharacterCase (char c )
{
    return ( isupper(c) ? tolower(c) : toupper(c)) ;
}
string ConverFirstLetterToUpperCase  (string s1 )
{
         s1 [0] = toupper(s1[0]);
         return s1 ;

}
string ConverFirstLetterToLowerCase  (string s1 )
{

    for (int i = 0 ; i < s1.length() ; i++ )
    {
          s1[i] = tolower(s1[i]);
    }
    return s1 ;

}
string ConvertEveryLetterToLower (string s1 )
{
  for (int i = 0 ; i < s1.length() ; i++ ) {

      s1[i]= tolower(s1[i]);
  }
    return s1 ;
}
int CountCapitalLetters (string s1 )
{
    short count = 0 ;
  for (int i = 0 ; i < s1.length() ; i++ )
  {
      if (isupper(s1[i]))
      {
          count++ ;
      }
  }
  return count ;
}
int CountSmallLetters(string s1 )
{
    short count = 0 ;
    for (int i = 0 ; i < s1.length() ; i++ )
    {
        if (islower(s1[i]))
        {
            count++ ;
        }
    }
    return count ;

}
int CountHowManyCharRepeated (string s1 , char c )
{
    int count = 0 ;
 for (int i = 0 ; i < s1.length() ; i++ )
 {

     if (s1[i] == c )
         count ++ ;

 }
    return count ;
}
int CountHowManyCharRepeatedCapitalOrSmall (string s1 , char c )
{
    int count = 0;
    for (int i = 0 ; i < s1.length() ; i++ )
    {
        if (s1[i] == toupper(c) || s1[i] == tolower(c))
            count ++ ;

    }

   return count ;

}
bool IfCharIsAVowel (char c )
{

     c= tolower(c);
   return (c == 'a' || c == 'e'|| c == 'i'|| c == 'o'|| c == 'u');

}
int CountNumberOfVowels ( string s1 )
{
    short count = 0 ;
    for (int i = 0 ; i < s1.length() ; i++ )
        {
           if (IfCharIsAVowel(s1[i]))
            count ++ ;
        }
  return count ;
}
void PrintVowlsInString (string s1 )
{
    for (int i = 0  ; i < s1.length() ; i ++ )
    {
        if (IfCharIsAVowel(s1[i]))
        {
            cout << s1[i] << " " ;
        }


    }


}
void PrintEachWordInAString (string s)
{

    string s1 ;
    int count = 0 ;

    for (int i = 0 ; i < s.length() ; i++)
    {

        if ( s[i] != ' ')
        {
            s1 += s[i] ;
        }
        else
        {
           cout << s1 << endl;
            s1 = "";

        }
        if (i == s.length()-1 ) {
            cout << s1 ;
        }
    }


}
short PrintNumberOfWords (string s )
{
    string delim = " " ;
    short pos = 0 ;
    short count = 0 ;
    string word ;
    while ( (pos = s.find(delim)) != string::npos )
    {
        word = s.substr(0,pos);
        if (word != "")
        {
            count++ ;
        }

        s.erase( 0 , pos + delim.length() );

    }

    if (word != " ")
    {
        count ++ ;
    }
    return count ;
}
vector <string> SplitString(string s , string delim )
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
string TrimLeft (string s)
{
    short pos = 0 ;

       while (s[pos] == ' ')
       {
           pos ++ ;
       }
       return s.erase(0 , pos );

}
string TrimRight (string s)
{
  short pos = s.length()-1 ;

    while (s[pos] == ' ')
    {
        pos-- ;
    }
    return s.erase(pos+1 , s.length()-1 );
}
string Trim (string s )
{
    s= TrimLeft(s) ;
    s= TrimRight(s) ;
    return s ;


}
string JoinString (vector <string> vstring , string delimiter )
{
    string s1 = "";
  for (string &s : vstring )
  {
      s1 +=  s + delimiter ;
  }
    return s1 .substr(0 , s1.length() - delimiter.length() ) ;
}
string JoinString (string arr [4] , string delimiter )
{
    string join = "" ;
    for (int i = 0 ; i < 4 ; i ++ )
    {
     join += arr[i] + delimiter ;
    }
    return join.substr( 0 , join.length() - delimiter.length() );
}
string ReversString1  (string s)
{
    vector <string> vstring ;
    vstring = SplitString( s  , " ");
    string s2 ;

    vector < string > :: iterator iter = vstring.end() ;

    while (iter != vstring.begin())
    {
        iter-- ;
        s2 += *iter + " ";
    }

    return  s2.substr(0 , s2.length()-1 );


}
string ReverseString (string s )
{
    s= TrimLeft(s);

    string delim = " " , s2 ;
    short l = 0  ;
    for (int i = s.length() -1 ; i >= 0 ; i-- )
    {
     l++ ;
     if (s[i] == ' ')
     {
         s2 += s.substr( i+1 , l-1 ) + delim  ;
         l = 0 ;
     }

    }
    s2 += s.substr( 0 , s.find(" ") );
    return Trim (s2) ;
}
string ReplaceWordInStringUsingBuiltInFunction ( string s , string StringToReplace , string ReplacedTo )
{
      int pos = s.find(StringToReplace);
      while (pos != string::npos)
      {
          s.replace( pos , StringToReplace.length() , ReplacedTo );
          pos = s.find(StringToReplace);
      }
    return s ;
}
string ReplaceWordInStringWithMatchCase ( string s , string ToReplace , string ReplaceTo , bool MatchCase = 1)// MC by def true
{

  vector<string> vstring ;
  vstring = SplitString( s , " ");

  for (string &s2 : vstring )
  {

      if (MatchCase)
          {
             if  (ConvertEveryLetterToLower( ToReplace ) ==  ConvertEveryLetterToLower  ( s2 ) )
             {
                  s2 = ReplaceTo ;
             }
      }
      else if (!MatchCase)
      {
          if (s2 == ToReplace)
              s2 = ReplaceTo ;

      }

  }
   s = JoinString(vstring , " ");

   return s ;
}
string RemovePunctuationFromString (string s )
{
  string s2 ;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (!ispunct(s[i]))
        {
            s2 += s[i] ;
        }
    }
        return s2 ;
}
int main ()
{
    
}
