#include "CrewMember.h"


CrewMember::CrewMember() 
{
	this->setName("");
	this->id = 0;
}
CrewMember::CrewMember(const string name, int id)
	: name(name) , id(id)
{	
}

CrewMember::CrewMember(const CrewMember& other)
{
	this->setName(other.name);
	this->id = other.id;
}
CrewMember::CrewMember(CrewMember&& other) noexcept
{

	*this = other;
}
CrewMember::~CrewMember()
{
}

const CrewMember& CrewMember::operator=(const CrewMember& other) 
{
	CrewMember* cm = new CrewMember(other.name, other.id);
	return *cm;
}
const CrewMember& CrewMember::operator=(CrewMember&& other) noexcept
{
	if (this != &other) {
		name.clear();
		this->name = other.name;
		this->id = other.id;
		other.name.clear();
		other.id = 0;
	}
	return *this;
}

void CrewMember::setName(const string name)
{
	this->name = name;
}
void CrewMember::setId(int id)
{
	this->id = id;
}

ostream& operator<<(ostream& os, const CrewMember& cm)
{
	os << "Crew member data: " << endl
		<< "Name: " << cm.name << " | ID: " << cm.id << endl;
		return os;
}
