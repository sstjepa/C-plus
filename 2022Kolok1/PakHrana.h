#pragma once
#include "Paketic.h"
using namespace std;

class PakHrana : public Paketic
{
private:
	int brCok;
	double Ukupnatezina;
	double cenaJed;

public:
	PakHrana();
	PakHrana(char* adresa, char* boja, int brCok, double Ukupnatezina, double cenaJed);
	virtual ~PakHrana();

	virtual double VratiTezinu();
	virtual double VratiCenu();
	virtual void prikaziAdr(ostream& izlaz);

};

