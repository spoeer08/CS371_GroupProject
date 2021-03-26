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
string ID;
string type;
bool availability;
int seats;

vector<Passenger> curPassengers;
vector<Fleet> curFleet;

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
void fillBus(vector<Fleet>&);
void printBus(const vector<Fleet>&);
void fillRates();
void getRates();
void adminMenu();
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
		getRates();
		break;
	case 5:
		adminMenu();
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

void fillRates(){ //Creates rates
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
	
	cout << "\nSelect which rate to change:" << endl;
	cout << "1. Luxury Bus Rates" << endl;
	cout << "2. Small Bus Rates" << endl;
	cout << "3. Minivan Rates" << endl;
	cin >> rateOption;
	
	switch (rateOption)
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
		cin>> smallWSeat;
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

void getRates(){ //Gets and prints rates
	cout << "\n------- Single Seat Rentals -------" << endl;
	cout << "\n----- Luxury Bus -----" << endl;
	cout << "Luxury bus aisle seat cost: $" << luxASeat << " per mile << endl;
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

void adminMenu(){ //Admin Menu
	
	int adminOption;
	
	cout << "\n----- Admin Menu -----";
	cout << "Please select an option below:" << endl;
	cout << "1. Add vehicle to fleet" << endl;
	cout << "2. View reservations" << endl;
	cout << "3. Edit reservations" << endl;
	cout << "4. Change rates" << endl;
	cout << "5. View income" << endl;
	cin >> adminOption;
	
switch (adminOption){
	
	case 1:
		fillBus();
		break;
	
	case 2:
		//viewReservation()
		break;

	case 3:
		//changeReservation()
		break;
		
	case 4:
		fillRates();
		break;

	case 5:
		//viewIncome()
		break;

	default:
		cout << "Invalid Option!\n";
		exit(1);
	}
	
void fillBus(vector<Fleet>& newCurFleet){ //Dynamically adds vehicles to fleet
	cout << "How many vehicles?";
	int numVehicles;
	cin >> numVehicles;

	for (int i=0, i < numVehicles; i++) {

		cout << "\nEnter bus id: " << endl;
		cin >> ID;
		cout << "Enter bus type: " << endl;
		cin >> type;
		cout << "Enter availability: " << endl;
		cin >> availabilty;
		cout << "Enter seats: " << endl;
		cin >> seats;
		
		Bus newBus(ID, type, availability, seats);
		newCurFleet.push_back(newBus);
		}	
	}

void printBus(const vector<Fleet>& newCurFleet)	{ //Dynamically display vehicles in fleet
	unsigned int size = newCurFleet.size();

	for (unsigned int i = 0, i < size; i++) {
		cout << "\nVehicle " << i << " ID: " << newCurFleet[i].getID() << endl;
		cout << "Vehicle " << i << " type: " << newCurFleet[i].getType() << endl;
		cout << "Vehicle " << i << " is available?: " << newCurFleet[i].getAvailability() << endl;
		cout << "Vehicle " << i << " seats: " << newCurFleet[i].getSeats() << endl;
		cout << endl;
		}
	}
}
