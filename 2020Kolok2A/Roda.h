#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Roda
{
private:
	float masa;
	float visina;
	float raspon;
	float najBrZaba;

public:
	Roda();
	Roda(float masa, float visina, float raspon, float zabe);
	~Roda();

	bool operator>(Roda& r);
	bool operator==(Roda& r);
	Roda& operator=(const Roda& r);
	float operator+(float br);

	friend istream& operator>>(istream& ulaz, Roda& r);
	friend ostream& operator<<(ostream& izlaz, Roda& r);
};

