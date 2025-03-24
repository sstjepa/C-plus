#include "Kvadrat.h"
#include <iostream>

using namespace std;

Kvadrat::Kvadrat() : Figura(1, nullptr) {}

Kvadrat::Kvadrat(double a) : Figura(1, new double[1] {a}) {}

Kvadrat::~Kvadrat() {}

double Kvadrat::Povrsina() const {
	return nizStr[0] * nizStr[0];
}


void Kvadrat::Prikazi() const {
	cout << "Kvadrat: " << endl;
	Figura::Prikazi();
}