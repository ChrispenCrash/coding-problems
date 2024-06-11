#include <iostream>
#include <stdexcept>
#include <vector>

class Matrix {
   private:
    std::vector<std::vector<double>> data;
    size_t rows;
    size_t cols;

   public:
    Matrix(const std::vector<std::vector<double>>& input_data)
        : data(input_data),
          rows(input_data.size()),
          cols(input_data[0].size()) {
        for (const auto& row : data) {
            if (row.size() != cols) {
                throw std::invalid_argument(
                    "All rows must have the same number of columns.");
            }
        }
    }

    // Method to get the number of rows
    size_t getRows() const { return rows; }

    // Method to get the number of columns
    size_t getCols() const { return cols; }

    // Addition of matrices
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument(
                "Matrices must have the same dimensions to be added.");
        }
        std::vector<std::vector<double>> result(rows,
                                                std::vector<double>(cols));
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return Matrix(result);
    }

    // Multiplication of matrices
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument(
                "Number of columns of the first matrix must equal the number "
                "of rows of the second matrix.");
        }
        std::vector<std::vector<double>> result(
            rows, std::vector<double>(other.cols, 0));
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return Matrix(result);
    }

    // Method to print the matrix
    void print() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                printf("%g ", elem);
                // std::cout << elem << " ";
            }
            printf("\n");
            // std::cout << std::endl;
        }
    }
};

int main() {
    // Initialize two matrices A and B
    Matrix A({{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.5}});
    Matrix B({{10.0, 11.0, 12.0}, {13.0, 14.0, 15.0}, {16.0, 17.0, 18.0}});

    // Print matrices A and B
    printf("Matrix A:\n");
    A.print();
    printf("Matrix B:\n");
    B.print();

    // Add matrices A and B to get matrix C
    Matrix C = A + B;
    printf("Matrix C (A + B):\n");
    C.print();

    // Multiply matrices A and B to get matrix D
    Matrix D = A * B;
    printf("Matrix D (A * B):\n");
    D.print();

    return 0;
}
