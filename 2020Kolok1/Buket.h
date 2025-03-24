#pragma once
#include "Cvet.h"
#include <iostream>
#include <fstream>
using namespace std;
class Buket
{
private:
	Cvet** niz;
	int top;
	int max;

public:
	Buket();
	Buket(int max);
	~Buket();

	void dodaj(Cvet* cvet);
	void ucitaj(const char* ime);
	void ispisi(ostream& izlaz);
	void sortitajPoCeni();
	void podeli(Buket* buket1, Buket* buket2);



};

