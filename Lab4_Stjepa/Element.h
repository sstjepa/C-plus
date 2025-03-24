#pragma once

class Element {
protected:
	int tip;

public:
	Element(int t);

	int vratiTip() const;
	virtual int vratiVr() const = 0;
	virtual void stampaj() const = 0;
};