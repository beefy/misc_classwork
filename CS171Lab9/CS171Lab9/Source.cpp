#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using std::ifstream;

const int MAX_CHARS_PER_LINE = 512;
int section_num = 1;
int line_left = 64;
bool center_next;
bool section_next;
bool add_spaces;
ofstream fout;

string center(string in) {

	int num_spaces = 40-in.length()/2;
	string spaces;

	for(int i = 0; i < num_spaces; i++) {
		spaces += " ";
	}

	return spaces + in;
}

string section(string in) {
	return "\n\n" + to_string(section_num) + ". " + in + "\n\n";
}

void processWords(string in) {

	if(add_spaces) {
		in = "        " + in;
		add_spaces = false;
	}

	//erase \n (just in case)
	while ( in.find ("\n") != string::npos )
	{
		in.erase ( in.find ("\n"), 2 );
	}

	string cur_word;
	bool done = false;

	do
	{
		cur_word = in.substr( 0, in.find (" "));
		in = in.substr(in.find(" ")+1, in.length());

		if(cur_word == in) in = "";

		//for some reason, the following if statement wouldn't work without length_left
		int length_left = line_left - cur_word.length();
		if(length_left >= 0) {
			fout << cur_word << " ";
			line_left = length_left;
		} else {
			fout << endl << "        " << in;
			line_left = 64 - in.length();
			length_left = line_left;
		} 

		if(in.length() <= 0) done = true;

	} while ( !done );

}

void process(string in) {

	//check for special formatting
	if(in == ".ce") {
		center_next = true;
		line_left = 64;
		return;
	}

	if(in == ".se") {
		section_next = true;
		line_left = 64;
		return;
	}

	if(in == "") {
		in = "\n\n";
		line_left = 64;
		add_spaces = true;
	}

	//if no formatting, parse words
	if(!center_next && !section_next && in != "\n\n") {
		processWords(in);
		return;
	}

	//else, formatt
	if(center_next ) {
		in = center(in);
		center_next = false;
		add_spaces = true;
	}

	if(section_next) {
		in = section(in);
		section_next = false;
		section_num++;
		add_spaces = true;
	}

	//print out formatted stuff
	fout << in << endl;
}

void main() {

	//initialize variables
	string file_name;
	char txt_line[MAX_CHARS_PER_LINE];
	int line_num = 0;
	int page_num = 2;

	//get input file
	cout << "Name of input file: ";
	cin >> file_name;

	ifstream fin;
	fin.open(file_name);

	if (!fin.good()) {
		cout << endl << "Not a good input file" << endl << endl;
		return;
	}

	//get output file
	cout << "Name of output file: ";
	cin >> file_name;

	fout.open(file_name);

	if (!fout.good()) {
		cout << endl << "Not a good output file" << endl << endl;
		return;
	}

	fout << endl << endl << endl << endl << endl;

	//parse file
	while(!fin.eof()) {

		//for page numbering
		if(line_num % 56 == 0 && line_num != 0) {

			fout << endl << endl << endl << endl << endl << endl << endl;
			fout << center(to_string(page_num)) << endl << endl << endl;
			page_num++;

		}

		fin.getline(txt_line,MAX_CHARS_PER_LINE);
		process(txt_line);

		line_num++;
	}

	int pages_left = 56 - (line_num % 56);

	for(int i = 0; i < pages_left; i++) {

		fout << endl;

	}
}