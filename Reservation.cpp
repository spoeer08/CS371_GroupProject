#include "Reservation.h"


using namespace std;

Reservation::Reservation(int p, Bus b, double c)
{
	setTotalPassengers(p);
//	setBus(b);
	setCost(c);
}

void Reservation::setTotalPassengers(int p)
{
	totalPassengers = p;
}

/*void Reservation::setBus(Bus b)
{
	bus = b;
}
*/

void Reservation::setCost(double c)
{
	cost = c;
}

int Reservation::getTotalPassengers() const
{
	return totalPassengers;
}

/*Bus Reservation::getBus() const
{
	return bus;
}
*/

double Reservation::getCost() const
{
	return cost;
}
