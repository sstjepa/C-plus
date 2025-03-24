#include "Kvadrat.h"

Kvadrat::Kvadrat() :Figura(), a(0)
{}

Kvadrat::Kvadrat(double x, double y, double a) :Figura(x, y)
{
	this->a = a;
}

Kvadrat::~Kvadrat()
{}

double Kvadrat::obim()
{
	return 4 * a;
}

double Kvadrat::povrsina()
{
	return a * a;
}

void Kvadrat::ispis(ostream& izlaz)
{
	Figura::ispis(izlaz);
	izlaz << "Kvadrat - ";
	izlaz << "Stranica A: " << a << endl;
}
