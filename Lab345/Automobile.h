#pragma once

#include "Vehicle.h"
#include "Wheel.h"
#include "Window.h"
#include "Door.h"
#include <vector>
using namespace std;


class Automobile : public Vehicle {
private:
	vector<Wheel> wheels;
	Window window;
	Door door;
public:
	explicit Automobile(const string&, unsigned int, const string&, const string&, const vector<Wheel>&, const Window&, const Door&);

	vector<Wheel> getWheels();
	void setWheels(Wheel&, size_t);

	Window getWindow();
	void setWindow(const Window&);

	Door getDoor();
	void setDoor(const Door&);

	virtual ~Automobile();
};
