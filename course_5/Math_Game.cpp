
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
enum enOperationType {add = 1 , sub =2 , dev = 3 , mul =4 , mixOp =5 };
enum enLevels { easy =1 , mid =2 , hard =3 , mixL =4 };
struct stQuestionInfo
{
    int Num1 =0 ;
    int Num2 =0 ;
    int RightAnswer =0 ;
    int UserAnswer =0 ;
    bool IsRight ;
    enOperationType QuestionOP ;
    enLevels QuestionLevel ;


};
struct stQuizInfo
{
    stQuestionInfo QuestionsList [10];
    enOperationType OpQuizz ;
    enLevels QuizzLevel ;
    short NumOfRightQuestions = 0 ;
    short NumOfWrongQuestions = 0 ;
    short NumOfQuestions = 0 ;
    bool IsPass ;

};
short RandomNumber (short from , short to)
{
    return rand() % (to - from +1 ) + from ;

}
int ReadQuestionAnswer ()
{
    int Answer =0 ;
    cin >> Answer ;
    return Answer ;
}
int simpleCalculator (int Num1 , int Num2 , enOperationType Op )
{
 switch (Op)
     {
     case (enOperationType::add):
          return Num1 + Num2 ;
     case (enOperationType::sub):
         return Num1 - Num2 ;
     case (enOperationType::mul):
         return Num1 * Num2 ;
     case (enOperationType::dev):
         return Num1 / Num2 ;

     default :
         return Num1 + Num2 ;

 }



}
enOperationType GenerateRandomOp ()
{
    int op = RandomNumber(1,4) ;
    return enOperationType (op) ;

}
enLevels GenerateRandomLevel ()
{
   int level = RandomNumber( 1,3 );
   return enLevels ( level) ;
}
int ReadNumOfQuestions ()
{
    int Answer = 0 ;

do {
cout << "How Many Questions do you want to answer ?" << endl;
    cin >> Answer ;

   }while (Answer <=0 || Answer > 10 );

    return Answer ;
}
enOperationType ReadOperationType ()
{
  int op = 1 ;
    do {
        cout << "Enter The Operation Type You Want ? Add [1] , Sub[2] , Div [3] , Mul [4] , Mix [5] "<< endl;
        cin >> op ;

       } while (op < 1 || op > 5 );

    return enOperationType (op) ;
}
enLevels ReadLevel ()
{
    int level = 1 ;
    do {
        cout << "Enter The Level You Want ? Easy [1] , Mid [2] , Hard [3] , Mix [4] "<< endl;
        cin >> level ;

    } while (level < 1 || level > 4 );

    return enLevels (level) ;
}
string LevelToString (enLevels level)
{
    string arr[4] = {"Easy" , "Mid" , "Hard" , "Mix" };
    return arr[level-1] ;

}
string OperationToString (enOperationType Op)
{
string arr [5] = {"Add" , "sub" , "Div" , "Mul" , "Mix" };
return arr [Op-1];

}
string ResultToString (bool Result)
{
 if (Result == true )
       return " Pass :-) " ;
    else
        return " Fail :-( " ;
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
stQuestionInfo GenerateAQuestion (enLevels level , enOperationType op )
{
    stQuestionInfo Question ;

    if (level == enLevels::mixL)
       level  = GenerateRandomLevel() ;


    if (op == enOperationType::mixOp)
        op = GenerateRandomOp() ;



    Question.QuestionLevel = level;
    Question.QuestionOP = op;

    if (level== enLevels::easy )
    {
        Question.Num1 = RandomNumber(1, 20) ;
        Question.Num2 = RandomNumber (1 , 20) ;
        Question.RightAnswer = simpleCalculator(Question.Num1 , Question.Num2 , Question.QuestionOP);
        return Question ;
    }
    else if (level==enLevels::mid)
    {
        Question.Num1 = RandomNumber(21, 50) ;
        Question.Num2 = RandomNumber (21 , 50) ;
        Question.RightAnswer = simpleCalculator(Question.Num1 , Question.Num2 , Question.QuestionOP);
        return Question ;
    }
    else if (level==enLevels::hard)
    {
        Question.Num1 = RandomNumber(50, 100) ;
        Question.Num2 = RandomNumber (50, 100) ;
        Question.RightAnswer = simpleCalculator(Question.Num1 , Question.Num2 , Question.QuestionOP);

        return Question ;

    }
}
void GenerateQuizQuestionList  (stQuizInfo &Quiz  )
{

for (int Question =0 ; Question < Quiz.NumOfQuestions ; Question ++)
    {
      Quiz.QuestionsList[Question] = GenerateAQuestion( Quiz.QuizzLevel ,Quiz.OpQuizz ) ;

    }

}
void CorrectQuestion (stQuizInfo & Quiz , short QuestionNumber)
{
if (Quiz.QuestionsList[QuestionNumber].UserAnswer ==Quiz.QuestionsList[QuestionNumber].RightAnswer)
    {
      Quiz.QuestionsList[QuestionNumber].IsRight = true ;
      cout << "Right Answer :-) "<< endl << endl;
      Quiz.NumOfRightQuestions ++ ;
}
else {

    Quiz.QuestionsList[QuestionNumber].IsRight = false ;
    cout <<"Wrong Answer :-( " << endl ;
    cout << "Right Answer is "<< Quiz.QuestionsList[QuestionNumber].RightAnswer << endl<< endl;
    Quiz.NumOfWrongQuestions++ ;
}
    Quiz.IsPass = (Quiz.NumOfRightQuestions >= Quiz.NumOfWrongQuestions);
}
void PrintQuestion (stQuizInfo Quiz , short QuestionNumber)
{
   cout << "Question [ " << QuestionNumber + 1 << " / " << Quiz.NumOfQuestions << " ]"<< endl;
   cout << Quiz.QuestionsList[QuestionNumber].Num1 << " "<< OperationsToChar( Quiz.QuestionsList[QuestionNumber].QuestionOP);
   cout << " " << Quiz.QuestionsList[QuestionNumber].Num2 << endl;
    cout <<"__________" << endl;


}
void AskAndCorrectQuestions (stQuizInfo & Quiz)
{

for (int Question =0 ; Question < Quiz.NumOfQuestions ; Question++)
    {
      PrintQuestion(Quiz , Question );
      Quiz.QuestionsList[Question].UserAnswer = ReadQuestionAnswer() ;
      CorrectQuestion(Quiz , Question);

   }

}
void PrintFinalResult (stQuizInfo Quiz )
{
    cout << "\t\t\t\t\t _____________________________________________" << endl;
    cout << "\t\t\t\t\t              Final Results is " << ResultToString(Quiz.IsPass) <<  endl;
    cout << "\t\t\t\t\t _____________________________________________" << endl<<endl;
    cout << "\t\t\t\t\t Questions level is           : " << LevelToString(Quiz.QuizzLevel )<< endl;
    cout << "\t\t\t\t\t Operation type               : " <<OperationToString(Quiz.OpQuizz)<< endl;
    cout << "\t\t\t\t\t Number of questions          : " << Quiz.NumOfQuestions << endl;
    cout << "\t\t\t\t\t Number of right questions is : " <<Quiz.NumOfRightQuestions <<endl;
    cout << "\t\t\t\t\t Number of wrong questions is : " << Quiz.NumOfWrongQuestions << endl;
    cout << "\t\t\t\t\t _____________________________________________" << endl;


}
void StartGame ()
{
    stQuizInfo Quiz ;

    Quiz.NumOfQuestions = ReadNumOfQuestions() ;
    Quiz.QuizzLevel = ReadLevel() ;
    Quiz.OpQuizz = ReadOperationType() ;

    GenerateQuizQuestionList(Quiz);
    AskAndCorrectQuestions(Quiz);
    PrintFinalResult(Quiz);



}
void PlayGame ()
{
    bool PlayAgain = true ;
  do {
      StartGame ();
      cout << " Do You want to play againg ? Yes[1] , No [0]" << endl;
      cin >> PlayAgain ;



  }while (PlayAgain == 1);

}
int main ()
{

srand((unsigned)time(NULL));
PlayGame();



return 0 ;

}