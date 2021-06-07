#pragma once

#include "Engine.h"
#include <string>
#include <iostream>
using namespace std;

class Vehicle {
private:
	Engine* installedEngine;
	string name;
	string owner;
public:
	explicit Vehicle(Engine, const string&, const string&);
	explicit Vehicle(const string&, unsigned int, const string&, const string&);

	string getVehicleName();
	void setVehicleName(const string&);

	string getVehicleOwner();
	void setVehicleOwner(const string&);

	Engine* getVehicleEngine();
	void setVehicleEngine(Engine);
	void setVehicleEngine(Engine*);

	virtual string drive() = 0;
	virtual string getDescription() = 0;

	virtual ~Vehicle();
};