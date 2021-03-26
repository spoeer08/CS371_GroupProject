#ifndef RESERVATION_H
#define RESERVATION_H

using namespace std;

class Reservation {

private:
	int day;
	int month;
	int year;

public:
	Reservation(int, int, int);
	Reservation();
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
};

#endif

