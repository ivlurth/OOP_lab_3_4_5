#pragma once

#include <string>
using namespace std;

class Door {
private:
	string lock;
public:
	explicit Door(const string&);
	string getLock();
	void setLock(const string&);
};
