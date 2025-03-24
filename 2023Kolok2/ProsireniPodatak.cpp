#include "ProsireniPodatak.h"

ProsireniPodatak::ProsireniPodatak() : T(0), E(0), V(0)
{}

ProsireniPodatak::ProsireniPodatak(float t, float e, float v)
{
	T = t;
	E = e;
	V = v;
}

ProsireniPodatak::~ProsireniPodatak()
{}

float ProsireniPodatak::getOsecaj()
{
	return (T + 0.33 * E - 0.7 * V - 4.0);
}

bool ProsireniPodatak::operator>(ProsireniPodatak& p)
{
	return (this->getOsecaj() > p.getOsecaj());
}

float ProsireniPodatak::operator+(float x)
{
	return (getOsecaj() + x);
}

ostream& operator<<(ostream& izlaz, ProsireniPodatak& p)
{
	return izlaz << p.T << " " << p.E << " " << p.V << " ";
}

istream& operator>>(istream& ulaz, ProsireniPodatak& p)
{
	return ulaz >> p.T >> p.E >> p.V;
}
