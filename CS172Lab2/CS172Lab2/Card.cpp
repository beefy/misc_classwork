#include "Card.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

string colors[3] = { "red", "purple", "green" };
string shapes[3] = { "diamond", "swiggle", "oval" };
string numbers[3] = { "one", "two", "three" };
string fillings[3] = { "solid", "stripped", "empty" };

string color;
string shape;
string number;
string filling;

void seed_rand() {
	time_t timer;
	time(&timer);
	srand(timer*timer);
}

Card::Card() {

	seed_rand();
	color = colors[rand() % 3];
	shape = shapes[rand() % 3];
	number = numbers[rand() % 3];
	filling = fillings[rand() % 3];
}