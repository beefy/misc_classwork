
#include "Socialite.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void main() {

	/*
		INITIALIZE SOCIALITES
	*/

	Socialite me = Socialite();
	Socialite entertainer = Socialite();
	Socialite political = Socialite();
	Socialite cartoon = Socialite();
	Socialite other = Socialite();

	me.setFirst("Nathaniel");
	me.setLast("Schultz");
	me.setID("1");
	me.setPic("http://image1.masterfile.com/em_w/01/45/87/640-01458710w.jpg");
	me.setWebURL("web_url");
	me.setWebDesc("A student programmer at Drexel University");

	entertainer.setFirst("Justin");
	entertainer.setLast("Timberlake");
	entertainer.setID("2");
	entertainer.setPic("http://ia.media-imdb.com/images/M/MV5BMTUwMjE1MjU2N15BMl5BanBnXkFtZTcwNjk0ODY1NA@@._V1_SY317_CR10,0,214,317_AL_.jpg");
	entertainer.setWebURL("web_url");
	entertainer.setWebDesc("Pop singer and song writer");

	political.setFirst("Edward");
	political.setLast("Snowden");
	political.setID("3");
	political.setPic("http://upload.wikimedia.org/wikipedia/commons/6/60/Edward_Snowden-2.jpg");
	political.setWebURL("web_url");
	political.setWebDesc("Surveillance rights activist");

	cartoon.setFirst("Fry");
	cartoon.setLast("Lock");
	cartoon.setID("4");
	cartoon.setPic("http://vignette4.wikia.nocookie.net/athfwiki/images/e/ef/Frylock-Braces.jpg/revision/latest?cb=20111106023624");
	cartoon.setWebURL("web_url");
	cartoon.setWebDesc("Outerspace superpowered french fry from Aqua Teen Hunger Force");

	other.setFirst("Ron");
	other.setLast("Burgundy");
	other.setID("5");
	other.setPic("http://www.hollywoodreporter.com/sites/default/files/imagecache/news_portrait/2012/05/anchorman_ron_burgundy_a_p.jpg");
	other.setWebURL("web_url");
	other.setWebDesc("News Anchor for Channel 4 News, Santiago");

	/*
		TEST GETTER METHODS
	*/
	cout << other.getFirst() << endl;
	cout << other.getLast() << endl;
	cout << other.getID() << endl;
	cout << other.getPic() << endl;
	cout << other.getWebDesc() << endl;


	/*
		OUTPUT TEXT FILES
	*/
	ofstream fout;
	fout.open("outputSocialites_Me.txt");
	fout << me.toStringText();

	fout.close();
	fout.open("outputSocialites_Entertainer.txt");
	fout << entertainer.toStringText();

	fout.close();
	fout.open("outputSocialites_Political.txt");
	fout << political.toStringText();

	fout.close();
	fout.open("outputSocialites_Cartoon.txt");
	fout << cartoon.toStringText();

	fout.close();
	fout.open("outputSocialites_Other.txt");
	fout << other.toStringText();

	/*
		OUTPUT HTML FILES
	*/
	fout.close();
	fout.open("outputSocialites_Me.html");
	fout << me.toStringHTML();

	fout.close();
	fout.open("outputSocialites_Entertainer.html");
	fout << entertainer.toStringHTML();

	fout.close();
	fout.open("outputSocialites_Political.html");
	fout << political.toStringHTML();

	fout.close();
	fout.open("outputSocialites_Cartoon.html");
	fout << cartoon.toStringHTML();

	fout.close();
	fout.open("outputSocialites_Other.html");
	fout << other.toStringHTML();
}

