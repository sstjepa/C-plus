#include "Distributer.h"

Distributer::Distributer() :niz(nullptr), top(0), max(0)
{}

Distributer::Distributer(int max)
{
	this->max = max;
	niz = new SalonPutnicka * [max];
	for (int i = 0; i < max; i++)
	{
		niz[i] = nullptr;
	}
	top = 0;
}

Distributer::~Distributer()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < top; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}
}

void Distributer::dodaj(SalonPutnicka* salon)
{
	if (top < max)
	{
		niz[top++] = salon;
	}
}

void Distributer::izbaci(int redniBr)
{
	for (int i = 0; i < top; i++)
	{
		if (redniBr == i)
		{
			for (int j = 0; j < top - 1; j++)
			{
				niz[j] = niz[j + 1];
			}
			delete niz[top];
			top--;
		}

	}
}

void Distributer::uvecaj(int redniBr, const char* tip, int za)
{
	if (redniBr < top && niz[redniBr] != nullptr)
	{
		if (!strcmp(niz[redniBr]->getTip(), tip))
		{
			niz[redniBr]->uvecaj(za);
		}
	}
	else
	{
		cout << "Greska" << endl;
	}
}

int Distributer::veciBrZap(int granica)
{
	int rez = 0;
	for (int i = 0; i < top; i++)
	{
		if (niz[i]->vratiBrZap() > granica)
			rez++;
	}
	return rez;
}

SalonPutnicka* Distributer::najblizi(double x, double y)
{
	return nullptr;
}

int Distributer::brojProd()
{
	int suma = 0;
	for (int i = 0; i < top; i++)
	{
		suma += niz[i]->vratiBrProd();
	}
	return suma;
}

double Distributer::prosecnaEfik()
{
	double rez = 0;
	for (int i = 0; i < top; i++)
	{
		rez += niz[i]->efikasnost();
	}
	return (rez / (top - 1));
}

void Distributer::prikazi(ostream& izlaz)
{
	for (int i = 0; i < top; i++)
	{
		niz[i]->ispisi(izlaz);
	}
}
