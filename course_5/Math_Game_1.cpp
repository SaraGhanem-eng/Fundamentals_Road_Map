#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
enum enOperationType {add = 1 , sub =2 , dev = 3 , mul =4 , mixOp =5 };
enum enLevels {easy =1 , mid =2 , hard =3 , mixL =4 };
struct stQuestionInfo
{
    double num1 =0 ;
    double  num2 =0 ;
    enOperationType op ;
    double RightAnswer =0 ;
};
struct stFinalResultInfo
{
    string FinalResult =" ";
    short NumOfQuestions =0 ;
    short NumOfRightAnswer =0 ;
    short NumOfWrongAnswers = 0 ;
    enOperationType OperationType ;
    enLevels Levels ;

};
short RandomNumber (short from , short to)
{
    return rand() % (to - from +1 ) + from ;

}
int  ReadNumoOfquestions ()
{
    int num ;
    cout << " How many questions do you want to answer ? " << endl;
    cin >> num ;
    return num ;
}
void GenerateQuestionNumbers (enLevels Levels , double &num1 , double &num2 )
{
    if (Levels== enLevels::easy )
    {
        num1 = RandomNumber(1, 20) ;
        num2 = RandomNumber (1 , 20) ;
    }
    else if (Levels==enLevels::mid)
    {
        num1 = RandomNumber(21, 50) ;
        num2 = RandomNumber (21 , 50) ;
    }
    else if (Levels==enLevels::hard)
    {
        num1 = RandomNumber(50, 100) ;
        num2 = RandomNumber (50, 100) ;

    }

}
enOperationType ReadOperationType()
{
    short num ;
    cout <<"Enter Operation Type  ? " << " [1] Add , [2] Sub , [3] Div , [4] Mul ,[5] Mix"<< endl;
    cin>> num;
    return enOperationType(num);

}
enLevels ReadLevel ()
{
    short num ;
    cout << " Enter Questions Level ? " << " [1] Easy , [2] Mid , [3] Hard , [4] Mix" << endl;
    cin >> num ;
    return enLevels(num) ;

}
enOperationType RandomOperation ()
{

    int OP =(RandomNumber(1,4));
    return enOperationType (OP) ;
}
enLevels GenerateRandomLevel()
{

    enLevels levels ;
    levels = enLevels (RandomNumber(1,3));
    return levels ;


}
char OperationsToChar (enOperationType Operations )
{
  switch (Operations)

      {
      case enOperationType::add:
          return '+';

      case enOperationType::sub:
          return '-';

      case enOperationType::mul:
          return '*' ;

      case enOperationType::dev:
          return '/';



      }


}
string OperatioToString (enOperationType op)
{
string arr [5] ={"+" , " - " , "/" , "*" , "Mix"};

    return arr[op-1];
}
string LevelToString (enLevels levels)
{
    string arr [4]= {"Easy" , "Mid" , "Hard" , "Mix"};
    return arr[levels-1];
}
double DoOperation (double num1 , double num2 , char op)
{

    if (op == '+')
        return num1 + num2 ;

    else if (op == '*')
        return num1 * num2 ;

    else if (op == '/')
        return num1/num2;

    else if (op =='-')
        return num1-num2;

}
stQuestionInfo GenerateQuestion(enOperationType operation , enLevels level)
{
    stQuestionInfo Q ;

    double num1 , num2 ;
    if (level == enLevels::mixL)
       { level = GenerateRandomLevel();}

    GenerateQuestionNumbers(level ,num1 , num2);

    Q.num1= num1 ;
    Q.num2 = num2 ;
    if (operation == enOperationType::mixOp)
       Q.op = RandomOperation();
   else
       Q.op = operation ;

       Q.RightAnswer = DoOperation (Q.num1 , Q.num2 , OperationsToChar((Q.op)));
    return Q ;
   }
void Printquestion (stQuestionInfo q , short numOfQ , short qnum)
{

    cout << "\t\t\t__________________"<< endl;
    cout << "\t\t\tQuestion [ " <<  qnum << " / " << numOfQ << " ] " << endl;
    cout << "\t\t\t__________________"<< endl;
    cout << "\t\t\t" <<q.num1 <<" "<<OperationsToChar(q.op)<<" "<<q.num2 << endl;
    cout << "\t\t\t" << "__________________" << endl;
    cout << "\t\t\t" ;

}
double ReadUseranswer (double &answer)
{
    cin >> answer ;
    return answer ;
}
void Checkanswer (double useranswer , double rightAnwer , short &numOfWrigthQs , short &numOfWrongQuestion)
{
    if ( rightAnwer ==  useranswer)

    {
        cout << " Answer is true :-) " << endl;
        numOfWrigthQs++;
    }
    else
    {
        cout << "Answer is false :-( " << endl<< endl;
        cout << "Right answer is " << rightAnwer << endl<<endl<<endl;
        numOfWrongQuestion ++ ;
    }
}
stFinalResultInfo startGame ()
{


     int NumOfQuestions = ReadNumoOfquestions();
     enLevels levels = ReadLevel();
     enOperationType operation = ReadOperationType() ;

     short numOfRrigthQs =0 , numOfWrongQuestion =0 ;

     string  PassOrFail = " ";

    for (int i=1 ; i <=NumOfQuestions ; i++)
        {


          stQuestionInfo QuestionInfo ;

          QuestionInfo = GenerateQuestion(operation , levels );
          Printquestion(QuestionInfo , NumOfQuestions , i);
          double answer ;
          Checkanswer( ReadUseranswer(answer) , QuestionInfo.RightAnswer , numOfRrigthQs  , numOfWrongQuestion  ) ;


         }

    if (numOfRrigthQs >= numOfWrongQuestion)

        PassOrFail ="Pass :-) " ;
    else
         PassOrFail = "Fail :-( " ;

    stFinalResultInfo final ;
    final.FinalResult = PassOrFail ;
    final.NumOfQuestions = NumOfQuestions ;
    final.NumOfRightAnswer =numOfRrigthQs ;
    final.NumOfWrongAnswers = numOfWrongQuestion ;
    final.OperationType = operation ;
    final.Levels = levels ;

  return final;

}
void ShowFinalResult (stFinalResultInfo finalresults )
{
    cout << "\t\t\t\t\t _____________________________________________" << endl;
    cout << "\t\t\t\t\t              Final Results is " << finalresults.FinalResult <<  endl;
    cout << "\t\t\t\t\t _____________________________________________" << endl<<endl;
    cout << "\t\t\t\t\t Questions level is           : " << LevelToString(finalresults.Levels )<< endl;
    cout << "\t\t\t\t\t Operation type               : " <<OperatioToString(finalresults.OperationType)<< endl;
    cout << "\t\t\t\t\t Number of questions          : " << finalresults.NumOfQuestions << endl;
    cout << "\t\t\t\t\t Number of right questions is : " <<finalresults.NumOfRightAnswer <<endl;
    cout << "\t\t\t\t\t Number of wrong questions is : " << finalresults.NumOfWrongAnswers << endl;
    cout << "\t\t\t\t\t _____________________________________________" << endl;


}
void PlayGame ()
{
    bool Playagain =true ;

 do {


     ShowFinalResult(startGame()) ;
     cout << "Do you want to play again ? yes [1] , no [0]" << endl;
     cin >> Playagain ;


    } while ( Playagain == 1 );


}

int main ()
{
    srand((unsigned)time(NULL));
    PlayGame() ;



    return 0 ;
}