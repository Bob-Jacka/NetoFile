#pragma once

/*
Custom library for actions in Netology C++ course.
Version - 1.0.5
*/

#include <iostream>
#include <fstream>

typedef const int cint; //constant custom integer type

using namespace std; // yeah, I know that it's wrong

inline void println(const string &str = "") {
    cout << str << endl;
}

template<typename T>
void print(T str, string separator = "") {
    cout << str << separator;
}

/*
Writes down int value into variable by address
*/
inline void intUserInput(int &variableAddress) {
    cin >> variableAddress;
}

/*
Writes down long value into variable by address
*/
inline void longUserInput(long &variableAddress) {
    cin >> variableAddress;
}

/*
Writes down string into variable by address
*/
inline void stringUserInput(string &variableAddress) {
    cin >> variableAddress;
}

/*
Writes down value into variable by address
*/
template<typename T>
void userInput(T &variableAddress) {
    cin >> variableAddress;
}

/*
Function for array output with separator.
Older brother of dynamicArrayOutput
*/
inline void lineArrayOutput(const int *array, const int array_size, const string &separator = " ",
                            const bool is_inline = false) {
    for (int i = 0; i < array_size - 1; i++) {
        cout << array[i] << separator;
    }
    cout << array[array_size - 1];

    if (!is_inline) {
        cout << endl;
    }
}

/*
New technology parametrized function for array output with old innovations
*/
template<typename T>
void dynamicArrayOutput(T *array, const int size, const bool reverse = false, const string &separator = " ") {
    if (reverse) {
        for (int i = size - 1; i >= 0; i--) {
            cout << array[i] << separator;
        }
    } else {
        for (int i = 0; i < size; i++) {
            cout << array[i] << separator;
        }
    }
}

template<typename T>
void deleteDynamicArray(T *array, const int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

/*
 *Inline function for creating 2d int array
 *Returns: initialized 2d int array
 */
inline int **create2DArrayInt(const int rows, const int cols) {
    const auto dyn_array = new int *[rows];
    for (int i = 0; i < rows; i++) {
        dyn_array[i] = new int[cols];
    }
    return dyn_array;
}
