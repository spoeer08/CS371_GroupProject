#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include "Passenger.h"
#include "Bus.h"
#include "Driver.h"
#include "Reservation.h"
#include "Renter.h"
#include <fstream>
#include <iomanip>
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
string rname;
string raddress;
string rphone;
string remail;
int tickets;
int ID;
string type;
bool availability;
int intAvailability;
int totalSeats;
int winSeats;
int aisleSeats;
string location;
int intLocation;
int numPassengers;
int numRenters;


//Vectors
vector<Passenger> curPassengers;
vector<Bus> curFleet;
vector<Reservation> curReservations;
vector<Renter> curRenters;


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


//Function prototypes
void createPassengers(vector<Passenger>&);
void listPassengers(const vector<Passenger>&);
void mainMenu();
void changeRates();
void getRates();
void createBus(vector<Bus>&);
void listBus(const vector<Bus>&);
void adminMenu();
void initialMenu();
void createReservation();
void listReservations(const vector<Reservation>&);
void createRenter(vector<Renter>&);
void listRenter(const vector<Renter>&);
void hireMenu(); 
void createRenter(vector<Renter>&); 
void listRenter(const vector<Renter>&);
void calcTripCost(Reservation&);
void makeHire(Renter);
void changeReservation();
void viewIncome(const vector<Reservation>&);
void viewReservation(const vector<Reservation>&);
int checkDate(int, int, int);
void cancelReservation();



//Time objects
time_t ttime = time(0);
tm* local_time = localtime(&ttime);

int main() {

	//Add all of the original buses to the fleet vector
	curFleet.push_back(lux1);
	curFleet.push_back(lux2);
	curFleet.push_back(lux3);
	curFleet.push_back(small1);
	curFleet.push_back(small2);
	curFleet.push_back(small3);
	curFleet.push_back(small4);
	curFleet.push_back(mini1);
	curFleet.push_back(mini2);
	curFleet.push_back(mini3);
	curFleet.push_back(mini4);
	
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
		cout << "Please select an option between 1 and 3\n";
		initialMenu();
	}
}



void mainMenu() {

	int mainOption;

	cout << "FLIXBUS MAIN MENU\n";
	cout << "Please select an option below:\n";
	cout << "1. Make a Reservation\n";
	cout << "2. Hire a Bus\n";
	cout << "3. View Ticket Rates\n";
	cout << "4. Cancel a Reservation\n";
	cout << "5. Go Back\n";
	cin >> mainOption;

	switch (mainOption) {
	case 1:
		createPassengers(curPassengers);
		createReservation();
		mainMenu();
		break;
	case 2:
		createRenter(curRenters);
		hireMenu();
		mainMenu();
		break;
	case 3:
		getRates();
		mainMenu();
		break;
	case 4:
		cancelReservation();
	case 5:
		initialMenu();
	default:
		cout << "Please select an option between 1 and 4\n";
		mainMenu();
	}


}



void createPassengers(vector<Passenger>& newCurPassengers) { //Dynamically create Passenger objects
	cout << "\nCUSTOMER CREATION\n";
	cout << "How many customer profiles would you like to make? ";
	cin >> numPassengers;

	for(int i=0; i < numPassengers; i++) {
		
		cout << "\nName: ";
		cin >> name;

		cout << "Address: (no spaces) ";
		cin >> address;

		cout << "Phone Number: (XXX-XXX-XXXX) ";
		cin >> phone;

		cout << "Email Address: ";
		cin >> email;

		cout << "Number of Tickets: ";
		cin >> tickets;
		while (tickets <= 0) {
			cout << "Tickets must be greater than 0\n";
			cout << "Number of Tickets: ";
			cin >> tickets;
		}

		Passenger newPassenger(name, address, phone, email, tickets);
		newCurPassengers.push_back(newPassenger);
	}
}

void listPassengers(const vector<Passenger>& newCurPassengers) { //Print all Passenger objects
	 int size = newCurPassengers.size();

	for ( int i = 1; i < (size+1); i++) {
		cout << "\nPassenger " << i << " Name: " << newCurPassengers[i-1].getName() << endl;
		cout << "Passenger " << i << " Address: " << newCurPassengers[i-1].getAddress() << endl;
		cout << "Passenger " << i << " Phone Number: " << newCurPassengers[i-1].getPhone() << endl;
		cout << "Passenger " << i << " Email: " << newCurPassengers[i-1].getEmail() << endl;
		cout << "Passenger " << i << " Tickets: " << newCurPassengers[i-1].getTickets() << endl;
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
		while (luxASeat <= 0) {
			cout << "Seat rate must be greater than 0\n";
			cout << "\nLuxury bus aisle seat rate: $";
			cin >> luxASeat;
		}
		cout << "Luxury bus window seat rate: $";
		cin >> luxWSeat;
		while (luxWSeat <= 0) {
			cout << "Seat rate must be greater than 0\n";
			cout << "\nLuxury bus window seat rate: $";
			cin >> luxWSeat;
		}
		cout << "Luxury bus other seat rate: $";
		cin >> luxOSeat;
		while (luxOSeat <= 0) {
			cout << "Seat rate must be greater than 0\n";
			cout << "\nLuxury bus other seat rate: $";
			cin >> luxOSeat;
		}
		cout << "Luxury bus rental rate: $";
		cin >> luxFullCost;
		while (luxFullCost <= 0) {
			cout << "Rental rate must be greater than 0\n";
			cout << "\nLuxury bus rental rate: $";
			cin >> luxFullCost;
		}
		cout << "Luxury bus rental mile rate: $";
		cin >> luxMileCost;
		while (luxMileCost <= 0) {
			cout << "Mileage rate must be greater than 0\n";
			cout << "\nLuxury bus mileage rate: $";
			cin >> luxMileCost;
		}
		cout << "Luxury bus security deposit: $";
		cin >> luxDeposit;
		while (luxDeposit <= 0) {
			cout << "Security deposit must be greater than 0\n";
			cout << "\nLuxury bus security deposit: $";
			cin >> luxDeposit;
		}
		break;

	case 2:
		cout << "Small bus aisle seat rate: $";
		cin >> smallASeat;
		while (smallASeat <= 0) {
			cout << "Seat rate must be greater than 0\n";
			cout << "Small bus aisle seat rate: $";
			cin >> smallASeat;
		}
		cout << "Small bus window seat rate: $";
		cin >> smallWSeat;
		while (smallWSeat <= 0) {
			cout << "Seat rate must be greater than 0\n";
			cout << "Small bus window seat rate: $";
			cin >> smallWSeat;
		}
		cout << "Small bus rental rate: $";
		cin >> smallFullCost;
		while (smallFullCost <= 0) {
			cout << "Rental rate must be greater than 0\n";
			cout << "Small bus rental rate: $";
			cin >> smallFullCost;
		}
		cout << "Small bus rental mile rate: $";
		cin >> smallMileCost;
		while (smallMileCost <= 0) {
			cout << "Mileage rate must be greater than 0\n";
			cout << "Small bus mileage rate: $";
			cin >> smallMileCost;
		}
		cout << "Small bus security deposit: $";
		cin >> smallDeposit;
		while (smallDeposit <= 0) {
			cout << "Security deposit must be greater than 0\n";
			cout << "Small bus security deposit: $";
			cin >> smallDeposit;
		}
		break;

	case 3:
		cout << "Minivan seat rate: $";
		cin >> miniSeat;
		while (miniSeat <= 0) {
			cout << "Seat rate must be greater than 0\n";
			cout << "Minivan seat rate: $";
			cin >> miniSeat;
		}
		cout << "Minivan rental rate: $";
		cin >> miniFullCost;
		while (miniFullCost <= 0) {
			cout << "Rental rate must be greater than 0\n";
			cout << "Minivan rental rate: $";
			cin >> miniFullCost;
		}
		cout << "Minivan rental mile rate: $";
		cin >> miniMileCost;
		while (miniMileCost <= 0) {
			cout << "Minivan mileage rate: $";
			cin >> miniMileCost;
		}
		cout << "Minivan security deposit: $";
		cin >> miniDeposit;
		while (miniDeposit <= 0) {
			cout << "Security deposit must be greater than 0\n";
			cout << "Minivan security deposit: $";
			cin >> miniDeposit;
		}
		break;

	default:
		cout << "Please select an option between 1 and 3\n";
		changeRates();
	}
}

