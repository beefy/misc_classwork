#include <iostream>
#include <string>

using namespace std;

string emptyWhenPattern(string pattern, string replacement, string in_line) {
	
	string out = in_line;
	int i = out.rfind(pattern,0);
	while(i != string::npos) {

		out = out.erase(i, pattern.length());
		int i = out.rfind(pattern,0);

	}

	return out;

}

void main() {

	string pattern;
	string replacement;
	string in;
	string cur_line;

	getline(cin, pattern);
	getline(cin, replacement);
	
	getline(cin, cur_line);

	while(cur_line != "$$") {
		
		cout << endl << "output: " << emptyWhenPattern(pattern, replacement, cur_line) << endl << endl;
		getline(cin, cur_line);

	}

	cout << endl << endl;

}