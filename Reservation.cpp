#include "Reservation.h"
#include "Passenger.h"
#include "Renter.h"
#include <iostream>


using namespace std;

Reservation::Reservation(string t, Renter renter, string s, string d, Bus b, int m, int day, int y, int dt) { //Reservation parameters for renters
	setResType(t);
	setRenter(renter);
	setSource(s);
	setDestination(d);
	setBus(b);
	setMonth(m);
	setDay(day);
	setYear(y);
	setDepartTime(dt);
}

Reservation::Reservation(string t, Passenger passenger, int tp, string s, string d, Bus b, string seat, int m, int day, int y, int dt) //Reservation parameters for passengers
{
	setResType(t);
	setPassenger(passenger);
	setTotalPassengers(tp);
	setSource(s);
	setDestination(d);
	setBus(b);
	setSeat(seat);
	setMonth(m);
	setDay(day);	
	setYear(y);
	setDepartTime(dt);

}

void Reservation::setResType(string t) {
	resType = t;
}

void Reservation::setPassenger(Passenger p) {
	passenger = p;
}

void Reservation::setRenter(Renter r) {
	renter = r;
}

void Reservation::setTotalPassengers(int tp)
{
	totalPassengers = tp;
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
	bus = b;
}

void Reservation::setDay(int dy)
{
	day = dy;
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

void Reservation::setSeat(string st) {
	seatType = st;
}

string Reservation::getResType()const {
	return resType;
}

Passenger Reservation::getPassenger()const {
	return passenger;
}

Renter Reservation::getRenter() const {
	return renter;
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

string Reservation::getSeat() const {
	return seatType;
}