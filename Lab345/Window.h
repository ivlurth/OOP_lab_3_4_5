#pragma once

#include <string>
using namespace std;

class Window {
private:
	string glass;
public:
	explicit Window(const string&);
	string getGlass();
	void setGlass(const string&);
};