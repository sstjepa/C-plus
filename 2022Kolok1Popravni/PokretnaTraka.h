#pragma once
#include <iostream>
#include <fstream>
#include "Proizvod.h"
using namespace std;
class PokretnaTraka
{
private:
	Proizvod** traka;
	int top;
	int max;

public:
	PokretnaTraka();
	PokretnaTraka(int max);
	~PokretnaTraka();

	void dodaj(Proizvod* proizvod);
	void povecaj(int kolicina);
	void izbaci();

	void zameniDef(int pozicija, Proizvod* proizvod);
	int trenBrDef();
	int trenBrPraz();

	virtual void prikazi(ostream& izlaz);






};

