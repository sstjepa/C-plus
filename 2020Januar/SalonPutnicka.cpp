#include "SalonPutnicka.h"

SalonPutnicka::SalonPutnicka() :naziv(nullptr), brZap(0), x(0), y(0), brojProdPut(0)
{
	strcpy(tip, "Putnicka");
}

SalonPutnicka::SalonPutnicka(char* naziv, int brZapP, double x, double y, int brojProdP)
{
	strcpy(tip, "Putnicka");
	this->naziv = new char[strlen(naziv) + 1];
	strcpy(this->naziv, naziv);
	this->brZap = brZapP;
	this->x = x;
	this->y = y;
	this->brojProdPut = brojProdP;
}

SalonPutnicka::~SalonPutnicka()
{
	if (naziv != nullptr)
	{
		delete[] naziv;
	}
}

double SalonPutnicka::efikasnost()
{
	return (double)(brojProdPut / brZap);
}

void SalonPutnicka::ispisi(ostream& izlaz)
{
	izlaz << "SALON ZA PUTNICKA VOZILA: "
		<< "Naziv: " << naziv << endl
		<< "Broj Zaposlenih: " << brZap << endl
		<< "Koordinate: " << "(" << x << ", " << y << ")" << endl
		<< "Broj Prodathih Vozila: " << brojProdPut << endl << endl;
}
