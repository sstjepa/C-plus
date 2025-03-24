#include <iostream>
#include <fstream>
#include "Figura.h"
#include "Kvadrat.h"
#include "Pravougaonik.h"
#include "Kolekcija.h"
using namespace std;


int main() {

	Kolekcija* kolekcija = new Kolekcija(3);

	kolekcija->dodaj(new Kvadrat(2.5, 5.3, 3));
	kolekcija->dodaj(new Pravougaonik(2.5, 5.3, 2, 3));
	kolekcija->dodaj(new Kvadrat(2.5, 5.3, 5));
	kolekcija->dodaj(new Pravougaonik(2.5, 5.3, 3, 4));

	ofstream izlaz("figure.txt");
	if (izlaz.good())
	{
		kolekcija->izlaz(izlaz);
		izlaz.close();
	}

	kolekcija->sortObim();
	ofstream izlaz1("sortirano.txt");
	if (izlaz1.good())
	{
		kolekcija->izlaz(izlaz1);
		izlaz1.close();
	}

	kolekcija->vratiObim(cout);
	cout << endl;
	kolekcija->vratiPov(cout);


	delete kolekcija;
	return 0;
}