#ifndef __AIRPORT__H
#define __AIRPORT__H

#include <iostream>
#include <vector>
#include <string>
#include "Flight.h"

using namespace std;
class Flight;

class Airport
{
public:
	static const int MAX_NUM_OF_FLIGHT = 5;

protected:
	string name;
	string country;
	string CODE; //only 3 upper chars
	vector<Flight> flightArr;
	int numOfFlight = 0;

public:
	Airport();
	Airport(const string name, const string country, const string code);
	Airport(const Airport& other);
	Airport(Airport&& other) noexcept;
	virtual ~Airport();

	const Airport& operator=(const Airport& other);
	const Airport& operator=(Airport&& other) noexcept;

	void setName(const string name);
	void setCountry(const string country);
	void setCode(const string code);

	const string getName()       const { return name; }
	const string getCountry()      const { return country; }
	const string  getCode() const { return CODE; }

	const int getNumOfFlight() const { return numOfFlight; }
	const Flight* getFlightArr(int i) const;

	void print();
	void addFlight(Flight flight);

	friend ostream& operator<<(ostream& os, const Airport& a);
	Flight&       operator[](int index);
};

#endif // !__AIRPORT__H