void getRates() { //Gets and prints rates
	cout << fixed << showpoint << setprecision(2);
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
	cout << "\n** Each ticket and bus hire is subject to " << (taxRate * 100) << "% tax**" << endl;

}




void adminMenu() { //Admin Menu

	int adminOption;

	cout << "\n----- Admin Menu -----";
cout << "Please select an option below:" << endl;
cout << "1. Add vehicle to fleet" << endl;
cout << "2. View reservations" << endl;
cout << "3. Edit reservations" << endl;
cout << "4. Change rates" << endl;
cout << "5. View Income" << endl;
cout << "6. Back to Initial Menu" << endl;
cin >> adminOption;

switch (adminOption) {

case 1:
	createBus(curFleet);
	listBus(curFleet);
	adminMenu();
	break;

case 2:
	viewReservation(curReservations);
	adminMenu();
	break;

case 3:
	changeReservation();
	break;

case 4:
	changeRates();
	adminMenu();
	break;
	
case 5:
	viewIncome(curReservations);
	

case 6:
	initialMenu();
	break;

default:
	cout << "Please select an option between 1 and 6\n";
	adminMenu();
}
}

void createBus(vector<Bus>& newCurFleet) { //Dynamically adds vehicles to fleet
	cout << "How many vehicles?";
	int numVehicles;
	cin >> numVehicles;

	for (int i = 0; i < numVehicles; i++) {

		cout << "\nEnter bus ID: " << endl;
		cin >> ID;
		while (ID <= 11) {
			cout << "Bus ID must be greater than 11\n";
			cout << "Enter bus ID:";
			cin >> ID;
		}
		cout << "Enter bus type: " << endl;
		cin >> type;
		while ((type != "luxury") && (type != "small") && (type != "mini")) {
			cout << "Valid bus types are luxury, small, or mini\n";
			cout << "Enter bus type: ";
			cin >> type;
		}
		cout << "Enter availability: (0=No, 1=Yes) " << endl;
		cin >> intAvailability;
		while ((intAvailability != 0) && (intAvailability != 1)) {
			cout << "Please enter either 0 or 1\n";
			cout << "Enter availability: (0=No, 1=Yes)";
			cin >> intAvailability;
			if (intAvailability == 0) {
				availability = false;
			}
			else {
				availability = true;
			}
		}
		cout << "Enter total seats: " << endl;
		cin >> totalSeats;
		while (totalSeats < 12) {
			cout << "Total seats must be greater than or equal to 12\n";
			cout << "Enter total seats: ";
			cin >> totalSeats;
		}
		cout << "Enter window seats: " << endl;
		cin >> winSeats;
		while ((winSeats <= 0) || (winSeats >= totalSeats)) {
			cout << "Window seats must be greater than 0 and less than total seats\n";
			cout << "Enter window seats: " << endl;
			cin >> winSeats;
		}
		cout << "Enter aisle seats: " << endl;
		cin >> aisleSeats;
		while ((aisleSeats <= 0) || (aisleSeats > (totalSeats - winSeats))) {
			cout << "Aisle seats must be greater than 0 and less than the difference of total-aisle seats\n";
			cout << "Enter aisle seats: " << endl;
			cin >> aisleSeats;
		}
		cout << "Enter location: " << endl;
		cout << "1. Green Bay\n";
		cout << "2. De Pere\n";
		cout << "3. Milwaukee\n";
		cout << "4. Eau Claire\n";
		cout << "5. Oshkosh\n";
		cout << "6. Whitewater\n";
		cout << "7. Madison\n";
		cin >> intLocation;
		while ((intLocation < 1) || (intLocation > 7)) {
			cout << "Please select an option between 1 and 7\n";
			cout << "Enter location: " << endl;
			cout << "1. Green Bay\n";
			cout << "2. De Pere\n";
			cout << "3. Milwaukee\n";
			cout << "4. Eau Claire\n";
			cout << "5. Oshkosh\n";
			cout << "6. Whitewater\n";
			cout << "7. Madison\n";
			cin >> intLocation;
		}
		switch (intLocation) {
		case 1:
			location = "Green Bay";
			break;
		case 2:
			location = "De Pere";
			break;
		case 3:
			location = "Milwaukee";
			break;
		case 4:
			location = "Eau Claire";
			break;
		case 5:
			location = "Oshkosh";
			break;
		case 6:
			location = "Whitewater";
			break;
		case 7:
			location = "Madison";
			break;
		}
		

			Bus newBus(ID, type, availability, totalSeats, winSeats, aisleSeats, location);
			newCurFleet.push_back(newBus);
		
		}
	}

	void listBus(const vector<Bus>&newCurFleet) { //Dynamically display vehicles in fleet
		 int size = newCurFleet.size();

		for ( int i = 1; i < (size+1); i++) {
			cout << "\nVehicle ID: " << newCurFleet[i-1].getID() << endl;
			cout << "Vehicle Type: " << newCurFleet[i-1].getType() << endl;
			cout << "Availability: " << newCurFleet[i-1].getAvailability() << endl;
			cout << "Total Seats: " << newCurFleet[i-1].getTotalSeats() << endl;
			cout << "Window Seats: " << newCurFleet[i-1].getWinSeats() << endl;
			cout << "Aisle Seats: " << newCurFleet[i-1].getAisleSeats() << endl;
			cout << "Depot Location: " << newCurFleet[i-1].getLocation() << endl;
			cout << endl;
		}
	}

	void createReservation() {
		int passOption;

		for (int i = 0; i < numPassengers; i++) {
			cout << "\nPlease select a passenger to make a reservation:\n";
			listPassengers(curPassengers);
			cin >> passOption;
			while ((passOption <= 0) || (passOption > curPassengers.size())) {
				cout << "Passenger " << passOption << " does not exist\n";
				cout << "\nPlease select a passenger to make a reservation:\n";
				cin >> passOption;
			}	
			makeReservation(curPassengers[passOption - 1]);
		}

	}

	void makeReservation(Passenger p) {
		bool validDate = false;
		int tickets = p.getTickets();

		cout << "Reservations can be made 2 weeks in advance.\n";
		cout << "Current Date/Time: " << (local_time->tm_mon + 1) << "/" << local_time->tm_mday << "/" << (local_time->tm_year + 1900) << " - " << local_time->tm_hour << ":" << local_time->tm_min << endl;

		//Date of travel
		int monthOption;
		do {
			cout << "Please enter month of departure:\n";
			cin >> monthOption;
			if (monthOption > 0 && monthOption < 13) {
				validDate = true;
			}
			else {
				cout << "MONTH OF TRAVEL MUST BE 1-12\n";
				validDate = false;
			}
		} while (validDate == false);

		int dayOption;
		do {
			cout << "Please enter day of departure:\n";
			cin >> dayOption;
			if ((monthOption == 1 || monthOption == 3 || monthOption == 5 || monthOption == 7 || monthOption == 8 || monthOption == 10 || monthOption == 12) && (dayOption > 0 && dayOption <= 31)) {
				validDate = true;
			}
			else if ((monthOption == 2) && dayOption <= 28) {
				validDate = true;
			}
			else if ((monthOption == 4 || monthOption == 6 || monthOption == 9 || monthOption == 11) && (dayOption > 0 && dayOption <= 30)) {
				validDate = true;
			}
			else {
				cout << "INVALID DAY SELECTED\n";
				validDate = false;
			}
		} while (validDate == false);

		int yearOption;
		do {
			cout << "Please enter year of departure:\n";
			cin >> yearOption;
			if (yearOption >= 2021) {
				validDate = true;
			}
			else {
				cout << "YEAR MUST BE 2021 OR GREATER\n";
				validDate = false;
			}
		} while (validDate == false);

		if (checkDate(yearOption, monthOption, dayOption) <= 14) {
			int departOption;
			do {
				cout << "Please enter depart time: (Military format)\n";
				cout << "Any time past 12pm, add difference to twelve\n";
				cout << "Example: 8pm is 8 hours past 12pm = (12+8) = 20\n";
				cin >> departOption;
				if (departOption > 0 && departOption <= 24) {
					validDate = true;
				}
				else {
					cout << "DEPART TIME MUST BE 1-24\n";
					validDate = false;
				}
			} while (validDate == false);



			//Source
			string source = "Green Bay";


			//Destination
			cout << "Please select a destination:\n";
			cout << "1. Madison\n";
			cout << "2. Milwaukee\n";
			cout << "3. Whitewater\n";
			cout << "4. Oshkosh\n";
			cout << "5. Eau Claire\n";
			int destOption;
			cin >> destOption;
			while ((destOption <= 0) || (destOption > 5)) {
				cout << "Please select an option between 1 and 5\n";
				cout << "Please select a destination from the list above: ";
				cin >> destOption;
			}

			string destination;
			switch (destOption) {
			case 1:
				destination = "Madison";
				break;
			case 2:
				destination = "Milwaukee";
				break;
			case 3:
				destination = "Whitewater";
				break;
			case 4:
				destination = "Oshkosh";
				break;
			case 5:
				destination = "Eau Claire";
				break;
			}

			//Bus Selection
			listBus(curFleet);
			cout << "Select a bus from the list above:\n";
			int busOption;
			cin >> busOption;
			while ((busOption < 1) || (busOption > curFleet.size())) {
				cout << "Bus " << busOption << " does not exist\n";
				cout << "Select a bus from the list above:\n";
				cin >> busOption;
			}

			string seatType; //Holds seatType for reservation object
			cout << "Select a seat from the list:\n";
			if (curFleet[busOption - 1].getType() == "luxury") {
				cout << "Luxury Bus seat options:\n";
				cout << "1. Luxury Aisle: $" << luxASeat << endl;
				cout << "2. Luxury Window: $" << luxWSeat << endl;
				cout << "3. Luxury Middle: $" << luxOSeat << endl;
				int seatOption;
				cin >> seatOption;
				while (seatOption < 1 || seatOption > 3) {
					cout << "Invalid seat selection\n";
					cout << "Luxury seat option:\n";
					cout << "1. Luxury Aisle: $" << luxASeat << endl;
					cout << "2. Luxury Window: $" << luxWSeat << endl;
					cout << "3. Luxury Middle: $" << luxOSeat << endl;
					cin >> seatOption;
				}
				switch (seatOption) {
				case 1:
					seatType = "luxASeat";
					curFleet[busOption - 1].setSeats((curFleet[busOption - 1].getTotalSeats() - tickets), curFleet[busOption - 1].getWinSeats(), (curFleet[busOption - 1].getAisleSeats() - tickets));
					break;
				case 2:
					seatType = "luxWSeat";
					curFleet[busOption - 1].setSeats((curFleet[busOption - 1].getTotalSeats() - tickets), (curFleet[busOption - 1].getWinSeats() - tickets), curFleet[busOption - 1].getAisleSeats());
					break;
				case 3:
					seatType = "luxOSeat";
					curFleet[busOption - 1].setSeats((curFleet[busOption - 1].getTotalSeats() - tickets), curFleet[busOption - 1].getWinSeats(), curFleet[busOption - 1].getAisleSeats());
					break;
				}
			}
			else if (curFleet[busOption - 1].getType() == "small") {
				cout << "Small Bus seat options:\n";
				cout << "1. Small Aisle: $" << smallASeat << endl;
				cout << "2. Small Window: $" << smallWSeat << endl;
				int seatOption;
				cin >> seatOption;
				while (seatOption < 1 || seatOption > 2) {
					cout << "Invalid seat selection\n";
					cout << "Small Bus seat options:\n";
					cout << "1. Small Aisle: $" << smallASeat << endl;
					cout << "2. Small Window: $" << smallWSeat << endl;
					int seatOption;
					cin >> seatOption;
				}
				switch (seatOption) {
				case 1:
					seatType = "smallASeat";
					curFleet[busOption - 1].setSeats((curFleet[busOption - 1].getTotalSeats() - tickets), curFleet[busOption - 1].getWinSeats(), (curFleet[busOption - 1].getAisleSeats() - tickets));
					break;
				case 2:
					seatType = "smallWSeat";
					curFleet[busOption - 1].setSeats((curFleet[busOption - 1].getTotalSeats() - tickets), (curFleet[busOption - 1].getWinSeats() - tickets), curFleet[busOption - 1].getAisleSeats());
					break;
				}
			}
			else {
				cout << "Minivan seat options:\n";
				cout << "1. Default seat $" << miniSeat << endl;
				int seatOption;
				cin >> seatOption;
				while (seatOption < 1 || seatOption > 1) {
					cout << "Invalid seat selection\n";
					cout << "Minivan seat options:\n";
					cout << "1. Default seat $" << miniSeat << endl;
					int seatOption;
					cin >> seatOption;
				}
				seatType = "miniSeat";
				curFleet[busOption - 1].setSeats((curFleet[busOption - 1].getTotalSeats() - tickets), (curFleet[busOption - 1].getWinSeats() - tickets), curFleet[busOption - 1].getAisleSeats());
			}

			//Create Reservation object from user input
			Reservation newReservation("Passenger", p, tickets, source, destination, curFleet[busOption - 1], seatType, monthOption, dayOption, yearOption, departOption);
			calcTripCost(newReservation);
			curReservations.push_back(newReservation);
			listReservations(curReservations);
		}
		else {
			int passOption;
			cout << "\nRESERVATION MAY ONLY BE MADE 2 WEEKS IN ADVANCE\n";
			cout << "\nPlease select a passenger to make a reservation:\n";
			listPassengers(curPassengers);
			cin >> passOption;
			while ((passOption <= 0) || (passOption > curPassengers.size())) {
				cout << "Passenger " << passOption << " does not exist\n";
				cout << "\nPlease select a passenger to make a reservation:\n";
				cin >> passOption;
			}
			makeReservation(curPassengers[passOption - 1]);
		}

	}

	void listReservations(const vector<Reservation>& newCurReservation) {
		 int size = newCurReservation.size();

		 //Testing file creation and writing
		 ofstream fileReservationOut;
		 fileReservationOut.open("Reservations.txt");

		for ( int i = 0; i < size; i++) {
			
			if (newCurReservation[i].getResType() == "Passenger") {
				fileReservationOut << "Reservation " << (i + 1) << ":\n";
				fileReservationOut << "Customer: " << newCurReservation[i].getPassenger().getName() << endl;
				fileReservationOut << "Total Passengers: " << newCurReservation[i].getTotalPassengers() << endl;
				fileReservationOut << "Source: " << newCurReservation[i].getSource() << endl;
				fileReservationOut << "Destination: " << newCurReservation[i].getDestination() << endl;
				fileReservationOut << "Bus Type: " << newCurReservation[i].getBus().getType() << endl;
				fileReservationOut << "Seat Type: " << newCurReservation[i].getSeat() << endl;
				fileReservationOut << "Day of Departure: " << newCurReservation[i].getDay() << endl;
				fileReservationOut << "Month of Departure: " << newCurReservation[i].getMonth() << endl;
				fileReservationOut << "Year of Departure: " << newCurReservation[i].getYear() << endl;
				fileReservationOut << "Time of Departure: " << newCurReservation[i].getDepartTime() << ":00" << endl;
				fileReservationOut << "Total Cost: $" << newCurReservation[i].getCost() << endl;
				fileReservationOut << endl;
				
			}
			else {
				fileReservationOut << "Reservation " << (i + 1) << ":\n";
				fileReservationOut << "Renter: " << newCurReservation[i].getRenter().getRName() << endl;
				fileReservationOut << "Source: " << newCurReservation[i].getSource() << endl;
				fileReservationOut << "Destination: " << newCurReservation[i].getDestination() << endl;
				fileReservationOut << "Bus Type: " << newCurReservation[i].getBus().getType() << endl;
				fileReservationOut << "Day of Departure: " << newCurReservation[i].getDay() << endl;
				fileReservationOut << "Month of Departure: " << newCurReservation[i].getMonth() << endl;
				fileReservationOut << "Year of Departure: " << newCurReservation[i].getYear() << endl;
				fileReservationOut << "Time of Departure: " << newCurReservation[i].getDepartTime() << ":00" << endl;
				fileReservationOut << "Total Cost: $" << newCurReservation[i].getCost() << endl;
			}
		}


		//Open the Reservations.txt file
		ifstream fileReservationIn;
		string line;
		fileReservationIn.open("Reservations.txt");
		if (fileReservationIn.is_open()) {
			while (getline(fileReservationIn, line, '\t')) {
				fileReservationIn >> line;
				cout << endl;
				cout << line << endl;
				cout << endl;
			}
			fileReservationOut.close(); // Close the file
		}
		else {
			cout << "Unable to open file";
		}

	}

	void hireMenu() {

		int renterOption;

		for (int i = 0; i < numRenters; i++) {
			cout << "\nPlease select a renter to hire a bus:\n";
			listRenter(curRenters);
			cin >> renterOption;
			while ((renterOption <= 0) || (renterOption > curRenters.size())) {
				cout << "Renter " << renterOption << " does not exist\n";
				cout << "Please select a renter from the list above";
				cin >> renterOption;
			}
			makeHire(curRenters[renterOption - 1]);
			//listReservations(curReservations type = hire)
		}
	}

	void makeHire(Renter r){
		cout << "\nBuses Available for Hire: ";

		listBus(curFleet);

		cout << "\nEnter ID of bus you would like to hire: " << endl;
		cin >> ID;
		while ((ID <= 0) || (ID > curFleet.size())) {
			cout << "Bus " << ID << " does not exist\n";
			cout << "Enter ID of bus you would like to hire: ";
			cin >> ID;
		}
		cout << "\nSelected Bus: " << endl;
		cout << "\nVehicle ID: " << curFleet[ID - 1].getID() << endl;
		cout << "Vehicle Type: " << curFleet[ID - 1].getType() << endl;
		cout << "Total Seats: " << curFleet[ID - 1].getTotalSeats() << endl;
		cout << "Window Seats: " << curFleet[ID - 1].getWinSeats() << endl;
		cout << "Aisle Seats: " << curFleet[ID - 1].getAisleSeats() << endl;
		cout << "Depot Location: " << curFleet[ID - 1].getLocation() << endl;
		Bus b = curFleet[ID - 1];
		b.setAvailability(false); //Change availability of selected bus	

		//Ask for Reservation info
		bool validDate = false;

		//Date of travel
		int monthOption;
		do {
			cout << "Please enter month of hire:\n";
			cin >> monthOption;
			if (monthOption > 0 && monthOption < 13) {
				validDate = true;
			}
			else {
				cout << "MONTH OF HIRE MUST BE 1-12\n";
				validDate = false;
			}
		} while (validDate == false);

		int dayOption;
		do {
			cout << "Please enter day of hire:\n";
			cin >> dayOption;
			if ((monthOption == 1 || monthOption == 3 || monthOption == 5 || monthOption == 7 || monthOption == 8 || monthOption == 10 || monthOption == 12) && (dayOption > 0 && dayOption <= 31)) {
				validDate = true;
			}
			else if ((monthOption == 2) && dayOption <= 28) {
				validDate = true;
			}
			else if ((monthOption == 4 || monthOption == 6 || monthOption == 9 || monthOption == 11) && (dayOption > 0 && dayOption <= 30)) {
				validDate = true;
			}
			else {
				cout << "INVALID DAY SELECTED\n";
				validDate = false;
			}
		} while (validDate == false);

		int yearOption;
		do {
			cout << "Please enter year of hire:\n";
			cin >> yearOption;
			if (yearOption >= 2021) {
				validDate = true;
			}
			else {
				cout << "YEAR MUST BE 2021 OR GREATER\n";
				validDate = false;
			}
		} while (validDate == false);

		int departOption;
		do {
			cout << "Please enter hire time: (Military format)\n";
			cout << "Any time past 12pm, add difference to twelve\n";
			cout << "Example: 8pm is 8 hours past 12pm = (12+8) = 20\n";
			cin >> departOption;
			if (departOption > 0 && departOption <= 24) {
				validDate = true;
			}
			else {
				cout << "HIRE TIME MUST BE 1-24\n";
				validDate = false;
			}
		} while (validDate == false);



		//Destination
		cout << "Please select a destination:\n";
		cout << "1. Madison\n";
		cout << "2. Milwaukee\n";
		cout << "3. Whitewater\n";
		cout << "4. Oshkosh\n";
		cout << "5. Eau Claire\n";
		int destOption;
		cin >> destOption;
		while ((destOption <= 0) || (destOption > 5)) {
			cout << "Please select an option between 1 and 5\n";
			cout << "Please select a destination from the list above: ";
			cin >> destOption;
		}

		string destination;
		switch (destOption) {
		case 1:
			destination = "Madison";
			break;
		case 2:
			destination = "Milwaukee";
			break;
		case 3:
			destination = "Whitewater";
			break;
		case 4:
			destination = "Oshkosh";
			break;
		case 5:
			destination = "Eau Claire";
			break;
		}

		Reservation newHire("Hire", r, b.getLocation(), destination, b, monthOption, dayOption, yearOption, departOption);
		calcTripCost(newHire);
		curReservations.push_back(newHire);
		listReservations(curReservations);
	}

	void createRenter(vector<Renter>& newCurRenters) {
		cout << "\nRENTER CREATION\n";
		cout << "How many renter profiles would you like to make?: ";
		cin >> numRenters;
		cout << "\nEnter Renter Information: " << endl;
		for (int i = 0; i < numRenters; i++) {
			cout << "\nName: ";
			cin >> rname;
			cout << "Address: (no spaces) ";
			cin >> raddress;
			cout << "Phone Number: ";
			cin >> rphone;
			cout << "Email: ";
			cin >> remail;

			Renter newRenter(rname, raddress, rphone, remail);
			newCurRenters.push_back(newRenter);
		}
	}

	void listRenter(const vector<Renter>& newCurRenters) {
		 int rsize = newCurRenters.size();

		for ( int i = 0; i < rsize; i++) {
			cout << "\nRenter " << i + 1 << " Name: " << newCurRenters[i].getRName() << endl;
			cout << "Renter " << i + 1 << " Address: " << newCurRenters[i].getRAddress() << endl;
			cout << "Renter " << i + 1 << " Phone Number: " << newCurRenters[i].getRPhone() << endl;
			cout << "Renter " << i + 1 << " Email: " << newCurRenters[i].getREmail() << endl;
			cout << endl;
		}
	}

	void calcTripCost(Reservation &r) {

		cout << fixed << showpoint << setprecision(2);
		double cost = 0.0;
		double distance;
		double deposit;
		double mileage;
		double rent;

		//Calculate distance depending on source and destination combo
		if (r.getSource() == "Green Bay") {
			if (r.getDestination() == "Madison") {
				distance = 135.6;
			}
			else if (r.getDestination() == "Milwaukee") {
				distance = 118.7;
			}
			else if (r.getDestination() == "Whitewater") {
				distance = 142.2;
			}
			else if (r.getDestination() == "Oshkosh") {
				distance = 50.4;
			}
			else {
				distance = 194.4;
			}
		}
		else if (r.getSource() == "Madison") {
			if (r.getDestination() == "Green Bay") {
				distance = 135.6;
			}
			else if (r.getDestination() == "Milwaukee") {
				distance = 79.6;
			}
			else if (r.getDestination() == "Whitewater") {
				distance = 45.3;
			}
			else if (r.getDestination() == "Oshkosh") {
				distance = 89.3;
			}
			else {
				distance = 178;
			}
		}
		else if (r.getSource() == "Milwaukee") {
			if (r.getDestination() == "Green Bay") {
				distance = 118.7;
			}
			else if (r.getDestination() == "Madison") {
				distance = 79.6;
			}
			else if (r.getDestination() == "Whitewater") {
				distance = 52.9;
			}
			else if (r.getDestination() == "Oshkosh") {
				distance = 87.5;
			}
			else {
				distance = 245;
			}
		}
		else if (r.getSource() == "Whitewater") {
			if (r.getDestination() == "Green Bay") {
				distance = 142.2;
			}
			else if (r.getDestination() == "Madison") {
				distance = 45.3;
			}
			else if (r.getDestination() == "Milwaukee") {
				distance = 52.9;
			}
			else if (r.getDestination() == "Oshkosh") {
				distance = 92.5;
			}
			else {
				distance = 215;
			}
		}
		else if (r.getSource() == "Oshkosh") {
			if (r.getDestination() == "Green Bay") {
				distance = 50.4;
			}
			else if (r.getDestination() == "Madison") {
				distance = 89.3;
			}
			else if (r.getDestination() == "Milwaukee") {
				distance = 87.5;
			}
			else if (r.getDestination() == "Whitewater") {
				distance = 92.5;
			}
			else {
				distance = 182;
			}
		}
		else {
			if (r.getDestination() == "Green Bay") {
				distance = 194.4;
			}
			else if (r.getDestination() == "Madison") {
				distance = 178;
			}
			else if (r.getDestination() == "Milwaukee") {
				distance = 245;
			}
			else if (r.getDestination() == "Oshkosh") {
				distance = 182;
			}
			else {
				distance = 215;
			}
		}
		

		if (r.getResType() == "Passenger") { //Passenger reservation cost

			//Calculate cost based on distance and seat type
			if (r.getSeat() == "luxASeat") {
				cost = (luxASeat * distance);
			}
			else if (r.getSeat() == "luxWSeat") {
				cost = (luxWSeat * distance);
			}
			else if (r.getSeat() == "luxOSeat") {
				cost = (luxOSeat * distance);
			}
			else if (r.getSeat() == "smallASeat") {
				cost = (smallASeat * distance);
			}
			else if (r.getSeat() == "smallWSeat") {
				cost = (smallWSeat * distance);
			}
			else if (r.getSeat() == "miniSeat") {
				cost = (miniSeat * distance);
			}

			//Add sales tax to trip cost
			cost *= r.getTotalPassengers();
			cost += (cost * taxRate);	
		}
		else { //Bus hire reservation cost
			if (r.getBus().getType() == "luxury") {
				rent = luxFullCost;
				deposit = luxDeposit;
				mileage = luxMileCost;

			}
			else if (r.getBus().getType() == "small") {
				rent = smallFullCost;
				deposit = smallDeposit;
				mileage = smallMileCost;
			}
			else {
				rent = miniFullCost;
				deposit = miniDeposit;
				mileage = miniMileCost;
			}

			cost += rent;
			cost += deposit;
			cost += (distance * mileage);
		}

		r.setCost(cost);
	}

	void changeReservation() {

		listReservations(curReservations);
		cout << "Please select a reservation to change\n";
		int resOption;
		cin >> resOption;

		cout << "Please select a property to change\n";
		cout << "1. Change Passenger Name\n";
		cout << "2. Change Depart Time\n";
		cout << "3. Change Seat Type\n";
		cout << "4. Modify Trip Cost\n";
		cout << "5. Cancel Reservation\n";
		cout << "6. Go Back\n";
		int changeOption;
		cin >> changeOption;
		
		string nameChange;
		int timeChange;
		int seatOption;
		string seatChange;
		double costChange;

		switch (changeOption) {
		case 1:
			cout << "Passenger Name: " << curReservations[resOption - 1].getPassenger().getName() << endl;
			cout << "Enter change: ";
			cin >> nameChange;
			curReservations[resOption - 1].getPassenger().setName(nameChange);
			cout << "Edited Name: " << curReservations[resOption - 1].getPassenger().getName() << endl;
			adminMenu();
			break;
		case 2:
			cout << "Depart Time: " << curReservations[resOption - 1].getDepartTime() << endl;
			cout << "Enter change: ";
			cin >> timeChange;
			curReservations[resOption - 1].setDepartTime(timeChange);
			cout << "Edited Time: " << curReservations[resOption - 1].getDepartTime() << endl;	
			break;
		case 3:
			cout << "Seat Type: " << curReservations[resOption - 1].getSeat() << endl;
			if (curReservations[resOption - 1].getBus().getType() == "luxury") {
				cout << "Enter a change option below:\n";
				cout << "1. Luxury Aisle: $" << luxASeat << endl;
				cout << "2. Luxury Window: $" << luxWSeat << endl;
				cout << "3. Luxury Middle: $" << luxOSeat << endl;
				cin >> seatOption;
				switch (seatOption) {
				case 1:
					seatChange = "luxASeat";
					break;
				case 2:
					seatChange = "luxWSeat";
					break;
				case 3:
					seatChange = "luxOSeat";
					break;
				default:
					cout << "Invalid Selection\n";
					changeReservation();
				}
			}
			else if (curReservations[resOption - 1].getBus().getType() == "small") {
				cout << "Enter a change option below:\n";
				cout << "1. Small Aisle: $" << smallASeat << endl;
				cout << "2. Small Window: $" << smallWSeat << endl;
				cin >> seatOption;
				switch (seatOption) {
				case 1:
					seatChange = "smallASeat";
					break;
				case 2:
					seatChange = "smallWSeat";
					break;
				default:
					cout << "Invalid Selection\n";
					changeReservation();
				}
			}
			else {
				cout << "Minibus seat cannot be changed\n";
				changeReservation();
			}

			curReservations[resOption - 1].setSeat(seatChange);
			calcTripCost(curReservations[resOption - 1]);
			cout << "Edited Seat: " << curReservations[resOption - 1].getSeat() << endl;
			cout << "New Cost: " << curReservations[resOption - 1].getCost() << endl;
			break;
		case 4:
			cout << "Trip Cost: " << curReservations[resOption - 1].getCost() << endl;
			cout << "Enter change: \n";
			cin >> costChange;
			while (costChange < 0) {
				cout << "Cost must be a positive number\n";
				cout << "Enter change: ";
				cin >> costChange;
			}
			curReservations[resOption - 1].setCost(costChange);
			cout << "New Cost: " << curReservations[resOption - 1].getCost() << endl;
			break;
		case 5:
			cancelReservation();
			break;
		case 6:
			adminMenu();
			break;
		default:
			cout << "Invalid Choice\n";
			changeReservation();
			
		}
	}

	void viewIncome(const vector<Reservation>& newCurReservation) {
		bool validDate = false;
		int typeChoice;
		int size = newCurReservation.size();

		cout << "\nView Income by:\n";
		cout << "1. Date\n";
		cout << "2. Vehicle\n";
		cin >> typeChoice;
		while ((typeChoice < 1) || (typeChoice > 2)) {
			cout << "Please enter either 1 or 2\n";
			cout << "1. Date\n";
			cout << "2. Vehicle\n";
			cin >> typeChoice;
		}

		switch (typeChoice) {
		case 1:
			int monthOption;
			do {
				cout << "Please enter month:\n";
				cin >> monthOption;
				if (monthOption > 0 && monthOption < 13) {
					validDate = true;
				}
				else {
					cout << "MONTH MUST BE 1-12\n";
					validDate = false;
				}
			} while (validDate == false);

			int dayOption;
			do {
				cout << "Please enter day:\n";
				cin >> dayOption;
				if ((monthOption == 1 || monthOption == 3 || monthOption == 5 || monthOption == 7 || monthOption == 8 || monthOption == 10 || monthOption == 12) && (dayOption > 0 && dayOption <= 31)) {
					validDate = true;
				}
				else if ((monthOption == 2) && dayOption <= 28) {
					validDate = true;
				}
				else if ((monthOption == 4 || monthOption == 6 || monthOption == 9 || monthOption == 11) && (dayOption > 0 && dayOption <= 30)) {
					validDate = true;
				}
				else {
					cout << "INVALID DAY SELECTED\n";
					validDate = false;
				}
			} while (validDate == false);

			int yearOption;
			do {
				cout << "Please enter year:\n";
				cin >> yearOption;
				if (yearOption >= 2021) {
					validDate = true;
				}
				else {
					cout << "YEAR MUST BE 2021 OR GREATER\n";
					validDate = false;
				}
			} while (validDate == false);

			for (int i = 0; i < size; i++) {
			
				if (newCurReservation[i].getMonth() == monthOption && newCurReservation[i].getDay() == dayOption && newCurReservation[i].getYear() == yearOption) {
					cout << "\nReservation: " << (i + 1) << endl;
					cout << "Income: " << newCurReservation[i].getCost() << endl;
				}
				else {
					cout << "\nReservation " << (i + 1) << " did not match criteria\n";
				}
			}
			break;
			
		case 2:
			int vehicleOption;
			string vehicle;

			cout << "Please select a vehicle type:\n";
			cout << "1. Luxury\n";
			cout << "2. Small\n";
			cout << "3. Minivan\n";
			cin >> vehicleOption;
			while (vehicleOption < 1 || vehicleOption > 3) {
				cout << "Please enter a number between 1 and 3\n";
				cout << "Please select a vehicle type:\n";
				cout << "1. Luxury\n";
				cout << "2. Small\n";
				cout << "3. Minivan\n";
				cin >> vehicleOption;
			}
			switch (vehicleOption) {
			case 1:
				vehicle = "luxury";
				break;
			case 2:
				vehicle = "small";
				break;
			case 3:
				vehicle = "mini";
				break;
			}

			for (int i = 0; i < size; i++) {

				if (newCurReservation[i].getBus().getType() == vehicle) {
					cout << "\nReservation: " << (i + 1) << endl;
					cout << "Income: " << newCurReservation[i].getCost() << endl;
				}
				else {
					cout << "\nReservation " << (i + 1) << " did not match criteria\n";
				}
			}

			break;

		}

		adminMenu();
	}

	void viewReservation(const vector<Reservation>& newCurReservation) {
		bool validDate = false;
		int typeChoice;
		int size = newCurReservation.size();

		cout << "\nView Reservation by:\n";
		cout << "1. Date\n";
		cout << "2. Vehicle\n";
		cin >> typeChoice;
		while ((typeChoice < 1) || (typeChoice > 2)) {
			cout << "Please enter either 1 or 2\n";
			cout << "1. Date\n";
			cout << "2. Vehicle\n";
			cin >> typeChoice;
		}

		switch (typeChoice) {
		case 1:
			int monthOption;
			do {
				cout << "Please enter month:\n";
				cin >> monthOption;
				if (monthOption > 0 && monthOption < 13) {
					validDate = true;
				}
				else {
					cout << "MONTH MUST BE 1-12\n";
					validDate = false;
				}
			} while (validDate == false);

			int dayOption;
			do {
				cout << "Please enter day:\n";
				cin >> dayOption;
				if ((monthOption == 1 || monthOption == 3 || monthOption == 5 || monthOption == 7 || monthOption == 8 || monthOption == 10 || monthOption == 12) && (dayOption > 0 && dayOption <= 31)) {
					validDate = true;
				}
				else if ((monthOption == 2) && dayOption <= 28) {
					validDate = true;
				}
				else if ((monthOption == 4 || monthOption == 6 || monthOption == 9 || monthOption == 11) && (dayOption > 0 && dayOption <= 30)) {
					validDate = true;
				}
				else {
					cout << "INVALID DAY SELECTED\n";
					validDate = false;
				}
			} while (validDate == false);

			int yearOption;
			do {
				cout << "Please enter year:\n";
				cin >> yearOption;
				if (yearOption >= 2021) {
					validDate = true;
				}
				else {
					cout << "YEAR MUST BE 2021 OR GREATER\n";
					validDate = false;
				}
			} while (validDate == false);

			for (int i = 0; i < size; i++) {

				if (newCurReservation[i].getMonth() == monthOption && newCurReservation[i].getDay() == dayOption && newCurReservation[i].getYear() == yearOption) {

					if (newCurReservation[i].getResType() == "Passenger") {
						cout << "\nReservation " << (i + 1) << ":\n";
						cout << "Customer: " << newCurReservation[i].getPassenger().getName() << endl;
						cout << "Total Passengers: " << newCurReservation[i].getTotalPassengers() << endl;
						cout << "Source: " << newCurReservation[i].getSource() << endl;
						cout << "Destination: " << newCurReservation[i].getDestination() << endl;
						cout << "Bus Type: " << newCurReservation[i].getBus().getType() << endl;
						cout << "Seat Type: " << newCurReservation[i].getSeat() << endl;
						cout << "Day of Departure: " << newCurReservation[i].getDay() << endl;
						cout << "Month of Departure: " << newCurReservation[i].getMonth() << endl;
						cout << "Year of Departure: " << newCurReservation[i].getYear() << endl;
						cout << "Time of Departure: " << newCurReservation[i].getDepartTime() << ":00" << endl;
						cout << "Total Cost: $" << newCurReservation[i].getCost() << endl;
						cout << endl;
					}
					else {
						cout << "\nReservation " << (i + 1) << ":\n";
						cout << "Renter: " << newCurReservation[i].getRenter().getRName() << endl;
						cout << "Source: " << newCurReservation[i].getSource() << endl;
						cout << "Destination: " << newCurReservation[i].getDestination() << endl;
						cout << "Bus Type: " << newCurReservation[i].getBus().getType() << endl;
						cout << "Day of Departure: " << newCurReservation[i].getDay() << endl;
						cout << "Month of Departure: " << newCurReservation[i].getMonth() << endl;
						cout << "Year of Departure: " << newCurReservation[i].getYear() << endl;
						cout << "Time of Departure: " << newCurReservation[i].getDepartTime() << ":00" << endl;
						cout << "Total Cost: $" << newCurReservation[i].getCost() << endl;
					}
				
					
				}
				else {
					cout << "\nReservation " << (i + 1) << " did not match criteria\n";
				}
			}
			break;

		case 2:
			int vehicleOption;
			string vehicle;

			cout << "Please select a vehicle type:\n";
			cout << "1. Luxury\n";
			cout << "2. Small\n";
			cout << "3. Minivan\n";
			cin >> vehicleOption;
			while (vehicleOption < 1 || vehicleOption > 3) {
				cout << "Please enter a number between 1 and 3\n";
				cout << "Please select a vehicle type:\n";
				cout << "1. Luxury\n";
				cout << "2. Small\n";
				cout << "3. Minivan\n";
				cin >> vehicleOption;
			}
			switch (vehicleOption) {
			case 1:
				vehicle = "luxury";
				break;
			case 2:
				vehicle = "small";
				break;
			case 3:
				vehicle = "mini";
				break;
			}

			for (int i = 0; i < size; i++) {

				if (newCurReservation[i].getBus().getType() == vehicle) {
					if (newCurReservation[i].getResType() == "Passenger") {
						cout << "\nReservation " << (i + 1) << ":\n";
						cout << "Customer: " << newCurReservation[i].getPassenger().getName() << endl;
						cout << "Total Passengers: " << newCurReservation[i].getTotalPassengers() << endl;
						cout << "Source: " << newCurReservation[i].getSource() << endl;
						cout << "Destination: " << newCurReservation[i].getDestination() << endl;
						cout << "Bus Type: " << newCurReservation[i].getBus().getType() << endl;
						cout << "Seat Type: " << newCurReservation[i].getSeat() << endl;
						cout << "Day of Departure: " << newCurReservation[i].getDay() << endl;
						cout << "Month of Departure: " << newCurReservation[i].getMonth() << endl;
						cout << "Year of Departure: " << newCurReservation[i].getYear() << endl;
						cout << "Time of Departure: " << newCurReservation[i].getDepartTime() << ":00" << endl;
						cout << "Total Cost: $" << newCurReservation[i].getCost() << endl;
						cout << endl;
					}
					else {
						cout << "\nReservation " << (i + 1) << ":\n";
						cout << "Renter: " << newCurReservation[i].getRenter().getRName() << endl;
						cout << "Source: " << newCurReservation[i].getSource() << endl;
						cout << "Destination: " << newCurReservation[i].getDestination() << endl;
						cout << "Bus Type: " << newCurReservation[i].getBus().getType() << endl;
						cout << "Day of Departure: " << newCurReservation[i].getDay() << endl;
						cout << "Month of Departure: " << newCurReservation[i].getMonth() << endl;
						cout << "Year of Departure: " << newCurReservation[i].getYear() << endl;
						cout << "Time of Departure: " << newCurReservation[i].getDepartTime() << ":00" << endl;
						cout << "Total Cost: $" << newCurReservation[i].getCost() << endl;
					}
				}
				else {
					cout << "\nReservation " << (i + 1) << " did not match criteria\n";
				}
			}

			break;

		}

		adminMenu();
	}

	int checkDate(int year, int month, int day) {
		double yearResDays;
		double yearCurDays;
		double dayResDays;
		double dayCurDays;
		double totalResDays;
		double totalCurDays;

		yearResDays = (year * 365);
		yearCurDays = ((local_time->tm_year + 1900) * 365);

		if (month == 1) {
			dayResDays = day;
		}
		else if (month == 2) {
			dayResDays = (31 + day);
		}
		else if (month == 3) {
			dayResDays = (31 + 28 + day);
		}
		else if (month == 4) {
			dayResDays = (31 + 28 + 31 + day);
		}
		else if (month == 5) {
			dayResDays = (31 + 28 + 31 + 30 + day);
		}
		else if (month == 6) {
			dayResDays = (31 + 28 + 31 + 30 + 31 + day);
		}
		else if (month == 7) {
			dayResDays = (31 + 28 + 31 + 30 + 31 + 30 + day);
		}
		else if (month == 8) {
			dayResDays = (31 + 28 + 31 + 30 + 31 + 30 + 31 + day);
		}
		else if (month == 9) {
			dayResDays = (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day);
		}
		else if (month == 10) {
			dayResDays = (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day);
		}
		else if (month == 11) {
			dayResDays = (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day);
		}
		else{
			dayResDays = (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day);
		}

		totalResDays = (yearResDays + dayResDays);

		if ((local_time->tm_mon + 1) == 1) {
			dayCurDays = local_time->tm_mday;
		}
		else if ((local_time->tm_mon + 1) == 2) {
			dayCurDays = (31 + local_time->tm_mday);
		}
		else if ((local_time->tm_mon + 1) == 3) {
			dayCurDays = (31 + 28 + local_time->tm_mday);
		}
		else if ((local_time->tm_mon + 1) == 4) {
			dayCurDays = (31 + 28 + 31 + local_time->tm_mday);
		}
		else if ((local_time->tm_mon + 1) == 5) {
			dayCurDays = (31 + 28 + 31 + 30 + local_time->tm_mday);
		}
		else if ((local_time->tm_mon + 1) == 6) {
			dayCurDays = (31 + 28 + 31 + 30 + 31 + local_time->tm_mday);
		}
		else if ((local_time->tm_mon + 1) == 7) {
			dayCurDays = (31 + 28 + 31 + 30 + 31 + 30 + local_time->tm_mday);
		}
		else if ((local_time->tm_mon + 1) == 8) {
			dayCurDays = (31 + 28 + 31 + 30 + 31 + 30 + 31 + local_time->tm_mday);
		}
		else if ((local_time->tm_mon + 1) == 9) {
			dayCurDays = (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + local_time->tm_mday);
		}
		else if ((local_time->tm_mon + 1) == 10) {
			dayCurDays = (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + local_time->tm_mday);
		}
		else if ((local_time->tm_mon + 1) == 11) {
			dayCurDays = (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + local_time->tm_mday);
		}
		else {
			dayCurDays = (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + local_time->tm_mday);
		}

		totalCurDays = (yearCurDays + dayCurDays);


		return (totalResDays - totalCurDays);

	}

	void cancelReservation() {
		cout << fixed << showpoint << setprecision(2);
		int passOption;

		cout << "\nPlease select a passenger to cancel a reservation:\n";
		listPassengers(curPassengers);
		cin >> passOption;
		while ((passOption <= 0) || (passOption > curPassengers.size())) {
			cout << "Passenger " << passOption << " does not exist\n";
			cout << "\nPlease select a passenger to make a reservation:\n";
			cin >> passOption;
			cout << endl;
		}

		if (checkDate(curReservations[passOption-1].getYear(), curReservations[passOption - 1].getMonth(), curReservations[passOption - 1].getDay()) == 7
			|| checkDate(curReservations[passOption - 1].getYear(), curReservations[passOption - 1].getMonth(), curReservations[passOption - 1].getDay()) == 2) { 
			cout << "Refund Amount: " << curReservations[passOption-1].getCost() << endl;
			
		}
		else if (checkDate(curReservations[passOption - 1].getYear(), curReservations[passOption - 1].getMonth(), curReservations[passOption - 1].getDay()) < 7 
			&& checkDate(curReservations[passOption - 1].getYear(), curReservations[passOption - 1].getMonth(), curReservations[passOption - 1].getDay()) > 1) { 
			cout << "30% Penalty due to cancelling less than one week in advance\n";
			cout << "Refund Amount: " << (curReservations[passOption - 1].getCost() * 0.7) << endl;
			
		}
		else {
			cout << "No refund due to cancelling one day before travel\n";
		}
		//Delete Reservation object from vector
		if (passOption == 1) {
			curReservations.erase(curReservations.begin());
		}
		else {
			curReservations.erase(curReservations.begin() + (passOption-1));
		}
	}
	