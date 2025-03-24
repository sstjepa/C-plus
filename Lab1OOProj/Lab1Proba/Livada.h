#include <string>
using namespace std;

class Livada {
private:
    int size;
    char** grid;
    char** hidden_grid;

public:
    Livada(int size, char** matrix);

    int getSize() const { return size; };

    void load_file(const string& filename);

    void count(int& countResult, int& krajResult);

    string water_plant(int row, int col, int strength);

    string make_rose(int row, int col, int strength);

    string make_snail(int row, int col, int strength);

    void spread_seeds(int row, int col, int total, int strength);

    void generate_roses(int num_roses);

    void generate_snails(int num_snails);

    void destroy_roses(int row, int col);

    void reveal();

    ~Livada();
};
