#include <iostream>
#include <string>

using namespace std;

char numerals [7] = { 'I','V','X','L','C','D','M' };
int numeralValue [7] = { 1, 5, 10, 50, 100, 500, 1000 };

int convertRomanNumber(string number) {

	//initialize variables
	int curCharNum;
	int nextCharNum;
	char curChar;
	char nextChar;

	//base case
	if(number.length() == 0) return 0;

	if(number.length() >= 2) {
		curChar = number.at(0);
		nextChar = number.at(1);
	} else if(number.length() <= 1) {
		curChar = number.at(0);
		nextChar = number.at(0);
	}
	
	//determine roman numeral
	for(int i = 0; i < 7; i++) {
		if(curChar == numerals[i]) {
			curCharNum = i;
		}

		if(nextChar == numerals[i]) {
			nextCharNum = i;
		}
	}

	if(curCharNum < nextCharNum) {
		return numeralValue[nextCharNum] - numeralValue[curCharNum] + convertRomanNumber(number.substr(2));
	} else {
		return numeralValue[curCharNum] + convertRomanNumber(number.substr(1));
	}
}