#include "Limousine.h"

Limousine::Limousine(size_t _length,
	size_t _passengerCount, const string& _model, unsigned int _horsePower, const string& _name, const string& _owner,
	const vector<Wheel>& _wheels, const Window& _window, const Door& _door)
	: PassengerCar{ _passengerCount, _model, _horsePower, _name, _owner, _wheels, _window, _door }, length(_length) { 
	cout << "Limousine has been created!" << endl;
}

size_t Limousine::getLength() {
	return length;
}

void Limousine::setLength(size_t _length) {
	length = _length;
}

string Limousine::drive() {
	return "I'm driving in a Limousine! Vzzzhh...";
}

Limousine::~Limousine() { 
	cout << "Limousine has been destroyed!" << endl;
}

string Limousine::getDescription() {
	stringstream ss;

	ss << "Limousine" << endl;
	ss << getVehicleEngine()->getEngineModel() << endl;
	ss << getVehicleEngine()->getHorsePower() << endl;
	ss << getVehicleName() << endl;
	ss << getVehicleOwner() << endl;
	ss << getWheels().size() << endl;
	ss << getWheels().at(0).getTyre() << endl;
	ss << getWindow().getGlass() << endl;
	ss << getDoor().getLock() << endl;
	ss << getPassengerCount() << endl;
	ss << getLength() << endl;

	return ss.str();
}