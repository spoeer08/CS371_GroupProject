#include <iostream>
#include "Passenger.h"
using namespace std;

int main() {

	string name;
	string address;
	string phone;
	string email;
	string date;
	int tickets;

	Passenger p1; //Passenger object

	cout << "Welcome to the Reservation Menu!\n";
	cout << "Please enter the following information:\n";

	cout << "Name: ";
	cin >> name;
	p1.setName(name);

	cout << "\nAddress: (no spaces) ";
	cin >> address;
	p1.setAddress(address);

	cout << "\nPhone Number: ";
	cin >> phone;
	p1.setPhone(phone);

	cout << "\nEmail Address: ";
	cin >> email;
	p1.setEmail(email);

	cout << "\nDate of Travel: ";
	cin >> date;
	p1.setDate(date);

	cout << "\nNumber of Tickets: ";
	cin >> tickets;
	p1.setTickets(tickets);

	p1.printInfo();



	

	

	return 0;
}