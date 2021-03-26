#include "Reservation.h"


using namespace std;

Reservation::Reservation() {
	setDay(1);
	setMonth(1);
	setYear(1);
}

Reservation::Reservation(int d, int m, int y) {
	setDay(d);
	setMonth(m);
	setYear(y);
}

void Reservation::setDay(int d) {
	day = d;
}

void Reservation::setMonth(int m) {
	month = m;
}

void Reservation::setYear(int y) {
	year = y;
}

int Reservation::getDay()const {
	return day;
}

int Reservation::getMonth() const {
	return month;
}

int Reservation::getYear() const {
	return year;
}