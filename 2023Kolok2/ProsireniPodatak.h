#pragma once
#include <iostream>
#include <fstream>
using namespace std;


class ProsireniPodatak
{
private:
	float T;
	float E;
	float V;

public:
	ProsireniPodatak();
	ProsireniPodatak(float t, float e, float v);
	~ProsireniPodatak();

	float getOsecaj();

	friend ostream& operator<<(ostream& izlaz, ProsireniPodatak& p);
	friend istream& operator>>(istream& ulaz, ProsireniPodatak& p);

	bool operator>(ProsireniPodatak& p);
	float operator+(float x);
};

