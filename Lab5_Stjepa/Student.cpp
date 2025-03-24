#include "Student.h"
using namespace std;

Student::Student() : brIndeksa(0), prosek(0.0) {}

//Student::Student(const string& first, const string& last, int number, double avg)
//	: ime(first), prezime(last), brIndeksa(number), prosek(avg) {}

bool Student::operator>(const Student& other) const {
	return prosek > other.prosek;
}

bool Student::operator<(const Student& other) const {
	return prosek < other.prosek;
}

Student& Student::operator=(const Student& other) {
	if (this != &other) {
		ime = other.ime;
		prezime = other.prezime;
		brIndeksa = other.brIndeksa;
		prosek = other.prosek;
	}
	return *this;
}

istream& operator>>(istream& ulaz, Student& student) {
	cout << "Unesite podatke o studentu: " << endl;
	cout << "Ime : ";
	ulaz >> student.ime;
	cout << "Prezime: ";
	ulaz >> student.prezime;
	cout << "Broj indeksa: ";
	ulaz >> student.brIndeksa;
	cout << "Trenutni prosek: ";
	ulaz >> student.prosek;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, const Student& student) {
	izlaz << "Podaci o studentu: " << endl;
	izlaz << "Ime: " << student.ime << endl;
	izlaz << "Prezime: " << student.prezime << endl;
	izlaz << "Broj indeksa: " << student.brIndeksa << endl;
	izlaz << "Prosek: " << student.prosek << endl;
	return izlaz;
}
