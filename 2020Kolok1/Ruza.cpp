#include "Ruza.h"
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

double Ruza::cenaSavrsene;

Ruza::Ruza(int r, int g, int b) :Cvet("Ruza"), R(r), G(g), B(b)
{}

Ruza::~Ruza()
{}

double Ruza::getCena()
{
	double deo1 = ((255 - R) * (255 - G) * (255 - B));
	double cena = pow(deo1, 0.25);
	return (cenaSavrsene / cena);
}

void Ruza::ispisi(ostream& izlaz)
{
	izlaz << "Ruza - (" << R << ", " << G << ", " << B << ") Cena: " << getCena() << endl;
}
