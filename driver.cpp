#include <iostream>
#include "Passenger.h"
#include "Bus.h"
using namespace std;

int main() {

	string name;
	string address;
	string phone;
	string email;
	string date;
	int tickets;

	Passenger p1; //Passenger object
	Bus bus1("0001", "Green Bay", "Madison", 135.6); //Bus object
	Bus bus2("0002", "Green Bay", "Milwaukee", 118.7); //Bus object
	Bus bus3("0003", "Green Bay", "Whitewater", 142.2); //Bus object
	Bus bus4("0004", "Green Bay", "Oshkosh", 50.4); //Bus object
	Bus bus5("0005", "Green Bay", "Eau Claire", 194.4); //Bus object


	cout << "Welcome to the Reservation Menu!\n";
	cout << "Please enter the following information:\n";

	cout << "\nName: ";
	cin >> name;
	p1.setName(name);

	cout << "Address: (no spaces) ";
	cin >> address;
	p1.setAddress(address);

	cout << "Phone Number: ";
	cin >> phone;
	p1.setPhone(phone);

	cout << "Email Address: ";
	cin >> email;
	p1.setEmail(email);

	cout << "Date of Travel: ";
	cin >> date;
	p1.setDate(date);

	cout << "Number of Tickets: ";
	cin >> tickets;
	p1.setTickets(tickets);

	p1.printPassInfo();
	bus1.printBusInfo();
	bus2.printBusInfo();
	bus3.printBusInfo();
	bus4.printBusInfo();


	return 0;
}