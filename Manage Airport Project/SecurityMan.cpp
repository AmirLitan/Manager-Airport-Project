#include "SecurityMan.h"

SecurityMan::SecurityMan() : CrewMember("", 0), Passenger(0),isArmd(0)
{
}
SecurityMan::SecurityMan(const string name, int id, int ticketNumber, bool isArmd)
	: CrewMember(name,id),Passenger(ticketNumber), isArmd(isArmd)
{
}
SecurityMan::~SecurityMan()
{
}

ostream& operator<<(ostream& os, const SecurityMan& s)
{
	os << "Id: " << s.id << 
		"Name: " << s.name << 
		"Tocket number: " << s.ticketNumber << 
		"Armd: " << s.isArmd;
	return os;
}