#pragma once
#include <iostream>
#include <string>

using namespace std;

class Socialite
{

public:

	//constructors
	Socialite();
	Socialite(Socialite &person);
	Socialite(string cliques, int numCliques);

	//desconstructors
	~Socialite();

	//setters
	void setLast(const string last);
	void setFirst(const string first);
	void setID(const string user_id);
	void setPic(const string pic_url);
	void setWebURL(const string web_url);
	void setWebDesc(const string web_desc);

	//getters
	string getLast();
	string getFirst();
	string getID();
	string getPic();
	string getWebURL();
	string getWebDesc();
	string getCliqueAt(int index);
	int getNumCliques();


	//output
	string toStringText();
	string toStringHTML();

	//other
	void addClique(string in);
	

private:

	string cliques_;
	string last_name;
	string first_name;
	string user_id;
	string pic_url;
	string web_url;
	string web_desc;

	int numCliques_;


};

