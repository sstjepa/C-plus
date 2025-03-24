#pragma once
#include "Figura.h"
class Kvadrat :
	public Figura
{
private:
	double a;

public:
	Kvadrat();
	Kvadrat(double x, double y, double a);
	~Kvadrat();

	virtual double obim();
	virtual double povrsina();

	virtual void ispis(ostream& izlaz);

};

