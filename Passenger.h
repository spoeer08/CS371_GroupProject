#include <string>
#ifndef PASSENGER_H
#define PASSENGER_H

using namespace std;

class Passenger {

private:
	string name;
	string address;
	string phone;
	string email;
	int tickets;

public:
	Passenger(); //Default Constructor
	Passenger(string, string, string, string, int);
	void setName(string);
	void setAddress(string);
	void setPhone(string);
	void setEmail(string);
	void setTickets(int);
	string getName() const;
	string getAddress() const;
	string getPhone() const;
	string getEmail() const;
	int getTickets() const;
	void printPassInfo();
	void makeReservation(Passenger);
};

#endif
