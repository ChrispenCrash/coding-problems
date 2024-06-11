#include <stdio.h>

#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    // Initialise two matrices
    std::vector<std::vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Add the two matrices
    std::vector<std::vector<int>> result(3, std::vector<int>(3, 0));
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print the result
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}