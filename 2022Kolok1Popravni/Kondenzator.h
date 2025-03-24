#pragma once
#include "Proizvod.h"
class Kondenzator :
	public Proizvod
{
private:
	float cap;

public:
	Kondenzator();
	Kondenzator(const char* barkod, float cap);
	~Kondenzator();


	virtual bool defektan();
	virtual void prikazi(ostream& izlaz);


};

