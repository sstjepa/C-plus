#pragma once
#include <iostream>
#include <fstream>
using namespace std;


template <class T>
class Kolekcija
{
private:
	T* niz;
	int top;
	int max;

public:
	Kolekcija();
	Kolekcija(int max);
	~Kolekcija();

	void DodajPodatak(T podatak);
	void Obrisi(int i);

	float OdrediProsek();
	T NajveciPodatak();

	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);

	friend ostream& operator<<(ostream& izlaz, Kolekcija<T>& k) {
		for (int i = 0; i < k.top; i++)
		{
			izlaz << (k.niz[i]) << " ";
		}
		return izlaz;
	}
};

template<class T>
inline Kolekcija<T>::Kolekcija()
{
	niz = nullptr;
	top = max = 0;
}

template<class T>
inline Kolekcija<T>::Kolekcija(int max)
{
	this->max = max;
	top = 0;
	niz = new T[max];
	/*for (int i = 0; i < max; i++)
	{
		niz[i] = T();
	}*/
}

template<class T>
inline Kolekcija<T>::~Kolekcija()
{
	if (niz != nullptr)
	{
		delete[] niz;
	}
}

template<class T>
inline void Kolekcija<T>::DodajPodatak(T podatak)
{
	if (top == max)
	{
		throw "Kolekcija je puna!";
	}
	else
	{
		niz[top++] = podatak;
	}
}

template<class T>
inline void Kolekcija<T>::Obrisi(int i)
{
	if (i < 0 || i >= top)
	{
		throw "Element ne postoji!!!";
	}
	else
	{
		for (int j = i; j < top - 1; j++)
		{
			niz[j] = niz[j + 1];
		}
		top--;
	}
}

template<class T>
inline float Kolekcija<T>::OdrediProsek()
{
	float rez = 0.0;
	for (int i = 0; i < top; i++)
	{
		rez = niz[i] + rez;
	}
	return (rez / (float)top);
}

template<class T>
inline T Kolekcija<T>::NajveciPodatak()
{
	T maks = niz[0];
	for (int i = 0; i < top; i++)
	{
		if (niz[i] > maks)
		{
			maks = niz[i];
		}
	}
	return maks;
}

template<class T>
inline void Kolekcija<T>::Sacuvaj(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (!izlaz.good())
	{
		throw "Problem sa upisivanjem!!!";
	}
	else
	{
		for (int i = 0; i < top; i++)
		{
			izlaz << niz[i] << " ";
		}
		/*izlaz << *this;*/
		izlaz.close();
	}
}

template<class T>
inline void Kolekcija<T>::Ucitaj(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (!ulaz.good())
	{
		throw "Problem sa ucitavanjem";
	}
	else
	{
		T podatak = T();
		while (ulaz >> podatak)
		{
			this->DodajPodatak(podatak);
		}
		ulaz.close();
	}
}
