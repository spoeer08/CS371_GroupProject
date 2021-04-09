#include "Renter.h"
#include <iostream>

using namespace std;

Renter::Renter() { //Default Constructor
	setRName("John");
	setRAddress("987 Bus Drive, Neenah 54956");
	setRPhone("987 - 654 - 3210");
	setREmail("john@gmail.com");

}

Renter::Renter(string rn, string ra, string rp, string re) { //Parameterized Constructor
	setRName(rn);
	setRAddress(ra);
	setRPhone(rp);
	setREmail(re);
}

void Renter::setRName(string n) {
	rname = n;
}

void Renter::setRAddress(string a) {
	raddress = a;
}

void Renter::setRPhone(string p) {
	rphone = p;
}

void Renter::setREmail(string e) {
	remail = e;
}

string Renter::getRName() const {
	return rname;
}

string Renter::getRAddress() const {
	return raddress;
}

string Renter::getRPhone() const {
	return rphone;
}

string Renter::getREmail() const {
	return remail;
}

void Renter::printRentInfo() {
	cout << getRName() << "\t" << getRAddress() << "\t" << getRPhone() << "\t" << getREmail() << "\t" << "\n";
}