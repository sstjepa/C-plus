#include "SalonPutnickaDostavna.h"

SalonPutnickaDostavna::SalonPutnickaDostavna() :SalonPutnicka(), brZapDos(0), brojProdDos(0)
{
	strcpy(tip, "PutnickaDostavna");
}

SalonPutnickaDostavna::SalonPutnickaDostavna(char* naziv, int brZapP, double x, double y, int brojProdP, int brZapD, int brojProdD)
	:SalonPutnicka(naziv, brZapP, x, y, brojProdP)
{
	strcpy(tip, "PutnickaDostavna");
	this->brojProdDos = brojProdD;
	this->brZapDos = brZapD;
}

SalonPutnickaDostavna::~SalonPutnickaDostavna()
{}

double SalonPutnickaDostavna::efikasnost()
{
	double rez;
	rez = ((brojProdDos / brZapDos) + (brojProdPut / brZap)) / 2;
	return rez;
}

void SalonPutnickaDostavna::ispisi(ostream& izlaz)
{
	izlaz << "SALON ZA PUTNICKA I DOSTAVNA VOZILA: "
		<< "Naziv: " << naziv << endl
		<< "Koordinate: " << "(" << x << ", " << y << ")" << endl
		<< "Broj Zaposlenih za Putnicka: " << brZap << endl
		<< "Broj Prodathih Putnickih Vozila: " << brojProdPut << endl
		<< "Broj Zaposlenih za Dostavna: " << brZapDos << endl
		<< "Broj Prodathih Dostavnih Vozila: " << brojProdDos << endl << endl << endl;
}

