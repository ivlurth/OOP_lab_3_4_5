#include "LandTrain.h"

LandTrain::LandTrain(TRAILER_ARRANGEMENT _arrangementType,
	size_t _cargoLoad, const string& _model, unsigned int _horsePower, const string& _name, const string& _owner,
	const vector<Wheel>& _wheels, const Window& _window, const Door& _door)
	: CargoCar{ _cargoLoad, _model, _horsePower, _name, _owner, _wheels, _window, _door }, arrangementType(_arrangementType) { 
	cout << "LandTrain has been created!" << endl;
}

TRAILER_ARRANGEMENT LandTrain::getArrangementType() {
	return arrangementType;
}

void LandTrain::setArrangementType(TRAILER_ARRANGEMENT _arrangementType) {
	arrangementType = _arrangementType;
}

string LandTrain::drive() {
	return "I'm driving in a LandTrain! Hmmm...";
}

LandTrain::~LandTrain() { 
	cout << "LandTrain has been destroyed!" << endl;
}

string LandTrain::getDescription() {
	stringstream ss;

	ss << "LandTrain" << endl;
	ss << getVehicleEngine()->getEngineModel() << endl;
	ss << getVehicleEngine()->getHorsePower() << endl;
	ss << getVehicleName() << endl;
	ss << getVehicleOwner() << endl;
	ss << getWheels().size() << endl;
	ss << getWheels().at(0).getTyre() << endl;
	ss << getWindow().getGlass() << endl;
	ss << getDoor().getLock() << endl;
	ss << getCargoLoad() << endl;
	ss << static_cast<size_t>(getArrangementType()) << endl;

	return ss.str();
}