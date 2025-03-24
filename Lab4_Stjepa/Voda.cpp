#include "Voda.h"
#include <iostream>

using namespace std;

Voda::Voda() : Element(2) {}

int Voda::vratiVr() const {
	return 0;
}

void Voda::stampaj() const {
	cout << "Voda - Dubina: " << dubina << endl;
}

istream& operator>>(istream& is, Voda& v) {
	is >> v.dubina;
	return is;
}