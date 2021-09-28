#pragma once

#include <string>

using namespace std;

class Date
{

	int year;
	int month;
	int day;

public:
	Date();
	Date(int day, int month, int year);
	~Date();
	void set_day(int);
	void set_month(int);
	void set_year(int);

	int get_day();
	int get_month();
	int get_year();

	string get_date();
};

