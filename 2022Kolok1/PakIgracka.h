#pragma once
#include "Paketic.h"
using namespace std;

class PakIgracka : public Paketic
{
private:
	int brIgr;
	double tezina;
	double cena;

public:
	PakIgracka();
	PakIgracka(char* adresa, char* boja, int brIgr, double tezina, double cena);
	virtual ~PakIgracka();

	virtual double VratiTezinu();
	virtual double VratiCenu();
	virtual void prikaziAdr(ostream& izlaz);

};

