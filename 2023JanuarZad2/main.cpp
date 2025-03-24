#include <iostream>
#include <fstream>
#include "Kolekcija.h"
#include "IzlozbeniPosetioci.h"
using namespace std;

void main() {
	{
		Kolekcija<int> k(20);
		k.dodaj(11);
		k.dodaj(2);
		k.dodaj(34);
		k.dodaj(23);
		k.dodaj(11);
		k.dodaj(44);

		int dan1, dan2;
		k.minZarada(&dan1, &dan2);
		cout << dan1 << ",  " << dan2 << endl;

		cout << k.ukupanBrPosetioca(2, 4) << endl;
		k.obrisi(2);
		k.sacuvaj("interaktivni.txt");

		Kolekcija<int> k1(20);
		k1.ucitaj("interaktivni.txt");
		k1.ispisiNaEkran();
	}
	{
		Kolekcija<IzlozbeniPosetioci> kol(20);
		kol.dodaj(IzlozbeniPosetioci(1, 2, 3));
		kol.dodaj(IzlozbeniPosetioci(4, 2, 10));
		kol.dodaj(IzlozbeniPosetioci(1, 2, 0));
		kol.dodaj(IzlozbeniPosetioci(3, 1, 0));
		kol.dodaj(IzlozbeniPosetioci(4, 4, 4));
		kol.dodaj(IzlozbeniPosetioci(0, 0, 0));
		kol.dodaj(IzlozbeniPosetioci(1, 12, 0));

		int dan1, dan2;
		kol.minZarada(&dan1, &dan2);
		cout << dan1 << ",  " << dan2 << endl;
		cout << kol.ukupanBrPosetioca(2, 4) << endl;

		kol.obrisi(2);
		kol.sacuvaj("izlozbeni.txt");

		Kolekcija<IzlozbeniPosetioci> kol1(20);
		kol1.ucitaj("izlozbeni.txt");
		kol1.ispisiNaEkran();
	}



}