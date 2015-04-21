#include <iostream>

using namespace std;

int main()
{
	int grade;
	int print_num = 0;
	char feedback[18][100] = {
		{"invalid input\n"}
		{"Congratulations, you got a perfect score: A+\n"},
		{"Very good: A+\n"},
		{"Very good: A\n"},
		{"Very good: A-\n"},
		{"Good job: B+\n"},
		{"Good job: B\n"},
		{"Good job: B-\n"},
		{"Not bad: C+\n"}
		{"Not bad: C\n"},
		{"Not bad: C-\n"},
		{"Not so good: D+\n"},
		{"Not so good: D\n"},
		{"Not so good: D-\n"},
		{"We need to talk: F+\n"},
		{"We need to talk: F\n"},
		{"We need to talk: F-\n"},
		{"You suck: F--\n"}
	};

	cout << "What grade did you make? ";
	cin >> grade;

	if(grade > 100) {
		print_num = 0;
	} else if(grade == 100) {
		print_num = 1;
	} else if(grade >= 97) {
		print_num = 2;
	} else if(grade >= 93) {
		print_num = 3;
	} else if(grade >= 90) {
		print_num = 4;
	} else if(grade >= 87) {
		print_num = 5;
	} else if(grade >= 83) {
		print_num = 6;
	} else if(grade >= 80) {
		print_num = 7;
	} else if(grade >= 77) {
		print_num = 8;
	} else if(grade >= 73) {
		print_num = 9;
	} else if(grade >= 70) {
		print_num = 10;
	} else if(grade >= 67) {
		print_num = 11;
	} else if(grade >= 63) {
		print_num = 12;
	} else if(grade >= 60) {
		print_num = 13;
	} else if(grade >= 57) {
		print_num = 14;
	} else if(grade >= 53) {
		print_num = 15;
	} else if(grade >= 50) {
		print_num = 16;
	} else if(grade >= 47) {
		print_num = 17;
	} else {
		print_num = 0;
	}

	cout << feedback[print_num];
	
	return 0;
}