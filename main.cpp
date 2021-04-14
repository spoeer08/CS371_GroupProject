#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Passenger.h"
#include "Bus.h"
#include "Driver.h"
#include "Reservation.h"
#include "Renter.h"
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
int totalSeats;
int winSeats;
int aisleSeats;
string location;
int numPassengers;

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

//Statically add buses to vector NEED TO FINISH


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
void hireMenu(const vector<Bus>&); 
void createRenter(vector<Renter>&); 
void listRenter(const vector<Renter>&);
void calcTripCost(Reservation&);





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
		createReservation();
		break;
	case 2:
		//scheduleMenu();
		break;
	case 3:
		hireMenu(curFleet);
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

	for (unsigned int i = 1; i < (size+1); i++) {
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
	cout << "6. Back to Main Menu" << endl;
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
	case 6:
		mainMenu();
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

		for (unsigned int i = 1; i < (size+1); i++) {
			cout << "\nVehicle " << i << " ID: " << newCurFleet[i-1].getID() << endl;
			cout << "Vehicle " << i << " type: " << newCurFleet[i-1].getType() << endl;
			cout << "Vehicle " << i << " is available?: " << newCurFleet[i-1].getAvailability() << endl;
			cout << "Vehicle " << i << " total seats: " << newCurFleet[i-1].getTotalSeats() << endl;
			cout << "Vehicle " << i << " window seats: " << newCurFleet[i-1].getWinSeats() << endl;
			cout << "Vehicle " << i << " aisle seats: " << newCurFleet[i-1].getAisleSeats() << endl;
			cout << "Vehicle " << i << " location: " << newCurFleet[i-1].getLocation() << endl;
			cout << endl;
		}
	}

	void createReservation() {
		int passOption;

		for (int i = 0; i < numPassengers; i++) {
			cout << "Please select a passenger:\n";
			listPassengers(curPassengers);
			cin >> passOption;
			makeReservation(curPassengers[passOption - 1]);
			listReservations(curReservations);
		}


	}

	void makeReservation(Passenger p) {
		bool validDate = false;

		cout << "Please select a source: \n";
		cout << "1. Green Bay\n";
		cout << "2. Madison\n";
		cout << "3. Milwaukee\n";
		cout << "4. Whitewater\n";
		cout << "5. Oshkosh\n";
		cout << "6. Eau Claire\n";
		int sourceOption;
		cin >> sourceOption;

		string source;
		switch (sourceOption) {
		case 1:
			source = "Green Bay";
			break;
		case 2: 
			source = "Madison";
			break;
		case 3:
			source = "Milwaukee";
			break;
		case 4: 
			source = "Whitewater";
			break;
		case 5:
			source = "Oshkosh";
			break;
		case 6:
			source = "Eau Claire";
			break;
		default:
			cout << "Invalid choice";
		}

		cout << "Please select a destination:\n";
		cout << "1. Green Bay\n";
		cout << "2. Madison\n";
		cout << "3. Milwaukee\n";
		cout << "4. Whitewater\n";
		cout << "5. Oshkosh\n";
		cout << "6. Eau Claire\n";
		int destOption;
		cin >> destOption;
		while (sourceOption == destOption) {
			cout << "Source and destination must be different\n";
			cout << "Please select a destination:\n";
			cout << "1. Green Bay\n";
			cout << "2. Madison\n";
			cout << "3. Milwaukee\n";
			cout << "4. Whitewater\n";
			cout << "5. Oshkosh\n";
			cout << "6. Eau Claire\n";
			cin >> destOption;

		}

		string destination;
		switch (destOption) {
		case 1:
			destination = "Green Bay";
			break;
		case 2:
			destination = "Madison";
			break;
		case 3:
			destination = "Milwaukee";
			break;
		case 4:
			destination = "Whitewater";
			break;
		case 5:
			destination = "Oshkosh";
			break;
		case 6:
			destination = "Eau Claire";
			break;
		default:
			cout << "Invalid choice";
		}

		cout << "Select a bus from the list:\n";
		listBus(curFleet);
		int busOption;
		cin >> busOption;
		Bus b = curFleet[busOption-1];

		string seatType; //Holds seatType for reservation object
		cout << "Select a seat from the list:\n";
		if (b.getType() == "luxury") {
			cout << "Luxury Bus seat options:\n";
			cout << "1. Luxury Aisle: $ " << luxASeat << endl;
			cout << "2. Luxury Window: $ " << luxWSeat << endl;
			cout << "3. Luxury Middle: $ " << luxOSeat << endl;
			int seatOption;
			cin >> seatOption;
			while (seatOption < 1 || seatOption > 3) {
				cout << "Invalid seat selection\n";
				cout << "Luxury seat option:\n";
				cout << "1. Luxury Aisle: $ " << luxASeat << endl;
				cout << "2. Luxury Window: $ " << luxWSeat << endl;
				cout << "3. Luxury Middle: $ " << luxOSeat << endl;
				int seatOption;
				cin >> seatOption;
			}
			switch (seatOption) {
			case 1:
				seatType = "luxASeat";
				break;
			case 2:
				seatType = "luxWSeat";
				break;
			case 3:
				seatType = "luxOSeat";
				break;
			}
		}
		else if (b.getType() == "small") {
			cout << "Small Bus seat options:\n";
			cout << "1. Small Aisle: $ " << smallASeat << endl;
			cout << "2. Small Window: $ " << smallWSeat << endl;
			int seatOption;
			cin >> seatOption;
			while (seatOption < 1 || seatOption > 2) {
				cout << "Invalid seat selection\n";
				cout << "Small Bus seat options:\n";
				cout << "1. Small Aisle: $ " << smallASeat << endl;
				cout << "2. Small Window: $ " << smallWSeat << endl;
				int seatOption;
				cin >> seatOption;
			}
			switch (seatOption) {
			case 1:
				seatType = "smallASeat";
				break;
			case 2:
				seatType = "smallWSeat";
				break;
			}
		}
		else {
			cout << "Minivan seat options:\n";
			cout << "1. Default seat $ " << miniSeat << endl;
			int seatOption;
			cin >> seatOption;
			while (seatOption < 1 || seatOption > 1) {
				cout << "Invalid seat selection\n";
				cout << "Minivan seat options:\n";
				cout << "1. Default seat $ " << miniSeat << endl;
				int seatOption;
				cin >> seatOption;
			}
			seatType = "miniSeat";
		}

		int monthOption;
		do {
			cout << "Please enter month of departure:\n";
			cin >> monthOption;
			if (monthOption > 0 && monthOption < 13) {
				validDate = true;
			}
			else {
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
			else if ((monthOption == 4 || monthOption == 6 || monthOption == 9 || monthOption == 11) && (dayOption > 0 && dayOption <= 30)) {
					validDate = true;
			}
			else {
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
				validDate = false;
			}
		} while (validDate == false);

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
				validDate = false;
			}
		} while (validDate == false);


		Reservation newReservation(numPassengers, source, destination, b, seatType, monthOption, dayOption, yearOption, departOption);
		calcTripCost(newReservation);
		curReservations.push_back(newReservation);

	}

	void listReservations(const vector<Reservation>& newCurReservation) {
		unsigned int size = newCurReservation.size();

		for (unsigned int i = 0; i < size; i++) {
			cout << "\nRESERVATION DETAILS:\n";
			cout << "\nReservation " << (i+1) << ":\n";
			cout << "Total Passengers: " << newCurReservation[i].getTotalPassengers() << endl;
			cout << "Source: " << newCurReservation[i].getSource() << endl;
			cout << "Destination: " << newCurReservation[i].getDestination() << endl;
			cout << "Bus Type: " << newCurReservation[i].getBus().getType() << endl;
			cout << "Seat Type: " << newCurReservation[i].getSeat() << endl;
			cout << "Day of Departure: " << newCurReservation[i].getDay() << endl;
			cout << "Month of Departure: " << newCurReservation[i].getMonth() << endl;
			cout << "Year of Departure: " << newCurReservation[i].getYear() << endl;
			cout << "Time of Departure: " << newCurReservation[i].getDepartTime() << endl;
			cout << "Total Cost: $" << newCurReservation[i].getCost() << endl;
			cout << endl;
		}
	}

	void hireMenu(const vector<Bus>& newCurFleet) {
		unsigned int size = newCurFleet.size();
		cout << "\nBuses for Hire: ";

			for (int i = 0; i < size; i++) {
				if (newCurFleet[i].getAvailability() == true) {
					cout << "\nVehicle " << i << " ID: " << newCurFleet[i].getID() << endl;
					cout << "Vehicle " << i << " type: " << newCurFleet[i].getType() << endl;
					cout << "Vehicle " << i << " is available?: " << newCurFleet[i].getAvailability() << endl;
					cout << "Vehicle " << i << " total seats: " << newCurFleet[i].getTotalSeats() << endl;
					cout << "Vehicle " << i << " window seats: " << newCurFleet[i].getWinSeats() << endl;
					cout << "Vehicle " << i << " aisle seats: " << newCurFleet[i].getAisleSeats() << endl;
					cout << "Vehicle " << i << " location: " << newCurFleet[i].getLocation() << endl;
				}
				else {
					cout << "\nVehicle " << i << " ID: " << newCurFleet[i].getID() << " is currently unavailable for hire" << endl;
				}
			}

		cout << "\nEnter bus you would like to hire: " << endl;
		cin >> ID;
		cout << "Selected Bus: " << endl;
		cout << "\nVehicle " << ID << " ID: " << newCurFleet[ID - 1].getID() << endl;
		cout << "Vehicle " << ID << " type: " << newCurFleet[ID - 1].getType() << endl;
		cout << "Vehicle " << ID << " is available?: " << newCurFleet[ID - 1].getAvailability() << endl;
		cout << "Vehicle " << ID << " total seats: " << newCurFleet[ID - 1].getTotalSeats() << endl;
		cout << "Vehicle " << ID << " location: " << newCurFleet[ID - 1].getLocation() << endl;
		cout << "Enter Renter Information: " << endl;
		createRenter(curRenters);
	}

	void createRenter(vector<Renter>& newCurRenters) {
		cout << "How many renters?: ";
		int numRenters;
		cin >> numRenters;

		for (int i = 0; i < numRenters; i++) {
			cout << "\nName: " << endl;
			cin >> rname;
			cout << "Address: (no spaces) " << endl;
			cin >> raddress;
			cout << "Phone Number: " << endl;
			cin >> rphone;
			cout << "Email: " << endl;
			cin >> remail;

			Renter newRenter(rname, raddress, rphone, remail);
			newCurRenters.push_back(newRenter);
		}
	}

	void listRenter(const vector<Renter>& newCurRenters) {
		unsigned int rsize = newCurRenters.size();

		for (unsigned int i = 0; i < rsize; i++) {
			cout << "\nRenter " << i + 1 << " Name: " << newCurRenters[i].getRName() << endl;
			cout << "Renter " << i + 1 << " Address: " << newCurRenters[i].getRAddress() << endl;
			cout << "Renter " << i + 1 << " Phone Number: " << newCurRenters[i].getRPhone() << endl;
			cout << "Renter " << i + 1 << " Email: " << newCurRenters[i].getREmail() << endl;
			cout << endl;
		}
	}

	void calcTripCost(Reservation &r) {
		double cost;
		double distance;

		//Calculate distance depending on source and destination combo
		if (r.getSource() == "Green Bay" && r.getDestination() == "Madison") {
			distance = 135.6;
		}
		else if (r.getSource() == "Green Bay" && r.getDestination() == "Milwaukee") {
			distance = 118.7;
		}
		else if (r.getSource() == "Green Bay" && r.getDestination() == "Whitewater") {
			distance = 142.2;
		}
		else if (r.getSource() == "Green Bay" && r.getDestination() == "Oshkosh") {
			distance = 50.4;
		}
		else {
			distance = 194.4;
		}

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
		cost += (cost * taxRate);

		r.setCost(cost);
	}


