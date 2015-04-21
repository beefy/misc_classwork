#include <iostream>
#include <string>

using namespace std;

bool ispalindrome(string in) {

	for(int i = 0; i < in.length()/2; i++) {
		if(in[0+i] != in[in.length()-1-i]) return false;
	}

	return true;
}

string makePalindrome(string in) {

	int startlen = in.length();
	string oppositeside;

	for(int i = 0; i < startlen; i++) {
		oppositeside = oppositeside + in[in.length()-1-i];
	}

	return in + oppositeside;
}

void main() {

	string in = "";

	cout << "Input: ";
	cin >> in;

	if(ispalindrome(in)) {
		cout << endl << in;
	} else {
		cout << endl << makePalindrome(in);
	}

	cout << endl;
}