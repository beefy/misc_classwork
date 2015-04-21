	#include <iostream>
	#include <cmath>

	using namespace std;

	int main(void)
	{
		float altitude = 0;
		float velocity = 0;
		float const ACCELERATION = -1.63;
		int time = 0;
		float fuel;
		float fuel_supply;

		//prompt user
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
			if(fuel_supply > 0) {

				cout << "How much fuel to burn? ";
				cin >> fuel;

				if(fuel > fuel_supply || fuel < 0) {
					do {
						cout << "You don't have that much fuel!" << endl;
						cout << "How much fuel to burn? ";
						cin >> fuel;
					} while (fuel < 0 || fuel > fuel_supply);

				}

				//decrement fuel supply
				fuel_supply -= fuel;

			}

			//increment time
			time++;

			//increment velocity
			velocity += ACCELERATION + 0.1*fuel;
			//increment altitude
			altitude += velocity;
		} while (altitude > 0);

		if( fabs(velocity) > 2 ) cout << "CRASH!" << endl << endl;
		else cout << "You made it, yay!" << endl << endl;


		return 0;
	}