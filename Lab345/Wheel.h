#pragma once

#include <string>
using namespace std;

class Wheel {
private:
	string tyre;
public:
	explicit Wheel(const string&);
	string getTyre();
	void setTyre(const string&);
};