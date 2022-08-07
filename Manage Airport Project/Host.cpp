#include "Host.h"

Host::Host(const string name, int id, int numOfFlights)
	:CrewMember(name,id), numOfFlights(numOfFlights)
{
}
Host::~Host()
{
}

void Host::setNumOfFlights(int numOfFlights)
{
	this->numOfFlights = numOfFlights;
}

ostream& operator<<(ostream& os, const Host& h)
{
	os << "Id: " << h.id << "Name: " << h.name << "Number Of Flights: " << h.numOfFlights;
	return os;
}