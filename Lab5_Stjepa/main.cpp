#include "Niz.h"
#include "Student.h"
using namespace std;

int main() {
	Niz<double> niz1;
	niz1.ucitaj();
	niz1.stampaj();
	niz1.sortiraj();
	niz1.stampaj();

	Niz<Student> niz2;
	niz2.ucitaj();
	niz2.stampaj();
	niz2.sortiraj();
	niz2.stampaj();

	return 0;
}
