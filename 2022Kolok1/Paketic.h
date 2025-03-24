#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Paketic
{
private:
	char* adresa;
	char* boja;

public:
	Paketic();
	Paketic(char* adresa, char* boja);
	virtual ~Paketic();

	inline char* vratiAdr() { return this->adresa; }
	virtual double VratiTezinu() = 0;
	virtual double VratiCenu() = 0;
	virtual void prikaziAdr(ostream& izlaz);

};

