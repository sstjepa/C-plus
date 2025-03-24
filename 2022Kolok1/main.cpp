#include "Paketic.h"
#include "PakHrana.h"
#include "PakIgracka.h"
#include "Sanke.h"

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	Sanke* sanke = new Sanke(10);

	sanke->dodajPaketic(new PakHrana((char*)"Takovksa 46", (char*)"Plav", 10, 1.24, 123.99));
	sanke->dodajPaketic(new PakIgracka((char*)"Sremska 4", (char*)"Crven", 5, 100, 220.46));
	sanke->dodajPaketic(new PakHrana((char*)"Stevana Sremca 50", (char*)"Ljubicast", 4, 120, 12.46));
	sanke->dodajPaketic(new PakIgracka((char*)"Bulevar Zorana Djindjica 17", (char*)"Zut", 19, 32, 512.46));
	sanke->dodajPaketic(new PakHrana((char*)"Dusanova 136A", (char*)"Crn", 1, 99, 250.96));
	sanke->dodajPaketic(new PakIgracka((char*)"Aleksandra Medvedeva 14", (char*)"Plav", 13, 30, 11.46));

	ofstream izlaz("pokloni.txt");
	if (izlaz.good())
	{
		sanke->prikaziSanke(izlaz);
		izlaz.close();
	}

	double SrednjaVr = sanke->SrednjaVr();
	Paketic* vratiNajtezi = sanke->vratiNajtezi();

	cout << "Srednja vr svih paketa: " << SrednjaVr << endl;
	cout << "Najtezi paket: ";
	vratiNajtezi->prikaziAdr(cout);
	cout << endl;


	for (int i = 0; i < 3; i++)
	{
		cout << "Unesi adresu: ";
		char adresa[100];
		cin.getline(adresa, 100);
		sanke->izbaciPaketic(adresa);
	}

	cout << "\nSanke nakon izbacivanja: \n";
	sanke->prikaziSanke(cout);


	delete sanke;
	return 0;
}