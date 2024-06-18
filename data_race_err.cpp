#include <iostream>
#include <thread>

int counter = 0;

void increment(int n) {
    for (int i = 0; i < n; ++i) {
        ++counter; // This line causes a data race
    }
}

int main() {
    int n = 100000;

    std::thread t1(increment, n);
    std::thread t2(increment, n);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
