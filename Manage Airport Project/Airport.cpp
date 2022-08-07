#include "Airport.h"
#include "Flight.h"

Airport::Airport()
{
	flightArr.reserve(MAX_NUM_OF_FLIGHT);
}
Airport::Airport(const string name, const string country, const string code) 
	:name(name), country(country), CODE(code)
{
	flightArr.reserve(MAX_NUM_OF_FLIGHT);
}
Airport::Airport(const Airport& other)
{
	*this = other;
}
Airport::Airport(Airport&& other) noexcept
{ 
	*this = move(other);
}
Airport::~Airport()
{
}

const Airport& Airport::operator=(const Airport& other)
{

	this->setName(other.name);
	this->setCountry(other.country);
	this->setCode(other.CODE);
	this->numOfFlight = other.numOfFlight;
	for (int i = 0; i < numOfFlight; i++)
	{
		addFlight(other.flightArr[i]);
	}
	return *this;
}
const Airport& Airport::operator=(Airport&& other) noexcept
{
	if (this != &other)
	{

	this->setName(other.name);
	this->setCountry(other.country);
	this->setCode(other.CODE);
		this->numOfFlight = other.numOfFlight;
		for (int i = 0; i < numOfFlight; i++)
		{
			addFlight(other.flightArr[i]);
		}

		other.name = nullptr;
		other.country = nullptr;
		other.CODE = nullptr;

	}
	return *this;
}



void Airport::setName(const string name)
{
	this->name = name;
}
void Airport::setCountry(const string  country)
{
	this->country = country;
}
void Airport::setCode(const string code)
{
	this->CODE = code;
}


const Flight* Airport::getFlightArr(int i) const
{
	return &flightArr[i];
}

void Airport::print()
{
	std::cout << *this << endl;
}

void Airport::addFlight(Flight flight)
{
	flightArr.push_back(flight);
	numOfFlight++;
}

ostream& operator<<(ostream& os, const Airport& a)
{
	os << "Airport date:" << endl
		<< "Name: " << a.getName() << " | Country:  " << a.getCountry() << " | COD: " << a.getCode() << endl;
		return os;
}
Flight& Airport::operator[](int index)
{	
	return flightArr[index];
}
