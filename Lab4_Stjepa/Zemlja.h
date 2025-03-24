#pragma once
#include "Element.h"
#include <iostream>

using namespace std;

class Zemlja : public Element {
private:
	int nadmorskaVisina;

public:
	Zemlja();

	int vratiVr() const override;
	void stampaj() const override;

	friend istream& operator>>(istream& is, Zemlja& z);
};