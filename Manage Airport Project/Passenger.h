#ifndef __PASSENGER__H
#define __PASSENGER__H

#include <iostream>
#include "CrewMember.h"

using namespace std;

class Passenger
{
protected:
	int ticketNumber; //3 digits

public:
	Passenger();
	Passenger(int ticketNumber);
	virtual ~Passenger();


	void        setTicketNumber(int ticketNumber);
	int getTicketNumber() const { return ticketNumber; }

	void eat() const;

	friend ostream& operator<<(ostream& os, const Passenger& p);
};

#endif // !__PASSENGER__H





