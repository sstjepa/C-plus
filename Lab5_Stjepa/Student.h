#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string ime;
	string prezime;
	int brIndeksa;
	double prosek;

public:
	Student();
	//Student(const string& first, const string& last, int number, double avg);
	bool operator>(const Student& other) const;
	bool operator<(const Student& other) const;
	Student& operator=(const Student& other);
	friend istream& operator>>(istream& ulaz, Student& student);
	friend ostream& operator<<(ostream& izlaz, const Student& student);
};