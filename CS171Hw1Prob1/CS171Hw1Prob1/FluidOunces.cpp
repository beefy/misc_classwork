#include <iostream>;

using namespace std;

int main(void) {

	//amount of each unit that you have
	int fluid_ounces = 0;
	int tablespoon = 0;
	int gill = 0;
	int cup = 0;
	int pint = 0;
	int quart = 0;
	int gallon = 0;
	int barrel = 0;

	//amount of fluid ounces in each unit
	const float TABLESPOON = 0.5;
	const int GILL = 4;
	const int CUP = 2*GILL;
	const int PINT = 2*CUP;
	const int QUART = 2*PINT;
	const int GALLON = 4*QUART;
	const int BARREL = 42*GALLON;

	//prompt user
	cout << "How many fluid ounces do you have? ";
	cin >> fluid_ounces;
	cout << fluid_ounces << " fluid ounces can be devided into: " << endl;
	
	//calculate
	barrel = fluid_ounces/BARREL;
	fluid_ounces -= barrel*BARREL;

	gallon = fluid_ounces/GALLON;
	fluid_ounces -= gallon*GALLON;

	quart = fluid_ounces/QUART;
	fluid_ounces -= quart*QUART;

	pint = fluid_ounces/PINT;
	fluid_ounces -= pint*PINT;

	cup = fluid_ounces/CUP;
	fluid_ounces -= cup*CUP;

	gill = fluid_ounces/GILL;
	fluid_ounces -= gill*GILL;

	tablespoon = fluid_ounces/TABLESPOON;
	fluid_ounces -= tablespoon*TABLESPOON;

	//print results
	cout << barrel << " barrel(s)" << endl;
	cout << gallon << " gallon(s)" << endl;
	cout << quart << " quart(s)" << endl;
	cout << pint << " pint(s)" << endl;
	cout << cup << " cup(s)" << endl;
	cout << gill << " gill(s)" << endl;	
	cout << tablespoon << " tablespoon(s)" << endl;

	return 0;
}