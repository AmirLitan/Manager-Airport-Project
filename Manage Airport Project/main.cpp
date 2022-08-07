#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable: 4996)

#include <iostream>
using namespace std;

#include "main.h"
 
int main()
{
	srand((unsigned)time(0));

	AirportManager* am = AirportManager::GetInstance(0, 0);
	Airline* airline = NULL;
	Airport* airport = NULL;
	CrewMember* member = NULL;

	int stop = 0;
	do
	{
		int choice = menu();
		switch (choice)
		{
		case eAddAirport:
			airport = initAirport();
			am->addAirport(*airport);
			break;

		case eAddAirline:
			airline = initAirline();
			am->addAirline(*airline);
			break;

		case eAddFlight:
			printAllAirlines(am);
			airline = pickAirlineByName(am);
			if (airline != NULL)
			{ 
				Flight* flight = initFlight();
				am->addFlight(*airline, *flight);
			}
			else
				cout << "Airline does'nt exist\n";
			break;

		case ePrintAirport:
			printAllAirports(am);
			airport = pickAirportByName(am);
			if(airport != NULL)
				am->printAirport(*airport);
			else
				cout << "Airport does'nt exist\n";
			break;

		case ePrintAirline:
			printAllAirlines(am);
			airline = pickAirlineByName(am);
			if(airline != NULL)
				am->printAirline(*airline);
			else
				cout << "Airline does'nt exist\n";
			break;

		case eFireCrewMember:
			printAllAirlines(am);
			airline = pickAirlineByName(am);
			if (airline != NULL)
			{
				member = pickMemberById(airline);
				if (member != NULL)
					am->fireCrewMember(*airline, *member);
				else
					cout << "member does'nt exist\n";
			}	
			else
				cout << "Airline does'nt exist\n";
			break;

		case eAddMemberToCrew:
			printAllAirlines(am);
			airline = pickAirlineByName(am);
			if (airline != NULL)
			{
				member = initCrewMember();
				if(member != NULL)
					am->addCrewMember(*airline, *member);
				else
					cout << "member does'nt exist\n";
			}
			else
				cout << "Airline does'nt exist\n";
			break;

		case eDeletePlaneFromAirline:
			printAllAirlines(am);
			airline = pickAirlineByName(am);
			if (airline != NULL)
			{
				Plane* plane = pickPlaneBySerialNumber(airline);
				if(plane != NULL)
					am->deletePlane(*airline, *plane);
				else
					cout << "plane does'nt exist\n";
			}
			else
				cout << "Airline does'nt exist\n";
			break;

		case -1:
			printf("Bye bye\n");
			stop = 1;
			break;

		default:
			printf("Wrong choice\n");
			break;
		}
	} while (!stop);
}

int menu()
{
	int option;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	for (int i = 0; i < eNofOptions; i++)
		cout << i << "-" << str[i] << "\n";
	cout <<"-1 -" << "Quit\n";
	cin >> option;
	cleanBuffer();
	return option;
}

void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

Airport* initAirport()
{
	char name[MAX_LEN], country[MAX_LEN];
	char CODE[4];

	cout << "Enter airport's name: \n";
	cin >> name;

	cout << "Enter airport's country: \n";
	cin >> country;

	cout << "Enter airport's code: (3 upper letters)\n";
	cin >> CODE;

	return new Airport(name, country, CODE);
}

Airline* initAirline()
{
	char name[MAX_LEN];

	cout << "Enter airline's name: \n";
	cin >> name;

	return new Airline(name);
}

Flight* initFlight()
{
	char takeoff[4];
	char land[4];

	cout << "Enter airport's takeoff code: (3 upper letters)\n";
	cin >> takeoff;

	cout << "Enter airport's landing code: (3 upper letters)\n";
	cin >> land;

	Date* date = initDate();
	Plane* plane = initPlane();

	return new Flight(takeoff, land, *date, *plane);
}

 Airline* pickAirlineByName(AirportManager* am)
{
	char airlineName[MAX_LEN];
	int size = am->getNumOfAirlines();

	cout << "Enter airline name: \n";
	cin >> airlineName;

	for (int i = 0; i < size; i++)
	{
		if (am->getAirlinesArr(i)->getName() == airlineName)
			return am->getAirlinesArr(i);
	}
	return NULL;
}

Airport* pickAirportByName(AirportManager* am)
{
	string airportName;
	int size = am->getNumOfAirports();

	cout << "Enter airport code: \n";
	cin >> airportName;

	for (int i = 0; i < size; i++)
	{
		if (am->getAirportsArr(i)->getName() == airportName) 
		{
			return am->getAirportsArr(i);
		}
	}
	return NULL;
}

CrewMember* pickMemberById(Airline* airline)
{
	int id, size = airline->getNumOfMembers();
	cout << "Enter crew member id: \n";
	cin >> id;

	for (int i = 0; i < size; i++)
	{
		if (airline->getCrewArr(i)[0].getId() == id)
			return &airline->getCrewArr(i)[0];
	}
	return NULL;
}

Plane* pickPlaneBySerialNumber(Airline* airline)
{
	int serialNum, size = airline->getNumOfPlanes();
	cout << "Enter plane serial number: \n";
	cin >> serialNum;

	for (int i = 0; i < size; i++)
	{
		if (airline->getPlaneArr(i)[0].getSerialNumber() == serialNum)
			return &airline->getPlaneArr(i)[0];
	}
	return NULL;
}

Date* initDate()
{
	int day, month, year;
	cout << "Enter Date flight: \n";

	cout << "Enter day: \n";
	cin >> day;

	cout << "Enter month: \n";
	cin >> month;

	cout << "Enter year: \n";
	cin >> year;

	return new Date(day, month, year);
}

Plane* initPlane()
{
	int numOfSeats, maxVolume, maxWeight;
	cout << "Enter num of seats: \n";
	cin >> numOfSeats;

	int type;
	cout << "Enter type [0-Jumbo, 1- Boeing, 2-Airbus]: \n";
	cin >> type;

	cout << "Enter max volume cargo: \n";
	cin >> maxVolume;
	cout << "Enter max weight cargo: \n";
	cin >> maxWeight;

	Cargo* cargo = new Cargo(maxWeight, maxVolume);

	return new Plane((Plane::ePlaneType)type, *cargo, numOfSeats);
}

CrewMember* initCrewMember()
{
	char name[MAX_LEN];
	int id;

	cout << "Enter Crew member name: \n";
	cin >> name;

	cout << "Enter Crew member id; \n";
	cin >> id;

	int status;
	cout << "Enter status [1- Pilot, 2-Host]: \n";
	cin >> status;

	switch (status)
	{
	case 1:
	{
		int yearExper;
		cout << "Enter Years of experience of pilot: \n";
		cin >> yearExper;

		return new Pilot(name, id, yearExper);
	}
	case 2:
	{
		int numOfFlights;
		cout << "Enter number of flights of host: \n";
		cin >> numOfFlights;

		return new Host(name, id, numOfFlights);
	}
	default:
		return NULL;
		break;
	}
}

void printAllAirlines(AirportManager* am)
{
	int size = am->getNumOfAirlines();
	cout << "All airlines are:\n";

	for (int i = 0; i < size; i++)
	{
		cout << am->getAirlinesArr(i)->getName() << "\n";
	}
}

void printAllAirports(AirportManager* am)
{
	int size = am->getNumOfAirports();
	cout << "All airports are:\n";

	for (int i = 0; i < size; i++)
	{
		cout << am->getAirportsArr(i)->getName() << "\n";
	}
}