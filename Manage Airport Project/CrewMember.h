#ifndef __CREWMEMBER__H
#define __CREWMEMBER__H

#include <iostream>
#include <string>
#include "Accessories.h"
using namespace std;

class CrewMember : public Accessories
{
protected:
	string name;
	int id;

public:
	CrewMember();
	CrewMember(const string name, int id);
	CrewMember(const CrewMember& other);
	CrewMember(CrewMember&& other) noexcept;
	virtual ~CrewMember();

	const CrewMember& operator=(const CrewMember& other);
	const CrewMember& operator=(CrewMember&& other) noexcept;

	void setName(const string name);
	void setId(int id);

	const string  getName()		const { return name; }
	int getId()			const { return id; }

	friend ostream& operator<<(ostream& os, const CrewMember& cm);
};

#endif // !__CREWMEMBER__H


