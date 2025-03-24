#include "Buket.h"
#include "Ruza.h"
#include "Lala.h"
#include <iostream>
#include <fstream>
using namespace std;

Buket::Buket() :niz(nullptr), top(0), max(0)
{}

Buket::Buket(int max)
{
	this->max = max;
	top = 0;
	niz = new Cvet * [max];
	for (int i = 0; i < max; i++)
	{
		niz[i] = nullptr;
	}
}

Buket::~Buket()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < max; i++)
		{
			if (niz[i] != nullptr)
			{
				delete niz[i];
			}
		}
		delete[] niz;
	}
}

void Buket::dodaj(Cvet* cvet)
{
	if (top < max)
	{
		niz[top++] = cvet;
	}
}

void Buket::ucitaj(const char* ime)
{
	ifstream ulaz(ime);
	if (ulaz.good())
	{
		ulaz >> Ruza::cenaSavrsene;
		ulaz >> Lala::cenaPoGramu;

		int brR;
		ulaz >> brR;
		for (int i = 0; i < brR; i++)
		{
			int r, g, b;
			ulaz >> r >> g >> b;
			this->dodaj(new Ruza(r, g, b));
		}

		int brL;
		ulaz >> brL;
		for (int i = 0; i < brL; i++)
		{
			int masa;
			ulaz >> masa;
			this->dodaj(new Lala(masa));
		}

		ulaz.close();
	}

}

void Buket::ispisi(ostream& izlaz)
{
	izlaz << "Buket:\n";
	for (int i = 0; i < top; i++)
	{
		if (niz[i] != nullptr)
		{
			niz[i]->ispisi(izlaz);
		}
		else
		{
			izlaz << "NULL\n";
		}
	}
	izlaz << "#################################################\n\n";
}

void Buket::sortitajPoCeni()
{
	for (int i = 0; i < top - 1; i++)
	{
		for (int j = 0; j < top; j++)
		{
			if (niz[i]->getCena() > niz[j]->getCena())
			{
				swap(niz[i], niz[j]);
			}
		}
	}
}

void Buket::podeli(Buket* buket1, Buket* buket2)
{
	int br = 0;
	for (int i = 0; i < top && br < 3; i++)
	{
		if (niz[i] != nullptr && !strcmp(niz[i]->getVrsta(), "Ruza"))
		{
			br++;
			buket1->dodaj(niz[i]);
			niz[i] = nullptr;
		}
	}

	br = 0;
	for (int i = top - 1; i > 0 && br < 4; i--)
	{
		if (niz[i] != nullptr && !strcmp(niz[i]->getVrsta(), "Lala"))
		{
			br++;
			buket1->dodaj(niz[i]);
			niz[i] = nullptr;
		}
	}

	bool prvaLala = false;
	for (int i = 0; i < top && !prvaLala; i++)
	{
		if (niz[i] != nullptr && !strcmp(niz[i]->getVrsta(), "Lala"))
		{
			delete niz[i];
			niz[i] = nullptr;
			prvaLala = true;
		}
	}

	br = 0;
	for (int i = 0; i < top; i++)
	{
		if (niz[i] != nullptr)
		{
			buket2->dodaj(niz[i]);
			niz[i] = nullptr;
		}
	}
}
