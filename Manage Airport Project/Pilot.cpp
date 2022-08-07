#include "Pilot.h"

Pilot::Pilot(const string name, int id, int yearsExperience)
	:CrewMember(name,id),yearsExperience(yearsExperience)
{
}
Pilot::~Pilot()
{
}

void Pilot::setYearsExperience(int yearsExperience)
{
	this->yearsExperience = yearsExperience;
}

ostream& operator<<(ostream& os, const Pilot& p)
{
	os << "Id: " << p.id << "Name: " << p.name << "Years of experience: " << p.yearsExperience;
	return os;
}