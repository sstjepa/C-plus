#include "Pravougaonik.h"
#include <iostream>

using namespace std;

Pravougaonik::Pravougaonik() : Figura(2, nullptr) {}

Pravougaonik::Pravougaonik(double a, double b) : Figura(2, new double[2] {a, b}) {}

Pravougaonik::~Pravougaonik() {}


double Pravougaonik::Povrsina() const {
	return nizStr[0] * nizStr[1];
}

void Pravougaonik::Prikazi() const {
	cout << "Pravougaonik: " << endl;
	Figura::Prikazi();
}