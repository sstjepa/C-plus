#include <iostream>
#include <fstream>

#include "Figura.h"
#include "Kvadrat.h"
#include "Pravougaonik.h"

#include <random>

using namespace std;

bool PorP(const Figura* f1, const Figura* f2) {
	return f1->Povrsina() < f2->Povrsina();
}

void Zameni(Figura*& a, Figura*& b) {
	Figura* temp = a;
	a = b;
	b = temp;
}


int main() {

	const int n = 2018;
	Figura* nizF[n];

	random_device random;
	mt19937 stvori(random());
	uniform_real_distribution<double> dis(1.0, 100.0);

	for (int i = 0; i < n / 2; i++)
	{
		double aa = dis(stvori);
		nizF[i] = new Kvadrat(aa);
	}

	for (int i = n / 2; i < n; i++)
	{
		double aa = dis(stvori);
		double bb = dis(stvori);
		nizF[i] = new Pravougaonik(aa, bb);
	}

	for (int i = 0; i < n; i++)
	{
		nizF[i]->Prikazi();
		cout << "Povrsina: " << nizF[i]->Povrsina() << endl;
		cout << endl;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (PorP(nizF[j], nizF[j + 1]))
			{
				Zameni(nizF[j], nizF[j + 1]);
			}
		}
	}

	ofstream izldat("Izlaz.txt");
	if (izldat.good())
	{
		for (int i = 0; i < n; i++)
		{
			izldat << "Povrsina: " << nizF[i]->Povrsina() << endl;
		}
	}

	for (int i = 0; i < n; ++i) {
		delete nizF[i];
	}

	return 0;
}