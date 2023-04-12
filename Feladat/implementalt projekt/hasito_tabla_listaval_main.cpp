#include <iostream>
#include "hasito_tabla_listaval.h"
#include <string>
#include <fstream>

using namespace std;

void beolvas(vector<char>& szo, HasitoTablaListaval<char, int>& tabla) {
	
	ifstream fin;
	fin.open("bemenet.txt");

	int meret = 0;

	while (!fin.eof()) {
		
		szo.resize(meret + 1);
		fin >> szo[meret];
		meret++;
	}
	
	tabla.BeallitMeret(meret - 1);

	szo.resize(szo.size() - 1);

	for (int i = 0; i < szo.size(); i++) {

		tabla.Beszur(szo[i], i);
	}
	fin.close();
}

void bevezeto() {
	
	cout << "Jatekszabaly:" << endl;
	cout << "Az akasztofa jatek egy szokitalalos kviz magyar szavakkal." << endl;
	cout << "A jatek lenyege, hogy betuk tippelesevel kell megfejteni, hogy melyik szora gondolt a jatekos tarsunk. (Ez esetben a szamitogep.)" << endl;
	cout << "A feladvanyrol csak annyit tudunk, hogy hany betubol all, melyek helyet vizszintes vonalakkal jelolunk." << endl;
	cout << "Tippeljunk egy betut es ha nem szerepel a szoban, hibanak szamit, amit egy akasztofa reszletekben torteno rajzolasaval szimbolizalunk." << endl;
	cout << "Ha elkeszult az akasztofa a palcika emberrel, nincs tobb lehetoseged probalkozni es ekkor megjelenik a szo osszes hianyzo betuje, vagyis a megfejtes." << endl;
	cout << "A jatekot gyerekek es felnottek egyarant jatszhatjak, mivel gyarapitja ismereteinket, fejleszti a szokincset es tornaztatja az agyat." << endl;
	cout << "Kellemes szorakozast a jatekhoz!" << endl;
}

void hiba(int hibakSzama) {
	
	if (hibakSzama == 1) {
		
		cout << "_________" << endl;
	}
	else if (hibakSzama == 2) {
		
		cout << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|_________" << endl;
	}
	else if (hibakSzama == 3) {
		
		cout << "________" << endl << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|_________" << endl;
	}
	else if (hibakSzama == 4) {
		
		cout << "________" << endl << "| /" << endl << "|/" << endl << "|" << endl << "|" << endl << "|" << endl << "|_________" << endl;
	}
	else if (hibakSzama == 5) {
		
		cout << "________" << endl << "| /    |" << endl << "|/" << endl << "|" << endl << "|" << endl << "|" << endl << "|_________" << endl;
	}
	else if (hibakSzama == 6) {

		cout << "________" << endl << "| /    |" << endl << "|/     O" << endl << "|" << endl << "|" << endl << "|" << endl << "|_________" << endl;
	}
	else if (hibakSzama == 7) {

		cout << "________" << endl << "| /    |" << endl << "|/     O" << endl << "|      |" << endl << "|" << endl << "|" << endl << "|_________" << endl;
	}
	else if (hibakSzama == 8) {

		cout << "________" << endl << "| /    |" << endl << "|/     O" << endl << "|     /|" << endl << "|" << endl << "|" << endl << "|_________" << endl;
	}
	else if (hibakSzama == 9) {

		cout << "________" << endl << "| /    |" << endl << "|/     O" << endl << "|     /|\\" << endl << "|" << endl << "|" << endl << "|_________" << endl;
	}
	else if (hibakSzama == 10) {

		cout << "________" << endl << "| /    |" << endl << "|/     O" << endl << "|     /|\\" << endl << "|     /" << endl << "|" << endl << "|_________" << endl;
	}
	else if (hibakSzama == 11) {

		cout << "________" << endl << "| /    |" << endl << "|/     O" << endl << "|     /|\\" << endl << "|     / \\" << endl << "|" << endl << "|_________" << endl;
	}
}

void jatek(vector<char>& szo, HasitoTablaListaval<char, int>& tabla) {
	
	bevezeto();
	cout << endl;

	int hibakSzama = 0;
	vector<char> talalgatas;
	talalgatas.resize(szo.size(), '-');
	bool kitalalta = false;

	cout << "A kitalalando szo " << szo.size() << " betubol all." << endl;

	while (!kitalalta) {

		cout << endl << "A megfejtas allasa: ";
		for (int i = 0; i < talalgatas.size(); i++) {

			cout << talalgatas[i];
		}
		cout << endl;

		char c;
		cout << "Tippelj egy betut!" << endl;
		cout << "A betu: ";
		cin >> c;

		vector<int> k = tabla.Keres(c);

		if (k.size() != 0) {

			cout << "Van \"" << c << "\" betu a szoban!" << endl;

			for (int i = 0; i < k.size(); i++) {

				talalgatas[k[i]] = c;
			}
		}
		else {
			
			hibakSzama++;
			cout << "Nincs \"" << c <<"\" betu a szoban!" << endl;
		}

		//cout << endl;
		hiba(hibakSzama);
		//cout << endl;

		if (talalgatas == szo) {

			cout << "Sikeres megfejtes!" << endl;
			for (int i = 0; i < szo.size(); i++) {

				cout << szo[i];
			}
			cout << endl;
			kitalalta = true;
		}

		if (hibakSzama == 11) {

			cout << "Ez most sajnos nem sikerult!" << endl;
			cout << "A megfejtes: ";
			for (int i = 0; i < szo.size(); i++) {

				cout << szo[i];
			}
			cout << endl;
			kitalalta = true;
		}
	}
}

int main() {

	vector<char> szo;
	HasitoTablaListaval<char, int> tabla;

	beolvas(szo, tabla);

	jatek(szo, tabla);
	
	return 0;
}