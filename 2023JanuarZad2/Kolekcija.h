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

	void prosiriMem();
public:
	Kolekcija();
	Kolekcija(int max);
	~Kolekcija();

	void dodaj(T t);
	void obrisi(int x);
	int ukupanBrPosetioca(int od, int Do);
	void minZarada(int* dan1, int* dan2);

	void sacuvaj(const char* imefajla);
	void ucitaj(const char* imefajla);

	/*friend ostream& operator<<(ostream& izlaz, Kolekcija<T>& k) {
		for (int i = 0; i < k.top; i++)
		{
			izlaz << (k.niz[i]) << " ";
		}
		return izlaz;
	}*/

	void ispisiNaEkran() {
		cout << endl;
		for (int i = 0; i < top; i++)
		{
			cout << niz[i] << endl;
		}
		cout << endl;
	}

};

template<class T>
inline void Kolekcija<T>::prosiriMem()
{
	int newMax = max + (max / 2);
	T* tmp = new T[newMax];
	for (int i = 0; i < top; i++)
	{
		tmp[i] = niz[i];
	}
	delete[] niz;


	max = newMax;
	niz = new T[max];
	for (int i = 0; i < top; i++)
	{
		niz[i] = tmp[i];
	}
	delete[] tmp;
}

template<class T>
inline Kolekcija<T>::Kolekcija() : niz(nullptr), top(0), max(0)
{}

template<class T>
inline Kolekcija<T>::Kolekcija(int max)
{
	this->max = max;
	top = 0;
	niz = new T[max];
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
inline void Kolekcija<T>::dodaj(T t)
{
	if (max == top)
	{
		prosiriMem();
		niz[top++] = t;
	}
	else
		niz[top++] = t;
}

template<class T>
inline void Kolekcija<T>::obrisi(int x)
{
	if (x<0 || x>top)
	{
		cout << "Vrednost X nije vazeca.";
	}
	else
	{
		for (int j = 0; j < x; j++)
		{
			for (int i = 0; i < top - 1; i++)
			{
				niz[i] = niz[i + 1];
			}
			top--;
		}
	}
}

template<class T>
inline int Kolekcija<T>::ukupanBrPosetioca(int od, int Do)
{
	int rez = 0;
	if (od > Do)
	{
		cout << "Nevazeci datumi";
	}
	else if (od<0 || od>top || Do<0 || Do>top)
	{
		cout << "Nevazeci datumi";
	}
	else
	{
		for (int i = od; i <= Do; i++)
		{
			rez = niz[i] + rez;
		}
	}
	return rez;
}

template<class T>
inline void Kolekcija<T>::minZarada(int* dan1, int* dan2)
{
	*dan1 = 0;
	for (int i = 1; i < top; ++i) {
		if (niz[i] < niz[*dan1])
			*dan1 = i;
	}

	*dan2 = (*dan1 + 1) % top;
	for (int i = 1; i < top; ++i)
	{
		if (i != *dan1 && niz[i] < niz[*dan2])
			*dan2 = i;
	}
}

template<class T>
inline void Kolekcija<T>::sacuvaj(const char* imefajla)
{
	ofstream izlaz(imefajla);
	if (!izlaz.good())
	{
		cout << "los izlaz";
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
inline void Kolekcija<T>::ucitaj(const char* imefajla)
{
	ifstream ulaz(imefajla);
	if (!ulaz.good())
	{
		cout << "los ulaz";
	}
	else
	{
		/*top = 0;
		while (ulaz >> niz[top])
		{
			top++;
		}*/

		T podatak = T();
		while (ulaz >> podatak)
		{
			this->dodaj(podatak);
		}
		ulaz.close();
	}

}
