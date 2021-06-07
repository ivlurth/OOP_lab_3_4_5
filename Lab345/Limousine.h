#pragma once

#include "PassengerCar.h"
#include <sstream>

class Limousine : public PassengerCar {
private:
	size_t length;
public:
	explicit Limousine(size_t, size_t, const string&, unsigned int, const string&, const string&,
		const vector<Wheel>&, const Window&, const Door&);

	size_t getLength();
	void setLength(size_t);

	virtual string drive() override;
	virtual ~Limousine();
	virtual string getDescription() override;
};
