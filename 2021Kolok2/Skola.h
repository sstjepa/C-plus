#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Skola
{
private:
	T* niz;
	int top;
	int max;

	void ZauzmiMem(int n);
public:
	Skola();
	Skola(int max);
	~Skola();

	void Dodaj(T& aktivnost);
	void Otkazi(int broj);
	float ProsecnaVrednost();

	void IzvestajProsek(const char* imeFajla);
	void IzvestajNajvrednija(const char* imeFajla);
	void IzvestajNajmanjeVredna(const char* imeFajla);

	void StampajNaEkran();

	friend istream& operator>>(istream& ulaz, Skola<T>& skola)
	{
		int n;
		ulaz >> n;
		for (int i = 0; i < n; i++)
		{
			T* akt = new T();
			ulaz >> *akt;
			skola.Dodaj(*akt);
		}
		return ulaz;
	};
};

template<class T>
inline void Skola<T>::ZauzmiMem(int n)
{
	max = n;
	top = 0;
	niz = new T[max];

}

template<class T>
inline Skola<T>::Skola() :niz(nullptr), top(0), max(0)
{}

template<class T>
inline Skola<T>::Skola(int max)
{
	ZauzmiMem(max);
}

template<class T>
inline Skola<T>::~Skola()
{
	if (niz != nullptr)
	{
		delete[] niz;
	}
}

template<class T>
inline void Skola<T>::Dodaj(T& aktivnost)
{
	if (top == max)
		throw "Nema dovoljno mesta!!!";
	else
	{
		if (top > 0)
		{
			int i = 0;
			bool nadjen = false;
			while (i < top && !nadjen)
			{
				if (aktivnost > niz[i])
				{
					nadjen = true;
					for (int j = top; j > i; j--)
					{
						niz[j] = niz[j - 1];
					}
					niz[i] = aktivnost;
				}
				i++;
			}
			if (!nadjen)
			{
				niz[top] = aktivnost;
			}
			top++;
		}
		else
		{
			niz[top++] = aktivnost;
		}
	}
}

template<class T>
inline void Skola<T>::Otkazi(int broj)
{
	if (broj < 0 || broj >= max)
		throw "Nepostojeci element!!";
	else
	{
		for (int i = broj; i < top - 1; i++)
		{
			niz[i] = niz[i + 1];
		}
		top--;
	}
}

template<class T>
inline float Skola<T>::ProsecnaVrednost()
{
	float rez = 0.0;
	for (int i = 0; i < top; i++)
	{
		rez = niz[i] + rez;
	}
	return (rez / (float)top);
}

template<class T>
inline void Skola<T>::IzvestajProsek(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (izlaz.good())
	{
		if (top == 0)
			izlaz << "0";
		else
			izlaz << "Prosecna vrednost svih aktivnosti:\t " << ProsecnaVrednost();
		izlaz.close();
	}
}

template<class T>
inline void Skola<T>::IzvestajNajvrednija(const char* imeFajla)
{
	if (top == 0)
		throw"Nema ni jedna aktivnost. Ne moze se napraviti izvestaj!!!";
	ofstream izlaz(imeFajla);
	if (izlaz.good())
	{
		izlaz << "Podaci o najvrednoijoj aktivnosti:\n" << niz[0];
		izlaz.close();
	}

}

template<class T>
inline void Skola<T>::IzvestajNajmanjeVredna(const char* imeFajla)
{
	if (top == 0)
		throw"Nema ni jedna aktivnost. Ne moze se napraviti izvestaj!!!";
	ofstream izlaz(imeFajla);
	if (izlaz.good())
	{
		izlaz << "Podaci o najvrednoijoj aktivnosti:\n" << niz[top - 1];
		izlaz.close();
	}
}

template<class T>
inline void Skola<T>::StampajNaEkran()
{
	for (int i = 0; i < top; i++)
		cout << niz[i] << endl;
	cout << "\nProsecna Vrednost: " << ProsecnaVrednost() << endl;
	cout << "Najvrednija aktivnost: " << niz[0] << endl;
	cout << "Najmanje vredna aktivnost: " << niz[top - 1] << endl;
	cout << "-----------------------------------------------\n\n" << endl;
}
