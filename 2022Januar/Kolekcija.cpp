#include "Kolekcija.h"

Kolekcija::Kolekcija() :niz(nullptr), top(0), max(0)
{
}

Kolekcija::Kolekcija(int max)
{
	this->max = max;
	top = 0;
	niz = new Figura * [max];
	for (int i = 0; i < max; i++)
	{
		niz[i] = nullptr;
	}
}

Kolekcija::~Kolekcija()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < max; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}
}

void Kolekcija::dodaj(Figura* figura)
{
	if (top < max)
	{
		niz[top++] = figura;
	}
	else
	{
		povecaj();
		niz[top++] = figura;
	}
}

void Kolekcija::povecaj()
{
	int novimax = max * 1.5;
	Figura** temp = new Figura * [novimax];
	for (int i = 0; i < novimax; i++)
	{
		temp[i] = nullptr;
	}
	for (int i = 0; i < top; i++)
	{
		temp[i] = niz[i];
	}
	delete[] niz;
	max = novimax;
	niz = temp;
}

void Kolekcija::vratiPov(ostream& izlaz)
{
	for (int i = 0; i < top; i++)
	{
		izlaz << "Povrsina: " << niz[i]->povrsina() << endl;
	}
}

void Kolekcija::vratiObim(ostream& izlaz)
{
	for (int i = 0; i < top; i++)
	{
		izlaz << "Obim: " << niz[i]->obim() << endl;
	}
}

void Kolekcija::sortObim()
{
	for (int i = 0; i < top - 1; i++)
	{
		for (int j = i; j < top; j++)
		{
			if (niz[i]->obim() > niz[j]->obim())
			{
				swap(niz[i], niz[j]);
			}
		}
	}
}

void Kolekcija::izlaz(ostream& izlaz)
{
	izlaz << "Sadrzaj: \n";
	for (int i = 0; i < top; i++)
	{
		if (niz[i] != nullptr)
		{
			niz[i]->ispis(izlaz);
		}
	}
}
