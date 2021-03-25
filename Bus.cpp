#include "Bus.h"
#include <iostream>

using namespace std;

Bus::Bus(string id, string s, string d, double dist) {
	setID(id);
	setSource(s);
	setDestination(d);
	setDistance(dist);
}

void Bus::setID(string id) {
	ID = id;
}

void Bus::setSource(string s) {
	source = s;
}

void Bus::setDestination(string d) {
	destination = d;
}

void Bus::setDistance(double dist) {
	distance = dist;
}

string Bus::getID() const {
	return ID;
}

string Bus::getSource()const {
	return source;
}

string Bus::getDestination() const {
	return destination;
}

double Bus::getDistance() const {
	return distance;
}

void Bus::printBusInfo() {
	cout << getID() << "\t" << getSource() << "\t" << getDestination() << "\t" << getDistance() << endl;
}