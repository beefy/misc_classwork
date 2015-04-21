#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


string emptyWhenPattern(string pattern, string replacement, string in_line) {
	
	string out = in_line;
	string::size_type i = out.find(pattern,0);
	while(i != string::npos) {

		out = out.replace(i, replacement.length(), replacement);
		i = out.find(pattern, 0 );

	}

	return out;

}

void main() {

	string pattern;
	string replacement;
	string in;
	string cur_line;

	cout << "Whats the pattern? " << endl;
	getline(cin, pattern);
	cout << "Whats the replacement? " << endl;
	getline(cin, replacement);
	cout << "Type input: " << endl;
	getline(cin, cur_line);

	while(cur_line != "$$") {
		
		cout << endl << "output: " << emptyWhenPattern(pattern, replacement, cur_line) << endl << endl;
		getline(cin, cur_line);

	}

	cout << endl << endl;

}