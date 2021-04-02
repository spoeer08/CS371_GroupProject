#include <string>
#ifndef ROUTE_H
#define ROUTE_H

using namespace std;

class Route {

private:
	string source;
	string destination;
	double distance;

public:
	Route(string, string, double);
	void setSource(string);
	void setDestination(string);
	void setDistance(double);
	string getSource() const;
	string getDestination() const;
	double getDistance() const;
};

#endif