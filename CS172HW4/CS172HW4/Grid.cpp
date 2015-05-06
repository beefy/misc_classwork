#include "Grid.h"
#include "Library.h"
#include <ostream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>

void seed_rand(int i) {
	time_t timer;
	time(&timer);
	srand(timer*i);
}

Grid::Grid() {

	cout << "WELCOME TO SUDOKU!!!\n\nAdd a number by typing [Row][Column] [Number]\nEx 'A1 5' puts 5 in the top column and top row\n\n";
	cout << "Enter QUIT to leave like the loser you are.\n\n";
	//ifstream data_file(promptForString("Sudoku Data File (txt): "));
	ifstream data_file("data.txt");

	string cur_line;

	//loop through each row (text line) in file
	while (getline(data_file, cur_line)) {

		//loop through each character in row
		vector<int> cur_row;
		for (int i = 0; i < 9; i++) {
			cur_row.push_back(-1 * (cur_line[i] - '0'));
		}

		//store row
		data.push_back(cur_row);
	}
}

Grid::Grid(string mode) {

	if (mode != "random") return;

	cout << "WELCOME TO SUDOKU!!!\n\nAdd a number by typing [Row][Column] [Number]\nEx 'A1 5' puts 5 in the top column and top row\n\n";
	cout << "Enter QUIT to leave like the loser you are.\n\n";

	int seed_num = 0;

	//make winnable game
	do {

		data.clear();

		seed_num++;
		seed_rand(((rand() + 1) % 42)*seed_num);

		//make random data file
		//loop through column
		for (int i = 0; i < 9; i++) {

			vector<int> cur_row;
			
			//loop through row
			for (int y = 0; y < 9; y++) {
				cur_row.push_back(((int)((rand() % 9) + 1)) + '0');
			}

			//store row
			data.push_back(cur_row);
		} 

		//test random vector filling
		//output(cout);
		//string pause;
		//cin >> pause;

	} while (!hasWon());

	//erase some numbers for user to play
}

//returns true if placed correctly
bool Grid::placeNum(int X, int Y, int num) {
	if ((data[X][Y]) >= 0) {
		data[X][Y] = num + '0';
		return true;
	}
	cout << "\n     Place has been taken\n\n";
	return false;
}

bool Grid::isValidCoords(string coords) {
	if (coords.length() < 4) return false;
	return (coords[0] >= 'A' && coords[0] <= 'I' &&
		coords[1] >= '1' && coords[1] <= '9' &&
		coords[2] == ' ' &&
		coords[3] >= '1' && coords[3] <= '9');
}

bool Grid::hasWon() {

	bool rowsAdd = false;
	bool columnsAdd = false;
	bool boxAdd = false;
	bool rowDuplicates = false;
	bool columnDuplicates = false;
	bool boxDuplicates = false;

	bool numsColumns[9] = { 0 };
	bool numsRows[9] = { 0 };
	bool numsBox[9] = { 0 };

	int columnSum = 0;
	int rowSum = 0;
	int boxSum;

	//loop through each row
	for (int i = 0; i < data.size(); i++) {

		//loop through each column
		for (int y = 0; y < data[i].size(); y++) {

			//cout << "checking: i=" << i << "    y=" << y << "    data col=" << data[y][i] << "    data row=" << data[i][y] << endl << endl;

			//check columns add
			//if (data[y][i] - '0' < 0) columnSum += abs(data[y][i] - '0');
			//else columnSum += data[y][i];

			if (data[i][y] - '0' < 0) {
				//check row add
				rowSum += abs(data[i][y]);
				columnSum += abs(data[y][i]);
				//check column duplicates
				if (numsColumns[abs(data[i][y])-1]) {
					cout << "\nRepeat In Column # 1\n      column number:" << i << "\n      row number:" << y << "     val:" << abs(data[i][y]) <<"\n\n";
					return false;
				} 
				numsColumns[abs(data[i][y]) - 1] = true;
				//numsRows[abs(data[y][i]) - 1] = true;
			}
			else if (data[y][i] - '0' < 0) {
				//check row add
				rowSum += abs(data[i][y]);
				columnSum += abs(data[y][i]);
				//check row duplicates
				if (numsRows[abs(data[y][i])-1]) {
					cout << "\nRepeat In Row # 1\n      column number:" << y << "\n      row number:" << i << "\n\n";
					return false;
				}
				numsRows[abs(data[y][i]) - 1] = true;
				//numsColumns[abs(data[i][y]) - 1] = true;
			}
			else if (data[i][y] - '0' > 0) {
				//check row add
				rowSum += data[i][y] - '0';
				columnSum += data[y][i] - '0';
				//check column duplicates
				if (numsColumns[data[i][y] - 1 - '0']) {
					cout << "\nRepeat In Column # 2\n      column number:" << i << "\n      row number:" << y << "\n";
					return false;
				}
				numsColumns[data[i][y] - '0' - 1] = true;
				//numsRows[data[y][i] - 1 - '0'] = true;
			}
			else if (data[y][i] - '0' > 0) {
				//check row add
				rowSum += data[i][y] - '0';
				columnSum += data[y][i] - '0';
				//check row duplicates
				if (numsRows[data[y][i] - 1 - '0']) {
					cout << "\nRepeat In Row # 2 \n      column number:" << y << "\n      row number:" << i << "\n\n";
					return false;
				}
				numsRows[data[y][i] - 1 - '0'] = true;
				//numsColumns[data[i][y] - 1 - '0'] = true;
			}
		}

		//check column sum
		if (columnSum != 45) {
			cout << "\nColumn added bad # 1\n      column number:" << i << "     sum:" << columnSum << "\n\n";
			return false;
		}
		columnSum = 0;

		//check column duplicates
		for (int i = 0; i < 9; i++) {
			if (!numsColumns[i]) {
				cout << "\nRepeat In Column # 3\n      column number:" << i << "\n\n";
				return false;
			}
		}

		//check row sum
		if (rowSum != 45) {
			cout << "\nRow added bad # 1\n       row number:" << i << "    sum:" << rowSum << "\n\n";
			return false;
		}
		rowSum = 0;

		//check row duplicates
		for (int i = 0; i < 9; i++) {
			if (!numsRows[i]) {
				cout << "\nRepeat In Row # 3\n       row number:" << i << "\n\n";
				return false;
			}
		}

	}

	//loop through each box
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {

			//loop through each element
			for (int c = 0; c < 3; c++) {
				for (int d = 0; d < 3; d++) {

					if (data[a + c][b + d] - '0' < 0) {
						//check box add
						boxSum += abs(data[a + c][b + d] - '0');
						//check box duplicates
						if (numsBox[abs(data[a + c][b + d] - '0') - 1]) {
							cout << "\nRepeat In Box\n      (box) column number:" << a+c << "\n      (box) row number:" << b+d << "\n\n";
							return false;
						}
						numsBox[abs(data[a + c][b + d] - '0') - 1] = true;
					}
					else {
						//check box add
						boxSum += data[a + c][b + d];
						//check box duplicates
						if (numsBox[data[a + c][b + d] - 1 - '0']) {
							cout << "\nRepeat In Box\n      (box) column number:" << a + c << "\n      (box) row number:" << b + d << "\n\n";
							return false;
						}
						numsBox[data[a + c][b + d] - 1] = true;
					}
				}
			}

			//check box add
			if (boxSum != 45) {
				cout << "\nBox Added Bad\n      (box) column number:" << a << "\n      (box) row number:" << b << "\n";
				return false;
			}

			//check box duplicates
			for (int i = 0; i < 9; i++) {
				if (!numsBox[i]) {
					cout << "\nRepeat In Box\n      (box) column number:" << a << "\n      (box) row number:" << b << "\n";
					return false;
				}
			}
		}
	}

	return true;
}

