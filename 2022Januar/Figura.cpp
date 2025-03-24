#include "Figura.h"

Figura::Figura() :x(0), y(0)
{}

Figura::Figura(double x, double y)
{
	this->x = x;
	this->y = y;
}

Figura::~Figura()
{}

void Figura::upis()
{
	cin >> x;
	cin >> y;
}

void Figura::ispis(ostream& izlaz)
{
	izlaz << "X koordinata: " << x << ",Y koordinata: " << y << endl;
}
