#include "Automobile.h"

Automobile::Automobile(const string& _model, unsigned int _horsePower, const string& _name, const string& _owner,
					   const vector<Wheel>& _wheels, const Window& _window, const Door& _door)
		  : Vehicle{_model, _horsePower, _name, _owner},
			wheels(_wheels),
			window(_window),
			door(_door)
{
	cout << "Automobile has been created!" << endl;
}

vector<Wheel> Automobile::getWheels() {
	return wheels;
}

void Automobile::setWheels(Wheel& _wheel, size_t _wheelCount) {
	wheels.resize(_wheelCount, _wheel);
	for (auto& it : wheels) {
		it.setTyre(_wheel.getTyre());
	}
}

Window Automobile::getWindow() {
	return window;
}

void Automobile::setWindow(const Window& _window) {
	window = _window;
}

Door Automobile::getDoor() {
	return door;
}

void Automobile::setDoor(const Door& _door) {
	door = _door;
}

Automobile::~Automobile() {
	wheels.clear();
	cout << "Automobile has been destroyed!" << endl;
}