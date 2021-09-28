#include "Person.h"
#include <iostream>
#include "Date.h"
#include "Contact.h"

using namespace std;

Person::Person() : name("John"), surname("Doe"), b_day(01,01,1900), phone_no("unknown phone no."), email("unkonwn e-mail address"), PESEL("unknown PESEL no."){}

Person::~Person(){}

Person::Person(string n, string s, Date d, string p, string e, string PE)
{ 
	name = n;
	surname = s;
	b_day = d;
	phone_no = p;
	email = e;
	PESEL = PE;
}

void Person::set_name(string n)
{
	name = n;
}

void Person::set_surname(string s)
{
	surname = s;
}

void Person::set_phone_no(string p)
{
	phone_no = p;
}
void Person::set_email(string e)
{
	email = e;
}
void Person::set_PESEL(string PE)
{
	PESEL = PE;
}

void Person::setB_day(Date d)
{
	b_day = d;
}

string Person::get_name()
{
	return name;
}

string Person::get_surname()
{
	return surname;
}

string Person::get_phone_no() { return phone_no; }
string Person::get_email() { return email; }
string Person::get_PESEL() { return PESEL; }

string Person::get_all_personal_data()
{
string result = "Name:" + name + ". Surname:" + surname + ". Phone number: " + phone_no + ". Email: " + email + ". PESEL: " + PESEL;
return result;
}

Date Person::getB_day() { return b_day;}


