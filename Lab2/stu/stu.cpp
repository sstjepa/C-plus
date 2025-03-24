#include "Student.h"
#include <iostream>
#include <fstream>
using namespace std;

void sortProsecnaOcena(int n, Student* studenti)
{
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - i-1; j++) {
			if (studenti[j].prosecnaOcena() < studenti[j + 1].prosecnaOcena()) {
				Student temp;
				temp= studenti[j];
				studenti[j] = studenti[j + 1];
				studenti[j + 1] = temp;
			}
		}
	}
}

void sortDuzinaStud(int n, Student* studenti)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (studenti[j].duzinastudiranja() < studenti[j + 1].duzinastudiranja()) {
				Student temp;
				temp = studenti[j];
				studenti[j] = studenti[j + 1];
				studenti[j + 1] = temp;
			}
		}
	}
}

void sortBrPolozenih(int n, Student* studenti)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (studenti[j].vratiBrPolozenih() < studenti[j + 1].vratiBrPolozenih()) {
				Student temp;
				temp= studenti[j];
				studenti[j] = studenti[j + 1];
				studenti[j + 1] = temp;
			}
		}
	}
}

int main()
{
	ifstream ulaz("studenti.txt");
	int n = 0;
	if (ulaz.good())
		ulaz >> n;
	Student* studenti;
	studenti = new Student[n];
	if (ulaz.good())
		for (int i = 0; i < n; i++)
			ulaz >> studenti[i];
	ulaz.close();
	cout << "SORTIRANJE PO PROSECNOJ OCENI: " << endl;
	cout << "*************" << endl;
	sortProsecnaOcena(n, studenti);
	for (int i = 0; i < n; i++)
		cout << studenti[i] << endl;

	cout << "SORTIRANJE PO DUZINI STUDIRANJA: " << endl;
	cout << "*************" << endl;
	sortDuzinaStud(n, studenti);
	for (int i = 0; i < n; i++)
		cout << studenti[i]<< endl;
	
	cout << "SORTIRANJE PO BROJU POLOZENIH ISPITA: " << endl;
	cout << "*************" << endl;
	sortBrPolozenih(n, studenti);
	for (int i = 0; i < n; i++)
		cout << studenti[i]<<endl;


	ofstream izdat("izlaz.txt");
	if (izdat.good()) {	
		for (int i = 0; i < n; i++)
			izdat << studenti[i] << endl;

	}

	delete[] studenti;
	return 0;
}