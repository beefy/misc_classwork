#include <iostream>
#include <string>

using namespace std;

int encrypt_1(int letter_num, int wheel_pos) {
	return (7*wheel_pos +(25-letter_num))%26;
}

int decrypt_1(int letter_num, int wheel_pos) {
	return 25 - (letter_num + 7 * (26-wheel_pos))%26;
}

int encrypt_2(int letter_num, int wheel_pos) {
	return (23*wheel_pos + letter_num)%26;
}

int decrypt_2(int letter_num, int wheel_pos) {
	return (letter_num + 23 * (26-wheel_pos))%26;
}

int encrypt_3(int letter_num) {
	if(letter_num < 13) return 2*letter_num + 1;	//find the inverse function
	else return 2*(letter_num-13);
}

int decrypt_3(int letter_num) {
	if(letter_num % 2 != 0) return (letter_num-1)/2;
	else return (letter_num/2)+13;
}

int letter_to_num(char in) {
	return in - 'A';
}

char num_to_letter(int in) {
	return 'A' + in;
}

int main(void) {

	string plain_text;
	string cipher_text;
	int wheel_1_pos;
	int wheel_2_pos;
	char cur_char = ' ';

	cout << "What is the position of wheel 1? ";
	cin >> wheel_1_pos;

	cout << "What is the position of wheel 2? ";
	cin >> wheel_2_pos;

	cout << "Plain text for the encription program: ";
//	cin >> plain_text;

//	cout << endl << "Cipher text for the decryption program: ";
//	cin >> cipher_text;

	cin >> cur_char;

	while (cur_char != '$') {

		if(!(cur_char >= 'A' && cur_char <= 'Z')) {
			cout << "#";
		} else if (cur_char != '$') {
			//translate to number then back to letter
			//cout << num_to_letter(letter_to_num(cur_char));

			//encrypt and then decrypt using the first wheel only
			cout << num_to_letter(decrypt_1(encrypt_1(letter_to_num(cur_char),wheel_1_pos),wheel_1_pos));
			
			//just encrypt using the first wheel only
			//cout << num_to_letter(encrypt_1(letter_to_num(cur_char),wheel_1_pos));

			//encrypt and then decrypt using the second wheel only
			//cout << num_to_letter(decrypt_2(encrypt_2(letter_to_num(cur_char),wheel_2_pos),wheel_2_pos));

			//encrypt and then decrypt using the second and first wheel
			//cout << num_to_letter(decrypt_1(decrypt_2(encrypt_2(encrypt_1(letter_to_num(cur_char),
				//wheel_1_pos),wheel_2_pos),wheel_2_pos),wheel_1_pos));
		
			//encrypt and decrypt only with the third wheel
			//cout << num_to_letter(decrypt_3(encrypt_3(letter_to_num(cur_char))));

			//encrypt and then decrupt using all wheels
			//cout << num_to_letter(decrypt_1(decrypt_2(decrypt_3(encrypt_3(encrypt_2(encrypt_1(letter_to_num(cur_char),
				//wheel_1_pos),wheel_2_pos))),wheel_2_pos),wheel_1_pos));

			//decrypt message
			//cout << num_to_letter(decrypt_1(decrypt_2(decrypt_3(letter_to_num(cur_char)),wheel_2_pos),wheel_1_pos));
		}

		cin >> cur_char;
		wheel_1_pos = (wheel_1_pos + 1) % 26;
	} 

	cout << endl << endl;

	return 0;
}