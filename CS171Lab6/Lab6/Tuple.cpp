#include <iostream>
#include <string>

using namespace std;


int lastNum = 0;
string tupler(string first, string last, int n) {
		
	//for(int b2 = b; b2 > a; b2--) {
	//	for(int a2 = a; a2 < b; a2++) {
	//		cout << b2 << a2;
	//	}
	//	cout << endl;
	//}

	/*
	aa
	ab
	bb

	*/
	for(int i = 0; i < n; i++) {
		char z = first.at(0)+i;
		return z 
	}

	//if(n == 0) return first;
	//else return last.append(tupler(first, last, n-1));

/*
	for(int x = 0; x < n; x++) {
		for(int y = 0; y < n; y++) {
			for(int z = 0; z < n; z++) {
				char a = first+x;
				char b = first+y;
				char c = first+z;
				cout << a << b << c << endl;
			}
		}s
	}*/
	cout << endl;
	return ' ';
}

//string tupler(char a, char b, int n) {
//	if(n<=1) return "a";
//	else {
//		for(n; n > 1; n++) {
//		return b+tupler(a,b,n-1);
//	}
//}

//int first_n = 0;
//int iter = 0;
//int stack = 0;
//
//void tupler(char a, char b, int n) {
//			
//	//if(n > first_n) first_n = n;
//	//keep doing something while in current tuple (call tupler())
//
//	//change something for next tuple (call tupler())
//
//	//base case (don't call tupler())
//
//	   cout << a;
// 
//	   //if(n > 0 && a > b) tupler(a,b,n-1);
//
//	   //cout << endl;
//
//    //   if(a < b) tupler(a+1,b,first_n);
//
//	/*if( n == 2 && a < b) {
//		int temp_iter = iter;
//		iter = 0;
//		cout << endl;
//		tupler(a+1,b,n+temp_iter);
//	}*/
//
//	if( n > 1 ) {
//		iter++;
//		stack++;
//		tupler(a, b, n-1);
//	}
//
// 	if( n <= 1 && a <= b) {
//		int temp_iter = iter;
//		iter = 0;
//		cout << endl;
//		tupler(a+1, b, n+temp_iter);
//	}
//
//	if( n <= 1 && a >= b) {
//		cout << endl << endl;
//		return;
//	}
//}

int main() {
	lastNum = 3;
	cout << tupler('a','c',3);

	return 0;
}