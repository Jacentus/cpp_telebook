#include "Contact.h"
#include "Person.h"
#include "Address.h"
#include "Employment.h"
#include <iostream>
#include <string>

Contact::Contact() : contact_name("unknown"), personal_details("John", "Doe", Date(01,12,2019), "unknown", "unknown", "unknown"), home_address("unknown", "unknown", "unknown", "unknown", "unknown"), employment_details("Unknown", "Unknown", Address("Unknown", "Unknown", "Unknown", "Unknown", "Unknown"), Date(1, 1, 1990)){}

Contact::Contact(string n, Person p, Address a, Employment e)
{
	contact_name = n;
	personal_details = p;
	home_address = a;
	employment_details = e;
}

void Contact::set_contact_name(string n)
{
	contact_name = n;
}

void Contact::set_personal_details(Person p)
{
	personal_details = p;
}

void Contact::set_home_address(Address a)
{
	home_address = a;
}

void Contact::set_employment_details(Employment e)
{
	employment_details = e;
}

Address Contact::get_home_address() { return home_address; }
Employment Contact::get_employment_details() { return employment_details; }
Person Contact::get_personal_details() { return personal_details; }
string Contact::get_contact_name() { return contact_name; }

Contact::~Contact() {}