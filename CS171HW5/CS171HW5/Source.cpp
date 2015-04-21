#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void introduction(istream &is, ostream &os, string target, string replacement) {

	bool quit = false;
	string cur_line = "";

	while (getline(is, cur_line)) {

		//parse out target
		int pos = cur_line.find(target);
		while (pos != string::npos) {
			cur_line = cur_line.replace(pos, target.length(), replacement);
			pos = cur_line.find(target);
		}

		os << cur_line << "\n";
	}
}

void updateStatus(double &velocity, double burnAmount, double &fuelRemaining, double &height) {
	double oldvelocity = velocity;
	velocity = velocity + 5 - burnAmount;
	height = height - (oldvelocity + velocity) / 2;
	fuelRemaining -= burnAmount;
}

//parameters are post crash
void touchdown(double &elapsedTime, double &velocity, double &burnAmount, double &height) {
	double oldvelocity = velocity - 5 + burnAmount;
	double oldheight = height + (oldvelocity + velocity) / 2;
	elapsedTime -= 1;
	double delta = (sqrt(pow(oldheight, 2) + oldheight*(10 - 2 * burnAmount)) - oldvelocity) / (5 - burnAmount);
	elapsedTime += delta;
	velocity = oldvelocity + (5 - burnAmount) * delta;

}

void damage(ostream &os, double velocity) {
	if (velocity <= 0) os << "Congratulations! A perfect landing!! Your license will be renewed...later.";
	else if (velocity < 2) os << "A little bumpy";
	else if (velocity < 5) os << "You blew it!!!!!! Your family will be notified...by post.";
	else if (velocity < 10) os << "Your ship is a heap of junk !!!!! Your family will be notified...by post.";
	else if (velocity < 30) os << "You blasted a huge crater !!!!! Your family will be notified...by post.";
	else if (velocity < 50) os << "Your ship is a wreck !!!!! Your family will be notified...by post.";
	else os << "You totaled an entire mountain !!!!! Your family will be notified...by post.";
}

void main() {

	ifstream input("input.txt");
	filebuf fb;
	fb.open("output.txt", ios::out);
	ostream output(&fb);

	string target = "$SPACECRAFT";
	string replacement = "APOLLO";

	string readintro;
	cout << "Read intro? ";
	getline(cin, readintro);
	if (readintro[0] == 'y' || readintro[0] == 'Y')
		introduction(input, cout, target, replacement);
	cout << "\n\n";

	double altitude = 0;
	double velocity = 0;
	//double const ACCELERATION = -1.63;
	double time = 0;
	double fuel;
	double fuel_supply;

	//prompt user for game start
	cout << "What is the initial altitude? ";
	cin >> altitude;
	cout << "What is the initial velocity? ";
	cin >> velocity;
	cout << "What is the initial fuel supply? ";
	cin >> fuel_supply;

	do {

		//print altitude
		cout << "After " << time << " seconds, the spaceship is " <<
			altitude << " meters high, and " << velocity << " meters/second fast" << endl;

		cout << "You have " << fuel_supply << " gallons of fuel left... " << endl;

		fuel = 0;
		if (fuel_supply > 0) {

			cout << "How much fuel to burn? ";
			cin >> fuel;

			if (fuel_supply-fuel > fuel_supply || fuel_supply-fuel < 0) {
				do {
					cout << "You don't have that much fuel!" << endl;
					cout << "How much fuel to burn? ";
					cin >> fuel;
				} while (fuel_supply-fuel < 0 || fuel_supply-fuel > fuel_supply);

			}
		}

		updateStatus(velocity, fuel, fuel_supply, altitude);
		time += 1;

	} while (altitude > 0);

	cout << "\n\n";
	touchdown(time, velocity, fuel, altitude);
	damage(cout, velocity);
	cout << "\n\n";
}