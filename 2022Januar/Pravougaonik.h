#pragma once
#include "Figura.h"
class Pravougaonik :
	public Figura
{
private:
	double c;
	double b;
public:
	Pravougaonik();
	Pravougaonik(double x, double y, double b, double c);
	~Pravougaonik();

	virtual double obim();
	virtual double povrsina();

	virtual void ispis(ostream& izlaz);

};

