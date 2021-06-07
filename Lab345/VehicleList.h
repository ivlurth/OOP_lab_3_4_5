#pragma once
#include <list>
#include <memory>
#include <iostream>

#include "Vehicle.h"


class VehicleList {
private:
	std::list<std::unique_ptr<Vehicle>> inList;

public:
	VehicleList();
	void add(std::unique_ptr<Vehicle>);
	void clear();
	~VehicleList();

	auto size() const {
		return inList.size();
	}

	auto begin() const {
		return inList.begin();
	}

	auto end() const {
		return inList.end();
	}

	auto rbegin() {
		return inList.rbegin();
	}

	auto rend()  {
		return inList.rend();
	}

	auto back() {
		return &inList.back();
	}

	void remove(int ind) {
		int j = 0;
		for (auto it = inList.begin(); it != inList.end(); it++, j++) {
			if (j == ind) {
				inList.erase(it);
				break;
			}
		}
	}

	Vehicle* getPointerAt(int ind) {
		int j = 0;
		for (auto it = inList.begin(); it != inList.end(); it++, j++) {
			if (j == ind) {
				return it->get();
			}
		}
		return nullptr;
	}
};