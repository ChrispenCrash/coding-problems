/*
Problem: Move zeroes to the end of the array
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char** argv) {
    int n = 100;

    std::srand(std::time(0));

    // std::cout << "Enter the size of the array: ";
    // std::cin >> n;

    // Create an array of size n
    int* arr = new int[n];

    // Fill the array with random values between 0 and 9 and print
    printf("Inital array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = std::rand() % 10;
        printf("%d ", arr[i]);
    }

    // Create new array of size n filled with zeroes
    int* output = new int[n]();

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            output[j] = arr[i];
            j++;
        }
    }

    printf("\nThe new array is:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", output[i]);
    }

    delete[] arr;
    delete[] output;

    return 0;
}
