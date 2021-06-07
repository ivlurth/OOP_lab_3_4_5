#include "Door.h"

Door::Door(const string& _lock) : lock(_lock) { }

string Door::getLock() { return lock; }

void Door::setLock(const string& _lock) {
	lock = _lock;
}