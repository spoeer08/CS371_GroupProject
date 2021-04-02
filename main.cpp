#include <iostream>
#include <vector>
#include "Passenger.h"
#include "Bus.h"
#include "Driver.h"
#include "Route.h"
using namespace std;




//Global variables
double luxASeat = 0.95;
double luxWSeat = 0.95;
double luxOSeat = 0.75;
double smallASeat = 0.65;
double smallWSeat = 0.65;
double miniSeat = 0.50;
int luxFullCost = 1500;
double luxMileCost = 0.25;
int luxDeposit = 5000;
int smallFullCost = 1300;
double smallMileCost = 0.20;
int smallDeposit = 3000;
int miniFullCost = 1000;
double miniMileCost = 0.15;
int miniDeposit = 1500;
int rateOption;
double taxRate = 0.10;
string name;
string address;
string phone;
string email;
string date;
int tickets;
int ID;
string type;
bool availability;
int totalSeats;
int winSeats;
int aisleSeats;
string location;

//Vectors
vector<Passenger> curPassengers;
vector<Bus> curFleet;


//Create all bus objects (3 luxury, 4 small, 4 minivans)
Bus lux1(1, "luxury", true, 52, 21, 21, "Green Bay");
Bus lux2(2, "luxury", true, 52, 21, 21, "De Pere");
Bus lux3(3, "luxury", true, 52, 21, 21, "Milwaukee");
Bus small1(4, "small", true, 36, 24, 12, "Green Bay");
Bus small2(5, "small", true, 36, 24, 12, "Eau Claire");
Bus small3(6, "small", true, 36, 24, 12, "Oshkosh");
Bus small4(7, "small", true, 36, 24, 12, "Whitewater");
Bus mini1(8, "mini", true, 12, 8, 0, "Milwaukee");
Bus mini2(9, "mini", true, 12, 8, 0, "Green Bay");
Bus mini3(10, "mini", true, 12, 8, 0, "Madison");
Bus mini4(11, "mini", true, 12, 8, 0, "Madison");

//Function blueprints
void createPassengers(vector<Passenger>&);
void listPassengers(const vector<Passenger>&);
void mainMenu();
void changeRates();
void getRates();
void createBus(vector<Bus>&);
void listBus(const vector<Bus>&);
void adminMenu();
void initialMenu();



int main() {

	initialMenu();

	return 0;
}

void initialMenu() {
	int initialOption;

	cout << "FLIXBUX System Menu\n";
	cout << "Please select an option below:\n";
	cout << "1. Main Menu\n";
	cout << "2. Admin Menu\n";
	cout << "3. Exit Program\n";
	cin >> initialOption;

	switch (initialOption) {
	case 1:
		mainMenu();
		break;
	case 2:
		adminMenu();
		break;
	case 3:
		exit(0);
	default:
		exit(1);
	}
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
		createPassengers(curPassengers);
		listPassengers(curPassengers);
		break;
	case 2:
		//scheduleMenu();
		break;
	case 3:
		//hireMenu();
		break;
	case 4:
		getRates();
		break;
	case 5:
		//adminMenu();
		break;
	default:
		cout << "Invalid Option!\n";
		exit(1);
	}


}



