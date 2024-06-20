#include <chrono>
#include <ctime>
#include <iostream>

int main() {
    const int N = 100;
    const int MAX = 10;
    const int num_runs = 1000000;

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

    // Find majority element using for loop
    long long total_duration = 0;
    int majority;
    for (int run = 0; run < num_runs; ++run) {
        auto start = std::chrono::high_resolution_clock::now();

        int count_for_loop[MAX] = {0};
        for (int i = 0; i < N; i++) {
            count_for_loop[arr[i]]++;
        }

        // Find the majority element
        majority = 0;
        int highest_count = count_for_loop[0];
        for (int i = 1; i < MAX; i++) {
            if (count_for_loop[i] > highest_count) {
                majority = i;
                highest_count = count_for_loop[i];
            }
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration =
            std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        total_duration += duration.count();
    }

    std::cout << "\n\nMajority: " << majority
              << "\tAverage time taken using for loop: "
              << (total_duration / (double)num_runs) << " microseconds"
              << std::endl;

    // TODO: Find majority element using Hash Map

    // TODO: Find majority element using Boyer-Moore Voting Algorithm

    delete[] arr;

    return 0;
}