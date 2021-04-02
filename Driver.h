#include <string>
#include "Bus.h"
#ifndef DRIVER_H
#define DRIVER_H

using namespace std;

class Driver {
private:
	string name;
	string address;
	string contactNumber;
	//Bus bus;
public:
	Driver();
	Driver(string, string, string);
	void setName(string n);
	void setAddress(string a);
	void setContactNumber(string n);
	string getName() const;
	string getAddress() const;
	string getContactNumber() const;

};

#endif