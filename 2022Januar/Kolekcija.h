#pragma once
#include "Figura.h"
#include <iostream>
#include <fstream>

using namespace std;

class Kolekcija
{
private:
	Figura** niz;
	int max;
	int top;

public:
	Kolekcija();
	Kolekcija(int max);
	~Kolekcija();

	void dodaj(Figura* figura);
	void povecaj();
	void vratiPov(ostream& izlaz);
	void vratiObim(ostream& izlaz);
	void sortObim();

	void izlaz(ostream& izlaz);


};

