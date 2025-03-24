#pragma once
#include "Element.h"
#include <iostream>

using namespace std;

class Put {
private:
	Element** elementi;
	int velicina;

public:
	Put(int velicina);
	~Put();

	void postavi(int indeks, Element* el);
	const Element* operator[](int indeks) const;
	void prikaziBrPoTipu() const;

	friend ostream& operator<<(ostream& os, const Put& put);
};