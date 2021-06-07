#pragma once

#include "CargoCar.h"
#include <sstream>

enum class TRAILER_ARRANGEMENT {
	A_DOUBLE,
	B_DOUBLE,
	B_TRIPLE,
	AB_TRIPLE,
	A_TRIPLE,
	BAB_QUAD,
	C_TRAIN,
	DOG_TRAILER
};

class LandTrain : public CargoCar {
private:
	TRAILER_ARRANGEMENT arrangementType;
public:
	explicit LandTrain(TRAILER_ARRANGEMENT, size_t, const string&, unsigned int, const string&, const string&,
		const vector<Wheel>&, const Window&, const Door&);

	TRAILER_ARRANGEMENT getArrangementType();
	void setArrangementType(TRAILER_ARRANGEMENT);

	virtual string drive() override;
	virtual ~LandTrain();
	virtual string getDescription() override;
};
