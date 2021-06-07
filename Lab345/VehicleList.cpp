#include "VehicleList.h"

	VehicleList::VehicleList() {
		std::cout << "VehicleList has been created!" << std::endl;
	}

	VehicleList::~VehicleList() {
		std::cout << "VehicleList has been destroyed!" << std::endl;
	}

	void VehicleList::add(std::unique_ptr<Vehicle> objP) {
		inList.push_back(move(objP));
	}

	void VehicleList::clear() {
		inList.clear();
	}