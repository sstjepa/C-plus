#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class Figura
{
protected:
	double x;
	double y;

public:
	Figura();
	Figura(double x, double y);
	~Figura();

	virtual double obim() = 0;
	virtual double povrsina() = 0;


	virtual void upis();
	virtual void ispis(ostream& izlaz);




};

