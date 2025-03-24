#include <iostream>
#include <fstream>
#include "Niz.h"
#include "Zaba.h"
#include "Roda.h"
using namespace std;

void main() {

	try
	{
		Niz<Roda>* A = new Niz<Roda>(10);
		ifstream ulaz("rode.txt");
		if (ulaz.good())
		{
			float rez;
			A->ucitaj(ulaz);
			rez = A->ukupnaMasa();
			cout << rez << endl;
			A->izbaci(2);
			/*A->izbaci(7);*/
			A->ispisi(cout);
			ulaz.close();
		}
	}
	catch (const char* poruka)
	{
		cout << poruka << endl;
	}

	try
	{
		Niz<Zaba>* B = new Niz<Zaba>(20);
		ifstream ulaz1("zabe.txt");
		if (ulaz1.good())
		{
			float rez1;
			B->ucitaj(ulaz1);
			rez1 = B->ukupnaMasa();
			cout << rez1 << endl;
			/*B->izbaci(-2);*/
			B->ispisi(cout);
			cout << endl;
			B->izbaci(5);
			B->ispisi(cout);
			ulaz1.close();
		}


	}
	catch (const char* poruka)
	{
		cout << poruka << endl;
	}






}