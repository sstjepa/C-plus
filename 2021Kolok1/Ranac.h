#pragma once
#include "Predmet.h"
#include <iostream>
#include <fstream>


class Ranac
{
private:
	int N;
	int trenBr;
	Predmet** niz;

public:
	Ranac();
	Ranac(int N);
	~Ranac();

	void dodajPredmet(Predmet* predmet);
	void prikazi(ostream& izlaz);
	double srednjaVr();
	Predmet* najvredniji();


};

