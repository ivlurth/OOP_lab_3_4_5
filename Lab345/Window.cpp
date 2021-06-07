#include "Window.h"

Window::Window(const string& _glass) : glass(_glass) { }

string Window::getGlass() { return glass; }

void Window::setGlass(const string& _glass) {
	glass = _glass;
}