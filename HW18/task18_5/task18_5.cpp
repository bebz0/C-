#include <iostream>
#include "Array.h"

int main() {
    //int
    std::cout << "Test 1: Array class" << std::endl;
    size_t n;
    std::cout << "Enter size of array: ";
    std::cin >> n;

    Array<int> myArray(n);
    myArray.fillFromInput();

    std::cout << "Original array: ";
    myArray.print();

    myArray.Sort();

    std::cout << "Sorted array:   ";
    myArray.print();
    std::cout << std::endl;


    // double array
    std::cout << "Test 2: Static Method" << std::endl;
    
    double rawArray[] = {3.67, 1.5, 5, 0.3, 9.2};
    size_t rawSize = 5;

    std::cout << "Raw array before: ";
    for(double d : rawArray) std::cout << d << " ";
    std::cout << std::endl;

    Array<double>::MergeSort(rawArray, rawSize);

    std::cout << "Raw array after:  ";
    for(double d : rawArray) std::cout << d << " ";
    std::cout << std::endl;

    return 0;
}