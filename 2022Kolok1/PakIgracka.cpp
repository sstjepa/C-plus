#include "PakIgracka.h"

PakIgracka::PakIgracka() :brIgr(0), cena(0), tezina(0)
{}

PakIgracka::PakIgracka(char* adresa, char* boja, int brIgr, double tezina, double cena) :Paketic(adresa, boja)
{
	this->brIgr = brIgr;
	this->tezina = tezina;
	this->cena = cena;
}

PakIgracka::~PakIgracka()
{
}

double PakIgracka::VratiTezinu()
{
	return this->tezina;
}

double PakIgracka::VratiCenu()
{
	return (this->brIgr * this->cena);
}

void PakIgracka::prikaziAdr(ostream& izlaz)
{
	Paketic::prikaziAdr(izlaz);
	izlaz << brIgr << ";" << tezina << ";" << cena << " ";
}
