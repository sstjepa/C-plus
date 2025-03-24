#pragma once
#include "Ispit.h"
#include <iostream>
using namespace std;
class Student
{
private:
	char ime[20];
	char prezime[20];
	int brojIndeksa;
	int maxbr;
	int polozeniIspiti;
	Ispit* ocene;
public:
	Student();
	Student(int mbi);
	~Student();
	int vratiBrIndeksa();
	int vratiBrPolozenih();
	void dodajocenu(Ispit o);
	void prikaziOcene();
	void azuriraj(char* novoime, char* novoprezime);
	float prosecnaOcena();
	int porediprosecneocene(Student& stud);
	Student& operator=(const Student& stud);
	friend istream& operator>>(istream& ulaz, Student& stud);
	friend ostream& operator<<(ostream& izlaz, Student& stud);

	int duzinastudiranja();
};
inline int Student::vratiBrIndeksa() {
	return brojIndeksa;
}
inline int Student::vratiBrPolozenih() {
	return polozeniIspiti;
}