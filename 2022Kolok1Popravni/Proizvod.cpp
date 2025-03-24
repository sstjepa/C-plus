#include "Proizvod.h"

Proizvod::Proizvod() :tip(nullptr)
{
	strcpy(barkod, "00000");
}

Proizvod::Proizvod(const char* barkod, const char* tip)
{
	this->barkod = new char[strlen(barkod) + 1];
	strcpy(this->barkod, barkod);
	this->tip = new char[strlen(tip) + 1];
	strcpy(this->tip, tip);
}

Proizvod::~Proizvod()
{
	if (tip != nullptr)
	{
		delete[] barkod;
		delete[] tip;
	}

}

void Proizvod::prikazi(ostream& izlaz)
{
	izlaz << "Tip: " << tip << endl;
	izlaz << "Barkod: " << barkod << endl;
}
