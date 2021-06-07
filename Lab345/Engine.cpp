#include "Engine.h"

Engine::Engine(const string& _model, unsigned int _horsePower) : model(_model), horsePower(_horsePower) { }

string Engine::getEngineModel() {
	return model;
}

void Engine::setEngineModel(const string& _model) {
	model = _model;
}

unsigned int Engine::getHorsePower() {
	return horsePower;
}

void Engine::setHorsePower(unsigned int _horsePower) {
	horsePower = _horsePower;
}

Engine::~Engine() { }