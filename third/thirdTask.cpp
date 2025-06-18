#include "../iolib.hpp"

/*
 *Possibility of return several values from function
 */
struct Tuple {
    int array_size;
    int *array;
};

Tuple user_array_input() {
    int array_size = 0;
    int *dynamic_array;
    print("Введите размер массива: ", " ");
    intUserInput(array_size);

    if (array_size > 0) {
        dynamic_array = new int[array_size];
    } else {
        throw;
    }

    int counter = 0;
    while (true) {
        if (counter < array_size) {
            int array_elem;
            cout << "dynamic_array" << "[" << counter << "]" << " = ";
            intUserInput(array_elem);
            dynamic_array[counter] = array_elem;
            counter++;
        } else {
            break;
        }
    }
    return Tuple{.array_size = array_size, .array = dynamic_array};
}

void user_array_output(ofstream &out_file, const int *dynamic_array, const int size) {
    out_file << size << endl;
    for (int i = size - 1; i >= 0; i--) {
        out_file << dynamic_array[i] << " ";
    }
}

int main() {
    ofstream out_file("out.txt");
    auto [array_size, dynamic_array] = user_array_input();

    user_array_output(out_file, dynamic_array, array_size);
    delete[] dynamic_array;
    out_file.close();
}
