#include "Bus.h"
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
	Bus bus;
	int day;
	int month;
	int year;
	int departTime;
	int arrivalTime;
	string seatType;

public:
	Reservation(int, string, string, Bus b, string s, int d, int m, int y, int dt);
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

