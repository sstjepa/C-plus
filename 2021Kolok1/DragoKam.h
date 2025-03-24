#pragma once
#include <iostream>
#include <fstream>
#include "Predmet.h"
using namespace std;
class DragoKam :
	public Predmet
{
private:
	double cistocaD;
	char* boja;
	int rezovi;

public:
	DragoKam();
	DragoKam(double masa, double cistoca, char* boja, int rez);
	~DragoKam();

	virtual void prikazi(ostream& izlaz);

};

