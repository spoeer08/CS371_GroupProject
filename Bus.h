#include <string>
#ifndef BUS_H
#define BUS_H

using namespace std;

class Bus {

private:
	string ID;
	string type;
	bool availability;
	int seats;

public:
	Bus(string, string, bool, int);
	void setID(string);
	void setType(string);
	void setAvailability(bool);
	void setSeats(int);
	string getID() const;
	string getType() const;
	bool getAvailability() const;
	int getSeats() const;
	void printBusInfo();
};

#endif