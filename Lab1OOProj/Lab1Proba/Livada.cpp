#include "livada.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

Livada::Livada(int size, char** matrix) : size(size) {
    grid = new char* [size];
    hidden_grid = new char* [size];
    for (int i = 0; i < size; ++i) {
        grid[i] = new char[size];
        hidden_grid[i] = new char[size];
        for (int j = 0; j < size; ++j) {
            grid[i][j] = matrix[i][j];
            hidden_grid[i][j] = '?';
        }
    }
}

void Livada::load_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    file >> size;
    grid = new char* [size];
    hidden_grid = new char* [size];
    for (int i = 0; i < size; ++i) {
        grid[i] = new char[size];
        hidden_grid[i] = new char[size];
        for (int j = 0; j < size; ++j) {
            file >> grid[i][j];
            hidden_grid[i][j] = '?';
        }
    }

    file.close();
}

void Livada::count(int& countResult, int& krajResult) {
    int kraj = 0, count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] == 'R' || grid[i][j] == 'T') {
                kraj++;
            }
            else if (grid[i][j] == '1' || grid[i][j] == '2' || grid[i][j] == '3') {
                count++;
            }
        }
    }
    countResult = count;
    krajResult = kraj;
}

string Livada::water_plant(int row, int col, int strength) {
    if (row < 0 || row >= size || col < 0 || col >= size) {
        return "Van Granice!";
    }
    char& cell = grid[row][col];
    if (cell == '-' || cell == 'G') {
        hidden_grid[row][col] = 'G';
        return "Pogodili ste travu mlazom vode.";
    }
    else if (cell == '1' || cell == '2') {
        return make_rose(row, col, strength);
    }
    else if (cell == '3') {
        return make_snail(row, col, strength);
    }
    else if (cell == 'S' || cell == 'W') {
        if (cell == 'S') {
            return "Pogodili ste puza mlazom vode.";
        }
        else {
            return "Pogodili ste Trojanskog puza mlazom vode.";
        }
    }
    else if (cell == 'R' || cell == 'T') {
        if (cell == 'R') {
            return "Pogodili ste ruzu mlazom vode.";
        }
        else {
            return "Pogodili ste Trojasnku ruzu mlazom vode.";
        }
    }
}

string Livada::make_rose(int row, int col, int strength) {
    char& cell = grid[row][col];
    int total, seed;
    if (cell == '1')
        seed = 1;
    else
        seed = 2;
    total = seed + strength;
    if (total == 2) {
        grid[row][col] = 'R';
        hidden_grid[row][col] = 'R';
        return "Ruza je izrasla!";
    }
    else if (total == 3) {
        grid[row][col] = 'G';
        hidden_grid[row][col] = 'G';
        spread_seeds(row, col, seed, strength);
        return "Seme ruze se rasejalo!";
    }
    else if (total == 4) {
        grid[row][col] = 'T';
        hidden_grid[row][col] = 'T';
        generate_roses(3);
        return "Trojanska Ruza je izrasla";
    }
    return "Nevalidan karakter!!!";
}

string Livada::make_snail(int row, int col, int strength) {
    int total = strength + 1;
    if (total == 2) {
        grid[row][col] = 'S'; // S - Puz
        hidden_grid[row][col] = 'S';
        destroy_roses(row, col);
        return "Puz se izlegao!";
    }
    else if (total == 3) {
        grid[row][col] = 'W'; // W - Trojanski Puz
        hidden_grid[row][col] = 'W';
        generate_snails(3);
        destroy_roses(row, col);
        return "Trojanski Puz se izlegao!";
    }
    else {
        return "Nevalidan karakter!!!";
    }
}

void Livada::spread_seeds(int row, int col, int total, int strength) {
    for (int i = max(0, row - 1); i < min(size, row + 2); ++i) {
        for (int j = max(0, col - 1); j < min(size, col + 2); ++j) {
            if (grid[i][j] == '-') {
                grid[i][j] = total == 1 ? '1' : '2'; // '1' - Malo Semenki, '2' - Mnogo Semenki
                hidden_grid[i][j] = grid[i][j];
            }
        }
    }
}

void Livada::generate_roses(int num_roses) {
    while (num_roses > 0) {
        int row = rand() % size;
        int col = rand() % size;
        if (grid[row][col] != 'R') {
            grid[row][col] = 'R';
            hidden_grid[row][col] = 'R';
            num_roses--;
        }
    }
}

void Livada::generate_snails(int num_snails) {
    while (num_snails > 0) {
        int row = rand() % size;
        int col = rand() % size;
        if (grid[row][col] != 'S') {
            grid[row][col] = 'S';
            hidden_grid[row][col] = 'S';
            destroy_roses(row, col);
            num_snails--;
        }
    }
}

void Livada::destroy_roses(int row, int col) {
    for (int i = max(0, row - 1); i < min(size, row + 2); ++i) {
        for (int j = max(0, col - 1); j < min(size, col + 2); ++j) {
            if (grid[i][j] == 'R' || grid[i][j] == '1' || grid[i][j] == '2') {
                grid[i][j] = 'G'; 
                hidden_grid[i][j] = 'G';
            }
        }
    }
}

void Livada::reveal() {
    cout << "Skriveno polje livade:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << hidden_grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
   /* for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }*/
}

Livada::~Livada() {
    for (int i = 0; i < size; ++i) {
        delete grid[i];
        delete hidden_grid[i];
    }
    delete[] grid;
    delete[] hidden_grid;
}
