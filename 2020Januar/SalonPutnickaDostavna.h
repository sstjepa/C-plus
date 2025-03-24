#pragma once
#include "SalonPutnicka.h"
#include <iostream>
#include <fstream>
using namespace std;
class SalonPutnickaDostavna :
	public SalonPutnicka
{
private:
	int brZapDos;
	int brojProdDos;

public:
	SalonPutnickaDostavna();
	SalonPutnickaDostavna(char* naziv, int brZapP, double x, double y, int brojProdP, int brZapD, int brojProdD);
	virtual ~SalonPutnickaDostavna();

	virtual int vratiBrZap() { return brZapDos; }
	virtual int vratiBrProd() { return brojProdPut + brojProdDos; };
	virtual int uvecaj(int broj) { return brojProdDos += broj; };

	virtual double efikasnost();
	virtual void ispisi(ostream& izlaz);
};

