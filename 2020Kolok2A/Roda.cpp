#include "Roda.h"

Roda::Roda() : masa(0), visina(0), raspon(0), najBrZaba(0)
{}

Roda::Roda(float masa, float visina, float raspon, float zabe)
{
	this->masa = masa;
	this->visina = visina;
	this->raspon = raspon;
	this->najBrZaba = zabe;
}

Roda::~Roda()
{}

bool Roda::operator>(Roda& r)
{
	if (masa == r.masa)
	{
		if (najBrZaba == r.najBrZaba)
		{
			if (visina == r.visina)
			{
				return (raspon > r.raspon);
			}
			else
			{
				return (visina > r.visina);
			}
		}
		else
		{
			return(najBrZaba > r.najBrZaba);
		}
	}
	else
	{
		return(masa > r.masa);
	}
}

bool Roda::operator==(Roda& r)
{
	return (masa == r.masa && visina == r.visina && raspon == r.raspon && najBrZaba == r.najBrZaba);
}

Roda& Roda::operator=(const Roda& r)
{
	if (this != &r)
	{
		this->masa = r.masa;
		this->visina = r.raspon;
		this->raspon = r.raspon;
		this->najBrZaba = r.najBrZaba;
	}
	return *this;
}

float Roda::operator+(float br)
{
	return (this->masa + br);
}

istream& operator>>(istream& ulaz, Roda& r)
{
	ulaz >> r.masa >> r.visina >> r.raspon >> r.najBrZaba;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Roda& r)
{
	izlaz << "Masa rode: " << r.masa
		<< " Visina rode: " << r.visina
		<< " Raspon krila: " << r.raspon
		<< " Najveci broj zaba pojeden u danu: " << r.najBrZaba;
	return izlaz;
}
