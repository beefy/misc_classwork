#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


char vowels [10] = { 'A','E','I','O','U', 'a', 'e', 'i', 'o', 'u' };
string consonant [21] = { "B","C","D","F","G","H","J","K","L","M","N","P","Q","R","S","T","V","W","X","Y","Z" };

string process(string in) {

	return in.substr(1,in.length()) + in[0] + "ay";

}

bool isvowel(char c) {

	for(int i = 0; i < 10; i++) {
		if(c == vowels[i]) return true;
	}

	return false;
}

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

	//getline(cin, cur_line);
	cin >> cur_line;

	while(cur_line != "$$") {
		
		//cout << endl << "output: " << emptyWhenPattern(pattern, replacement, cur_line) << endl << endl;
		//getline(cin, cur_line);
		
		if(isvowel(cur_line[0])) cout << cur_line << "way ";
		else cout << process(cur_line) << " ";

		cin >> cur_line;
	}

	cout << endl << endl;

}