#ifndef __CARGO__H
#define __CARGO__H

#include <iostream>
using namespace std;

class Cargo
{
protected:
	int maxWeight;
	int maxVolume;

public:
	Cargo(int maxWeight = 0, int maxVolume = 0);
	Cargo(const Cargo& other);
	Cargo(Cargo&& other) noexcept;
	~Cargo();

	const Cargo& operator=(const Cargo& other);
	const Cargo& operator=(Cargo&& other) noexcept;

	void setWeight(int maxWeight);
	void setVolume(int maxVolume);
	
	int getWeight()		const { return maxWeight; }
	int getVolume()			const { return maxVolume; }

	friend ostream& operator<<(ostream& os, const Cargo& c);
};

#endif // !__CARGO__H


