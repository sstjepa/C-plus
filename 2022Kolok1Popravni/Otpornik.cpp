#include "Otpornik.h"

Otpornik::Otpornik() :Proizvod(), otp(0), maxTemp(0), minTemp(0)
{}

Otpornik::Otpornik(const char* barkod, float otp, float min, float max) :Proizvod(barkod, "Otpornik")
{
	this->otp = otp;
	minTemp = min;
	maxTemp = max;
}

Otpornik::~Otpornik()
{}

bool Otpornik::defektan()
{
	if (this->otp == 0.0)
	{
		return true;
	}
	return false;
}

void Otpornik::prikazi(ostream& izlaz)
{
	Proizvod::prikazi(izlaz);
	izlaz << "Otpornost: " << otp << ", Min Temp: " << minTemp << ", Max Temp: " << maxTemp << endl << endl;
}
