#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


void computeBloodAlcoholConcentration(int numDrinks, int weight,
    int duration, double &maleBAC, double &femaleBAC) {
		
		double weightKg = weight*0.453592;
		maleBAC = (0.806*numDrinks*1.2)/(0.58*weightKg) - (0.017*(duration/60));
		femaleBAC = (0.806*numDrinks*1.2)/(0.49*weightKg) - (0.017*(duration/60));

}

void main() {
	string sex;
	string status;
	float weight;
	float time;
	double maleBAC;
	double femaleBAC;
	double BAC;

	cout << "Enter your weight: ";
	cin >> weight;
	cout << "Enter your sex: ";
	cin >> sex;
	cout << "Enter the time since last drink: ";
	cin >> time;
	cout << endl << endl;
	cout << "# drinks  BAC    Status" << endl;

	for(int i = 0; i < 12; i++) {
		computeBloodAlcoholConcentration(i,weight,time,maleBAC,femaleBAC);
		if(sex[0] == 'm') BAC = maleBAC;
		else BAC = femaleBAC;

		if(BAC <= 0) status = "Safe to Drive";
		else if(BAC < 0.04) status = "Some Impairment";
		else if(BAC < 0.08) status = "Driving Skills Significantly Affected";
		else if(BAC < 0.10) status = "Criminal Penalties in Most US States";
		else if(BAC >= 0.10) status = "Legally Intoxicated - Criminal Penalties in All US States";

		cout << setprecision(3) << fixed << "       " << i << " " << BAC << " " << status << endl;
	}
}