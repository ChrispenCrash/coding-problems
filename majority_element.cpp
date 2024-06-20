#include <ctime>
#include <iostream>

int main() {
    const int N = 100;
    const int MAX = 10;

    std::srand(std::time(0));

    int* arr = new int[N];

    // Fill and print initial array
    printf("Array:\n");
    for (int i = 0; i < N; i++) {
        arr[i] = std::rand() % MAX;
        printf("%d ", arr[i]);
    }

    // Initial loop to count occurrences of each element
    int init_count[MAX] = {0};
    for (int i = 0; i < N; i++) {
        init_count[arr[i]]++;
    }
    printf("\n\nOccurrences of each number:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d: %d\t", i, init_count[i]);
    }

    delete[] arr;

    return 0;
}