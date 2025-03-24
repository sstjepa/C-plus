#include "Jabuka.h"
#include <fstream>
#include <iostream>
using namespace std;

Jabuka::Jabuka() :Predmet(), ks(0), kk(0), boja(nullptr)
{}

Jabuka::Jabuka(double masa, double ks, double kk, char* boja) :Predmet(masa, ((ks < 0.5 || kk < 0.5) ? 0 : (ks * kk * masa * 1000)))
{
	this->ks = ks;
	this->kk = kk;
	this->boja = new char[strlen(boja) + 1];
	strcpy(this->boja, boja);
}

Jabuka::~Jabuka()
{
	if (boja != nullptr)
	{
		delete[] boja;
	}
}

void Jabuka::prikazi(ostream& izlaz)
{
	cout << "Jabuka - ";
	cout << "Koef slatkoce: " << ks << ", Koef kiselosti: " << kk << ", Boja : " << boja << ", Masa: " << vratiMasu() << ", Vrednost: " << vratiVr() << endl;
}
