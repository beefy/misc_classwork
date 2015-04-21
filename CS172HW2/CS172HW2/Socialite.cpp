#include "Socialite.h"

#include <iostream>
#include <string>

using namespace std;


/*
	Constructors
*/

Socialite::Socialite(){

	Socialite::last_name = "";
	Socialite::first_name = "";
	Socialite::user_id = "";
	Socialite::pic_url = "";
	Socialite::web_url = "";
	Socialite::web_desc = "";
	Socialite::numCliques_ = 0;
	Socialite::cliques_ = "";

}

Socialite::Socialite(string cliques, int numCliques){

	Socialite::last_name = "";
	Socialite::first_name = "";
	Socialite::user_id = "";
	Socialite::pic_url = "";
	Socialite::web_url = "";
	Socialite::web_desc = "";
	Socialite::numCliques_ = numCliques;
	Socialite::cliques_ = cliques;

}

Socialite::Socialite(Socialite &person) {

	Socialite::last_name = person.last_name;
	Socialite::first_name = person.first_name;
	Socialite::pic_url = person.pic_url;
	Socialite::user_id = person.user_id;
	Socialite::web_url = person.web_url;
	Socialite::web_desc = person.web_desc;
	Socialite::numCliques_ = person.numCliques_;
	Socialite::cliques_ = person.cliques_;
}

/*
	Desconstructors
*/
Socialite::~Socialite()
{

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

string Socialite::getCliqueAt(int index) {
	
	if (index < 0 || index > numCliques_) return "ERROR: no such index";

	string cur_socialite;
	string temp_cliques = Socialite::cliques_;

	for (int i = 0; i < index+1; i++) {
		cur_socialite = temp_cliques.substr(0, temp_cliques.find(';'));
		temp_cliques = temp_cliques.substr(temp_cliques.find(';')+1, temp_cliques.length());
	}

	return cur_socialite;
}

int Socialite::getNumCliques() {

	//return count(Socialite::cliques_.begin(), Socialite::cliques_.end(), ';');
	return numCliques_;
}


/*
	OUTPUT
*/

string Socialite::toStringText() {
	
	string output;
	
	output =  "Socialite: " + Socialite::first_name + " " + Socialite::last_name;
	output += "\nUserid: " + Socialite::user_id;
	output += "\nPicture: " + Socialite::pic_url;
	output += "\nShared Link: " + Socialite::web_url;
	output += "\nDescription : " + Socialite::web_desc;
	output += "\nCliques : " ;
	
	for (int i = 0; i < Socialite::numCliques_; i++) {
		output += "\n" + Socialite::getCliqueAt(i);
	} 
		
	return output;
}

string Socialite::toStringHTML() {

	string output;

	output =  "<html>";
	output += "<head>";
	output += "<title>" + first_name + "'s Socialite Page</title>";
	output += "</head>";
	output += "<body>";
	output += "<img SRC='" + pic_url + "' ALT='socialite picture' align='RIGHT' />";
	output += "<h1>" + web_desc + "</h1>";
	output += "<h2>" + first_name + " " + last_name + "</h2>";
	output += "<hr />";
	output += "<p>" + first_name + " " + last_name + " wants to share <a HREF='" + web_url + "' target=_blank>";
	output += web_desc + "</a> with you:<br /></p>";
	//"http://xkcd.com/156/</p>";
	output += "<hr />";
	output += "<p><i>Cliques:</i></p>";
	output += "<ul>";
	  for (int i = 0; i < numCliques_; i++) {
		  output += "<li>" + getCliqueAt(i) + "</li>";
	  }
	  output += "</ul>";
	  output += "</body>";
	output += "</html>";

	return output;
}

/*
	OTHER
*/

void Socialite::addClique(string in) {

	Socialite::cliques_ += in + ";";
	Socialite::numCliques_++;

}

