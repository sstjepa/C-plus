#include <iostream>
#include <fstream>

class Figura {
protected:
	int brojStranica;
	double* nizStranica;

public:
	Figura() : brojStranica(0), nizStranica(nullptr) {}

	Figura(int brStr, double* niz) : brojStranica(brStr) {
		if (brojStranica > 0) {
			nizStranica = new double[brojStranica];
			for (int i = 0; i < brojStranica; ++i) {
				nizStranica[i] = niz[i];
			}
		}
		else {
			nizStranica = nullptr;
		}
	}

	virtual ~Figura() {
		delete[] nizStranica;
	}

	virtual double Povrsina() const = 0;

	virtual void Prikazi() const {
		std::cout << "Broj stranica: " << brojStranica << std::endl;
		std::cout << "Niz stranica: ";
		for (int i = 0; i < brojStranica; ++i) {
			std::cout << nizStranica[i] << " ";
		}
		std::cout << std::endl;
	}
};

class Kvadrat : public Figura {
public:
	Kvadrat() : Figura(1, nullptr) {}

	Kvadrat(double a) : Figura(1, new double[1] {a}) {}

	~Kvadrat() {}

	double Povrsina() const override {
		return nizStranica[0] * nizStranica[0];
	}

	void Prikazi() const override {
		std::cout << "Kvadrat:" << std::endl;
		Figura::Prikazi();
	}
};

class Pravougaonik : public Figura {
public:
	Pravougaonik() : Figura(2, nullptr) {}

	Pravougaonik(double a, double b) : Figura(2, new double[2] {a, b}) {}

	~Pravougaonik() {}

	double Povrsina() const override {
		return nizStranica[0] * nizStranica[1];
	}

	void Prikazi() const override {
		std::cout << "Pravougaonik:" << std::endl;
		Figura::Prikazi();
	}
};

bool PoredjenjePovrsina(const Figura* f1, const Figura* f2) {
	return f1->Povrsina() < f2->Povrsina();
}

int main() {
	const int n = 2018;
	Figura* nizFigura[n];

	for (int i = 0; i < n / 2; ++i) {
		nizFigura[i] = new Kvadrat(2); // Primer vrednosti stranice
	}

	for (int i = n / 2; i < n; ++i) {
		nizFigura[i] = new Pravougaonik(3.0, 4.0); // Primer vrednosti stranica
	}

	// Prikazivanje podataka
	for (int i = 0; i < n; ++i) {
		nizFigura[i]->Prikazi();
		std::cout << "Povrsina: " << nizFigura[i]->Povrsina() << std::endl;
		std::cout << std::endl;
	}

	// Sortiranje niza po povrsini (Bubble sort)
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (PoredjenjePovrsina(nizFigura[j], nizFigura[j + 1])) {
				std::swap(nizFigura[j], nizFigura[j + 1]);
			}
		}
	}

	// Cuvanje niza u tekstualni fajl
	std::ofstream izlazniFajl("figura.txt");
	if (izlazniFajl.is_open()) {
		for (int i = 0; i < n; ++i) {
			izlazniFajl << "Povrsina: " << nizFigura[i]->Povrsina() << std::endl;
		}
		izlazniFajl.close();
	}
	else {
		std::cerr << "Greska pri otvaranju fajla!" << std::endl;
	}

	// Oslobadjanje memorije
	for (int i = 0; i < n; ++i) {
		delete nizFigura[i];
	}

	return 0;
}