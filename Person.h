#pragma once

#include "Date.h"
#include <iostream>
#include <string>

class Person
{
	string name, surname, phone_no, email, PESEL;
	Date b_day;

public:
	
	Person();
	Person(string name, string surname, Date, string phone_no, string email, string PESEL);
	
	void set_name(string);
	void set_surname(string);
	void set_phone_no(string);
	void set_email(string);
	void set_PESEL(string);
	void setB_day(Date);

	string get_name();
	string get_surname();
	string get_phone_no();
	string get_email();
	string get_PESEL();
	string get_all_personal_data();

	Date getB_day();

	~Person();
};

