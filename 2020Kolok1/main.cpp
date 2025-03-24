#include "Cvet.h"
#include "Ruza.h"
#include "Lala.h"
#include "Buket.h"

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	Buket* buket = new Buket(15);

	buket->ucitaj("ulaz.txt");
	buket->sortitajPoCeni();
	buket->ispisi(cout);

	Buket* b1 = new Buket(10);
	Buket* b2 = new Buket(10);
	buket->podeli(b1, b2);


	ofstream buket1("buket1.txt");
	b1->ispisi(buket1);
	buket1.close();

	ofstream buket2("buket2.txt");
	b2->ispisi(buket2);
	buket2.close();

	delete buket;
	delete b1;
	delete b2;

	return 0;
}