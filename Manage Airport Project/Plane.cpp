#include "Plane.h"


Plane::Plane(ePlaneType type, const Cargo& cargo, int numOfSeats) 
	:serialNumber((rand() % 999) + 100), numOfSeats(numOfSeats), type(type)
{
	this->cargo = cargo;
}
Plane::Plane(const Plane& other)
{
	*this = other;
}
Plane::Plane(Plane&& other) noexcept
{
	*this = move(other);
}
Plane::~Plane()
{
}

const Plane& Plane::operator=(const Plane& other)
{
	this->serialNumber = other.serialNumber;
	this->numOfSeats = other.numOfSeats;
	this->type = other.type;
	this->cargo = Cargo(other.getCargo()->getWeight(), other.getCargo()->getVolume());

	return *this;
}
const Plane& Plane::operator=(Plane&& other) noexcept
{
	if (this != &other) 
	{
		this->serialNumber = other.serialNumber;
		this->numOfSeats = other.numOfSeats;
		this->type = other.type;
		this->cargo = Cargo(other.getCargo()->getWeight(), other.getCargo()->getVolume());

		other.serialNumber = 0;
		other.numOfSeats = 0;
	}
	return *this;
}

void Plane::setNumOfSeats(int numOfSeats)
{
	this->numOfSeats = numOfSeats;
}

void Plane::addCrewMember(const CrewMember& other)
{
}
const void Plane::takeoff() const
{
}
const void Plane::land() const
{
}

ostream& operator<<(ostream& os, const Plane& p) 
{
	const char* planeTypes[3] = { "Jumbo", "Boeing", "Airbus" };

	os << "Serial number: " << p.serialNumber << endl <<
		" | Plane type: " << planeTypes[p.getType()] << endl <<
		" | Number of seats:  " << p.numOfSeats << endl <<
		" | Cargo: " << *p.getCargo() << endl;
	return os;
}