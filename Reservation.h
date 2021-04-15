#include "Bus.h"
#include "Passenger.h"
#ifndef RESERVATION_H
#define RESERVATION_H

using namespace std;

class Reservation {

private:
	int totalPassengers;
	double cost;
	string source;
	string destination;
	double distance;
	Passenger passenger;
	Bus bus;
	int day;
	int month;
	int year;
	int departTime;
	int arrivalTime;
	string seatType;
	string resType;

public:
	Reservation(string, string, string, Bus, int, int, int, int);
	Reservation(string, Passenger, int, string, string, Bus, string, int, int, int, int);
	void setResType(string);
	void setPassenger(Passenger);
	void setTotalPassengers(int);
	void setCost(double);
	void setSource(string);
	void setDestination(string);
	void setDistance(double);
	void setBus(Bus);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDepartTime(int);
	void setSeat(string);
	string getResType() const;
	Passenger getPassenger() const;
	string getSource() const;
	string getDestination() const;
	double getDistance() const;
	int getTotalPassengers() const;
	double getCost() const;
	Bus getBus() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	int getDepartTime() const;
	string getSeat() const;

};

#endif

