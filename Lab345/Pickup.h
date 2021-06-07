#pragma once

#include "PassengerCar.h"
#include <sstream>

class Pickup : public PassengerCar {
private:
	size_t cargoLoad;
public:
	explicit Pickup(size_t, size_t, const string&, unsigned int, const string&, const string&,
		const vector<Wheel>&, const Window&, const Door&);

	size_t getCargoLoad();
	void setCargoLoad(size_t);

	virtual string drive() override;
	virtual ~Pickup();
	virtual string getDescription() override;
};
