#pragma once
#include "Figura.h"

class Kvadrat :
	public Figura
{
public:
	Kvadrat();
	Kvadrat(double a);
	~Kvadrat();


	double Povrsina() const;
	void Prikazi() const;
};