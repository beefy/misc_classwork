#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void seed_rand(int i) {
	time_t timer;
	time(&timer);
	srand(timer*i);
}

float get_rand() {
	return (rand() % 2000 - 1000)/1000.0;
}

void cartesian_to_polar(float x, float y, float &radius, float &theta) {
	radius = sqrt( pow(x,2) + pow(y,2) );
	theta = atan( y/x );
	
	double pi = 3.14159265358979323846;

	if( x < 0 && y >= 0 ) theta += pi;
	if( x < 0 && y < 0 ) theta -= pi;
}

int main() {
	
	float greater_zero = 0;
	float less_zero = 0;

	float x;
	float y;
	float radius = 0;
	float theta = 0;
	float inCircle = 0;
	float points = 100000;

	for(int i = 0; i < points; i++) {

		
		seed_rand(i);

		x = get_rand();
		y = get_rand();

		cartesian_to_polar(x,y,radius,theta);

		if(radius < 1) inCircle++;
		
	}

	cout << 4 * (inCircle/points);

	cout << endl << endl;

	return 0;
}