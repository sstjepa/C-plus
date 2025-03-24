#include "Lala.h"
#include <iostream>
#include <fstream>
using namespace std;

double Lala::cenaPoGramu;

Lala::Lala(double masa) :Cvet("Lala")
{
	this->masa = masa;
}

Lala::~Lala()
{}

double Lala::getCena()
{
	return (cenaPoGramu * masa);
}

void Lala::ispisi(ostream& izlaz)
{
	izlaz << "Lala - (" << masa << ") Cena: " << getCena() << endl;
}
