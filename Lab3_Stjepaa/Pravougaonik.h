#pragma once
#include "Figura.h"
class Pravougaonik :
	public Figura
{
public:
	Pravougaonik();
	Pravougaonik(double a, double b);
	~Pravougaonik();

	double Povrsina() const;
	void Prikazi() const;
};