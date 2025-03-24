#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class IzlozbeniPosetioci
{
private:
	int brOdraslih;
	int brSkola;
	int brDece;
public:
	IzlozbeniPosetioci();
	IzlozbeniPosetioci(int brOdraslih, int brSkola, int brDece);
	~IzlozbeniPosetioci();

	friend ostream& operator<<(ostream& izlaz, IzlozbeniPosetioci& pos);
	friend istream& operator>>(istream& ulaz, IzlozbeniPosetioci& pos);
	int operator+(int x);
	bool operator<(IzlozbeniPosetioci& pos);

};

