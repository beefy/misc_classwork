
#include <iostream>
#include <string>
#include "C:\Users\Nathaniel\Desktop\English_length.h"
using namespace std;

bool English_length::isLessThan(const English_length &L) {
	if (English_length::yards_ * 36 + English_length::feet_ * 12 + English_length::inches_ < 
		L.yards_ * 36 + L.feet_*12 + L.inches_) return true;
	else return false;
}

English_length min(English_length len1, English_length len2) {
	if (len1.isLessThan(len2)) return len1; 
	else return len2;
}