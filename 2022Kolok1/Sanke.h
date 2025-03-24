#pragma once
#include "Paketic.h"
#include <fstream>
#include <iostream>
using namespace std;

class Sanke
{
private:
	Paketic** niz;
	int top;
	int max;

public:
	Sanke();
	Sanke(int max);
	~Sanke();

	void dodajPaketic(Paketic* paket);
	void izbaciPaketic(const char* adresa);
	void prikaziSanke(ostream& izlaz);

	double SrednjaVr();
	Paketic* vratiNajtezi();

};

