#ifndef __MAIN__H
#define __MAIN__H
#include <string>
#include <vector>
#include "AirportManager.h"
#include "Airport.h"
#include "Airline.h"
#include "Flight.h"
#include "CrewMember.h"
#include "Pilot.h"
#include "Host.h"
#include "Passenger.h"
#include "SecurityMan.h"
#include "Plane.h"
#include "Cargo.h"
#include "Date.h"

#include <ctime>

enum eMenuOptions
{
	eAddAirport, eAddAirline, eAddFlight, ePrintAirport, ePrintAirline,
	eFireCrewMember, eAddMemberToCrew, eDeletePlaneFromAirline,
	eNofOptions

};

static const int MAX_LEN = 255;

const char* str[eNofOptions] = { "Add Airport", "Add Airline", "Add Flight", "Print Airport", "Print Airline" ,
	"Fire Crew member", "Add Member to Crew", "Delete Plane from Airline" };

int menu();
void cleanBuffer();

Airport* initAirport();
Airline* initAirline();
Flight* initFlight();
CrewMember* initCrewMember();
 Airline* pickAirlineByName(AirportManager* am);
Airport* pickAirportByName(AirportManager* am);
CrewMember* pickMemberById(Airline* airline);
Plane* pickPlaneBySerialNumber(Airline* airline);
Date* initDate();
Plane* initPlane();
void printAllAirlines(AirportManager* am);
void printAllAirports(AirportManager* am);

#endif // !__MAIN__H
