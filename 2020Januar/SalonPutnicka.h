#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class SalonPutnicka
{
protected:
	char tip[50];
	char* naziv;
	int brZap;
	double x, y;
	int brojProdPut;

public:
	SalonPutnicka();
	SalonPutnicka(char* naziv, int brZapP, double x, double y, int brojProdP);
	virtual ~SalonPutnicka();

	double getX() { return x; };
	double getY() { return y; };

	virtual int vratiBrZap() { return brZap; };
	char* getTip() { return tip; };
	virtual int vratiBrProd() { return brojProdPut; };
	virtual int uvecaj(int broj) { return brojProdPut += broj; };

	virtual double efikasnost();
	virtual void ispisi(ostream& izlaz);


};

