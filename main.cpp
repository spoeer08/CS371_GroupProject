#include <iostream>
#include <vector>
#include "Passenger.h"
#include "Bus.h"
using namespace std;


string name;
string address;
string phone;
string email;
string date;
int tickets;

vector<Passenger> curPassengers;

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

//Function blueprints
void fillVector(vector<Passenger>&);
void printVector(const vector<Passenger>&);
void mainMenu();


int main() {
	
	mainMenu();

	return 0;
}



void mainMenu() {

	int mainOption;

	cout << "FLIXBUS MAIN MENU\n";
	cout << "Please select an option below:\n";
	cout << "1. Make a Reservation\n";
	cout << "2. Schedule a Bus\n";
	cout << "3. Hire a Bus\n";
	cout << "4. View Ticket Rates\n";
	cout << "5. Perform Administrative Tasks\n";
	cin >> mainOption;

	switch (mainOption) {
	case 1:
		fillVector(curPassengers);
		printVector(curPassengers);
		break;
	case 2:
		//scheduleMenu();
		break;
	case 3:
		//hireMenu();
		break;
	case 4:
		//ticketMenu();
		break;
	case 5:
		//adminMenu();
		break;
	default:
		cout << "Invalid Option!\n";
		exit(1);
	}


}



void fillVector(vector<Passenger>& newCurPassengers) { //Dynamically create Passenger objects
	cout << "How many passengers? ";
	int numPassengers;
	cin >> numPassengers;

	for(int i=0; i < numPassengers; i++) {
		
		cout << "\nName: ";
		cin >> name;

		cout << "Address: (no spaces) ";
		cin >> address;

		cout << "Phone Number: ";
		cin >> phone;

		cout << "Email Address: ";
		cin >> email;

		cout << "Number of Tickets: ";
		cin >> tickets;

		Passenger newPassenger(name, address, phone, email, tickets);
		newCurPassengers.push_back(newPassenger);
	}
}

void printVector(const vector<Passenger>& newCurPassengers) { //Print all Passenger objects
	unsigned int size = newCurPassengers.size();

	for (unsigned int i = 0; i < size; i++) {
		cout << "\nPassenger " << i << " Name: " << newCurPassengers[i].getName() << endl;
		cout << "Passenger " << i << " Address: " << newCurPassengers[i].getAddress() << endl;
		cout << "Passenger " << i << " Phone Number: " << newCurPassengers[i].getPhone() << endl;
		cout << "Passenger " << i << " Email: " << newCurPassengers[i].getEmail() << endl;
		cout << "Passenger " << i << " Tickets: " << newCurPassengers[i].getTickets() << endl;
		cout << endl;
	}
}


