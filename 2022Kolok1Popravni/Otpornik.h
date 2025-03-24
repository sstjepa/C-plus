#pragma once
#include "Proizvod.h"
class Otpornik :
	public Proizvod
{
private:
	float otp;
	float minTemp;
	float maxTemp;

public:
	Otpornik();
	Otpornik(const char* barkod, float otp, float min, float max);
	~Otpornik();

	virtual bool defektan();
	virtual void prikazi(ostream& izlaz);


};

