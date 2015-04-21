#include <iostream>;
#include <iomanip>;

using namespace std;

int main(void) {
	
	//initialize variables
	long yearly_tuition [5];
	long total_tuition;
	double percent_increase;
	
	//prompt for initial tuition
	cout << "What is the initial tuition amount? ";
	cin >> yearly_tuition[0];

	//multiply tuition to get long in cents
	yearly_tuition[0] *= 100;
	
	//prompt for percent increase
	cout << "What is the yearly percent increase in tuition? ";
	cin >> percent_increase;

	//calculate real percent increase
	percent_increase /= 100;

	//calculate yearly tuition
	yearly_tuition[1] = yearly_tuition[0] + yearly_tuition[0]*percent_increase;
	yearly_tuition[2] = yearly_tuition[1] + yearly_tuition[1]*percent_increase;
	yearly_tuition[3] = yearly_tuition[2] + yearly_tuition[2]*percent_increase;
	yearly_tuition[4] = yearly_tuition[3] + yearly_tuition[3]*percent_increase;

	//calculate total tuition
	total_tuition = yearly_tuition[0] + yearly_tuition[1] + yearly_tuition[2] +
						yearly_tuition[3] + yearly_tuition[4];

	//print yearly tuition
	cout << fixed << setprecision(2) << "Year one tuition:   $" << yearly_tuition[0]/100 + (yearly_tuition[0]%100)*0.01 << endl;
	cout << fixed << setprecision(2) << "Year two tuition:   $" << yearly_tuition[1]/100 + (yearly_tuition[1]%100)*0.01 << endl;
	cout << fixed << setprecision(2) << "Year three tuition: $" << yearly_tuition[2]/100 + (yearly_tuition[2]%100)*0.01 << endl;
	cout << fixed << setprecision(2) << "Year four tuition:  $" << yearly_tuition[3]/100 + (yearly_tuition[3]%100)*0.01 << endl;
	cout << fixed << setprecision(2) << "Year five tuition:  $" << yearly_tuition[4]/100 + (yearly_tuition[4]%100)*0.01 << endl;

	//print total tuition
	cout << endl << fixed << setprecision(2) << "Total Tuition: $" << total_tuition/100 + (total_tuition%100)*0.01 << endl;

	return 0;
}