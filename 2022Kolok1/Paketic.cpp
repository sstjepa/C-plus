#include "Paketic.h"
#include <cstring>

Paketic::Paketic() : adresa(nullptr), boja(nullptr)
{}

Paketic::Paketic(char* adresa, char* boja)
{
	this->adresa = new char[strlen(adresa) + 1];
	strcpy(this->adresa, adresa);

	this->boja = new char[strlen(boja) + 1];
	strcpy(this->boja, boja);
}

Paketic::~Paketic()
{
	delete adresa;
	delete boja;
}

void Paketic::prikaziAdr(ostream& izlaz)
{
	izlaz << adresa << ";" << boja << " ";
}
