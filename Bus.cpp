#include "Bus.h"
#include <iostream>

using namespace std;


Bus::Bus(string id, string t, bool a, int s) {
	setID(id);
	setType(t);
	setAvailability(a);
	setSeats(s);
}

void Bus::setID(string id) {
	ID = id;
}

void Bus::setType(string t) {
	type = t;
}

void Bus::setAvailability(bool a) {
	availability = a;
}

void Bus::setSeats(int s) {
	seats = s;
}

string Bus::getID() const {
	return ID;
}

string Bus::getType() const {
	return type;
}

bool Bus::getAvailability() const {
	return availability;
}

int Bus::getSeats() const {
	return seats;
}


void Bus::printBusInfo() {
	cout << getID() << "\t" << getType() << "\t" << getAvailability() << "\t" << getSeats() << endl;
}