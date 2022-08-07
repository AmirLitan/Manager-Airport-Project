#ifndef __PLANE__H
#define __PLANE__H

#include <iostream>
#include "Cargo.h"


using namespace std;
class CrewMember;

class Plane
{
public:
	enum ePlaneType { JUMBO, BOEING, AIRBUS };
	
protected:	
	int numOfSeats;
	int serialNumber;
	static int numberGenerator;
	ePlaneType type;
	Cargo cargo;

public:
	Plane(ePlaneType type, const Cargo& cargo, int numOfSeats = 0);
	Plane(const Plane& other);
	Plane(Plane&& other) noexcept;
	virtual ~Plane();

	const Plane& operator=(const Plane& other);
	const Plane& operator=(Plane&& other) noexcept;

	void setNumOfSeats(int numOfSeats);

	const int getNumOfSeats() const { return numOfSeats; }
	const int getSerialNumber() const { return serialNumber; }
	const ePlaneType getType() const { return type; }
	const Cargo* getCargo() const { return &cargo; }

	void addCrewMember(const CrewMember& other);
	const void takeoff() const;
	const void land() const;

	friend ostream& operator<<(ostream& os, const Plane& p);
};


#endif // !__PLANE__H


