#include "../iolib.hpp"

int main() {
    ifstream file("in.txt");
    if (file.is_open()) {
        string word;
        while (file >> word) {
            println(word);
        }
    } else {
        std::cerr << "Error opening file" << std::endl;
    }
    file.close();
}
