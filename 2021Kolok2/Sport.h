#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Sport
{
private:
	int brIgraca;
	int brRezervnih;
	char* obuca;
	float budzet;
	float koef;

	float vrednost;

	void kreirajObjekat(int brIgraca, int brRezervnih, const char* obuca, float budzet, float koef);


public:
	Sport();
	Sport(int brIgraca, int brRezervnih, const char* obuca, float budzet, float koef);
	~Sport();

	Sport(const Sport& s);

	Sport& operator=(const Sport& s);

	friend istream& operator>>(istream& ulaz, Sport& s);
	friend ostream& operator<<(ostream& izlaz, Sport& s);
	float operator+(float x);
	bool operator>(Sport& s);
};