void Grid::output(ostream &out) {

	vector< vector<string> > outData(9, vector<string>(9));
	for (int i = 0; i < outData.size(); i++) {
		for (int y = 0; y < outData[i].size(); y++){
			if ((data[i][y]) == 0) outData[i][y] = "_";
			else if (data[i][y] - '0' < 0) outData[i][y] = abs(data[i][y] - '0');
			else outData[i][y] = data[i][y];
		}
	}

	out << "     1 2 3   4 5 6   7 8 9\n";
	out << "   +=======================+\n";
	out << ("A  | " + outData[0][0] + " " + outData[0][1] + " " + outData[0][2] + " | " + 
		outData[0][3] + " " + outData[0][4] + " " + outData[0][5] + " | " +
		outData[0][6] + " " + outData[0][7] + " " + outData[0][8] + " |\n").c_str();
	out << ("B  | " + outData[1][0] + " " + outData[1][1] + " " + outData[1][2] + " | " + 
		outData[1][3] + " " + outData[1][4] + " " + outData[1][5] + " | " +
		outData[1][6] + " " + outData[1][7] + " " + outData[1][8] + " |\n").c_str();
	out << ("C  | " + outData[2][0] + " " + outData[2][1] + " " + outData[2][2] + " | " + 
		outData[2][3] + " " + outData[2][4] + " " + outData[2][5] + " | " +
		outData[2][6] + " " + outData[2][7] + " " + outData[2][8] + " |\n").c_str();
	out << "   +-----------------------+\n";
	out << ("D  | " + outData[3][0] + " " + outData[3][1] + " " + outData[3][2] + " | " + 
		outData[3][3] + " " + outData[3][4] + " " + outData[3][5] + " | " +
		outData[3][6] + " " + outData[3][7] + " " + outData[3][8] + " |\n").c_str();
	out << ("E  | " + outData[4][0] + " " + outData[4][1] + " " + outData[4][2] + " | " + 
		outData[4][3] + " " + outData[4][4] + " " + outData[4][5] + " | " +
		outData[4][6] + " " + outData[4][7] + " " + outData[4][8] + " |\n").c_str();
	out << ("F  | " + outData[5][0] + " " + outData[5][1] + " " + outData[5][2] + " | " + 
		outData[5][3] + " " + outData[5][4] + " " + outData[5][5] + " | " +
		outData[5][6] + " " + outData[5][7] + " " + outData[5][8] + " |\n").c_str();
	out << "   +-----------------------+\n";
	out << ("G  | " + outData[6][0] + " " + outData[6][1] + " " + outData[6][2] + " | " + 
		outData[6][3] + " " + outData[6][4] + " " + outData[6][5] + " | " +
		outData[6][6] + " " + outData[6][7] + " " + outData[6][8] + " |\n").c_str();
	out << ("H  | " + outData[7][0] + " " + outData[7][1] + " " + outData[7][2] + " | " + 
		outData[7][3] + " " + outData[7][4] + " " + outData[7][5] + " | " +
		outData[7][6] + " " + outData[7][7] + " " + outData[7][8] + " |\n").c_str();
	out << ("I  | " + outData[8][0] + " " + outData[8][1] + " " + outData[8][2] + " | " + 
		outData[8][3] + " " + outData[8][4] + " " + outData[8][5] + " | " +
		outData[8][6] + " " + outData[8][7] + " " + outData[8][8] + " |\n").c_str();
	out << "   +=======================+\n\n";
}

vector<int> & Grid::operator[](int & index) {
	return data[index];
}

ostream & operator<<(ostream & out, Grid & G)
{
	G.output(out);
	return out;
}