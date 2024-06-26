#include <array>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string random_word(int random_number) {
    string word;
    switch (random_number) {
        case 0:
            word = "apple";
            break;
        case 1:
            word = "banana";
            break;
        case 2:
            word = "cherry";
            break;
        case 3:
            word = "date";
            break;
        case 4:
            word = "elderberry";
            break;
        case 5:
            word = "fig";
            break;
        case 6:
            word = "grape";
            break;
        case 7:
            word = "honeydew";
            break;
        case 8:
            word = "kiwi";
            break;
        case 9:
            word = "lemon";
            break;
    }

    return word;
}

int main() {
    const int N = 10000;
    const int MAX = 10;
    const int num_runs = 10000;

    srand(time(0));

    // int* arr = new int[N];
    // Supposely better way to declare array but slower
    // array<string, N> words;
    vector<string> words;
    string word;

    // Fill and print initial array
    // printf("Word list:\n");
    for (int i = 0; i < N; i++) {
        word = random_word(rand() % MAX);
        words.push_back(word);
        // printf("%s ", word.c_str());
    }

    // 2D vector to store pairs of words and their counts
    vector<pair<string, int>> wordCount;
    string majority_word;
    int highest_count = 0;

    // Loop through the vector of strings
    for (const auto& word : words) {
        bool found = false;
        // Check if the word is already in the wordCount vector
        for (auto& entry : wordCount) {
            if (entry.first == word) {
                // Increment the count if the word is found
                ++entry.second;
                found = true;
                break;
            }

            if (entry.second > highest_count) {
                majority_word = entry.first;
                highest_count = entry.second;
            }
        }
        // If the word is not found, add it to the wordCount vector with count 1
        if (!found) {
            wordCount.push_back(make_pair(word, 1));
        }
    }

    // Print the word counts
    printf("\n\nWord counts:\n");
    for (const auto& entry : wordCount) {
        // cout << entry.first << ": " << entry.second << endl;
        printf("%s: %d\n", entry.first.c_str(), entry.second);
    }

    printf("\nMajority word: %s Count: %d\n\n", majority_word.c_str(),
           highest_count);

    printf("Starting for loop...\n");
    // Find majority element using For Loop
    long long total_duration = 0;
    string majority;
    for (int run = 0; run < num_runs; ++run) {
        auto start = chrono::high_resolution_clock::now();

        wordCount.clear();
        for (const auto& word : words) {
            bool found = false;
            // Check if the word is already in the wordCount vector
            for (auto& entry : wordCount) {
                if (entry.first == word) {
                    // Increment the count if the word is found
                    ++entry.second;
                    found = true;
                    break;
                }

                // if (entry.second > highest_count) {
                //     majority_word = entry.first;
                //     highest_count = entry.second;
                // }
            }
            // If the word is not found, add it to the wordCount vector with
            // count 1
            if (!found) {
                wordCount.push_back(make_pair(word, 1));
            }
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration =
            chrono::duration_cast<chrono::microseconds>(end - start);

        total_duration += duration.count();
    }

    cout << "(for loop) \tMajority(" << highest_count << "): "
         << majority_word
         // cout << "(for loop) Majority: " << majority_word
         << "\tAverage time: " << (total_duration / (double)num_runs)
         << " microseconds" << endl;

    // Find majority element using Hash Map
    total_duration = 0;
    unordered_map<string, int> hash_count;

    for (int run = 0; run < num_runs; ++run) {
        // This line was slowing the hashmap
        hash_count.clear();
        // for (int i = 0; i < MAX; i++) {
        //     hash_count[i] = 0;
        // }

        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < N; i++) {
            hash_count[words[i]]++;
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration =
            chrono::duration_cast<chrono::microseconds>(end - start);

        total_duration += duration.count();
    }

    // Set majority to the first element in the hash map
    majority_word = hash_count.begin()->first;
    highest_count = hash_count.begin()->second;
    for (const auto& pair : hash_count) {
        if (pair.second > highest_count) {
            majority_word = pair.first;
            highest_count = pair.second;
        }
    }

    cout << "(hash map) \tMajority(" << highest_count << "): " << majority_word
         << "\tAverage time: " << (total_duration / (double)num_runs)
         << " microseconds" << endl;

    // Find majority element using Boyer-Moore Voting Algorithm
    total_duration = 0;
    int running_count = 0;
    string candidate_majority;
    for (int run = 0; run < num_runs; ++run) {
        auto start = chrono::high_resolution_clock::now();

        candidate_majority = "";
        running_count = 0;
        for (int i = 0; i < N; i++) {
            if (running_count == 0) {
                candidate_majority = words[i];
            }
            (candidate_majority == words[i]) ? running_count++
                                             : running_count--;
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration =
            chrono::duration_cast<chrono::microseconds>(end - start);

        total_duration += duration.count();
    }

    int actual_count = 0;
    for (int i = 0; i < N; i++) {
        if (words[i] == candidate_majority) {
            actual_count++;
        }
    }

    cout << "(Boyer-Moore) \tMajority(" << actual_count
         << "): " << candidate_majority
         << "\tAverage time: " << (total_duration / (double)num_runs)
         << " microseconds" << endl;

    // delete[] words;

    return 0;
}