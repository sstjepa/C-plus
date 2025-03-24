#include "DragoKam.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

DragoKam::DragoKam() :Predmet(), cistocaD(0), boja(nullptr), rezovi(0)
{}

DragoKam::DragoKam(double masa, double cistoca, char* boja, int rez) :Predmet(masa, masa + cistoca)
{
	this->cistocaD = cistoca;
	this->boja = new char[strlen(boja) + 1];
	strcpy(this->boja, boja);
	this->rezovi = rez;
}

DragoKam::~DragoKam()
{
	if (boja != nullptr)
	{
		delete[] boja;
	}
}

void DragoKam::prikazi(ostream& izlaz)
{
	cout << "Dragi kamen - ";
	cout << "Koef cistoce: " << cistocaD << ", Boja: " << boja << ", Br rezova: " << rezovi << ", Masa: " << vratiMasu() << ", Vrednost: " << vratiVr() << endl;
}
