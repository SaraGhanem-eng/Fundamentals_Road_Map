#pragma once 

#include <iostream>
#include <queue>
#include <stack>
#include "../../Libs/clsDate.h"
using namespace std ;

class clsQueueLine 
{

private :
struct stTicketInfo
{
  string Prefix ;
  short Suffix ; 
  string FullNumber ;
  string DateTime ;
  short WaitingClients ;
  short ServeTime ;
  
};

short _WaitingClients = 0 ;
short _ServedClients = 0 ;
short _TotalTickets = 0 ;
short _AverageServeTime = 0 ;
string _Prefix ;

queue <stTicketInfo> _QueueLine ;

stTicketInfo _FillTicketInfo()
{
 stTicketInfo Ticket ;

 Ticket.DateTime = clsDate::GetSystemTimeString() + " - " + clsDate::DateToString(clsDate::GetSystemDate())  ;
 Ticket.Prefix = _Prefix ;
 Ticket.Suffix = _TotalTickets;
 Ticket.FullNumber = Ticket.Prefix + to_string(Ticket.Suffix) ;
 Ticket.WaitingClients = _WaitingClients;
 Ticket.ServeTime = _WaitingClients * _AverageServeTime ;
  
 return Ticket;
} 

void _PrintTicketInfo(stTicketInfo Ticket)
{
   cout << "\n\n\t_________________________\n\n";
   cout << "\t\t" << Ticket.FullNumber << endl << endl;
   cout << "\t" << Ticket.DateTime << endl;
   cout << "\tWaiting Clients: " << Ticket.WaitingClients << endl;
   cout << "\tServe Time In " << endl;
   cout << "\t" << Ticket.ServeTime << " Minutes " << endl;
   cout << "\t_________________________\n\n";
}

public :    

clsQueueLine (string prefix , int ServeTime )
{
  _Prefix = prefix ;
  _AverageServeTime = ServeTime ;
}

void IssueTicket()
{
  _TotalTickets++;
  stTicketInfo NewTicket = _FillTicketInfo();
  _QueueLine.push(NewTicket);
  _WaitingClients ++ ;

}

void PrintInfo()
{
    cout << "\n_________________________";
    cout << "\n         Queue Info       \n";
    cout << "_________________________\n";
    cout << "Prefix    : " << _Prefix << endl;
    cout << "Total Tickets   : " << _TotalTickets << endl;
    cout << "Served Clients  : " << _ServedClients << endl;
    cout << "Waiting Clients : " << _WaitingClients << endl;
    cout << "_________________________\n";
}

void PrintTicketsLineRTL()
{
queue <stTicketInfo> _TempQueue = _QueueLine ;

cout << "\nTickets : " ;
if (_QueueLine.size() == 0 )
{
     cout << " Total Tickets = 0 ";
     return ;
}

while (!_TempQueue.empty())
{
    cout << _TempQueue.front().FullNumber << " <--  ";
    _TempQueue.pop();
}
cout << endl;
}

void PrintTicketsLineLTR()
{
cout << "\nTickets : " ;
if (_QueueLine.size() == 0 )
{
     cout << " Total Tickets = 0 ";
     return ;
}

queue <stTicketInfo> _TempQueue = _QueueLine ;   
stack <stTicketInfo> _TempStack ;

 while (!_TempQueue.empty())
{
    _TempStack.push(_TempQueue.front());
    _TempQueue.pop();
}

while (!_TempStack.empty())
{
    cout << _TempStack.top().Prefix << _TempStack.top().Suffix << " -->  ";
    _TempStack.pop();
}

cout << endl;
}

void PrintAllTickets()
{
queue <stTicketInfo> _TempQueue = _QueueLine ;

 if (_QueueLine.empty())
 { 
    cout << "\n\n\t\t\t---No Tickets---\n";
    return;
 }

cout << "\n\n\t\t\t--- Tickets ---\n\n";
while(!_TempQueue.empty())
{
    _PrintTicketInfo(_TempQueue.front());
    _TempQueue.pop();
}
}

void ServeNextClient ()
{
   if (!_QueueLine.empty() ) 
   {
    _QueueLine.pop();  
    _ServedClients++ ;
    _WaitingClients --;
   }
}

short WaitingClients()
{
    return _QueueLine.size() ;
}

string WhoIsNext ()
{
    if (_QueueLine.empty())
        return "\nNo Clients Left\n";     
    else
        return _QueueLine.front().FullNumber;
}

short SavedClients()
{
    return _TotalTickets - WaitingClients() ;
}

};