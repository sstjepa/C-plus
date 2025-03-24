#include "IzlozbeniPosetioci.h"

IzlozbeniPosetioci::IzlozbeniPosetioci() :brOdraslih(0), brDece(0), brSkola(0)
{}

IzlozbeniPosetioci::IzlozbeniPosetioci(int brOdraslih, int brSkola, int brDece)
{
	this->brOdraslih = brOdraslih;
	this->brSkola = brSkola;
	this->brDece = brDece;
}

IzlozbeniPosetioci::~IzlozbeniPosetioci()
{}

int IzlozbeniPosetioci::operator+(int x)
{
	return (brDece + brOdraslih + brSkola + x);
}

bool IzlozbeniPosetioci::operator<(IzlozbeniPosetioci& pos)
{
	return ((this->brOdraslih + this->brSkola / 2) < (pos.brOdraslih + pos.brSkola / 2));
}

ostream& operator<<(ostream& izlaz, IzlozbeniPosetioci& pos)
{
	izlaz << pos.brOdraslih << " " << pos.brSkola << " " << pos.brDece;
	return izlaz;
}

istream& operator>>(istream& ulaz, IzlozbeniPosetioci& pos)
{
	ulaz >> pos.brOdraslih >> pos.brSkola >> pos.brDece;
	return ulaz;
}
