#pragma once
#include <iostream>
#include <fstream>
#include "Predmet.h"
using namespace std;
class Jabuka :
	public Predmet
{
private:
	double ks;
	double kk;
	char* boja;

public:
	Jabuka();
	Jabuka(double masa, double ks, double kk, char* boja);
	~Jabuka();
	virtual void prikazi(ostream& izlaz);

};

