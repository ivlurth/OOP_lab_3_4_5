#pragma once

#include <string>
using namespace std;

class Engine {
private:
	string model;
	unsigned int horsePower;
public:
	explicit Engine(const string&, unsigned int);
	string getEngineModel();
	void setEngineModel(const string&);

	unsigned int getHorsePower();
	void setHorsePower(unsigned int);

	~Engine();
};