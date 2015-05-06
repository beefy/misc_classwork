#pragma once
#include <ostream>
#include <vector>

using namespace std;

class Grid
{
public:
	Grid();
	Grid(string mode);

	bool isValidCoords(string coords);
	bool placeNum(int X, int Y, int num);
	bool hasWon();
	void output(ostream &out);

	vector< vector<int> > data;

	vector<int> & operator[](int & index);
};

ostream & operator<<(ostream & out, Grid & G);