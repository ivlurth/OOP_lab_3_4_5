#pragma once

#include "CargoCar.h"
#include <sstream>

class Truck : public CargoCar {
private:
	bool forkLiftPresent;
public:
	explicit Truck(bool, size_t, const string&, unsigned int, const string&, const string&,
		const vector<Wheel>&, const Window&, const Door&);

	bool hasForkLift();
	void setForkLiftPresence(bool);

	virtual string drive() override;
	virtual ~Truck();
	virtual string getDescription() override;
};