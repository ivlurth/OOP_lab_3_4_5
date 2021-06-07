#pragma once

#include "Automobile.h"

class PassengerCar : public Automobile {
private:
	size_t passengerCount;
public:
	explicit PassengerCar(size_t, const string&, unsigned int, const string&, const string&, 
								  const vector<Wheel>&, const Window&, const Door&);
	size_t getPassengerCount();
	void setPassengerCount(size_t _passengerCount);

	virtual ~PassengerCar();
};