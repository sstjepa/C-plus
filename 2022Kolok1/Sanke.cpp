#include "Sanke.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

Sanke::Sanke() :niz(nullptr), top(0), max(0)
{}

Sanke::Sanke(int max)
{
	this->max = max;
	top = 0;
	niz = new Paketic * [max];
	for (int i = 0; i < max; i++)
	{
		niz[i] = nullptr;
	}
}

Sanke::~Sanke()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < max; ++i)
			if (niz[i] != nullptr)
				delete niz[i];
		delete[] niz;
	}
}

void Sanke::dodajPaketic(Paketic* paket)
{
	if (top < max)
	{
		niz[top++] = paket;
	}
}

void Sanke::izbaciPaketic(const char* adresa)
{
	for (int i = 0; i < top; i++)
	{
		if (!strcmp(niz[i]->vratiAdr(), adresa))
		{
			delete niz[i];
			niz[i] = nullptr;
			for (int j = i; j < top - 1; j++)
			{
				niz[j] = niz[j + 1];
			}
			--i;
			--top;
			niz[top] = nullptr;
		}
	}
}

void Sanke::prikaziSanke(ostream& izlaz)
{
	izlaz << "Sadrzaj: \n";
	for (int i = 0; i < top; i++)
	{
		if (niz[i] != nullptr)
		{
			niz[i]->prikaziAdr(izlaz);
		}

	}
}

double Sanke::SrednjaVr()
{
	double rez = 0;
	for (int i = 0; i < top; i++)
	{
		if (niz[i] != nullptr)
		{
			rez += niz[i]->VratiCenu();
		}
	}
	return (rez / top);
}

Paketic* Sanke::vratiNajtezi()
{
	Paketic* paket = niz[0];
	for (int i = 0; i < top; i++)
	{
		if (niz[i]->VratiTezinu() > paket->VratiTezinu())
		{
			paket = niz[i];
		}
	}
	return paket;
}
