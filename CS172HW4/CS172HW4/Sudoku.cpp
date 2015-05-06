#include "Grid.h"
#include <iostream>
#include <istream>
#include <string>

using namespace std;

void main() {

	Grid game = Grid();

	bool winner = false;
	string cur_input = "";

	game.output(cout);
	getline(cin, cur_input);

	while (cur_input != "QUIT" && !winner) {


		if (game.isValidCoords(cur_input)) {
			game.placeNum(cur_input[0]-'A', cur_input[1]-'1', cur_input[3]-'0');
		}
		else {
			cout << "\n     Sorry, I couldn't read those coordinates\n\n";
		}

		if (game.hasWon()) {
			winner = true;
		}

		game.output(cout);

		getline(cin, cur_input);
	}

	if (winner) {
		cout << "\n\n     CONGRADULATIONS!!\n     YOU WIN!\n\n";
		return;
	}

	cout << "\n\n     HAHA YOU LOSE.\n\n\n";
}