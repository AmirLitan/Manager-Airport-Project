
#include "Cargo.h"


	Cargo::Cargo(int maxWeight, int maxVolume) 
		: maxWeight(maxWeight), maxVolume(maxVolume)
	{
	}
	Cargo::Cargo(const Cargo& other)
	{
		*this = other;
	}

	Cargo::Cargo(Cargo&& other) noexcept
	{
		*this = other;
	}

	Cargo::~Cargo() {}

	const Cargo& Cargo::operator=(const Cargo& other)
	{
		this->maxWeight = other.maxWeight;
		this->maxVolume = other.maxVolume;
		return *this;
	}
	const Cargo& Cargo::operator=(Cargo&& other) noexcept
	{
		if (this != &other) {
			this->maxWeight = other.maxWeight;
			this->maxVolume = other.maxVolume;

			other.maxWeight = 0;
			other.maxVolume = 0;
		}
		return *this;

	}

	void Cargo::setWeight(int maxWeight)
	{
		this->maxWeight = maxWeight;
	}
	void Cargo::setVolume(int maxVolume)
	{
		this->maxVolume = maxVolume;
	}

	 ostream& operator<<(ostream& os, const Cargo& c)
	 {
		 os << "Weight: " << c.getWeight() << " | Volume: " << c.getVolume() << endl;
		 return os;
	 }