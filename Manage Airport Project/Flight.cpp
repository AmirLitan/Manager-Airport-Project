#include "Flight.h"


Flight::Flight()
	: takeoff(""), land(""), currentNumOfPassengers(0)
{
	passArr.reserve(NUM_OF_PASSENGERS);
}
Flight::Flight(const string takeoff, const string land,const Date& date, const Plane& plane, int currentNumOfPassengers)
	: takeoff(takeoff), land(land) , currentNumOfPassengers(currentNumOfPassengers = 0)
{
	this->date = new Date(date.getDay(), date.getMonth(), date.getYear());
	this->plane = new Plane(plane.getType(), *plane.getCargo(), plane.getNumOfSeats());
}

Flight::Flight(const Flight& other)
{
	*this = other;
}

Flight::Flight(Flight&& other) noexcept
{
	*this = move(other);
}

Flight::~Flight()
{
	takeoff.clear();
	land.clear();
	delete date;
	delete plane;
	for (int i = 0; i < NUM_OF_PASSENGERS; i++)
	{
		delete[] passArr[i];
	}
	passArr.clear();
}

const Flight& Flight::operator=(const Flight& other)
{
	this->setTakeoff(other.takeoff);
	this->setLanding(other.land);
	this->setDate(*other.getDate());
	this->setPlane(*other.plane);
	this->currentNumOfPassengers = other.currentNumOfPassengers;
	return *this;
}
const Flight& Flight::operator=(Flight&& other) noexcept
{
	if (this != &other) {
		this->setTakeoff(other.takeoff);
		this->setLanding(other.land);
		this->setDate(*other.getDate());
		this->setPlane(*other.plane);
		this->currentNumOfPassengers = other.currentNumOfPassengers;

		other.takeoff.clear();
		other.land.clear();
		other.date = nullptr;
		other.plane = nullptr;
		other.currentNumOfPassengers = 0;
	}
	return *this;
}

void Flight::setTakeoff(const string takeoff)
{
	this->takeoff = takeoff;
}
void Flight::setLanding(const string landing)
{
	this->land = landing;
}
void Flight::setDate(Date& date)
{
	this->date = new Date(date);
}
void Flight::setPlane(Plane& plane)
{
	this->plane = new Plane(plane);
}
void Flight::setCurrentNumOfPassengers(int num)
{
	this->currentNumOfPassengers = num;
}

ostream& operator<<(ostream& os, const Flight& f)
{
	os << endl << "Flight data: " << endl
		<< "Takeoff: " << f.takeoff << " | land: " << f.land << endl
		<< "Number of Passengers: " << f.currentNumOfPassengers << endl;
	return os;
}

const Flight& Flight::operator+=(const Passenger& passenger)
{
	passArr.push_back(new Passenger(passenger));
	currentNumOfPassengers++;
	return *this;
}