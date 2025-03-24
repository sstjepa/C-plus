#include "Ranac.h"
#include <iostream>
#include <fstream>

Ranac::Ranac() :N(0), trenBr(0), niz(nullptr)
{}

Ranac::Ranac(int N) :trenBr(0)
{
	this->N = N;
	niz = new Predmet * [N];
	for (int i = 0; i < N; i++)
	{
		niz[i] = nullptr;
	}
}

Ranac::~Ranac()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < N; i++)
		{
			if (niz[i] != nullptr)
			{
				delete niz[i];
			}
		}
		delete[] niz;

	}
}

void Ranac::dodajPredmet(Predmet* predmet)
{
	if (trenBr + 1 < N)
	{
		niz[trenBr++] = predmet;
	}
}

void Ranac::prikazi(ostream& izlaz)
{
	cout << "Sadrzaj ranca(Trenutni broj: " << trenBr << "):\n";
	for (int i = 0; i < trenBr; i++)
	{
		niz[i]->prikazi(izlaz);
	}
}

double Ranac::srednjaVr()
{
	double srednja = 0;
	for (int i = 0; i < trenBr; i++)
	{
		srednja += niz[i]->vratiVr();
	}
	return(srednja / trenBr);
}

Predmet* Ranac::najvredniji()
{
	if (trenBr == 0) return nullptr;

	double maxVr = niz[0]->vratiVr() / niz[0]->vratiMasu();
	int maxInd = 0;
	for (int i = 1; i < trenBr; ++i) {
		double newVr = niz[i]->vratiVr() / niz[i]->vratiMasu();
		if (newVr > maxVr) {
			maxVr = newVr;
			maxInd = i;
		}
	}

	return niz[maxInd];
}
