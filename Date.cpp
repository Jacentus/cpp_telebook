#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date() : day(1), month(1), year(1990) {}

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

Date::~Date()
{
}

void Date::set_day(int d)
{
	day = d;
}

void Date::set_month(int m)
{
	month = m;
}

void Date::set_year(int y)
{
	year = y;
}

int Date::get_day()
{
	return day;
}

int Date::get_month()
{
	return month;
}
int Date::get_year()
{
	return year;
}

string Date::get_date()
{
	string result = to_string(day) + "-" + to_string(month) + "-" + to_string(year);
	return result;
}

