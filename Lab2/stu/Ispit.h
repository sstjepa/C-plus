#pragma once
#include <iostream>
using namespace std;
class Ispit
{
private:
	char imeIspita[20];
	int ocena;
	char datum[20];
public:
	Ispit();
	Ispit(int o, char* d, char* imeis);
	~Ispit();
	void unesi();
	void stampaj();
	bool operator<(const Ispit& desno) const;
	bool provera(const Ispit& i);

	char* getimeispita() { return imeIspita; }
	int getocena() { return ocena; }
	char* getdatum() { return datum; }
	void setimeispita(char* ii) { strcpy_s(imeIspita, ii); }
	void setocena(int o) { ocena = 0; }
	void setdatum(char* d) { strcpy_s(datum, d); }

	Ispit& operator=(const Ispit& is);
	friend istream& operator>>(istream& ulaz, Ispit& is);
	friend ostream& operator<<(ostream& izlaz, Ispit& is);
};
