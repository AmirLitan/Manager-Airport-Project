#ifndef __SECURITYMAN__H
#define __SECURITYMAN__H

#include <iostream>
#include <string>
#include "CrewMember.h"
#include "Passenger.h"

using namespace std;

class SecurityMan : public CrewMember, protected Passenger
{
protected:
	bool isArmd;

public:
	SecurityMan();
	SecurityMan(const string name, int id, int ticketNumber, bool isArmd);
	virtual ~SecurityMan();

	bool getIsArmd() const { return isArmd; }
	friend ostream& operator<<(ostream& os, const SecurityMan& s);
};

#endif // !__SECURITYMAN__H




