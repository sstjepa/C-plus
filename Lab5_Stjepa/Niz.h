#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Niz {
private:
	T elem[100];
	int size;

public:
	Niz();
	T& operator[](int index);
	int velicina() const;
	void ucitaj();
	void stampaj() const;
	void sortiraj();
};

template <class T>
Niz<T>::Niz() : size(0) {}

template <class T>
T& Niz<T>::operator[](int index) {
	if (index < 0 || index >= size) {
		cerr << "greska";
	}
	else return elem[index];
}

template <class T>
int Niz<T>::velicina() const {
	return size;
}

template <class T>
void Niz<T>::ucitaj() {
	cout << "Unesite broj elementa niza: ";
	cin >> size;

	cout << "Unesite elemente: " << endl;
	for (int i = 0; i < size; ++i) {
		cin >> elem[i];
	}
}

template <class T>
void Niz<T>::stampaj() const {
	cout << "Elementi niza: " << endl;
	for (int i = 0; i < size; ++i) {
		cout << elem[i] << " ";
	}
	cout << endl;
}

template <class T>
void Niz<T>::sortiraj() {
	for (size_t i = 0; i < size - 1; ++i) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < size; ++j) {
			if (elem[j] < elem[minIndex]) {
				minIndex = j;
			}
		}
		swap(elem[i], elem[minIndex]);
	}
}