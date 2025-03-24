#pragma once
#include "Element.h"
#include <iostream>

using namespace std;

class Voda : public Element {
private:
	float dubina;

public:
	Voda();

	int vratiVr() const override;
	void stampaj() const override;

	friend istream& operator>>(istream& is, Voda& v);
};