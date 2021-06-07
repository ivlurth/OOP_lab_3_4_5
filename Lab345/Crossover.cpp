#include "Crossover.h"

Crossover::Crossover(bool _fullTimeAllDrive,
	size_t _passengerCount, const string& _model, unsigned int _horsePower, const string& _name, const string& _owner,
	const vector<Wheel>& _wheels, const Window& _window, const Door& _door) 
	: PassengerCar{_passengerCount, _model, _horsePower, _name, _owner, _wheels, _window, _door }, fullTimeAllDrive(_fullTimeAllDrive) { 
	cout << "Crossover has been created!" << endl;
}

bool Crossover::isFullTimeAllDrive() {
	return fullTimeAllDrive;
}

void Crossover::setFullTimeAllDrive(bool _flag) {
	fullTimeAllDrive = _flag;
}

string Crossover::drive() {
	return "I'm driving in a Crossover! Brrr...";
}

Crossover::~Crossover() { 
	cout << "Crossover has been destroyed!" << endl;
}

string Crossover::getDescription() {
	stringstream ss;

	ss << "Crossover" << endl;
	ss << getVehicleEngine()->getEngineModel() << endl;
	ss << getVehicleEngine()->getHorsePower() << endl;
	ss << getVehicleName() << endl;
	ss << getVehicleOwner() << endl;
	ss << getWheels().size() << endl;
	ss << getWheels().at(0).getTyre() << endl;
	ss << getWindow().getGlass() << endl;
	ss << getDoor().getLock() << endl;
	ss << getPassengerCount() << endl;
	ss << isFullTimeAllDrive() << endl;

	return ss.str();
}