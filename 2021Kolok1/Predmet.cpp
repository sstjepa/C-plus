#include "Predmet.h"

Predmet::Predmet() : masa(0), vrednost(0)
{}

Predmet::Predmet(double masa, double vrednost)
{
	this->masa = masa;
	this->vrednost = vrednost;
}

Predmet::~Predmet()
{
}

double Predmet::vratiVr()
{
	return vrednost;
}

double Predmet::vratiMasu()
{
	return masa;
}
