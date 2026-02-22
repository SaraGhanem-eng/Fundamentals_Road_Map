
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void ClearScreen() {
    system("clear");
}
short RandomNumber (short from , short to)
{
return rand() % (to - from +1 ) + from ;

}
enum enItems {stone =1 , paper =2 , scissors =3 };
string ToString(enItems Items)
{
if (Items == enItems::stone)
    return "Stone" ;

    else if (Items == enItems::paper)
        return "Paper" ;
    else
        return "scissors" ;

}
enItems UserChoice ()
{
    short num;
    do {

        cout << "Witch Item do you want to choose ? " << endl;
        cout << "Stone [1] , Paper [2] , Scissors [3] " <<endl;
        cin >> num;
    } while (num < 1 || num > 3);

    return enItems (num);

}
enItems ComputerChoice()
{
return enItems( RandomNumber(1,3));

}
string WhoWins (enItems user , enItems computer )
{
if ( computer == enItems::stone)

    if (user == enItems::stone)
        return "No Winner";
    else if (user == enItems::paper)
        return "Player 1";
    else
        return "Computer";

 else if (computer == enItems::paper)

     if (user == enItems::paper)
         return "No Winner" ;

    else if (user == enItems::stone)
        return "Computer" ;

    else
        return "Player 1" ;

 else if (computer == enItems::scissors)

     if (user == enItems::scissors)
         return "No Winner" ;

    else if (user == enItems::stone)
        return "Player 1";

    else
        return "Computer";


}
void ShowScoreRound (int roundnum , enItems user , enItems computer, string winner )
{
    cout << "_______________ Round [ " << roundnum  << " ] _______________" << endl;
    cout << "   PLayer 1 Choice : " << ToString ( user ) << endl;
    cout << "   Computer Choice : "  << ToString (computer) << endl;
    cout << "   Round winner : " << " [ " << winner << " ] "<< endl;
    cout << "___________________________________________" <<endl<<endl<<endl<<endl;

}
string EverySingleRound (int roundnum  )
{

    enItems User_choice ;
    enItems Computer_choice ;

cout << "Round [ " << roundnum << " ] Begins : " << endl<<endl;

    User_choice  = UserChoice();
    Computer_choice = ComputerChoice();

    string winner = WhoWins(User_choice,Computer_choice);



   ShowScoreRound(roundnum , User_choice , Computer_choice , winner );

return winner ;

}
void GameOver (short roundnum ,short player ,short computer , short draw , string finalwinner)
{
    cout <<"\t\t"<< " _____________________________________________________________" << endl << endl;
    cout <<"\t\t"<< " ________________ + + + Game Over + + + ______________________" << endl << endl;
    cout <<"\t\t"<< " Game Rounds        : " <<roundnum << endl;
    cout <<"\t\t"<< " Player 1 won times : "<< player << endl;
    cout <<"\t\t"<< " Computer won times : " << computer << endl;
    cout <<"\t\t"<< " Draw times         : " << draw << endl;
    cout <<"\t\t"<< " Final winner       : " << finalwinner<< endl;
    cout <<"\t\t"<< "_______________________________________________________________" << endl<< endl;



}
bool MoreRounds ()
{
    char yesorno ;
    cout << "Do you want to play another game ? (Y/N) " << endl;
    cin>> yesorno ;

    if (yesorno == 'y' || yesorno =='Y' )
        return true ;
    else
        return false ;

}
void StartGame ()
{

        short rounds ;
        cout << "How many rounds do you want to play from 1 to 10  ? "<< endl;
        cin >> rounds ;


        short computer =0 ;
        short user = 0 ;
        short draw =0 ;

        for (int i =1 ; i<= rounds ; i++ )
        {

            string winner = EverySingleRound (i);



            if (winner == "Computer")
                computer++ ;
            else if (winner == "Player 1")
                user ++ ;
            else
                draw ++;


        }

        string winner ;
        if ( user == computer)
            winner =  " No Winner ";
        else if (user > computer )
            winner = " Player 1 " ;
        else
            winner = " Computer" ;




        GameOver (rounds , user , computer , draw , winner );

}



int main ()
{

    srand((unsigned)time(NULL));


do {

ClearScreen();
StartGame();

}while (MoreRounds());


return 0 ;

}