#include "Address.h"
#include "Employment.h"
#include "Date.h"
#include "Contact.h"

using namespace std;

Employment::Employment() : company_name("Unknown"), NIP("Unknown"), company_address("Unknown", "Unknown","Unknown","Unknown","Unknown"), employment_date(1, 1, 1990){}

Employment::Employment(string c_name, string NIP_no, Address a, Date d)
{
	company_name = c_name;
	NIP = NIP_no;
	company_address = a;
	employment_date = d;
}

void Employment::set_company_name(string c_name)
{
	company_name = c_name;
}

void Employment::set_NIP(string n)
{
	NIP = n;
}

void Employment::set_Employment_Date(Date d)
{
	employment_date = d;
}

void Employment::set_Company_Address(Address c_a)
{
	company_address = c_a;
}

string Employment::get_company_name() { return company_name; }
string Employment::get_NIP() { return NIP; }
Date Employment::get_Employment_Date() { return employment_date; }
Address Employment::get_Company_Address() { return company_address; }

string Employment::get_whole_employment_data()
{
string result = "Company name:" + company_name + ". NIP number:" + NIP;
return result;
}