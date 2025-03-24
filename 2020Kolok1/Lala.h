#pragma once
#include <iostream>
#include <fstream>
#include "Cvet.h"
using namespace std;

class Lala :
	public Cvet
{
private:
	double masa;

public:
	static double cenaPoGramu;
	Lala(double masa = 0);
	~Lala();


	virtual double getCena();
	virtual void ispisi(ostream& izlaz);






};

