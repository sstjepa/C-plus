#include <iostream>
#include "livada.h"

using namespace std;

int main() {
    srand(time(0));

    string filename = "livada.txt";
    Livada livada(0, nullptr); 
    livada.load_file(filename);

    int size = livada.getSize();

    while (true) {
        livada.reveal();
        int countResult, krajResult;
        livada.count(countResult, krajResult);
        if (countResult == 0) {
            cout << "Cestitke, pobedili ste, nasli ste sva jaja i sve semenke.\n";
            cout << "Finalni skor na tabeli je: " << krajResult << endl;
            break;
        }

        int row = rand() % size;
        int col = rand() % size;
        cout << "Gadjamo " << row + 1 << " red, " << col + 1 << " kolona na livadi.\n";

        int strength=rand()%2;
        do {
            /*cout << "Unesite jacinu mlaza (1-slabo, 2-jako): ";
            cin >> strength;*/
            strength+=1;
        } while (strength != 1 && strength != 2);

        cout << livada.water_plant(row, col, strength) << endl;

    }
    return 0;
}
