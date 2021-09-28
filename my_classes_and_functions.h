#pragma once

//Classes

#include "Date.h"
#include "Person.h"
#include "Contact.h"
#include "Address.h"
#include "Employment.h"

//Libraries

#include <string>
#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>

//various_functions

Contact GatherAllContactInfo(); //INPUT OF ALL DATA OF CONTACT CLASS. CREATES AND RETURNS CONTACT

void RevealAllContactInfo(Contact); //DISPLAYS ALL CONTACT DETAILS

void ShowMeMyContacts(vector <Contact> & pointer_to_ARRAY); //ENLISTS ALL CONTACTS STORED IN THE ARRAY

int LetMeChooseMyContact(vector <Contact>& pointer_to_ARRAY); //CHECKS IF THE GIVEN CONTACT IS PRESENT IN THE ARRAY

void ShowMeMyMENU(); //DISPLAYS MENU

char NavigateTheMENU(); //VALIDATES CHOICE OF MENU OPTION, RETURNS CHOSEN OPTION

vector<Contact> ReadContactsFromFile(ifstream &VCARDS); //OPENS .TXT FILE, READS STRINGS, CREATES CONTACTS AND PLACES THEM IN A VECTOR TO BE USED IN THE MAIN FUNCTION

void SaveContactsToFile(vector < Contact>& pointer_to_ARRAY); //READS ARRAY OF CONTACTS, SAVES ALL INFO AS STRINGS IN A .TXT FILE