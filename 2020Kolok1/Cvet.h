#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class Cvet
{
private:
	char* vrsta;
public:
	Cvet();
	Cvet(const char* vrsta);
	virtual ~Cvet();

	char* getVrsta();

	virtual double getCena() = 0;
	virtual void ispisi(ostream& izlaz) = 0;
};

