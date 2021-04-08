#include <string>
#ifndef BUS_H
#define BUS_H

using namespace std;

class Bus {

private:
	int ID;
	string type;
	bool availability;
	int totalSeats;
	int winSeats;
	int aisleSeats;
	int totalPassengers;
	double rent;
	double securityDeposit;
	double demand;
	string location;


public:
	Bus();
	Bus(int, string, bool, int, int, int, string);
	void setID(int);
	void setType(string);
	void setAvailability(bool);
	void setSeats(int, int, int);
	void setPassengers(int);
	void setDemand(double);
	void setLocation(string);
	void setRent(double);
	void setSecurityDeposit(double);
	int getID() const;
	string getType() const;
	bool getAvailability() const;
	int getTotalSeats() const;
	int getWinSeats() const;
	int getAisleSeats() const;
	int getPassengers() const;
	double getDemand() const;
	string getLocation() const;
	double getRent() const;
	double getSecurityDeposit() const;
	void printBusInfo();
};

#endif