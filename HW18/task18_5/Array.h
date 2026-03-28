#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* data;
    size_t size;

    // Function to merge two sorted subarrays
    static void _merge(T* arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary arrays
        T* L = new T[n1];
        T* R = new T[n2];

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        // Merge the temporary arrays back into arr
        int i = 0, j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L, if any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        // Copy the remaining elements of R, if any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        // Free memory
        delete[] L;
        delete[] R;
    }

    // REcursion for split and sort
    static void _mergeSortRecursive(T* arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            _mergeSortRecursive(arr, left, mid);      // left part
            _mergeSortRecursive(arr, mid + 1, right); // right part

            _merge(arr, left, mid, right); 
        }
    }

public:
    // Constructor
    Array(size_t n) : size(n) {
        data = new T[size];
    }

    // Destructor
    ~Array() {
        if (data) delete[] data;
    }

    // by index
    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    void fillFromInput() {
        std::cout << "Enter " << size << " elements: ";
        for (size_t i = 0; i < size; i++) {
            std::cin >> data[i];
        }
    }

    void print() const {
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    static void MergeSort(T* arrayPtr, size_t arraySize) {
        if (arraySize > 1) {
            _mergeSortRecursive(arrayPtr, 0, arraySize - 1);
        }
    }
    
    void Sort() {
        MergeSort(this->data, this->size);
    }
};