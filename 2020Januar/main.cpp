#include "SalonPutnicka.h"
#include "SalonPutnickaDostavna.h"
#include "Distributer.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	Distributer* distributer = new Distributer(10);

	SalonPutnicka* s1 = new SalonPutnicka((char*)"Naziv1", 3, 2.1, 3.1, 15);
	SalonPutnicka* s2 = new SalonPutnicka((char*)"Naziv2", 4, 2.2, 3.2, 16);
	SalonPutnicka* s3 = new SalonPutnickaDostavna((char*)"Naziv1", 3, 2.1, 3.1, 15, 4, 81);
	SalonPutnicka* s4 = new SalonPutnickaDostavna((char*)"Naziv4", 6, 2.4, 3.4, 18, 7, 92);

	distributer->dodaj(s1);
	distributer->dodaj(s2);
	distributer->dodaj(s3);
	distributer->dodaj(s4);
	distributer->prikazi(cout);
	cout << "#########################################" << endl;

	distributer->uvecaj(1, (char*)"Putnicka", 3);
	distributer->prikazi(cout);

	distributer->uvecaj(3, (char*)"PutnickaDostavna", 6);
	distributer->prikazi(cout);

	distributer->izbaci(0);
	distributer->prikazi(cout);

	cout << "Broj objekata koji imajju vise zap od granice: " << distributer->veciBrZap(4) << endl;
	cout << "Ukupan broj prodatih vozila: " << distributer->brojProd() << endl;
	cout << "Prosecna Efikasnost: " << distributer->prosecnaEfik() << endl;

	delete distributer;
	return 0;
}