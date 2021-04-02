#include "Route.h"

Route::Route(string s, string d, double dist)
{
	setSource(s);
	setDestination(d);
	setDistance(dist);
}

void Route::setSource(string s)
{
	source = s;
}

void Route::setDestination(string d)
{
	destination = d;
}

void Route::setDistance(double dist)
{
	distance = dist;
}

string Route::getSource() const
{
	return source;
}

string Route::getDestination() const
{
	return destination;
}

double Route::getDistance() const
{
	return distance;
}
