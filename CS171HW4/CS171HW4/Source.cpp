#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void seed_rand(int in) {
	time_t timer;
	time(&timer);
	srand(timer*in);
}

void setupDoors(char &door1, char &door2, char &door3) {
		
	int randnum = rand() % 3;

	if(randnum == 0) {
		door1 = 'C';
		door2 = 'G';
		door3 = 'G';
	} else if(randnum == 1) {
		door1 = 'G';
		door2 = 'C';
		door3 = 'G';
	} else if(randnum == 2) {
		door1 = 'G';
		door2 = 'G';
		door3 = 'C';
	}
}

void pickDoorChoicesStay(char door1, char door2, char door3, int &doorPlayer, int &doorMonty) {

	doorPlayer = rand() % 3 + 1;
	doorMonty = doorPlayer;
	int doorwithcar;
	if(door1 == 'C') doorwithcar = 1;
	else if(door2 == 'C') doorwithcar = 2;
	else if(door3 == 'C') doorwithcar = 3;

	while((doorPlayer == doorMonty) || (doorMonty == doorwithcar)) {
		doorMonty = rand() % 3 + 1;
	}
}

void pickDoorChoicesChange(char door1, char door2, char door3, int &doorPlayer, int &doorMonty) {

	doorPlayer = rand() % 3 + 1;
	doorMonty = doorPlayer;
	int doorwithcar;
	if(door1 == 'C') doorwithcar = 1;
	else if(door2 == 'C') doorwithcar = 2;
	else if(door3 == 'C') doorwithcar = 3;

	while((doorPlayer == doorMonty) || (doorMonty == doorwithcar)) {
		doorMonty = rand() % 3 + 1;
	}

	int oldpick = doorPlayer;

	while(doorPlayer == oldpick || doorPlayer == doorMonty) {
		doorPlayer = rand() % 3 + 1;
	}
}

void main() {

	char door1;
	char door2;
	char door3;
	int doorPlayer;
	int doorMonty;
	int doorwithcar;

	double wonafterchange = 0;
	double wonaftersame = 0;

	for(int i = 0; i < 10000; i++) {
		doorPlayer = 0;
		doorMonty = 0;

		seed_rand(i+rand()%100);

		setupDoors(door1, door2, door3);
		pickDoorChoicesStay(door1, door2, door3, doorPlayer, doorMonty);

	    if(door1 == 'C') doorwithcar = 1;
	    else if(door2 == 'C') doorwithcar = 2;
    	else if(door3 == 'C') doorwithcar = 3;

		if(doorPlayer == doorwithcar) wonaftersame++;
	}

	for(int i = 0; i < 10000; i++) {
		doorPlayer = 0;
		doorMonty = 0;

		seed_rand(i+rand()%100);

		setupDoors(door1, door2, door3);
		pickDoorChoicesChange(door1, door2, door3, doorPlayer, doorMonty);

	    if(door1 == 'C') doorwithcar = 1;
	    else if(door2 == 'C') doorwithcar = 2;
    	else if(door3 == 'C') doorwithcar = 3;

		if(doorPlayer == doorwithcar) wonafterchange++;
	}

	cout << "Percent won after not changing doors: " << wonaftersame/10000 << endl;
	cout << "Percent won after changing doors:     " << wonafterchange/10000 << endl;

}