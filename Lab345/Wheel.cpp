#include "Wheel.h"

Wheel::Wheel(const string& _tyre) : tyre(_tyre) { }

string Wheel::getTyre() { return tyre; }

void Wheel::setTyre(const string& _tyre) {
	tyre = _tyre;
}