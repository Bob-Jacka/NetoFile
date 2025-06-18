#include "../iolib.hpp"

int main() {
    ifstream array_file("in.txt");
    if (array_file.is_open()) {
        int array_size;
        array_file >> array_size;
        const auto file_array = new int[array_size];
        for (int i = array_size - 1; i >= 0; i--) {
            array_file >> file_array[i];
        }
        dynamicArrayOutput(file_array, array_size);
        delete[] file_array;
    } else {
        std::cerr << "Error opening file" << std::endl;
    }
    array_file.close();
}
