
#include <iostream>
using namespace std  ;

enum enWinner {player = 1 , computer =2 , draw =3 };
enum enChoices {stone =1 , paper =2 , scissors =3 };
struct stRoundInfo
{
   short RoundNumber ;
   enChoices PlayerChoice  ;
    enChoices ComputerChoice ;
    enWinner Winner ;
    string WinnerName ;

};
struct stGameInfo
{
    short NumberOfRounds ;
    short ComputerWinTimes ;
    short PlayerWinTimes ;
    short DrawTimes ;
    enWinner GameWinner ;
    string WinnerName ;



};
short RandomNumber (short from , short to)
{
    return rand() % (to - from +1 ) + from ;

}
enChoices ReadPlayerChoice ()
{
    short Choice ;
  do {
       cout << " Your Choice : [1] : Stone , [2] : Paper , [3] Scissors " << endl;
       cin >> Choice ;



     }while (Choice < 1 || Choice >3);

return enChoices (Choice) ;
}
enChoices GetComputerChoice ()
{
    return enChoices (RandomNumber(1,3));
}
string ChoiceName (enChoices Choice )
{
  string ChoiceWinners [3] { " Stone ", " Paper " , " Scissors "  };
  return ChoiceWinners [Choice -1 ];

}
string WinnerName (enWinner Winer )
{
string WinnerNames [3] { " Player ", " Computer " , " Draw "  };
return WinnerNames [Winer -1 ];

}
short HowManyRounds ()
{
    short Rounds ;

  do {
        cout << "How many rounds do you want to play " << endl;
        cin >> Rounds ;

      } while (Rounds < 1 || Rounds > 10);

 return Rounds ;
}
enWinner WhoWonTheRound (stRoundInfo RoundInfo)
{
    if (RoundInfo.ComputerChoice == RoundInfo.PlayerChoice)
        return enWinner::draw;


    switch(RoundInfo.PlayerChoice)
    {
        case enChoices::stone:

            if (RoundInfo.ComputerChoice == enChoices::paper)

            {
                return enWinner::computer;
            }

            break ;

        case enChoices::paper:

            if (RoundInfo.ComputerChoice == enChoices::scissors)
            {
                return enWinner::computer;
            }

            break ;

        case enChoices::scissors:

            if (RoundInfo.ComputerChoice == enChoices::stone)
            {
                return enWinner::computer;
            }
            break ;

    }
}
enWinner WhoWonTheGame (short PlayerWonTimes , short ComputerWonTimes)
{
  if (ComputerWonTimes == PlayerWonTimes )
      return enWinner::draw ;

    else if (ComputerWonTimes > PlayerWonTimes)
        return enWinner::computer ;

    else
        return enWinner::player ;


}
string Tabs (short TabNum )
{
  string t = "";
    for (int i =1 ; i <= TabNum ; i++ )
        {
          t += "\t" ;

        }
    return t ;
}
stGameInfo FillGameInfo (short NumberOfronds , short PlayerWinTimes , short ComputerWinTimes ,short  DrawTimes )
{
  stGameInfo GameInfo ;

    GameInfo.NumberOfRounds = NumberOfronds ;
    GameInfo.PlayerWinTimes = PlayerWinTimes ;
    GameInfo.ComputerWinTimes = ComputerWinTimes ;
    GameInfo.DrawTimes = DrawTimes ;
    GameInfo.GameWinner = WhoWonTheGame( GameInfo.PlayerWinTimes , GameInfo.ComputerWinTimes ) ;
    GameInfo.WinnerName = WinnerName(GameInfo.GameWinner);

    return GameInfo ;
}
void PrintHeaderGameOver ()
{
cout <<endl<<endl<<endl;
cout << Tabs(5) << "________________________________________________________________" <<  endl;
cout << Tabs(5) << Tabs(5) << " + + + + " <<" Game Over " << " + + + + " << Tabs(5) <<  endl;
cout << Tabs(5) << "________________________________________________________________"<< endl<<endl;
cout << Tabs(5) << "______________________ [ Game Results ] ________________________" << endl << endl;

}
void PrintGameInfo (stGameInfo GameInfo)
{
cout << Tabs(5) << "Game Rounds         :" << GameInfo.NumberOfRounds << endl;
cout << Tabs(5) << "Player 1 Won Times  :" << GameInfo.PlayerWinTimes << endl;
cout << Tabs(5) << "ComPuter Won Times  :" << GameInfo.ComputerWinTimes << endl;
cout << Tabs(5) << "Draw Times          :" << GameInfo.DrawTimes << endl;
cout << Tabs(5) << "Final Winner        :" << GameInfo.WinnerName << endl;
cout << Tabs(5) << "__________________________________________________________________" << endl << endl;

}
void PrintRoundResults (stRoundInfo RoundResults )
{
    cout << Tabs(2) << "_______________ Round [ " << RoundResults.RoundNumber << " ] _______________ " << endl;
    cout << Tabs(2) << "Player 1 Choice : " << ChoiceName(RoundResults.PlayerChoice )<< endl;
    cout << Tabs(2) << "Computer Choice : " << ChoiceName(RoundResults.ComputerChoice) << endl;
    cout << Tabs(2) << "Round Winner    : " << RoundResults.WinnerName << endl;
    cout << Tabs(2) << "____________________________________________" << endl << endl<< endl;


}
stGameInfo PlayGame (short Rounds )
{
    stRoundInfo RoundInfo ;

    short PlayerWinTimes =0 , ComputerWinTimes =0 , DrawTime =0 ;

    for (int i=1 ; i <= Rounds ; i++ )
        {

        cout << Tabs(2) << "Round [ " << i << " ] Begins : "<< endl << endl;

        RoundInfo.RoundNumber = i ;
        RoundInfo.PlayerChoice = ReadPlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound( RoundInfo ) ;
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);


        if (RoundInfo.Winner == enWinner::draw)
                DrawTime ++ ;
        else if
           (RoundInfo.Winner > enWinner::player)
                PlayerWinTimes ++ ;
        else
                ComputerWinTimes ++ ;




        PrintRoundResults(RoundInfo);
        }




    return FillGameInfo (Rounds , PlayerWinTimes , ComputerWinTimes , DrawTime );

}
void StartGame ()
{
   char PlayAgain = 'y';

  do {

      stGameInfo GameInfo =  PlayGame(HowManyRounds());
      PrintHeaderGameOver();
      PrintGameInfo(GameInfo);


      cout << " Do you want to play again ? [y / n] "<<endl;
      cin >> PlayAgain ;




     }while (PlayAgain == 'y' || PlayAgain == 'Y');



}
int main ()
{
srand((unsigned)time(NULL));
StartGame() ;

    return 0 ;
}