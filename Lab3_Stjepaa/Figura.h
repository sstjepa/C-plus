#pragma once
class Figura
{
protected:
	int brojStr;
	double* nizStr;

public:
	Figura();
	Figura(int brStr, double* niz);
	virtual ~Figura();

	virtual double Povrsina() const = 0;
	virtual void Prikazi() const;
};