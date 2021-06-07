#include "CargoCar.h"

CargoCar::CargoCar(size_t _cargoLoad,
	const string& _model, unsigned int _horsePower, const string& _name, const string& _owner,
	const vector<Wheel>& _wheels, const Window& _window, const Door& _door) :
	Automobile{ _model, _horsePower, _name, _owner, _wheels, _window, _door }, cargoLoad(_cargoLoad)
{
	cout << "CargoCar has been created!" << endl;
}

size_t CargoCar::getCargoLoad() {
	return cargoLoad;
}

void CargoCar::setCargoLoad(size_t _cargoLoad) {
	cargoLoad = _cargoLoad;
}

CargoCar::~CargoCar() { 
	cout << "CargoCar has been destroyed!" << endl;
}