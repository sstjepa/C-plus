#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Predmet
{
private:

	double masa;
	double vrednost;

public:
	Predmet();
	Predmet(double masa, double vrednost);
	~Predmet();

	double vratiVr();
	double vratiMasu();
	virtual void prikazi(ostream& izlaz) = 0;

};

