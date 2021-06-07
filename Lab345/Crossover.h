#pragma once

#include "PassengerCar.h"
#include <sstream>

class Crossover : public PassengerCar{
private:
	bool fullTimeAllDrive;
public:
	explicit Crossover(bool, size_t, const string&, unsigned int, const string&, const string&,
					   const vector<Wheel>&, const Window&, const Door&);

	bool isFullTimeAllDrive();
	void setFullTimeAllDrive(bool);

	virtual string drive() override;
	virtual ~Crossover();
	virtual string getDescription() override;
};
