#include <iostream>
#include <fstream>
#include "Sport.h"
#include "Skola.h"
using namespace std;

int main() {

	try {
		Skola<Sport>* skolaSporta = new Skola<Sport>(10);

		ifstream ulaz("sport.txt");
		if (!ulaz.good()) return 0;

		ulaz >> *skolaSporta;
		ulaz.close();
		skolaSporta->Otkazi(0);
		skolaSporta->Otkazi(2);
		skolaSporta->IzvestajProsek("izvestajProsek.txt");
		skolaSporta->IzvestajNajvrednija("izvestajNajvrednija.txt");
		skolaSporta->IzvestajNajmanjeVredna("izvestajNajmanjeVredna.txt");
		skolaSporta->StampajNaEkran();
		delete skolaSporta;
	}
	catch (const char* s) {
		cout << s << endl;
	}

	try {
		Skola<int>* skolaUmetnosti = new Skola<int>(10);
		cout << "Dodajte 5 aktivnosti za skolu umetnosti:\n";
		int x;
		for (int i = 0; i < 5; ++i)
		{
			cin >> x;
			skolaUmetnosti->Dodaj(x);
		}
		cout << endl;

		skolaUmetnosti->Otkazi(0);
		skolaUmetnosti->Otkazi(2);
		skolaUmetnosti->IzvestajProsek("izvestajProsek_umetnost.txt");
		skolaUmetnosti->IzvestajNajvrednija("izvestajNajvrednija_umetnost.txt");
		skolaUmetnosti->IzvestajNajmanjeVredna("izvestajNajmanjeVredna_umetnost.txt");
		skolaUmetnosti->StampajNaEkran();

		delete skolaUmetnosti;
	}
	catch (const char* s) {
		cout << s << endl;
	}

	return 0;
}