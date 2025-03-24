#include "ZlatnaPol.h"
#include "DragoKam.h"
#include "Jabuka.h"
#include "Ranac.h"

#include <iostream>
#include <fstream>
using namespace std;

int main() {

	Ranac* ranac = new Ranac(5);
	char c;

	for (int i = 0; i < 3; i++)
	{
		cout << "z - zlatna poluga, d - drago kamenje, j - jabuka\n";
	opet:cin >> c;
		switch (c)
		{
		case 'z':
		{
			double masa, cistoca;
			cout << "Masa poluge: ";
			cin >> masa;
			cout << "Stepen cistoce: ";
			cin >> cistoca;
			ranac->dodajPredmet(new ZlatnaPol(masa, cistoca));
			cout << "----------------------------------" << endl;
			break;

		}
		case 'd':
		{
			double masa, cistocaD;
			char boja[100];
			int rezovi;
			cout << "Masa poluge: ";
			cin >> masa;
			cout << "Koef cistoce: ";
			cin >> cistocaD;
			cout << "Boja: ";
			cin >> boja;
			cout << "Broj rezova: ";
			cin >> rezovi;

			ranac->dodajPredmet(new DragoKam(masa, cistocaD, boja, rezovi));
			cout << "----------------------------------" << endl;
			break;
		}
		case 'j':
		{
			double masa, ks, kk;
			char boja[100];
			cout << "Masa poluge: ";
			cin >> masa;
			cout << "Koef slatkoce: ";
			cin >> ks;
			cout << "Koef kiselosti: ";
			cin >> kk;
			cout << "Boja: ";
			cin >> boja;

			ranac->dodajPredmet(new Jabuka(masa, ks, kk, boja));
			cout << "----------------------------------" << endl;
			break;
		}
		default:
			goto opet;
		}
	}

	cout << endl << endl;
	ranac->prikazi(cout);
	cout << endl << endl << "Najvredniji po jed mase: \n";
	(ranac->najvredniji())->prikazi(cout);
	cout << endl << endl << "Srednja vrednost: \n" << ranac->srednjaVr() << endl;

	delete ranac;
	return 0;

}