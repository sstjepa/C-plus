#include "Pravougaonik.h"

Pravougaonik::Pravougaonik() :Figura(), b(0), c(0)
{}

Pravougaonik::Pravougaonik(double x, double y, double b, double c) :Figura(x, y)
{
	this->b = b;
	this->c = c;
}

Pravougaonik::~Pravougaonik()
{}

double Pravougaonik::obim()
{
	return 2 * (b + c);
}

double Pravougaonik::povrsina()
{
	return c * b;
}

void Pravougaonik::ispis(ostream& izlaz)
{
	Figura::ispis(izlaz);
	izlaz << "Pravougaonik - ";
	izlaz << "Stranica B: " << b << ", Stranica C: " << c << endl;
}
