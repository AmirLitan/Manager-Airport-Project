#ifndef __PILOT__H
#define __PILOT__H

#include <iostream>
#include <string>
#include "CrewMember.h"

using namespace std;

class Pilot : public CrewMember
{
protected:
	int yearsExperience;

public:
	Pilot(const string name, int id, int yearsExperience);
	virtual ~Pilot();

	void        setYearsExperience(int yearsExperience);
	int getYearsExperience() const { return yearsExperience; }

	friend ostream& operator<<(ostream& os, const Pilot& p);
};

#endif // !__PILOT__H



