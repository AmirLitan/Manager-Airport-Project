#ifndef __FLIGHT__H
#define __FLIGHT__H

#include <iostream>
#include "Date.h"
#include "Passenger.h"
#include "Plane.h"

#include <vector>
#include <string>

using namespace std;
class Date;
class Airport;
class Plane;
class Passenger;

class Flight
{
public:
	static const int NUM_OF_PASSENGERS = 100;
protected:
	string takeoff;
	string land;
	Date* date;
	Plane* plane;
	vector <Passenger*> passArr;
	int currentNumOfPassengers;

public:
	Flight();
	Flight(const string takeoff, const string land, const Date& date, const Plane& plane, int currentNumOfPassengers = 0);
	Flight(const Flight& other);
	Flight(Flight&& other) noexcept;
	virtual ~Flight();

	const Flight& operator=(const Flight& other);
	const Flight& operator=(Flight&& other) noexcept;

	void setTakeoff(const string takeoff);
	void setLanding(const string landing);
	void setDate(Date& date);
	void setPlane(Plane& plane);
	void setCurrentNumOfPassengers(int num);

	int getCurrentNumOfPassengers() const { return currentNumOfPassengers; }
	Plane* getPlane() const { return plane; }
	Date* getDate() const { return date; }

	string getTakeoff() { return takeoff; }
	string getLand() { return land; }

	friend ostream& operator<<(ostream& os, const Flight& f);
	const Flight& operator+=(const Passenger& passenger);
};

#endif // !__FLIGHT__H

