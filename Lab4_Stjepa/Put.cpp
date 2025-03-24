#include "Put.h"
#include <iostream>
using namespace std;

Put::Put(int vel) : velicina(vel) {
	elementi = new Element * [velicina];
	for (int i = 0; i < velicina; ++i) {
		elementi[i] = nullptr;
	}
}

Put::~Put() {
	for (int i = 0; i < velicina; ++i) {
		delete elementi[i];
	}
	delete[] elementi;
}

void Put::postavi(int indeks, Element* el) {
	if (indeks >= 0 && indeks < velicina) {
		elementi[indeks] = el;
	}
}

const Element* Put::operator[](int indeks) const {
	if (indeks >= 0 && indeks < velicina) {
		return elementi[indeks];
	}
	return nullptr;
}

void Put::prikaziBrPoTipu() const {
	int brojZemlja = 0;
	int brojVoda = 0;

	for (int i = 0; i < velicina; ++i) {
		if (elementi[i]->vratiTip() == 1) {
			brojZemlja++;
		}
		else if (elementi[i]->vratiTip() == 2) {
			brojVoda++;
		}
	}

	cout << "Broj elemenata po tipu:" << endl;
	cout << "Zemlja: " << brojZemlja << endl;
	cout << "Voda: " << brojVoda << endl;
}

ostream& operator<<(ostream& os, const Put& put) {
	for (int i = 0; i < put.velicina; ++i) {
		if (put.elementi[i]) {
			put.elementi[i]->stampaj();
		}
	}
	return os;
}