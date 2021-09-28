#include "my_classes_and_functions.h"

using namespace std;

char choice; //used to navigate the menu
ifstream VCARDS; //stores .txt file with saved Contacts

int main()
{
	vector<Contact> ARRAY = ReadContactsFromFile(VCARDS);
	
	cout << "***************************TELEBOOK***************************" << endl;
	cout << "*****************************MENU*****************************" << endl;
	cout << "**************************************************************" << endl;
	cout << "A. Add a contact info" << endl;
	cout << "D. Delete contact info" << endl;
	cout << "C. Change contact info" << endl;
	cout << "S. Show contact info" << endl;
	cout << "E. Exit program" << endl;
	cout << "**************************************************************" << endl;

	while (true) //loop allowing to navigate through menu many times, until chosen otherwise
	{
		char choice = NavigateTheMENU();
		switch (choice)
		{
		case 'A': //adding new vcard
		{
			ARRAY.push_back(GatherAllContactInfo());
			break;
		}
		case 'D': //deleting existing vcard
		{
			ShowMeMyContacts(ARRAY);
			if (ARRAY.empty() == true) break;
			cout << endl << "Which contact would you like to delete? Select number: ";
			ARRAY.erase(ARRAY.begin() + LetMeChooseMyContact(ARRAY));
			break;
		}
		case 'C': //amending existing vcard 
		{
			ShowMeMyContacts(ARRAY);
			if (ARRAY.empty() == true) break;
			cout << endl << "Which contact would you like to change? Select number: " << endl;
			int n = LetMeChooseMyContact(ARRAY); //variable to define index in ARRAY to be amended
			ARRAY[n] = GatherAllContactInfo();  //puting new object into the place of old one. Function gathers all data and returns new instance of Contact class
			break;
		}
		case 'S': //showing vcard info 
		{
			ShowMeMyContacts(ARRAY);
			if (ARRAY.empty() == true) break;
			cout << endl << "Which contact would you like to view? Select number: " << endl;
			RevealAllContactInfo(ARRAY.at(LetMeChooseMyContact(ARRAY)));
			break;
		}
		case 'E': //exit the loop
		{
			cout << "Goodbye!" << endl << endl;
			exit(0);
		}
		default: break;
		}
		cout << "would you like to take another action? [Y/N]" << endl; //choice to come back to menu at the end of while loop 
		char again;
		cin >> again;
		again = toupper(again);
		if (again != 'Y') //exit if anything else was put
		{
			cout << "Goodbye!" << endl;
			break;
		}
		system("cls");
		
		if (again == 'Y') ShowMeMyMENU(); //to show menu again after system cls
	}
	
	SaveContactsToFile(ARRAY); //save vector of contacts to file

	system("Pause");
	return (0);
}