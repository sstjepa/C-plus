#include "Ispit.h"
#include <fstream>
#include <string.h>

Ispit::Ispit()
{
	ocena = 5;
	strcpy_s(datum, "2000-01-01");
	strcpy_s(imeIspita, "");
}
Ispit::Ispit(int o, char* d, char* imeis)
{
	ocena = o;
	strcpy_s(datum, d);
	strcpy_s(imeIspita, imeis);
}
Ispit::~Ispit() {}
void Ispit::unesi()
{
	cin >> imeIspita >> ocena >> datum;
}
void Ispit::stampaj()
{
	cout << imeIspita << ' ' << ocena << ' ' << datum << endl;
}
bool Ispit::operator<(const Ispit& desno) const
{
	return ocena < desno.ocena;
}
bool Ispit::provera(const Ispit& i)
{
	if (strcmp(datum, i.datum))
		return 1;
	return 0;
}
Ispit& Ispit::operator=(const Ispit& is)
{
	if (this != &is)
	{
		strcpy_s(datum, is.datum);
		ocena = is.ocena;
		strcpy_s(imeIspita, is.imeIspita);
	}
	return *this;
}
istream& operator>>(istream& ulaz, Ispit& is)
{
	ulaz >> is.imeIspita >> is.ocena >> is.datum;
	return ulaz;
}
ostream& operator<<(ostream& izlaz, Ispit& is)
{
	izlaz << is.imeIspita << ' ' << is.ocena << ' ' << is.datum << endl;
	return izlaz;
}