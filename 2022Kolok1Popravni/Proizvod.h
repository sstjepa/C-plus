#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Proizvod
{
private:
	char* barkod;
	char* tip;
public:
	Proizvod();
	Proizvod(const char* barkod, const char* tip);
	~Proizvod();

	char* getTip() { return tip; };

	virtual bool defektan() = 0;
	virtual void prikazi(ostream& izlaz);

};

