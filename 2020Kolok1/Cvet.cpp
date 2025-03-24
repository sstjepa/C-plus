#include <string>
#include "Cvet.h"

Cvet::Cvet() : vrsta(nullptr)
{}

Cvet::Cvet(const char* vrsta)
{
	this->vrsta = new char[strlen(vrsta) + 1];
	strcpy(this->vrsta, vrsta);
}

Cvet::~Cvet()
{
	if (vrsta != nullptr)
	{
		delete[] vrsta;
	}
}

char* Cvet::getVrsta()
{
	return vrsta;
}
