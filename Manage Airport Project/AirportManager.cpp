#include "AirportManager.h"



AirportManager* AirportManager::airportManager = nullptr;

AirportManager* AirportManager::GetInstance(int numOfAirports, int numOfAirlines)
{
	if (airportManager == nullptr) {
		airportManager = new AirportManager(numOfAirports, numOfAirlines);
	}
	return airportManager;
}

AirportManager::~AirportManager()
{
	airlineArr.clear();
	airportArr.clear();
}



ostream& operator<<(ostream& os, const AirportManager& am)
{
	os << "Number of airports: " << am.currentNumOfAirports << endl
		<< "Number of airlines: " << am.currentNumOfAirlines << endl;
	return os;
}
AirportManager& AirportManager::operator+=(Airport& airport)
{
	airportArr.emplace_back(airport);
	currentNumOfAirports++;
	return *this;
}
AirportManager& AirportManager::operator+=(Airline& airline)
{
	airlineArr.emplace_back(airline);
	currentNumOfAirlines++;
	return *this;
}

 Airport* AirportManager::getAirportsArr(int i)  { return &airportArr[i]; }
 Airline* AirportManager::getAirlinesArr(int i)  { return &airlineArr[i]; }

void AirportManager::addAirport(Airport& a)
{
	*this += a;
}
void AirportManager::addAirline(Airline& a)
{
	*this += a;
}
void AirportManager::addFlight(Airline& airline, Flight& flight)
{
	int i;
	for (i = 0; i < currentNumOfAirlines; i++)
	{
		if (airline.getName() == airlineArr[i].getName())
		{
			airlineArr[i].addFlight(flight);
		}
	}
	for (i = 0; i < currentNumOfAirports; i++)
	{
		if (flight.getTakeoff() == airportArr[i].getCode())
		{
			airportArr[i].addFlight(flight);
		}
		if (flight.getLand() == airportArr[i].getCode())
		{
			airportArr[i].addFlight(flight);
		}
	}
}
void AirportManager::printAirport(const Airport& airport)
{
	int numOfFlight = airport.getNumOfFlight();
	cout << "num of flight: " << numOfFlight << endl;
	cout << airport;
	for (int i = 0; i < numOfFlight; i++)
	{
		cout << *airport.getFlightArr(i) << endl;
		cout << *airport.getFlightArr(i)[0].getPlane() << endl;
		cout << *airport.getFlightArr(i)[0].getDate() << endl;
	}
}
void AirportManager::printAirline(const Airline& airline)
{
	cout << airline;
	cout << "List of flights: " << endl;
	for (int i = 0; i < airline.getNumOfFlights(); i++)
	{
		cout << *airline.getFlightArr(i) << endl;
		cout << *airline.getFlightArr(i)[0].getPlane() << endl;
		cout << *airline.getFlightArr(i)[0].getDate() << endl;
	}
	cout << "List of planes: " << endl;
	for (int i = 0; i < airline.getNumOfPlanes(); i++)
	{
		cout << airline.getPlaneArr(i)[0] << endl;
	}
	cout << "List of crew: " << endl;
	for (int i = 0; i < airline.getNumOfMembers(); i++)
	{
		cout << airline.getCrewArr(i)[0] << endl;
	}
}
void AirportManager::fireCrewMember(Airline& airline, CrewMember& cm)
{
	airline.fireCrewMember(cm);
}
void AirportManager::addCrewMember(Airline& airline, CrewMember& cm)
{
	airline.addCrewMember(cm);
}
void AirportManager::deletePlane(Airline& airline, Plane& plane)
{
	airline.deletePlane(plane);
}