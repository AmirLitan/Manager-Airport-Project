#include "Airline.h"


Airline::Airline()
{
	flightArr.reserve(MAX_NUM_OF_FLIGHTS);
	planeArr.reserve(MAX_NUM_OF_PLANES);
}

Airline::Airline(const string name, int numOfFlights)
	: currentNumOfFlights(0), currentNumOfMembers(0) ,currentNumOfPlanes(0)
{
	this->setName(name);
	flightArr.reserve(MAX_NUM_OF_FLIGHTS);
	planeArr.reserve(MAX_NUM_OF_PLANES);
}
Airline::Airline(const Airline& other)
{
	*this = other;
}
Airline::Airline(Airline&& other) noexcept
{
	*this = other;
}
Airline::~Airline()
{
	 name.clear();
	 flightArr.clear();
	 planeArr.clear();
}

 const Airline& Airline::operator=(const Airline& other)
{
	this->setName(other.name);

	this->currentNumOfFlights = other.currentNumOfFlights;
	this->currentNumOfMembers = other.currentNumOfMembers;
	this->currentNumOfPlanes = other.currentNumOfPlanes;

	for (int i = 0; i < currentNumOfFlights; i++)
	{
		addFlight(*other.flightArr[i]);
	}
	for (int i = 0; i < currentNumOfFlights; i++)
	{
		addPlane(*other.planeArr[i]);
	}
	for (int i = 0; i < currentNumOfFlights; i++)
	{
		crewArr = other.crewArr;
	}
	return *this;
}
const Airline& Airline::operator=(Airline&& other) noexcept
{

	name.clear();
	flightArr.clear();
	planeArr.clear();


	this->setName(other.name);

	this->currentNumOfFlights = other.currentNumOfFlights;
	this->currentNumOfMembers = other.currentNumOfMembers;
	this->currentNumOfPlanes = other.currentNumOfPlanes;
	this->setName(other.name);

	for (int i = 0; i < currentNumOfFlights; i++)
	{
		addFlight(*other.flightArr[i]);
	}
	for (int i = 0; i < currentNumOfFlights; i++)
	{
		addPlane(*other.planeArr[i]);
	}
	for (int i = 0; i < currentNumOfFlights; i++)
	{
		crewArr = other.crewArr;
	}

	other.name.clear();
	other.name.clear();
	other.flightArr.clear();
	other.planeArr.clear();

	return *this;
}

void Airline::setName(const string name)
{
	this->name = name;
}
void Airline::setNumOfFlights(int currentNumOfFlights)
{
	this->currentNumOfFlights = currentNumOfFlights;
}
void Airline::setNumOfMembers(int currentNumOfMembers)
{
	this->currentNumOfMembers = currentNumOfMembers;
}

CrewMember* Airline::getCrewArr(const int& i) const
{
	return crewArr.getTypeByNum(i);
}

Plane* Airline::getPlaneArr(const int& i) const
{
	return planeArr[i];
}

Flight* Airline::getFlightArr(const int& i) const
{
	return flightArr[i];
}

void Airline::addPlane(Plane& plane)
{
	if (currentNumOfPlanes <= MAX_NUM_OF_PLANES) {
		planeArr.push_back(new Plane(plane));
		currentNumOfPlanes++;
	}
	else
	{
		throw std::invalid_argument("MAX number of plane");
	}
}

void Airline::addFlight(Flight& flight)
{
	addPlane(*flight.getPlane());
	if (currentNumOfFlights <= MAX_NUM_OF_FLIGHTS) {

		this->flightArr.push_back(new Flight(flight));
		currentNumOfFlights++;
	}
	else
	{
		throw std::invalid_argument("MAX number of flight");
	}
}
void Airline::fireCrewMember(CrewMember& cm)
{
	crewArr.remove(cm.getName());
}

void Airline::addCrewMember(CrewMember& cm)
{
	crewArr.push(&cm , cm.getName() , false);
}
void Airline::deletePlane(Plane& p)
{
	for (int i = 0; i < currentNumOfPlanes; i++)
	{
		if (p.getSerialNumber() == planeArr[i]->getSerialNumber())
		{
			planeArr.erase(planeArr.begin() + i);
		}
	}
}

void Airline::print()
{
	cout << *this;
}

ostream& operator<<(ostream& os, const Airline& a)
{
	os << "Airline data: " << endl
		<< "Airline name: " << a.getName() << endl;
	return os;
}

const Airline& Airline::operator+=(const Plane& other)
{
	return *this;
}