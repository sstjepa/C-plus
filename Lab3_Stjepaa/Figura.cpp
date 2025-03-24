#include "Figura.h"
#include <iostream>

using namespace std;

Figura::Figura() : brojStr(0), nizStr(nullptr) {}

Figura::Figura(int brStr, double* niz) : brojStr(brStr) {
	if (brojStr > 0) {
		nizStr = new double[brojStr];
		for (int i = 0; i < brojStr; ++i) {
			nizStr[i] = niz[i];
		}
	}
	else {
		nizStr = nullptr;
	}

}

Figura::~Figura() {
	delete[] nizStr;
}


void Figura::Prikazi() const {
	cout << "Broj stranica: " << brojStr << endl;
	cout << "Niz stranica: ";
	for (int i = 0; i < brojStr; ++i) {
		cout << nizStr[i] << " ";
	}
	cout << endl;
}