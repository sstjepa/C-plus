#include "Zaba.h"

Zaba::Zaba() : gustinaPega(0), masa(0), omiljenaMusica(0)
{}

Zaba::Zaba(float gustina, float masa, float musice)
{
	this->gustinaPega = gustina;
	this->masa = masa;
	this->omiljenaMusica = musice;
}

Zaba::~Zaba()
{}

bool Zaba::operator>(Zaba& z)
{
	if (masa == z.masa)
	{
		if (omiljenaMusica == z.omiljenaMusica)
		{
			return(gustinaPega < z.gustinaPega);
		}
		else
		{
			return(omiljenaMusica < z.omiljenaMusica);
		}
	}
	else
	{
		return(masa < z.masa);
	}
}

bool Zaba::operator==(Zaba& z)
{
	return (gustinaPega == z.gustinaPega && masa == z.masa && omiljenaMusica == z.omiljenaMusica);
}

Zaba& Zaba::operator=(const Zaba& z)
{
	if (this != &z)
	{
		gustinaPega = z.gustinaPega;
		masa = z.masa;
		omiljenaMusica = z.omiljenaMusica;
	}
	return *this;
}

float Zaba::operator+(float br)
{
	return (this->masa + br);
}

istream& operator>>(istream& ulaz, Zaba& z)
{
	ulaz >> z.gustinaPega >> z.masa >> z.omiljenaMusica;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Zaba& z)
{
	izlaz << "Gustina pega: " << z.gustinaPega
		<< " Masa: " << z.masa
		<< " Omiljena velicina musice: " << z.omiljenaMusica;
	return izlaz;
}
