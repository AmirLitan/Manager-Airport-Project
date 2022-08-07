#ifndef __HOST__H
#define __HOST__H

#include <iostream>
#include <string>
#include "CrewMember.h"

using namespace std;

class Host : public CrewMember
{
protected:
	int numOfFlights;

public:
	Host(const string name, int id, int numOfFlights);
	virtual ~Host();

	void        setNumOfFlights(int numOfFlights);
	int getNumOfFlights() const { return numOfFlights; }

	friend ostream& operator<<(ostream& os, const Host& h);
};

#endif // !__HOST__H




