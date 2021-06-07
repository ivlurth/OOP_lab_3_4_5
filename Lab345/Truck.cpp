#include "Truck.h"

Truck::Truck(bool _hasForkLift,
	size_t _cargoLoad, const string& _model, unsigned int _horsePower, const string& _name, const string& _owner,
	const vector<Wheel>& _wheels, const Window& _window, const Door& _door)
	: CargoCar{ _cargoLoad, _model, _horsePower, _name, _owner, _wheels, _window, _door }, forkLiftPresent(_hasForkLift) { 
	cout << "Truck has been created!" << endl;
}

bool Truck::hasForkLift() {
	return forkLiftPresent;
}

void Truck::setForkLiftPresence(bool _hasForkLift) {
	forkLiftPresent = _hasForkLift;
}

string Truck::drive() {
	return "I'm driving in a Truck! Kaboom...";
}

Truck::~Truck() { 
	cout << "Truck has been destroyed!" << endl;
}

string Truck::getDescription() {
	stringstream ss;

	ss << "Truck" << endl;
	ss << getVehicleEngine()->getEngineModel() << endl;
	ss << getVehicleEngine()->getHorsePower() << endl;
	ss << getVehicleName() << endl;
	ss << getVehicleOwner() << endl;
	ss << getWheels().size() << endl;
	ss << getWheels().at(0).getTyre() << endl;
	ss << getWindow().getGlass() << endl;
	ss << getDoor().getLock() << endl;
	ss << getCargoLoad() << endl;
	ss << hasForkLift() << endl;

	return ss.str();
}