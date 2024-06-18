#include <iostream>
#include <thread>
#include <mutex>

// Global variable
int counter = 0;
// Mutex to protect counter
std::mutex counter_mutex;

// Function to increment the counter
void increment(int n) {
    for (int i = 0; i < n; ++i) {
        std::lock_guard<std::mutex> lock(counter_mutex); // Lock the mutex
        ++counter; // Safely increment the counter
    }
}

int main() {
    int n = 100000;

    // Create two threads
    std::thread t1(increment, n);
    std::thread t2(increment, n);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    // Print the final counter value
    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
