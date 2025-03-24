#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Zemlja.h"
#include "Voda.h"

int mainn() {
	const int ukupnoElemenata = 2018;
	const int polovinaElemenata = ukupnoElemenata / 2;

	std::ofstream outputFile("podacii.txt");

	if (!outputFile.is_open()) {
		std::cerr << "Nije moguće otvoriti izlazni fajl." << std::endl;
		return 1;
	}

	// Postavljamo seed za generisanje pseudo-slučajnih brojeva
	std::srand(static_cast<unsigned>(std::time(0)));

	// Generisanje 1009 elemenata tipa Zemlja
	for (int i = 0; i < polovinaElemenata; ++i) {
		outputFile << "1 " << std::rand() % 1000 + 1 << std::endl;
	}

	// Generisanje 1009 elemenata tipa Voda
	for (int i = 0; i < polovinaElemenata; ++i) {
		outputFile << "2 " << static_cast<float>(std::rand()) / RAND_MAX * 100.0f << std::endl;
	}

	outputFile.close();

	std::cout << "Generisanje podaci.txt uspelo!" << std::endl;

	return 0;
}
