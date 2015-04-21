
#include "Socialite.h"

#include <iostream>
#include <string>
#include <fstream>
#include "library.h"

using namespace std;

void main() {

	/*
		INITIALIZE SOCIALITES
	*/
	Socialite socialites[100];
	int cur_socialite_num = 0;

	ifstream fin;
	fin.open("cshw2test.txt");

	if (!fin.good()) {
		cout << "ERROR: file not good";
		return;
	}

	//loop for each socialite
	while (!fin.eof()) {

		string cur_user_id;
		string cur_first_name;
		string cur_last_name;
		string cur_pic_url;
		string cur_web_url;
		string cur_web_desc;
		string cur_cliques;
		int cur_cliques_num = 0;

		getline(fin, cur_user_id);

		if (cur_user_id == "") return;

		getline(fin, cur_first_name);
		getline(fin, cur_last_name);
		getline(fin, cur_pic_url);
		getline(fin, cur_web_url);
		getline(fin, cur_web_desc);


		string cur_clique;
		getline(fin, cur_clique);

		//loop for each clique
		while (cur_clique != "$$$$") {
			cur_cliques += cur_clique + ";";
			cur_cliques_num++;
			getline(fin, cur_clique);

			cout << "          clique entered" << endl;
		}

		//initialize current socialite
		socialites[cur_socialite_num] = Socialite(cur_cliques, cur_cliques_num);
		socialites[cur_socialite_num].setFirst(cur_first_name);
		socialites[cur_socialite_num].setLast(cur_last_name);
		socialites[cur_socialite_num].setID(cur_user_id);
		socialites[cur_socialite_num].setPic(cur_pic_url);
		socialites[cur_socialite_num].setWebURL(cur_web_url);
		socialites[cur_socialite_num].setWebDesc(cur_web_desc);

		//output current socialite at text
		ofstream fout;
		fout.open(cur_first_name + "_" + cur_user_id + ".txt");
		fout << socialites[cur_socialite_num].toStringText();

		//output current socialite at html
		fout.close();
		fout.open(cur_first_name + "_" + cur_user_id + ".html");
		fout << socialites[cur_socialite_num].toStringHTML();

		cout << "socialite entered" << endl;
	}


}

