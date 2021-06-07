#include "PassengerCar.h"

PassengerCar::PassengerCar(size_t _passengerCount,
						   const string& _model, unsigned int _horsePower, const string& _name, const string& _owner,
	const vector<Wheel>& _wheels, const Window& _window, const Door& _door) : 
	Automobile{_model, _horsePower, _name, _owner, _wheels, _window, _door}, passengerCount(_passengerCount)
{
	cout << "PassengerCar has been created!" << endl;
}

size_t PassengerCar::getPassengerCount() {
	return passengerCount;
}

void PassengerCar::setPassengerCount(size_t _passengerCount) {
	passengerCount = _passengerCount;
}

PassengerCar::~PassengerCar() { 
	cout << "PassengerCar has been destroyed!" << endl;
}