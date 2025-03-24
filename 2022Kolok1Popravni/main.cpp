#include <iostream>
#include <fstream>
#include "Proizvod.h"
#include "Kondenzator.h"
#include "Otpornik.h"
#include "PokretnaTraka.h"

using namespace std;


int main() {

	PokretnaTraka* poktrak = new PokretnaTraka(6);

	poktrak->dodaj(new Kondenzator("0001", 5));
	poktrak->dodaj(new Otpornik("0003", 0, 2, 20));
	poktrak->dodaj(new Kondenzator("0004", 5200));
	poktrak->dodaj(new Otpornik("0005", 10000, 2, 20));
	poktrak->dodaj(new Kondenzator("0008", 0));
	poktrak->dodaj(new Otpornik("0009", 12000, 2, 31));

	Proizvod* otp = new Otpornik("0012", 3, 69, 69);
	poktrak->zameniDef(1, otp);
	Proizvod* kon = new Kondenzator("9999", 7777);
	poktrak->zameniDef(4, kon);

	poktrak->povecaj(2);

	poktrak->dodaj(new Kondenzator("0069", 3));
	poktrak->dodaj(new Kondenzator("0420", 18));

	poktrak->prikazi(cout);


	for (int i = 0; i < 8; i++)
	{
		poktrak->izbaci();
	}



	delete poktrak;

	return 0;
}