#include "Kondenzator.h"

Kondenzator::Kondenzator() :Proizvod(), cap(0)
{}

Kondenzator::Kondenzator(const char* barkod, float cap) :Proizvod(barkod, "Kondenzator")
{
	this->cap = cap;
}

Kondenzator::~Kondenzator()
{}

bool Kondenzator::defektan()
{
	if (this->cap == 0.0)
	{
		return true;
	}
	return false;
}

void Kondenzator::prikazi(ostream& izlaz)
{
	Proizvod::prikazi(izlaz);
	izlaz << "Kapacitivnost: " << cap << endl << endl;
}
