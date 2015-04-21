#include <iostream>
#include <string>

using namespace std;

void blastoff(int i) {
	if(i <= 0) cout << "Blastoff!" << endl << endl;
	else {
		cout << i << " ";
		blastoff(i-1);
	}
}


int main() {
	blastoff(5);
}