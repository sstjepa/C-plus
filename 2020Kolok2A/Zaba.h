#pragma once
#include <iostream>
using namespace std;
class Zaba
{
private:
	float gustinaPega;
	float masa;
	float omiljenaMusica;

public:
	Zaba();
	Zaba(float gustina, float masa, float musice);
	~Zaba();

	bool operator>(Zaba& z);
	bool operator==(Zaba& z);
	Zaba& operator=(const Zaba& z);
	float operator+(float br);

	friend istream& operator>>(istream& ulaz, Zaba& z);
	friend ostream& operator<<(ostream& izlaz, Zaba& z);

};

