#include <string>
#ifndef BUS_H
#define BUS_H

using namespace std;

class Bus {

private:
	int ID;
	string type;
	bool availability;
	int seats;

public:
	Bus(int, string, bool, int);
	void setID(int);
	void setType(string);
	void setAvailability(bool);
	void setSeats(int);
	int getID() const;
	string getType() const;
	bool getAvailability() const;
	int getSeats() const;
	void printBusInfo();
};

#endif