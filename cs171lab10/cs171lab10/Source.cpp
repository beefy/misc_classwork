#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// contact[x][0] --> name
// contact[x][1] --> phone
// contact[x][2] --> email

//maximum number of contacts is 500
int const MAX_CONTACTS = 500;
string contact[MAX_CONTACTS][3];
int cur_contact_num = 0;
int contact_num;

fstream file;

void storeContact(string contact_string) {
	
	string::size_type pos_end;

	//get name
	pos_end = contact_string.find(":", 0);
	contact[cur_contact_num][0] = contact_string.substr(0, pos_end);
	contact_string = contact_string.substr(pos_end+1);

	//get phone
	pos_end = contact_string.find(":", 0);
	contact[cur_contact_num][1] = contact_string.substr(0, pos_end);
	contact_string = contact_string.substr(pos_end + 1);

	//get email
	pos_end = contact_string.find(":", 0);
	contact[cur_contact_num][2] = contact_string.substr(0, pos_end);
	contact_string = contact_string.substr(pos_end + 1);

	cur_contact_num++;

}

void rewriteFile() {
	//rewrite file
	file.close();
	file.open("contactList.txt", ios::out);

	if (!file.good()) cout << "FILE NOT GOOD";

	string out_to_file;

	for (int i = 0; i < contact_num; i++) {
		out_to_file += contact[i][0] + ":";
		out_to_file += contact[i][1] + ":";
		out_to_file += contact[i][2] + "\n";
	}

	file << out_to_file;
}

void printContacts() {

	for (int i = 0; i < contact_num; i++) {
		cout << "  " << i+1 << ".\n";
		cout << "     Name: " << contact[i][0] << endl;
		cout << "     Phone: " << contact[i][1] << endl;
		cout << "     Email: " << contact[i][2] << endl;
	}
}

void printContacts(string contact[][3], int contact_num) {

	for (int i = 0; i < contact_num; i++) {
		cout << "  " << i + 1 << ".\n";
		cout << "     Name: " << contact[i][0] << endl;
		cout << "     Phone: " << contact[i][1] << endl;
		cout << "     Email: " << contact[i][2] << endl;
	}
}

void removeContact() {

	cout << "Which Contact Number to Remove? Type Q for cancel.\n";
	string in;
	getline(cin, in);
	int contact_to_remove = atoi(in.c_str()) - 1;

	if (in == "Q" || in == "q") {
		cout << "Remove Cancelled\n\n";
		return;
	}

	if (contact_num < contact_to_remove) {
		cout << "No Contact Found\n\n";
		return;
	}

	for (int i = contact_to_remove; i < contact_num + 1; i++) {
		contact[i][0] = contact[i + 1][0];
		contact[i][1] = contact[i + 1][1];
		contact[i][2] = contact[i + 1][2];
	}

	contact_num--;

	
	rewriteFile();

}

void addContact() {

	string name;
	string phone;

	string email;

	cout << "\n  Name: ";
	getline(cin, name);
	cout << "\n  Phone: ";
	getline(cin, phone);
	cout << "\n  Email: ";
	getline(cin, email);

	contact[contact_num][0] = name;
	contact[contact_num][1] = phone;
	contact[contact_num][2] = email;
	contact_num++;
	cout << "\nContact Added\n\n";

	rewriteFile();
}

void searchContact() {
	
	string search_phrase;
	cout << "\n  Search Phrase: ";
	getline(cin, search_phrase);

	string found_contacts[MAX_CONTACTS][3];
	int found_num = 0;

	for (int i = 0; i < contact_num; i++) {
		if (contact[i][0].find(search_phrase, 0) != string::npos ||
			contact[i][1].find(search_phrase, 0) != string::npos ||
			contact[i][2].find(search_phrase, 0) != string::npos) {
				
			found_contacts[found_num][0] = contact[i][0];
			found_contacts[found_num][1] = contact[i][1];
			found_contacts[found_num][2] = contact[i][2];
			found_num++;
		}
	}

	printContacts(found_contacts, found_num);
}

void main() {

	fstream file_end;
	string cur_line = " ";
	string option = "";
	bool quit = false;

	//open file for reading in
	file.open("contactList.txt", ios::in);
	file_end.open("contactList.txt", ios::in);
	
	if (!file.good()) {
		cout << "FILE NOT FOUND, EXITING\n\n";
		return;
	}

	/*
		READ IN FILE
	*/
	while (!getline(file_end, cur_line).eof()) {
		getline(file, cur_line);
		contact_num++;
		storeContact(cur_line);
	}

	cout << "Contact File Loaded";

	/*
		LOOP THROUGH OPTIONS
	*/
	while (!quit) {
		//prompt user
		cout << "\n\n[1] List Contacts\n[2] Add Contact\n[3] Remove Contact\n[4] Search For Contact\n" <<
			"[Q] Quit\n\n";
		getline(cin, option);

		cout << endl << endl;

		if (option == "1") printContacts();
		else if (option == "2") addContact();
		else if (option == "3") removeContact();
		else if (option == "4") searchContact();
		else if (option == "Q" || option =="q") quit = true;
		else cout << "\n\nUnrecognized Input\n\n";
	}

	//open for writing
	//file.open("contactList.txt", ios::out);
}