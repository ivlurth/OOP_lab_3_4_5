#include "Vehicle.h"

Vehicle::Vehicle(Engine _engine, const string& _name, const string& _owner) : installedEngine(&_engine), name(_name), owner(_owner) 
{
	cout << "Vehicle has been created!" << endl;
}


Vehicle::Vehicle(const string& _model, unsigned int _horsePower, const string& _name, const string& _owner)
	   : installedEngine(new Engine{_model, _horsePower}), name(_name), owner(_owner) { 
	cout << "Vehicle has been created!" << endl;
}

string Vehicle::getVehicleName() {
	return name;
}

void Vehicle::setVehicleName(const string& _name) {
	name = _name;
}


string Vehicle::getVehicleOwner() {
	return owner;
}

void Vehicle::setVehicleOwner(const string& _owner) {
	owner = _owner;
}


Engine* Vehicle::getVehicleEngine() {
	return installedEngine;
}

void Vehicle::setVehicleEngine(Engine _engine) {
	installedEngine = &_engine;
}

void Vehicle::setVehicleEngine(Engine* _engine) {
	installedEngine = _engine;
}

Vehicle::~Vehicle() {
	delete installedEngine;
	cout << "Vehicle has been destroyed!" << endl;
}