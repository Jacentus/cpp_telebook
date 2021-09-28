#include "Address.h"

using namespace std;

Address::Address() : street("Unknown"), street_no("Unknown"), flat_no("Unknown"), post_code("Unknown"), city("Unknown"){}

Address::Address(string s, string sn, string fn, string pc, string c)
{
	street = s;
	street_no = sn;
	flat_no = fn;
	post_code = pc;
	city = c;
}

void Address::set_street(string s)
{
	street = s;
}
void Address::set_post_code(string pc)
{
	post_code = pc;
}
void Address::set_city(string c)
{
	city = c;
}
void Address::set_street_no(string sn)
{
	street_no = sn;
}
void Address::set_flat_no(string fn)
{
	flat_no = fn;
}
string Address::get_street()
{
	return street;
}
string Address::get_post_code()
{
	return post_code;
}
string Address::get_city()
{
	return city;
}
string Address::get_street_no()
{
	return street_no;
}
string Address::get_flat_no()
{
	return flat_no;
}

string Address::get_whole_address()
{
	string result = "Street: " + street + "." + " street no.: " + street_no + "." + " Flat no.: " + flat_no + " City: " + city + "." + " Post code: " + post_code + ".";
	return result;
}

Address::~Address()
{
}
