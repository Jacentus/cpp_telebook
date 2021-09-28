#include "my_classes_and_functions.h"

using namespace std;

string contact_name, person_name, person_surname, phone, email, PESEL, str_home, str_home_no, flat_home_no, post_home_no, city_home, company_name, nip, str_work, str_work_no, flat_work_no, post_work_no, city_work;
int db, mb, yb, de, me, ye;

Contact GatherAllContactInfo()
{
	cin.ignore(100, '\n');
	cout << "Put contact name: "; getline(cin, contact_name);
	cout << "Personal details:" << endl;
	cout << "Put persons name: "; getline(cin, person_name);
	cout << "Put persons surname: "; getline(cin, person_surname);
	cout << "Put day of birth: "; 
	do
	{
		cin >> db;
		if ((db <= 0) || (db > 31))
		{
			cout << "Invalid input! Try again!" << endl;
		}
	} while ((db <= 0) || (db > 31));
	cout << "Put month of birth: ";
	do
	{
		cin >> mb;
		if ((mb <= 0) || (mb > 12))
		{
			cout << "Invalid input! Try again!" << endl;
		}
	} while ((mb <= 0) || (mb > 12));
	cout << "Put year of birth: "; 
	do
	{
		cin >> yb;
		if ((yb <= 1900) || (yb >= 2025))
		{
			cout << "Invalid input! Try again!" << endl;
		}
	} while ((yb <= 1900) || (yb >= 2025));
	cin.ignore(100, '\n');
	cout << "Put phone number: "; getline(cin, phone);
	cout << "Put email: "; getline(cin, email);
	cout << "Put PESEL: "; getline(cin, PESEL);
	cout << "Home address:" << endl;
	cout << "Put home street: "; getline(cin, str_home);
	cout << "Put home street no: "; getline(cin, str_home_no);
	cout << "Put home flat no: "; getline(cin, flat_home_no);
	cout << "Put home postal code: "; getline(cin, post_home_no);
	cout << "Put city of living: "; getline(cin, city_home);
	cout << "Employment details:" << endl;
	cout << "Put company name: "; getline(cin, company_name);
	cout << "Put company nip: "; getline(cin, nip);
	cout << "Company address:" << endl;
	cout << "Put office street: "; getline(cin, str_work);
	cout << "Put office street no: "; getline(cin, str_work_no);
	cout << "Put office flat no: "; getline(cin, flat_work_no);
	cout << "Put office postal code: "; getline(cin, post_work_no);
	cout << "Put city of working: "; getline(cin, city_work);
	cout << "Put day of employment: "; 	
	do
	{
		cin >> de;
		if ((de <= 0) || (de > 31))
		{
			cout << "Invalid input! Try again!" << endl;
		}
	} while ((de <= 0) || (de > 31));
	cout << "Put month of employment: ";
	do
	{
		cin >> me;
		if ((me <= 0) || (me > 12))
		{
			cout << "Invalid input! Try again!" << endl;
		}
	} while ((me <= 0) || (me > 12));
	cout << "Put year of employment: "; 	
	do
	{
		cin >> ye;
		if ((ye <= 1900) || (ye >= 2025))
		{
			cout << "Invalid input! Try again!" << endl;
		}
	} while ((ye <= 1900) || (ye >= 2025));
	cin.ignore(100, '\n');
	Contact vcard(contact_name, Person(person_name, person_surname, Date(db, mb, yb), phone, email, PESEL), Address(str_home, str_home_no, flat_home_no, post_home_no, city_home), Employment(company_name, nip, Address(str_work, str_work_no, flat_work_no, post_work_no, city_work), Date(de, me, ye)));

	return vcard;
}

void RevealAllContactInfo(Contact contact)
{
	cout << "Personal info: " << contact.get_personal_details().get_all_personal_data() << " Date of birth: " << contact.get_personal_details().getB_day().get_date();
	cout << endl << "Home address: " << contact.get_home_address().get_whole_address();
	cout << endl << "Employment information: " << contact.get_employment_details().get_whole_employment_data();
	cout << endl << "Office address: " << contact.get_employment_details().get_Company_Address().get_whole_address();
	cout << endl << "Hired since: " << contact.get_employment_details().get_Employment_Date().get_date() << endl;
}

void ShowMeMyContacts(vector<Contact> &pointer_to_ARRAY)
{
	cout << "You have the following contacts stored: ";
	if (pointer_to_ARRAY.empty() == true) { cout << "no contacts stored! " << endl; return; }
	for (int i = 0; i < pointer_to_ARRAY.size(); i++) //loop enlisting all vcards stored in ARRAY.
	{
		cout << i + 1 << ". " << pointer_to_ARRAY.at(i).get_contact_name();//+1 in order not to have 0. vcard
		cout << " ";
	}
}

int LetMeChooseMyContact(vector <Contact>& pointer_to_ARRAY)
{
	int n;
	do 
	{ 
	cin >> n; 
	if ((n > pointer_to_ARRAY.size()) || (n <= 0)) cout << "No such contact! Try again!";
	} while (n > pointer_to_ARRAY.size() || n <= 0);

	return n - 1;
}

void ShowMeMyMENU()
{
	cout << "***************************TELEBOOK***************************" << endl;
	cout << "*****************************MENU*****************************" << endl;
	cout << "**************************************************************" << endl;
	cout << "A. Add a contact info" << endl;
	cout << "D. Delete contact info" << endl;
	cout << "C. Change contact info" << endl;
	cout << "S. Show contact info" << endl;
	cout << "E. Exit program" << endl;
	cout << "**************************************************************" << endl;
}

