#include "Socialite.h"

#include <iostream>
#include <string>

using namespace std;


/*
	Constructor
*/

Socialite::Socialite(){

	Socialite::last_name = "";
	Socialite::first_name = "";
	Socialite::user_id = "";
	Socialite::pic_url = "";
	Socialite::web_url = "";
	Socialite::web_desc = "";

}

/*
	SETTERS
*/

void Socialite::setLast(string last) {
	Socialite::last_name = last;
}

void Socialite::setFirst(const string first) {
	Socialite::first_name = first;
}

void Socialite::setID(const string user_id) {
	Socialite::user_id = user_id;
}

void Socialite::setPic(const string pic_url) {
	Socialite::pic_url = pic_url;
}

void Socialite::setWebURL(const string web_url) {
	Socialite::web_url = web_url;
}

void Socialite::setWebDesc(const string web_desc) {
	Socialite::web_desc = web_desc;
}

/*
	GETTERS
*/

string Socialite::getLast() {
	return Socialite::last_name;
}

string Socialite::getFirst() {
	return Socialite::first_name;
}

string Socialite::getID() {
	return Socialite::user_id;
}

string Socialite::getPic() {
	return Socialite::pic_url;
}

string Socialite::getWebURL() {
	return Socialite::web_url;
}

string Socialite::getWebDesc() {
	return Socialite::web_desc;
}


/*
	OUTPUT
*/

string Socialite::toStringText() {
	string output;
	output += "Name: " + Socialite::first_name + " " + Socialite::last_name;
	output += "\nUserID: " + Socialite::user_id;
	output += "\nDescription: " + Socialite::web_desc;

	return output;
}

string Socialite::toStringHTML() {
	string output;
	output += "<img src= '" + Socialite::pic_url + "'</img>";
	output += "<br />";
	output += "<p>Name: " + Socialite::first_name + " " + Socialite::last_name + "</p>";
	output += "<br />";
	output += "<p>UserID: " + Socialite::user_id + "</p>";
	output += "<br />";
	output += "<p>Description: " + Socialite::web_desc+ "</p>";

	return output;
}

