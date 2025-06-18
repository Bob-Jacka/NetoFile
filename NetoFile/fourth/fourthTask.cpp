#include "../iolib.hpp"

int main() {
    ifstream array_file("in.txt");

    if (array_file.is_open()) {
        int rows, cols;
        array_file >> rows >> cols;

        int **dyn_array = create2DArrayInt(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                array_file >> dyn_array[i][j];
            }
        }
        array_file.close();

        for (int i = 0; i < rows; i++) {
            for (int j = cols - 1; j >= 0; j--) {
                cout << dyn_array[i][j] << ' ';
            }
            println();
        }

        deleteDynamicArray(dyn_array, rows);
    } else {
        cerr << "Error opening file" << endl;
    }
    array_file.close();
}
