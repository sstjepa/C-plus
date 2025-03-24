#include "PakHrana.h"

PakHrana::PakHrana() : brCok(0), Ukupnatezina(0), cenaJed(0)
{}

PakHrana::PakHrana(char* adresa, char* boja, int brCok, double Ukupnatezina, double cenaJed) :Paketic(adresa, boja)
{
	this->brCok = brCok;
	this->Ukupnatezina = Ukupnatezina;
	this->cenaJed = cenaJed;
}

PakHrana::~PakHrana()
{
}

double PakHrana::VratiTezinu()
{
	return this->Ukupnatezina;
}

double PakHrana::VratiCenu()
{
	return (this->Ukupnatezina * this->cenaJed);
}

void PakHrana::prikaziAdr(ostream& izlaz)
{
	Paketic::prikaziAdr(izlaz);
	izlaz << brCok << ";" << Ukupnatezina << ";" << cenaJed << " ";
}
