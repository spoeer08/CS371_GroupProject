#include "Passenger.h"
#include <iostream>
#include "Reservation.h"

using namespace std;

Passenger::Passenger() { //Default Constructor
	setName("Bob");
	setAddress("123 Lucky Street Green Bay, WI 54301");
	setPhone("123 - 456 - 7890");
	setEmail("bob@yahoo.com");
	setTickets(1);

}

Passenger::Passenger(string n, string a, string p, string e, int t) { //Parameterized Constructor
	setName(n);
	setAddress(a);
	setPhone(p);
	setEmail(e);
	setTickets(t);
}

void Passenger::setName(string n) {
	name = n;
}

void Passenger::setAddress(string a) {
	address = a;
}

void Passenger::setPhone(string p) {
	phone = p;
}

void Passenger::setEmail(string e) {
	email = e;
}

void Passenger::setTickets(int t) {
	tickets = t;
}

string Passenger::getName() const {
	return name;
}

string Passenger::getAddress() const {
	return address;
}

string Passenger::getPhone() const {
	return phone;
}

string Passenger::getEmail() const {
	return email;
}

int Passenger::getTickets() const {
	return tickets;
}

void Passenger::printPassInfo() {
	cout << getName() << "\t" << getAddress() << "\t" << getPhone() << "\t" << getEmail() << "\t" << getTickets() << "\n";
}

