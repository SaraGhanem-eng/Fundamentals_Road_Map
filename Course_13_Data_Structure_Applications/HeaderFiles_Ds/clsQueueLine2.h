#pragma once 

#include <iostream>
#include <queue>
#include <stack>
#include "../../Libs/clsDate.h"
using namespace std ;

class clsQueueLine2 
{
private :

short _TotalTickets ;
short _ServingTime ;
string _Prefix ;


class clsTicket
{
private:
short _TotalTickets ;
short _WaitingClients ;
short _AverageWaitingTime ;
short _ServingTime ;
string _TicketTime ;
string _Prefix ;


public :
 
clsTicket(string prefix , short suffix , short waitingClients , short servingTime )
{
  _Prefix = prefix ;
  _TotalTickets = suffix ;
  _WaitingClients = waitingClients ;
  _ServingTime = servingTime ;
  _TicketTime = clsDate::DateToString(clsDate::GetSystemDate()) + " - " + clsDate::GetSystemTimeString();
}
string Prefix()
{
    return _Prefix;

}
short Number()
{
    return _TotalTickets;
}

string FullNumber()
{
    return _Prefix + to_string(_TotalTickets);
}

string TicketTime()
{
    return _TicketTime;
}

short WaitingClients()
{
    return _WaitingClients;
}

short ExpectedServeTime()
{
    return _ServingTime * _WaitingClients;
}


void Print()
{
    cout << "\n\t\t\t  _______________________\n";
    cout << "\n\t\t\t\t    " << FullNumber();
    cout << "\n\n\t\t\t    " << _TicketTime;
    cout << "\n\t\t\t    Wating Clients = " << WaitingClients();
    cout << "\n\t\t\t      Serve Time In";
    cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
    cout << "\n\t\t\t  _______________________\n";
                
}

};
queue <clsTicket> _QueueLine ;
public:
clsQueueLine2 (string prefix , short serveingTime )
{
  _TotalTickets = 0 ;
  _Prefix = prefix ;
  _ServingTime = serveingTime ;
}

short ServedClients()
{
  return  _TotalTickets - WaitingClients();
}

short WaitingClients()
{
   return  _QueueLine.size();
}

string WhoIsNext()
{
    if (_QueueLine.empty())
        return "No Clients Left.";
    else
        return _QueueLine.front().FullNumber();
  
}

void IssueTicket ()
{
    _TotalTickets ++ ;
    clsTicket Ticket (_Prefix , _TotalTickets , WaitingClients() , _ServingTime );
    _QueueLine.push(Ticket);
}

bool ServeNextClient()
{
    if (_QueueLine.empty() )
    return false ;

      _QueueLine.pop();
      return true ;
    
}

void PrintInfo()
{
    cout << "\n\t\t\t _________________________\n";
    cout << "\n\t\t\t\tQueue Info";
    cout << "\n\t\t\t _________________________\n";
    cout << "\n\t\t\t    Prefix   = " << _Prefix;
    cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets ;
    cout << "\n\t\t\t    Served Clients  = " << ServedClients();
    cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
    cout << "\n\t\t\t _________________________\n";
    cout << "\n";

}


void PrintTicketsLineRTL()
{
queue <clsTicket> _TempQueue = _QueueLine ;

cout << "\nTickets : " ;
if (_QueueLine.size() == 0 )
{
     cout << " Total Tickets = 0 ";
     return ;
}

while (!_TempQueue.empty())
{
    cout << _TempQueue.front().FullNumber() << " <--  ";
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

queue <clsTicket> _TempQueue = _QueueLine ;   
stack <clsTicket> _TempStack ;

 while (!_TempQueue.empty())
{
    _TempStack.push(_TempQueue.front());
    _TempQueue.pop();
}

while (!_TempStack.empty())
{
    cout << _TempStack.top().Prefix() << _TempStack.top().Number() << " -->  ";
    _TempStack.pop();
}

cout << endl;
}

void PrintAllTickets()
{
queue <clsTicket> _TempQueue = _QueueLine ;

 if (_QueueLine.empty())
 { 
    cout << "\n\n\t\t\t---No Tickets---\n";
    return;
 }

cout << "\n\n\t\t\t--- Tickets ---\n\n";
while(!_TempQueue.empty())
{
    _TempQueue.front().Print();
    _TempQueue.pop();
}
}



};