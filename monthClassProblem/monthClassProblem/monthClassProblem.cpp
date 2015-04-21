// monthClassProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void)
{
	int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int month;
	cout<<"Enter a month (number-wise plz): "; 
	cin>>month;
	cout<<"Month is: "<< month << endl;
	cout<<"Days in the month is: "<< month_days[month-1] << endl;

	return 0;
}

