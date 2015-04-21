#include <string>
#include <iostream>

using namespace std;

//returns the barcode for one digit
string convertDigit(int value) {
	switch(value) {
		case 0: return "||:::";
		case 9: return "|:|::";
		case 8: return "|::|:";
		case 7: return "|:::|";
		case 6: return ":||::";
		case 5: return ":|:|:";
		case 4: return ":|::|";
		case 3: return "::||:";
		case 2: return "::|:|";
		case 1: return ":::||";
		default: return "";
	}
}

//returns the check digit for a zipcode
int makeCheckDigit(int zipcode) {
	if(zipcode > 0) {
		return 10-((
			zipcode%10 +
			zipcode%100/10 +
			zipcode%1000/100 +
			zipcode%10000/1000 +
			zipcode%100000/10000)%10);
	} else return 0;
}

//returns the barcode string
string barcode(int zipcode) {

	string out = "|";
	out += convertDigit(zipcode%100000/10000);
	out += convertDigit(zipcode%10000/1000);
	out += convertDigit(zipcode%1000/100);
	out += convertDigit(zipcode%100/10);
	out += convertDigit(zipcode%10);
	out += convertDigit(makeCheckDigit(zipcode));
	out+= "|";
	return out;
}

int main() {
	cout << barcode(19104) << endl << endl;
	return 0;
}