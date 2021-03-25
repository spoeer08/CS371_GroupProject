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

	//Create all bus objects (3 luxury, 4 small, 4 minivans)
	Bus lux1("01", "luxury", true, 52);
	Bus lux2("02", "luxury", true, 52); 
	Bus lux3("03", "luxury", true, 52); 
	Bus small1("04", "small", true, 36);
	Bus small2("05", "small", true, 36);
	Bus small3("06", "small", true, 36);
	Bus small4("07", "small", true, 36);
	Bus mini1("08", "mini", true, 12);
	Bus mini2("09", "mini", true, 12);
	Bus mini3("10", "mini", true, 12);
	Bus mini4("11", "mini", true, 12);
	



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
	lux1.printBusInfo();
	lux2.printBusInfo();
	lux3.printBusInfo();
	small1.printBusInfo();
	small2.printBusInfo();
	small3.printBusInfo();
	small4.printBusInfo();
	mini1.printBusInfo();
	mini2.printBusInfo();
	mini3.printBusInfo();
	mini4.printBusInfo();


	return 0;
}