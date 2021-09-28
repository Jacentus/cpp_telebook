#pragma once

#include "Person.h"
#include "Address.h"
#include "Employment.h"

class Contact
{
	string contact_name;
	Person personal_details;
	Address home_address;
	Employment employment_details;

public:

	Contact();
	Contact(string contact_name, Person, Address, Employment);

	void set_personal_details(Person);
	void set_home_address(Address);
	void set_employment_details(Employment);
	void set_contact_name(string);

	Address get_home_address();
	Employment get_employment_details();
	Person get_personal_details();
	string get_contact_name();

	~Contact();
};
