#include "Bus.h"
#ifndef RESERVATION_H
#define RESERVATION_H

using namespace std;

class Reservation {

private:
	int totalPassengers;
	//Bus bus;
	double cost;

public:
	Reservation(int, Bus, double);
	void setTotalPassengers(int);
	void setBus(Bus);
	void setCost(double);
	int getTotalPassengers() const;
	Bus getBus() const;
	double getCost() const;
};

#endif

