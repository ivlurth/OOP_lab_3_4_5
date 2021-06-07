#pragma once

#include "Automobile.h"

class CargoCar : public Automobile {
private:
	size_t cargoLoad;
public:
	explicit CargoCar(size_t, const string&, unsigned int, const string&, const string&,
		const vector<Wheel>&, const Window&, const Door&);
	size_t getCargoLoad();
	void setCargoLoad(size_t _cargoLoad);

	virtual ~CargoCar();
};