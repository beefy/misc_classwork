#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	//initializing
	const double YEAR_ONE = 10000000000.00;
	const double YEAR_TWO = 3;
	const double YEAR_THREE = -10000000000.00;
	const double YEAR_FOUR = 5;
	float average;

	//computing
	average = (YEAR_ONE + YEAR_TWO + YEAR_THREE + YEAR_FOUR)/4; 
	
	//printing things out
	if(YEAR_ONE > 0.0) cout << fixed << setprecision(2) << "1998 earnings were: $" << YEAR_ONE << endl;
	else cout <<  fixed << setprecision(2) << "1998 earnings were: -$" << YEAR_ONE*-1 << endl; 

	if(YEAR_TWO > 0.0) cout <<  fixed << setprecision(2) << "1999 earings were: $" <<  YEAR_TWO << endl;
	else cout <<  fixed << setprecision(2) << "1999 earings were: -$" <<  YEAR_TWO*-1 << endl;

	if(YEAR_THREE > 0.0) cout <<  fixed << setprecision(2) << "2000 earnings were: $" << YEAR_THREE << endl;
	else cout <<  fixed << setprecision(2) << "2000 earnings were: -$" << YEAR_THREE*-1 << endl;

	if(YEAR_FOUR > 0.0) cout <<  fixed << setprecision(2) << "2001 earnings were: $" << YEAR_FOUR << endl;
	else cout <<  fixed << setprecision(2) << "2001 earnings were: -$" << YEAR_FOUR*-1 << endl;

	cout << "Average earnings was: $" << average << endl;

	return 0;
}


