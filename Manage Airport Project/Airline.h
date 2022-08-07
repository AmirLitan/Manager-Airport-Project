#ifndef __AIRLINE__H
#define __AIRLINE__H

#include <stdexcept>

#include <iostream>
#include "LinkedList.h"
#include "Flight.h"
#include "Plane.h"
#include "CrewMember.h"
#include <string>
#include <vector>

using namespace std;
class Flight;
class Plane;
class CrewMember;

class Airline
{
public:
	static const int MAX_NUM_OF_FLIGHTS = 10;
	static const int MAX_NUM_OF_PLANES = 5;
protected:
	string name;
	vector<Flight*> flightArr;
	vector<Plane*> planeArr;
	Node<CrewMember*,string> crewArr;
	int currentNumOfFlights;
	int currentNumOfMembers;
	int currentNumOfPlanes;

public:
	Airline();
	Airline(const string name, int numOfFlights = 0);
	Airline(const Airline& other);
	Airline(Airline&& other) noexcept;
	virtual ~Airline();

	const Airline& operator=(const Airline& other);
	const Airline& operator=(Airline&& other) noexcept;

	void setName(const string name);
	void setNumOfFlights(int currentNumOfFlights);
	void setNumOfMembers(int currentNumOfMembers);

	const string getName()       const { return name; }
	int getNumOfFlights()		   const { return currentNumOfFlights; }
	int getNumOfMembers() const { return currentNumOfMembers; }
	int getNumOfPlanes() const { return currentNumOfPlanes; }

	CrewMember* getCrewArr(const int& i) const;
	Plane* getPlaneArr(const int& i) const;
	Flight* getFlightArr(const int& i) const;

	void addPlane(Plane& plane);
	void addFlight(Flight& flight);
	void fireCrewMember(CrewMember& cm);
	void addCrewMember(CrewMember& cm);
	void deletePlane(Plane& p);
	void print();

	friend ostream& operator<<(ostream& os, const Airline& a);
	const Airline& operator+=(const Plane& other);
};

#endif // !__AIRLINE__H
