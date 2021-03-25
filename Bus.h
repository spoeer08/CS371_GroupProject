#include <string>
#ifndef BUS_H
#define BUS_H

using namespace std;

class Bus {

private:
	string ID;
	string source;
	string destination;
	double distance;

public:
	Bus(string, string, string, double);
	void setID(string);
	void setSource(string);
	void setDestination(string);
	void setDistance(double);
	string getID() const;
	string getSource() const;
	string getDestination() const;
	double getDistance() const;
	void printBusInfo();
};

#endif