#include <string>
#ifndef RENTER_H
#define RENTER_H

using namespace std;

class Renter {

private:
	string rname;
	string raddress;
	string rphone;
	string remail;

public:
	Renter(); //Default Constructor
	Renter(string, string, string, string);
	void setRName(string);
	void setRAddress(string);
	void setRPhone(string);
	void setREmail(string);
	string getRName() const;
	string getRAddress() const;
	string getRPhone() const;
	string getREmail() const;
	void printRentInfo();
};

#endif