void createPassengers(vector<Passenger>& newCurPassengers) { //Dynamically create Passenger objects
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

void listPassengers(const vector<Passenger>& newCurPassengers) { //Print all Passenger objects
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

void changeRates() { //Creates rates

	cout << "\nSelect which rate to change:" << endl;
	cout << "1. Luxury Bus Rates" << endl;
	cout << "2. Small Bus Rates" << endl;
	cout << "3. Minivan Rates" << endl;
	cin >> rateOption;

	switch (rateOption){
	case 1:
		cout << "\nLuxury bus aisle seat rate: $";
		cin >> luxASeat;
		cout << "Luxury bus window seat rate: $";
		cin >> luxWSeat;
		cout << "Luxury bus other seat rate: $";
		cin >> luxOSeat;
		cout << "Luxury bus rental rate: $";
		cin >> luxFullCost;
		cout << "Luxury bus rental mile rate: $";
		cin >> luxMileCost;
		cout << "Luxury bus security deposit: $";
		cin >> luxDeposit;
		break;

	case 2:
		cout << "Small bus aisle seat rate: $";
		cin >> smallASeat;
		cout << "Small bus window seat rate: $";
		cin >> smallWSeat;
		cout << "Small bus rental rate: $";
		cin >> smallFullCost;
		cout << "Small bus rental mile rate: $";
		cin >> smallMileCost;
		cout << "Small bus security deposit: $";
		cin >> smallDeposit;
		break;

	case 3:
		cout << "Minivan seat rate: $";
		cin >> miniSeat;
		cout << "Minivan rental rate: $";
		cin >> miniFullCost;
		cout << "Minivan rental mile rate: $";
		cin >> miniMileCost;
		cout << "Minivan security deposit: $";
		cin >> miniDeposit;
		break;

	default:
		cout << "Invalid Option!\n";
		exit(1);
	}
}

void getRates() { //Gets and prints rates
	cout << "\n------- Single Seat Rentals -------" << endl;
	cout << "\n----- Luxury Bus -----" << endl;
	cout << "Luxury bus aisle seat cost: $" << luxASeat << " per mile" << endl;
	cout << "Luxury bus window seat cost: $" << luxWSeat << " per mile" << endl;
	cout << "Luxury bus middle seat cost: $" << luxOSeat << " per mile" << endl;
	cout << "----- Small Bus -----" << endl;
	cout << "Small Bus aisle seat cost: $" << smallASeat << " per mile" << endl;
	cout << "Small Bus window seat cost: $" << smallWSeat << " per mile" << endl;
	cout << "----- Minivan -----" << endl;
	cout << "Minivan seat cost: $" << miniSeat << " per mile" << endl;
	cout << "\n------- Full Vehicle Rentals -------" << endl;
	cout << "\n----- Luxury Bus -----" << endl;
	cout << "Luxury bus costs $" << luxFullCost << " with additional $" << luxMileCost << " per mile" << endl;
	cout << "Luxury bus security deposit is $" << luxDeposit << endl;
	cout << "----- Small Bus -----" << endl;
	cout << "Small bus costs $" << smallFullCost << " with additional $" << smallMileCost << " per mile" << endl;
	cout << "Small bus security deposit is $" << smallDeposit << endl;
	cout << "----- Minivan -----" << endl;
	cout << "Minivan costs $" << miniFullCost << " with additional $" << miniMileCost << " per mile" << endl;
	cout << "Minivan security deposit is $" << miniDeposit << endl;
	cout << "\n** Each ticket and bus hire is subject to " << taxRate << "% tax**" << endl;

}




void adminMenu() { //Admin Menu

	int adminOption;

	cout << "\n----- Admin Menu -----";
	cout << "Please select an option below:" << endl;
	cout << "1. Add vehicle to fleet" << endl;
	cout << "2. View reservations" << endl;
	cout << "3. Edit reservations" << endl;
	cout << "4. Change rates" << endl;
	cout << "5. View income" << endl;
	cin >> adminOption;

	switch (adminOption) {

	case 1:
		createBus(curFleet);
		listBus(curFleet);
		break;

	case 2:
		//viewReservation()
		break;

	case 3:
		//changeReservation()
		break;

	case 4:
		changeRates();
		break;

	case 5:
		//viewIncome()
		break;

	default:
		cout << "Invalid Option!\n";
		exit(1);
	}
}

	void createBus(vector<Bus>&newCurFleet) { //Dynamically adds vehicles to fleet
		cout << "How many vehicles?";
		int numVehicles;
		cin >> numVehicles;

		for (int i = 0; i < numVehicles; i++) {

			cout << "\nEnter bus id: " << endl;
			cin >> ID;
			cout << "Enter bus type: " << endl;
			cin >> type;
			cout << "Enter availability: (0=No, 1=yes) " << endl;
			cin >> availability;
			cout << "Enter total seats: " << endl;
			cin >> totalSeats;
			cout << "Enter window seats: " << endl;
			cin >> winSeats;
			cout << "Enter aisle seats: " << endl;
			cin >> aisleSeats;
			cout << "Enter location: " << endl;
			cin >> location;

			Bus newBus(ID, type, availability, totalSeats, winSeats, aisleSeats, location);
			newCurFleet.push_back(newBus);
		
		}
	}

	void listBus(const vector<Bus>&newCurFleet) { //Dynamically display vehicles in fleet
		unsigned int size = newCurFleet.size();

		for (unsigned int i = 0; i < size; i++) {
			cout << "\nVehicle " << i << " ID: " << newCurFleet[i].getID() << endl;
			cout << "Vehicle " << i << " type: " << newCurFleet[i].getType() << endl;
			cout << "Vehicle " << i << " is available?: " << newCurFleet[i].getAvailability() << endl;
			cout << "Vehicle " << i << " total seats: " << newCurFleet[i].getTotalSeats() << endl;
			cout << "Vehicle " << i << " window seats: " << newCurFleet[i].getWinSeats() << endl;
			cout << "Vehicle " << i << " aisle seats: " << newCurFleet[i].getAisleSeats() << endl;
			cout << "Vehicle " << i << " location: " << newCurFleet[i].getLocation() << endl;
			cout << endl;
		}
	}

	/*void makeReservation(Passenger p) {
		cout << "Please enter date of travel: ";
		cin >> dateChoice << endl;
		cout << "Please select a bus type: (1=luxury, 2=small, 3=minivan) ";
		cin >> busChoice << endl;
		cout << "Please select a route: ";
		cin >> routeChoice << endl;
	}
	*/


