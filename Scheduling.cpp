#include "Scheduling.h"

using namespace std;


Scheduling::Scheduling() {
	setOrigin(1);
	setDestination(1);
	setBusType(1);

}

Scheduling::Scheduling(int o, int d, int b) {
	setOrigin(o);
	setDestination(d);
}

void Scheduling::setOrigin(int o) {
	origin = o;
}

void Scheduling::setDestination(int d) {
	destination = d;
}

void Scheduling::setBusType(int b) {
	bustype = b;

}
int Scheduling::getOrigin()const {
	return origin;
}

int Scheduling::getDestination() const {
	return destination;
}

int Scheduling::getBusType() const {
	return bustype;
}