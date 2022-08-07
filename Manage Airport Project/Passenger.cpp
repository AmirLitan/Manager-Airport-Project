#include "Passenger.h"

Passenger::Passenger() : ticketNumber(0)
{
}
Passenger::Passenger(int ticketNumber) : ticketNumber(ticketNumber)
{
}

Passenger::~Passenger() {}

void Passenger::setTicketNumber(int ticketNumber)
{
	this->ticketNumber = ticketNumber;
}

void Passenger::eat() const {}

ostream& operator<<(ostream& os, const Passenger& p)
{
	os << "Passenger ticket number: " << p.ticketNumber;
	return os;
}