#pragma once
#include "SalonPutnicka.h"
#include "SalonPutnickaDostavna.h"
#include <iostream>
#include <fstream>
using namespace std;
class Distributer
{
private:
	SalonPutnicka** niz;
	int top;
	int max;

public:
	Distributer();
	Distributer(int max);
	~Distributer();

	void dodaj(SalonPutnicka* salon);
	void izbaci(int redniBr);
	void uvecaj(int redniBr, const char* tip, int za);
	int veciBrZap(int granica);
	SalonPutnicka* najblizi(double x, double y);
	int brojProd();
	double prosecnaEfik();
	void prikazi(ostream& izlaz);


};

