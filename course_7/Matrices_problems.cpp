
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<iomanip>

using namespace std;

int GenerateRandomNumberInLimit (int From , int To )
{
    int randnum = rand()%(To - From +1 ) + From ;
    return randnum ;

}
void FillMatrixWithRandNums (int arr[3][3] , short row , short column )
{
    for (int i = 0 ; i < row ; i ++ )
    {
        for (int j = 0 ; j < column ; j++ )
        {
            arr[i][j] = GenerateRandomNumberInLimit(1 , 10);
        }

    }


}
void FillMatrixWithOrderdNumbers (int arr[3][3] , int row , int column )
{
   short cnt = 1 ;

  for (int i = 0 ; i < row ; i ++ )
  {
      for (int j = 0 ; j < column ; j ++ )
      {
          arr[i][j] = cnt  ;
          cnt ++ ;
      }
  }


}
void PrintMatrix (int arr[3][3], short row , short column )
{
    for ( int i = 0 ; i < 3 ; i ++ )
    {
        for (int j = 0 ; j < 3 ; j ++ )
        {
            printf("  %0*d   " , 2 , arr[i][j]);

        }
        cout << endl;
    }


}
void GenerateTransposedMatrix (int arr[3][3], int arrTr[3][3] ,short row , short column )
{
    for (int i = 0 ; i < row ; i++ )
    {
        for (int j = 0 ; j < column ; j ++ )
        {
            arrTr[i][j] = arr[j][i] ;
        }
    }

}
void GeneraateDoubledArey (int arr[3][3] , int arr2[3][3] , int arrMUL[3][3] , short row , short column)
{

for (int i = 0 ; i < row ; i++ )
{
    for ( int j = 0 ; j < column ; j ++ )
    {
        arrMUL[i][j] = arr[i][j] * arr2[i][j];
    }
}

}
void PrintMiddleRow (int arr[3][3] , short row , short column )
{
   short midrow = row /2 ;

    for (int i = 0 ; i < column ; i ++ )
    {
        printf(" %0*d  " , 2 , arr[midrow][i]);
    }

     cout << endl;

}
void PrintMiddleCol (int arr[3][3] , short row , short column  )
{
   short midcol = column/2 ;

    for ( int i = 0 ; i < row ; i++ )
    {
        printf(" %0*d  " , 2 , arr[i][midcol] ) ;
    }
cout << endl;

}
int GetSumOfMatrix (int arr[3][3] , short row , short column )
{
int sum = 0 ;

    for ( int i = 0 ; i < row ; i ++ )
    {
        for (int j = 0 ; j < column  ; j ++ )
        {
           sum += arr[i][j];
        }

    }
    return sum ;
}
bool CheckIfEqal (int arr[3][3] , int arr2 [3][3] , short row , short column  )
{
  return (GetSumOfMatrix(arr , 3 , 3) == GetSumOfMatrix(arr2 , 3 , 3));

}
bool CheckIfTipical (int arr[3][3] , int arr2 [3][3] , short row , short column )
{
   for (int i = 0 ; i < row ; i++ )
       {
          for (int j = 0 ; j < column ; j++ )
          {
              if (arr[i][j] != arr2[i][j] )
                  return false ;
          }
   }

    return true ;
}
bool IfIdentityMatrix (int arr[3][3] , short row , short column )
{
  for (int i = 0 ; i < row ; i++)
  {
      for (int j = 0 ; j < column ; j++ )
      {

          if (j == i )
          {
              if (arr[i][j] != 1 )
                  return false ;
          }
          else if (arr[i][j] != 0)
              return false ;

      }

  }
    return true ;
}
bool IfScalerMatrix (int arr[3][3] , short row , short column)
{
    int d = arr[0][0];

    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++ )
        {

            if (j == i && arr[i][j] != d)
            {
              return false ;
            }
            else if ((i!= j) && arr[i][j] != 0)
                return false ;

        }

    }
    return true ;
}
int CountNumberINMatrix (int arr[3][3] , short row , short column , short number)
{
int count = 0 ;
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++ )
        {
            if (arr[i][j] == number  )
                count ++ ;
        }

    }
    return count ;

}
bool IfSparceMatrix (int arr[3][3] , short row , short column )
{

short HalfOfElements = (row * column) /2 ;
    return (CountNumberINMatrix(arr , 3 , 3, 0) > HalfOfElements);
}
bool IfNumIsThere (int arr[3][3] , short row , short column , short num)
{
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++ )
        {
         if (arr[i][j] == num )
            return true ;

        }

    }

    return false ;
}
void PrintReplicatedNumbers (int arr[3][3] , int arr2[3][3] , short row , short column )
{

    for (int i = 0 ; i < row ; i++ )
    {
        for (int j = 0 ; j < column ; j++ )
        {
            if (IfNumIsThere(arr , row , column , arr2[i][j]) )
            {
                cout << setw(3) << arr2[i][j] << "   " ;
            }
        }

    }


}
int MaxNumINMatrix (int arr[3][3] , short row , short column )
{
    int Max = arr[0][0];
  for (int i = 0 ; i < row  ; i ++ )
  {
      for (int j = 0; j < column ; j ++ )
      {
          if (arr[i][j] >= Max )
              Max = arr[i][j];
      }
  }
return Max;
}
int MinNumINMatrix (int arr[3][3] , short row , short column )
{
    int Min = arr[0][0];
    for (int i = 0 ; i < row  ; i ++ )
    {
        for (int j = 0; j < column ; j ++ )
        {
            if (arr[i][j] <= Min )
                Min = arr[i][j];
        }
    }
    return Min;
}
bool IfRowIsPalindrom (int arr[3][3] , short row , short column )
{
    int t = column-1 ;
    for (int i = 0 ; i < column / 2; i++ )
        {
             if (arr[row][i] != arr[row][t])
              {
                   return false ;
              }
                  t--;
        }
return true ;
}
bool IfIsPalindromMatrix (int arr[3][3] , short row , short column)
{
for (int i = 0 ; i < row ; i++ )
{
    for (int j = 0 ; j < column /2 ; j++ )
    {
      if (arr[i][j] != arr[i][column-1-j])
      {
          return false ;
      }
    }
   return true ;
}

return true ;

}
void PrintFibonacciUsingLoop ( short length )
{
  short p1 =1 , p2 =1 , fib =1 ;
    cout << fib<< "  ";
    for (int i = 1 ; i < length ; i++ )
        {
          cout << fib << " ";
          p1 = p2 ;
          p2 = fib ;
          fib = p2 + p1 ;
        }



}
void PrintFibonacciUsingRecurtion (short n , short p1 , short p2 )
{
 int fib = 0 ;

  if (n > 0 )
  {
    fib = p1 + p2 ;
    p2 = p1 ;
    p1 = fib ;
    cout << fib << "  " ;
    PrintFibonacciUsingRecurtion (n-1 , p1 , p2 )  ;


  }



}
int main ()
{
    
}