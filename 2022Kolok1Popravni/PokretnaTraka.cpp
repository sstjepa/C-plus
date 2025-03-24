#include "PokretnaTraka.h"

PokretnaTraka::PokretnaTraka() :traka(nullptr), top(0), max(0)
{}

PokretnaTraka::PokretnaTraka(int max)
{
	this->max = max;
	traka = new Proizvod * [max];
	for (int i = 0; i < max; i++)
	{
		traka[i] = nullptr;
	}
	top = 0;
}

PokretnaTraka::~PokretnaTraka()
{
	if (traka != nullptr)
	{
		for (int i = 0; i < top; i++)
		{
			delete traka[i];
		}
		delete[] traka;
	}
}

void PokretnaTraka::dodaj(Proizvod* proizvod)
{
	if (top < max)
	{
		traka[top++] = proizvod;
	}
}

void PokretnaTraka::povecaj(int kolicina)
{
	int newKap = max + kolicina;
	Proizvod** temp = new Proizvod * [newKap];
	for (int i = 0; i < newKap; i++)
	{
		temp[i] = nullptr;
	}
	for (int i = 0; i < top; i++)
	{
		temp[i] = traka[i];
	}
	delete[] traka;
	max = newKap;
	traka = temp;
}

void PokretnaTraka::izbaci()
{

	if (top == 0)
		return;
	int i = 0;
	while (traka[i] == nullptr)
	{
		i++;
	}

	ofstream izlaz;
	izlaz.open("pakovanje.txt", ios_base::app);
	traka[i]->prikazi(izlaz);
	izlaz.close();

	delete traka[i];
	for (; i < top - 1; i++)
	{
		traka[i] = traka[i + 1];
	}
	top--;
	traka[top] = nullptr;

}

void PokretnaTraka::zameniDef(int pozicija, Proizvod* proizvod)
{
	if (pozicija<0 || pozicija>max)
		return;
	if (traka[pozicija]->defektan())
	{
		if (pozicija < (max / 3) && !strcmp(traka[pozicija]->getTip(), proizvod->getTip()))
		{
			delete traka[pozicija];
			traka[pozicija] = proizvod;
		}
		else
		{
			traka[pozicija] = nullptr;
		}
	}

}

int PokretnaTraka::trenBrDef()
{
	int br = 0;
	for (int i = 0; i < top; i++)
	{
		if (traka[i] != nullptr && traka[i]->defektan())
		{
			br++;
		}
	}

	return br;
}

int PokretnaTraka::trenBrPraz()
{
	int brP = 0;
	for (int i = 0; i < top; i++)
	{
		if (traka[i] == nullptr)
		{
			brP++;
		}
	}
	return brP;
}

void PokretnaTraka::prikazi(ostream& izlaz)
{
	izlaz << "SADRZAJ TRAKE:\n\n";
	for (int i = 0; i < top; ++i)
		if (traka[i] != nullptr)
			traka[i]->prikazi(izlaz);
		else
			izlaz << "NULL\n\n";
	izlaz << "###########################################-KRAJ";
}
