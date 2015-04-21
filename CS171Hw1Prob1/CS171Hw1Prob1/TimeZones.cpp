#include <iostream>;
#include <iomanip>;

using namespace std;

int main(void) {

	//initialize variables/times
	int cur_time = 0;
	int honolulu = -600;
	int seattle = -300;
	int london = 500;
	int moscow = 800;
	int hong_kong = 1200;
	int aukland = 1700;

	//prompt user
	cout << "What is the current time in Philadelphia? ";
	cin >> cur_time;

	//to avoid negative times
	cur_time += 2400;

	//calculate times
	honolulu += cur_time;
	honolulu %= 2400;
	seattle += cur_time;
	seattle %= 2400;
	london += cur_time;
	london %= 2400;
	moscow += cur_time;
	moscow %= 2400;
	hong_kong += cur_time;
	hong_kong %= 2400;
	aukland += cur_time;
	aukland %= 2400;


	//print times
	cout << endl << "Current times in other cities" << endl << endl;
	cout << "Honolulu:  " << setw(4) << setfill('0') << honolulu << endl;
	cout << "Seattle:   " << setw(4) << setfill('0') << seattle << endl;
	cout << "London:    " << setw(4) << setfill('0') << london << endl;
	cout << "Moscow:    " << setw(4) << setfill('0') << moscow << endl;
	cout << "Hong Kong: " << setw(4) << setfill('0') << hong_kong << endl;
	cout << "Aukland:   " << setw(4) << setfill('0') << aukland << endl << endl;

	return 0;
}