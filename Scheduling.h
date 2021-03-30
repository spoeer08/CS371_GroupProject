#ifndef RESERVATION_H
#define RESERVATION_H

using namespace std;

class Scheduling {

private:
	int origin;
	int destination;
	int bustype;

public:
	Scheduling(int, int, int);
	Scheduling();
	void setOrigin(int);
	void setDestination(int);
	void setBusType(int);
	int getOrigin() const;
	int getDestination() const;
	int getBusType() const;
};

#endif