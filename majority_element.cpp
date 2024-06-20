#include <chrono>
#include <ctime>
#include <iostream>
#include <unordered_map>

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

    // Find majority element using For Loop
    long long total_duration = 0;
    int majority;
    for (int run = 0; run < num_runs; ++run) {
        auto start = std::chrono::high_resolution_clock::now();

        int count_for_loop[MAX] = {0};
        for (int i = 0; i < N; i++) {
            count_for_loop[arr[i]]++;
        }

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

    std::cout << "\n\n(for loop) \tMajority: " << majority
              << "\tAverage time: " << (total_duration / (double)num_runs)
              << " microseconds" << std::endl;

    // Find majority element using Hash Map
    // TODO: Find out why it's much slower than the for loop
    total_duration = 0;
    std::unordered_map<int, int> hash_count;
    majority = 0;
    for (int run = 0; run < num_runs; ++run) {
        hash_count.clear();
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < N; i++) {
            hash_count[arr[i]]++;
        }
        majority = arr[0];
        int highest_count = hash_count[arr[0]];
        for (const auto& pair : hash_count) {
            if (pair.second > highest_count) {
                majority = pair.first;
                highest_count = pair.second;
            }
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration =
            std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        total_duration += duration.count();
    }

    std::cout << "(hash map) \tMajority: " << majority
              << "\tAverage time: " << (total_duration / (double)num_runs)
              << " microseconds" << std::endl;

    // Find majority element using Boyer-Moore Voting Algorithm
    total_duration = 0;
    for (int run = 0; run < num_runs; ++run) {
        auto start = std::chrono::high_resolution_clock::now();

        int majority = 0;
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (count == 0) {
                majority = arr[i];
            }
            majority == arr[i] ? count++ : count--;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration =
            std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        total_duration += duration.count();
    }

    std::cout << "(Boyer-Moore) \tMajority: " << majority
              << "\tAverage time: " << (total_duration / (double)num_runs)
              << " microseconds" << std::endl;

    delete[] arr;

    return 0;
}