#pragma once
#include <iostream>
#include <string>

using namespace std;

class Address
{
	string street, street_no, flat_no, post_code, city;

public:
	
	Address();

	Address(string str, string str_no, string flat_no, string post, string city);
	
	void set_street(string);
	void set_post_code(string);
	void set_city(string);
	void set_street_no(string);
	void set_flat_no(string);

	string get_street();
	string get_post_code();
	string get_city();
	string get_street_no();
	string get_flat_no();

	string get_whole_address();

	~Address();
};

