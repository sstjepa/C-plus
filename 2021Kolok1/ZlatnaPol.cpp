#include "ZlatnaPol.h"
#include <iostream>
#include <fstream>
using namespace std;
ZlatnaPol::ZlatnaPol() :Predmet(), cistoca(0)
{}

ZlatnaPol::ZlatnaPol(double masa, double cistoca)
	:Predmet(masa, (((cistoca > 24) ? 24 : cistoca) / 24)* masa)
{
	if (cistoca > 24)
		this->cistoca = cistoca;
	else
		this->cistoca = cistoca;
}

void ZlatnaPol::prikazi(ostream& izlaz)
{
	cout << "Zlatna poluga - ";
	cout << "Stepen cistoce: " << cistoca << ", Masa: " << vratiMasu() << ", Vrednost: " << vratiVr() << endl;
}
