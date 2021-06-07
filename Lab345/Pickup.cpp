#include "Pickup.h"

Pickup::Pickup(size_t _cargoLoad,
	size_t _passengerCount, const string& _model, unsigned int _horsePower, const string& _name, const string& _owner,
	const vector<Wheel>& _wheels, const Window& _window, const Door& _door)
	: PassengerCar{ _passengerCount, _model, _horsePower, _name, _owner, _wheels, _window, _door }, cargoLoad(_cargoLoad) {
	cout << "Pickup has been created!" << endl;
}

size_t Pickup::getCargoLoad() {
	return cargoLoad;
}

void Pickup::setCargoLoad(size_t _cargoLoad) {
	cargoLoad = _cargoLoad;
}

string Pickup::drive() {
	return "I'm driving in a Pickup! Pew-pew...";
};

Pickup::~Pickup() { 
	cout << "Pickup has been destroyed!" << endl;
}

string Pickup::getDescription() {
	stringstream ss;

	ss << "Pickup" << endl;
	ss << getVehicleEngine()->getEngineModel() << endl;
	ss << getVehicleEngine()->getHorsePower() << endl;
	ss << getVehicleName() << endl;
	ss << getVehicleOwner() << endl;
	ss << getWheels().size() << endl;
	ss << getWheels().at(0).getTyre() << endl;
	ss << getWindow().getGlass() << endl;
	ss << getDoor().getLock() << endl;
	ss << getPassengerCount() << endl;
	ss << getCargoLoad() << endl;

	return ss.str();
}