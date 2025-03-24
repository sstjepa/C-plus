#include "Sport.h"
void Sport::kreirajObjekat(int brIgraca, int brRezervnih, const char* obuca, float budzet, float koef)
{
	if (brIgraca > 20)
	{
		throw"Nemoguce dodati";
	}
	this->brIgraca = brIgraca;

	if (brRezervnih > 10)
	{
		throw"Nemoguce dodati";
	}
	this->brRezervnih = brRezervnih;

	this->obuca = new char[strlen(obuca) + 1];
	strcpy(this->obuca, obuca);

	if (koef < 0 || koef>1.0)
	{
		throw"Nemoguce dodati";
	}
	this->koef = koef;

	if (budzet > 50000)
	{
		throw"Nemoguce dodati";
	}
	this->budzet = budzet;

	this->vrednost = (this->brIgraca + this->brRezervnih) * this->budzet * this->koef;
}

Sport::Sport() :brIgraca(0), brRezervnih(0), obuca(nullptr), budzet(0.0), koef(0.0), vrednost(0)
{}

Sport::Sport(int brIgraca, int brRezervnih, const char* obuca, float budzet, float koef)
{
	kreirajObjekat(brIgraca, brRezervnih, obuca, budzet, koef);
}

Sport::~Sport()
{
	if (obuca != nullptr)
	{
		delete[] obuca;
	}
}

Sport::Sport(const Sport& s)
{
	if (obuca != nullptr)
	{
		delete[] obuca;
	}
	kreirajObjekat(s.brIgraca, s.brRezervnih, s.obuca, s.budzet, s.koef);
}

Sport& Sport::operator=(const Sport& s)
{
	if (this != &s)
	{
		if (obuca != nullptr)
		{
			delete obuca;
		}
		kreirajObjekat(s.brIgraca, s.brRezervnih, s.obuca, s.budzet, s.koef);
	}
	return *this;
}

float Sport::operator+(float x)
{
	return (vrednost + x);
}

bool Sport::operator>(Sport& s)
{
	return (this->vrednost > s.vrednost);
}

istream& operator>>(istream& ulaz, Sport& s)
{
	int br;
	int brr;
	char o[50];
	float b;
	float k;
	ulaz >> br >> brr >> o >> b >> k;
	s.kreirajObjekat(br, brr, o, b, k);
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Sport& s)
{
	izlaz << s.brIgraca << " " << s.brRezervnih << " " << s.obuca << " " << s.budzet << " " << s.koef;
	return izlaz;
}
