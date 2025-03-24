#pragma once
#include "Predmet.h"
#include <iostream>
#include <fstream>
using namespace std;
class ZlatnaPol : public Predmet
{
private:

	double cistoca;

public:
	ZlatnaPol();
	ZlatnaPol(double masa, double cistoca);
	virtual void prikazi(ostream& izlaz);
};