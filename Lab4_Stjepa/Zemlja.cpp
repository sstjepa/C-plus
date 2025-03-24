#include "Zemlja.h"
#include <iostream>

using namespace std;

Zemlja::Zemlja() : Element(1) {}

int Zemlja::vratiVr() const {
	return nadmorskaVisina;
}

void Zemlja::stampaj() const {
	cout << "Zemlja - Nadmorska visina: " << nadmorskaVisina << endl;
}

istream& operator>>(istream& is, Zemlja& z) {
	is >> z.nadmorskaVisina;
	return is;
}