char NavigateTheMENU()
{
	cout << "Choose option: "; 
	char choice;
	cin >> choice; 
	choice = toupper(choice);
	while (true) //loop allowing to re-input should one fail to choose valid menu command
	{
	if (!((choice == 'A') || (choice == 'D') || (choice == 'C') || (choice == 'S') || (choice == 'E')))
	{
		cout << "You didn't choose valid option. Try again: " << endl;
		cin >> choice;
		choice = toupper(choice);
	}
	else break;
	}
	return choice;
}

vector<Contact> ReadContactsFromFile(ifstream& VCARDS)
{
	VCARDS.open("vcards.txt", fstream::in || fstream::app);

	if (!VCARDS.is_open())
	{
		cout << "Unable to open your telebook!" << endl;
		exit(0);
	}
	if (VCARDS.good() == false)
	{
		cout << "Opps! Sth went wrong!" << endl;
		exit(0);
	}

	vector <Contact> ARRAY;

	string line;
	int line_no = 1;

	while (getline(VCARDS, line))
	{
		switch (line_no)
		{
		case 1: { contact_name = line; }
		case 2: { person_name = line; }
		case 3: { person_surname = line; }
		case 4:
		{
			string temp = line;
			db = atoi(temp.c_str());
		}
		case 5:
		{
			string temp = line;
			mb = atoi(temp.c_str());
		}
		case 6:
		{
			string temp = line;
			yb = atoi(temp.c_str());
		}
		case 7: {phone = line; }
		case 8: {email = line; }
		case 9: {PESEL = line; }
		case 10: {str_home = line; }
		case 11: {str_home_no = line; }
		case 12: {flat_home_no = line; }
		case 13: {post_home_no = line; }
		case 14: {city_home = line; }
		case 15: {company_name = line; }
		case 16: {nip = line; }
		case 17: {str_work = line; }
		case 18: {str_work_no = line; }
		case 19: {flat_work_no = line; }
		case 20: {post_work_no = line; }
		case 21: {city_work = line; }
		case 22:
		{
			string temp = line;
			de = atoi(temp.c_str());
		}
		case 23:
		{
			string temp = line;
			me = atoi(temp.c_str());
		}
		case 24:
		{
			string temp = line;
			ye = atoi(temp.c_str());
		}
		}

		line_no++;

		if ((line_no == 25) || (VCARDS.eof() == true))
		{
			Contact vcard(contact_name, Person(person_name, person_surname, Date(db, mb, yb), phone, email, PESEL), Address(str_home, str_home_no, flat_home_no, post_home_no, city_home), Employment(company_name, nip, Address(str_work, str_work_no, flat_work_no, post_work_no, city_work), Date(de, me, ye))); //stworz obiekt	
			ARRAY.push_back(vcard); //put newly created object into the vector
			line_no = 1; //start counting again
		}
	}
	VCARDS.close();
	return ARRAY;
}

void SaveContactsToFile(vector < Contact>& ARRAY)  
	{
	fstream VCARDS;
	VCARDS.open("vcards.txt", ios::out);
	
	for (int i = 0; i < ARRAY.size(); i++)
		{
		VCARDS << ARRAY[i].get_contact_name()<<endl;
		VCARDS << ARRAY[i].get_personal_details().get_name() << endl;
		VCARDS << ARRAY[i].get_personal_details().get_surname() << endl;
		VCARDS << to_string(ARRAY[i].get_personal_details().getB_day().get_day()) << endl;
		VCARDS << to_string(ARRAY[i].get_personal_details().getB_day().get_month()) << endl;
		VCARDS << to_string(ARRAY[i].get_personal_details().getB_day().get_year()) << endl;
		VCARDS << ARRAY[i].get_personal_details().get_phone_no() << endl;
		VCARDS << ARRAY[i].get_personal_details().get_email() << endl;
		VCARDS << ARRAY[i].get_personal_details().get_PESEL() << endl;
		VCARDS << ARRAY[i].get_home_address().get_street() << endl;
		VCARDS << ARRAY[i].get_home_address().get_street_no() << endl;
		VCARDS << ARRAY[i].get_home_address().get_flat_no() << endl;
		VCARDS << ARRAY[i].get_home_address().get_post_code() << endl;
		VCARDS << ARRAY[i].get_home_address().get_city() << endl;
		VCARDS << ARRAY[i].get_employment_details().get_company_name() << endl;
		VCARDS << ARRAY[i].get_employment_details().get_NIP() << endl;
		VCARDS << ARRAY[i].get_employment_details().get_Company_Address().get_street() << endl;
		VCARDS << ARRAY[i].get_employment_details().get_Company_Address().get_street_no() << endl;
		VCARDS << ARRAY[i].get_employment_details().get_Company_Address().get_flat_no() << endl;
		VCARDS << ARRAY[i].get_employment_details().get_Company_Address().get_post_code() << endl;
		VCARDS << ARRAY[i].get_employment_details().get_Company_Address().get_city() << endl;
		VCARDS << to_string(ARRAY[i].get_employment_details().get_Employment_Date().get_day()) << endl;
		VCARDS << to_string(ARRAY[i].get_employment_details().get_Employment_Date().get_month()) << endl;
		if (i == ARRAY.size()-1)//TO PREVENT THE LAST CONTACT TO MAKE ENDL AT THE END OF THE FILE
		{
			VCARDS << to_string(ARRAY[i].get_employment_details().get_Employment_Date().get_year());
		}
		else { VCARDS << to_string(ARRAY[i].get_employment_details().get_Employment_Date().get_year())<<endl;}
	}
	
	VCARDS.close();
	} 
