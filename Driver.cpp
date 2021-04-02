#include "Driver.h"

Driver::Driver()
{
	setName("Billy");
	setAddress("1456 Horton Lane");
	setContactNumber("920-456-7832");
}

Driver::Driver(string n, string a, string c) {
	setName(n);
	setAddress(a);
	setContactNumber(c);
}

void Driver::setName(string n)
{
	name = n;
}

void Driver::setAddress(string a)
{
	address = a;
}

void Driver::setContactNumber(string c)
{
	contactNumber = c;
}

string Driver::getName() const
{
	return name;
}

string Driver::getAddress() const
{
	return address;
}

string Driver::getContactNumber() const
{
	return contactNumber;
}
