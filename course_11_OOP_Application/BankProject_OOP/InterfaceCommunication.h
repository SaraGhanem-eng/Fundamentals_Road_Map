#pragma once

#include <iostream>
#include <string>

using namespace std;

class InterfaceCommunication
{

/* This Abstract class or interface class looks like a contract between you and the Client ,
It forces you to Implement spesific methods at your class with spesific name type and parameters list .
*/

public:

	virtual void SendEmail(string Title, string Body) = 0;
	virtual void SendFax(string Title, string Body) = 0;
	virtual void SendSMS(string Title, string Body) = 0;

};
