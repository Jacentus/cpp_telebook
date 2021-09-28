#pragma once

#include "Date.h"
#include "Address.h"

class Employment
{
	string company_name;
	string NIP;
	Address company_address;
	Date employment_date;

public:

	Employment();
	Employment(string company_name, string NIP, Address, Date);

	void set_company_name(string);
	void set_NIP(string);
	void set_Employment_Date(Date);
	void set_Company_Address(Address);

	string get_company_name();
	string get_NIP();
	Date get_Employment_Date();
	Address get_Company_Address();

	string get_whole_employment_data();
};

