#include "Student.h"
#include "Ispit.h"
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

Student::Student() {
	maxbr = 50;
	ocene = new Ispit[50];
}
Student::~Student() {
	if (ocene != 0)
		delete[] ocene;
}
Student::Student(int mbi)
{
	maxbr = mbi;
	ocene = new Ispit[mbi];
}
void Student::dodajocenu(Ispit ocena) {
	ocene[polozeniIspiti] = ocena;
	polozeniIspiti++;
}
void Student::prikaziOcene() {
	for (int i = 0; i < polozeniIspiti; i++) {
		for (int j = 0; j < polozeniIspiti - 1; j++) {
			if (ocene[j] < ocene[j + 1]) {
				Ispit temp = ocene[j];
				ocene[j] = ocene[j + 1];
				ocene[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < polozeniIspiti; i++) {
		cout << ocene[i] << endl;
	}
}
void Student::azuriraj(char* novoime, char* novoprezime) {
	strcpy_s(ime, novoime);
	strcpy_s(prezime, novoprezime);
}
istream& operator>>(istream& ulaz, Student& stud) {
	ulaz >> stud.ime >> stud.prezime >> stud.brojIndeksa >> stud. polozeniIspiti;
	for (int i = 0; i < stud.polozeniIspiti; i++)
		ulaz >> stud.ocene[i];
	return ulaz;
}
ostream& operator<<(ostream& izlaz, Student& stud) {
	izlaz << stud.ime << ' ' << stud.prezime << ' ' << stud.brojIndeksa << ' ' << stud.polozeniIspiti << endl;
	for (int i = 0; i < stud.polozeniIspiti; i++)
		izlaz << stud.ocene[i];
	return izlaz;
}
float Student::prosecnaOcena() {
	float s = 0;
	for (int i = 0; i < polozeniIspiti; i++) {
		s += ocene[i].getocena(); 
	}
	float ps = s / polozeniIspiti;
	return ps;
}
int Student::porediprosecneocene(Student& stud)
{
	if (this->prosecnaOcena() > stud.prosecnaOcena()) {
		cout << "Prvi student ima vecu prosecnu ocenu" << endl;
		return 1;
	}
	if (this->prosecnaOcena() == stud.prosecnaOcena()) {
		cout << "Studenti imaju iste ocene" << endl;
		return 0;
	}
	cout << "Drugi student ima vecu prosecnu ocenu" << endl;
	return -1;
}
Student& Student::operator=(const Student& stud)
{
	if (this != &stud)
	{
		if(ocene!=0)
			delete[] ocene;
		strcpy_s(ime, stud.ime);
		strcpy_s(prezime, stud.prezime);
		brojIndeksa = stud.brojIndeksa;
		maxbr = stud.maxbr;
		polozeniIspiti = stud.polozeniIspiti;
		ocene = new Ispit[maxbr];
		for (int i = 0; i < polozeniIspiti; i++) {
			ocene[i] = stud.ocene[i];
		}
	}
	return *this;
}
int Student::duzinastudiranja()
{
	char prviispit[11], zadnjiispit[11];
	strcpy_s(prviispit, ocene[0].getdatum());
	strcpy_s(zadnjiispit, ocene[0].getdatum());
	for (int i = 1; i < polozeniIspiti; i++)
	{
		if (strcmp(prviispit, ocene[i].getdatum()) > 0)
			strcpy_s(prviispit, ocene[i].getdatum());
		if (strcmp(zadnjiispit, ocene[i].getdatum()) < 0)
			strcpy_s(zadnjiispit, ocene[i].getdatum());
	}
	char god[5];
	strncpy_s(god, zadnjiispit, 4);
	int duzina = (atoi(god)-1) * 365;
	strncpy_s(god, prviispit, 4);
	duzina -= 365 * (atoi(god)-1);
	char mes[3];
	strncpy_s(mes, zadnjiispit + 5, 2);
	duzina += 30 * (atoi(mes) - 1);
	strncpy_s(mes, prviispit + 5, 2);
	duzina -= 30 * (atoi(mes) - 1);
	char dan[3];
	strncpy_s(dan, zadnjiispit + 8, 2);
	duzina += atoi(mes);
	strncpy_s(dan, prviispit + 8, 2);
	duzina -= atoi(mes);
	return duzina;
}