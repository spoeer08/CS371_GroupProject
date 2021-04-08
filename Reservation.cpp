#include "Reservation.h"


using namespace std;

Bus bus();

Reservation::Reservation(int p, string s, string d, Bus b, int day, int m, int y, int dt)
{
	setTotalPassengers(p);
	setSource(s);
	setDestination(d);
	setBus(b);
	setDay(day);
	setMonth(m);
	setYear(y);
	setDepartTime(dt);

}

void Reservation::setTotalPassengers(int p)
{
	totalPassengers = p;
}

void Reservation::setCost(double c)
{
	cost = c;
}

void Reservation::setSource(string s)
{
	source = s;
}

void Reservation::setDestination(string d)
{
	destination = d;
}

void Reservation::setDistance(double dist)
{
	distance = dist;
}

void Reservation::setBus(Bus b) {
	Bus bus1();
	bus = b;
}

void Reservation::setDay(int day)
{
	day = day;
}

void Reservation::setMonth(int m)
{
	month = m;
}

void Reservation::setYear(int y) {
	year = y;
}

void Reservation::setDepartTime(int dt)
{
	departTime = dt;
}

string Reservation::getSource() const
{
	return source;
}

string Reservation::getDestination() const
{
	return destination;
}

double Reservation::getDistance() const
{
	return distance;
}

int Reservation::getTotalPassengers() const
{
	return totalPassengers;
}

double Reservation::getCost() const
{
	return cost;
}

Bus Reservation::getBus() const {
	return bus;
}

int Reservation::getDay() const
{
	return day;
}

int Reservation::getMonth() const
{
	return month;
}

int Reservation::getYear() const
{
	return year;
}

int Reservation::getDepartTime() const
{
	return departTime;
}
