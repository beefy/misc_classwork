#include <iostream>
#include <string>
#include <time.h>

using namespace std;

string vowels [5] = { "A","E","I","O","U" };
string consonant [21] = { "B","C","D","F","G","H","J","K","L","M","N","P","Q","R","S","T","V","W","X","Y","Z" };


int get_rand(int n) {

	return rand() % n;

}

void print_vowel() {

	cout << vowels[get_rand(5)];
}

void print_consonant() {
	cout << consonant[get_rand(21)];
}

void seed_rand2() {
	time_t timer;
	time(&timer);
	srand(timer);
}

void print_word() {
	
	print_consonant();
	print_vowel();
	print_consonant();
	print_consonant();
	print_vowel();
	print_consonant();
}

int main2() {

	seed_rand2();
	print_word();

	cout << endl << endl;
	return 0;
}