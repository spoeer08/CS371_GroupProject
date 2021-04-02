#include "Bus.h"
#include <iostream>

using namespace std;


Bus::Bus(int id, string t, bool a, int ts, int ws, int as, string l) {
	setID(id);
	setType(t);
	setAvailability(a);
	setSeats(ts, ws, as);
	setLocation(l);
}

void Bus::setID(int id) {
	ID = id;
}

void Bus::setType(string t) {
	type = t;
}

void Bus::setAvailability(bool a) {
	availability = a;
}

void Bus::setSeats(int ts, int ws, int as) {
	totalSeats = ts;
	winSeats = ws;
	aisleSeats = as;
}

void Bus::setLocation(string l) {
	location = l;
}

void Bus::setRent(double r) {
	rent = r;
}

void Bus::setSecurityDeposit(double s) {
	securityDeposit = s;
}

int Bus::getID() const {
	return ID;
}

string Bus::getType() const {
	return type;
}

bool Bus::getAvailability() const {
	return availability;
}

int Bus::getTotalSeats() const {
	return totalSeats;
}

int Bus::getWinSeats() const {
	return winSeats;
}

int Bus::getAisleSeats() const {
	return aisleSeats;
}

string Bus::getLocation() const {
	return location;
}

double Bus::getRent() const {
	return rent;
}

double Bus::getSecurityDeposit() const {
	return securityDeposit;
}


void Bus::printBusInfo() {
	cout << getID() << "\t" << getType() << "\t" << getAvailability() << "\t" << getTotalSeats() << "\t" << getWinSeats() << "\t" << getAisleSeats()  << endl;
}