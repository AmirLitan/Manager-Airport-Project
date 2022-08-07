#ifndef __AIRPORTMANAGER__H
#define __AIRPORTMANAGER__H

#include <iostream>
#include <vector>
#include "Airline.h"
#include "Airport.h"


using namespace std;

class Airport;
class Airline;
class CrewMember;
class Flight;
class Plane;



class AirportManager
{
public:
	static const int MAX_NUM_OF_AIRPORTS = 5;
	static const int MAX_NUM_OF_AIRLINES = 10;

protected:

	AirportManager(int numOfAirports = 0, int numOfAirlines = 0) 
		: currentNumOfAirlines(0), currentNumOfAirports(0) {}

	static AirportManager* airportManager;

	vector<Airport> airportArr;
	vector<Airline> airlineArr;
	int currentNumOfAirports;
	int currentNumOfAirlines;
public:
	AirportManager() = delete;
	AirportManager(const AirportManager& other) = delete;
	AirportManager(AirportManager&& other)noexcept = delete;
	const AirportManager& operator=(const AirportManager& other) = delete;
	const AirportManager& operator=(AirportManager&& other) noexcept = delete;

	static AirportManager* GetInstance(int numOfAirports = 0, int numOfAirlines = 0);
	virtual ~AirportManager();

	int getNumOfAirports()       const { return currentNumOfAirports; }
	int getNumOfAirlines()      const { return currentNumOfAirlines; }

	 Airport* getAirportsArr(int i) ;
	 Airline* getAirlinesArr(int i) ;

	friend ostream& operator<<(ostream& os, const AirportManager& am);
	AirportManager& operator+=(Airport& airport);
	AirportManager& operator+=(Airline& airline);

	void addAirport(Airport& a);
	void addAirline(Airline& a);
	void addFlight(Airline& airline, Flight& flight);
	void printAirport(const Airport& airport);
	void printAirline(const Airline& airline);
	void fireCrewMember(Airline& airline, CrewMember& cm);
	void addCrewMember(Airline& airline, CrewMember& cm);
	void deletePlane(Airline& airline, Plane& plane);
};


#endif // !__AIRPORTMANAGER__H