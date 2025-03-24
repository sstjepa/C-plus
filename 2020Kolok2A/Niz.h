#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Niz
{
private:
	T* niz;
	int top;
	int max;

public:
	Niz();
	Niz(int max);
	~Niz();

	void dodaj(T& element);
	void izbaci(int broj);
	void ucitaj(istream& ulaz);
	void ispisi(ostream& izlaz);

	float ukupnaMasa();

};

template<class T>
inline Niz<T>::Niz() :niz(nullptr), top(0), max(0)
{}

template<class T>
inline Niz<T>::Niz(int max)
{
	this->max = max;
	niz = new T[this->max];
	top = 0;
}

template<class T>
inline Niz<T>::~Niz()
{
	if (niz != nullptr)
	{
		delete[] niz;
	}
}

template<class T>
inline void Niz<T>::dodaj(T& element)
{
	if (top == max)
		throw"Niz je pun.";
	for (int i = 0; i < top; i++)
		if (niz[i] == element)
			throw"Element postoji..";

	if (top == 0)
	{
		niz[top++] = element;
		return;
	}
	else
	{
		for (int i = 0; i < top; i++)
		{
			if (niz[i] > element) {
				int k = i;
				for (int j = top; j > i; j--)
				{
					niz[j] = niz[j - 1];
				}
				top++;
				niz[k] = element;
				return;
			}
		}
		niz[top++] = element;
	}
}

template<class T>
inline void Niz<T>::izbaci(int broj)
{
	if (broj > top || broj < 1)
		throw "element ne postoji";
	else
	{
		int indeks = broj - 1;
		for (int i = indeks; i < top - 1; i++)
		{
			niz[i] = niz[i + 1];
		}
		top--;
	}
}

template<class T>
inline void Niz<T>::ucitaj(istream& ulaz)
{
	int n;
	ulaz >> n;
	for (int i = 0; i < n; i++)
	{
		T* pom = new T();
		ulaz >> *pom;
		this->dodaj(*pom);
	}
}

template<class T>
inline void Niz<T>::ispisi(ostream& izlaz)
{
	for (int i = 0; i < top; i++)
	{
		izlaz << niz[i] << endl;
	}
}

template<class T>
inline float Niz<T>::ukupnaMasa()
{
	float rez = 0;
	for (int i = 0; i < top; i++)
	{
		rez = niz[i] + rez;
	}
	return rez;
}

