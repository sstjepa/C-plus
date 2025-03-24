#include <iostream>
#include <fstream>
#include "Put.h"
#include "Zemlja.h"
#include "Voda.h"

using namespace std;

int main() {
	const int velicinaPuta = 2018;
	Put put(velicinaPuta);

	ifstream inputFile("podaci.txt");

	for (int i = 0; i < velicinaPuta; ++i) {
		int tip;
		inputFile >> tip;

		Element* el = nullptr;
		if (tip == 1) {
			Zemlja* z = new Zemlja();
			inputFile >> *z;
			el = z;
		}
		else if (tip == 2) {
			Voda* v = new Voda();
			inputFile >> *v;
			el = v;
		}

		put.postavi(i, el);
	}

	inputFile.close();


	cout << put;
	cout << "#########################" << endl;
	cout << endl;

	/*int brojZemlja = 0;
	int sumaNV = 0;*/
	int brojZemlja = 0;
	double sumaNV = 0;

	for (int i = 0; i < velicinaPuta; ++i) {
		if (put[i] && put[i]->vratiTip() == 1) {
			brojZemlja++;
			sumaNV += put[i]->vratiVr();
		}
	}


	put.prikaziBrPoTipu();
	if (brojZemlja > 0) {
		/*double prosecnaNV = static_cast<double>(sumaNV) / brojZemlja;*/
		double prosecnaNV = (sumaNV) / brojZemlja;
		cout << "Prosecna nadmorska visina na putu: " << prosecnaNV << endl;
	}
	else {
		cout << "Nema elemenata tipa Zemlja na putu." << endl;
	}

	return 0;
}