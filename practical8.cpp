#include <iostream>
#include <vector>
#include <algorithm>

void transpose(std::vector<std::vector<char>>& matrix) {
    std::vector<std::vector<char>> transposed(matrix[0].size(), std::vector<char>(matrix.size()));

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    matrix = transposed;
}

int main() {
    std::vector<std::vector<char>> matrix = {
        {'R', 'o', 'w'},
        {'T', 'r', 'a'},
        {'n', 's', 'p'},
        {'o', 's', 'i'},
        {'t', 'i', 'o'},
        {'n', 'C', 'i'},
        {'p', 'h', 'e'},
        {'r', 'O', 'p'},
        {'e', 'r', 'a'},
        {'t', 'i', 'o'},
        {'n', 'O', 'p'},
        {'e', 'r', 'a'},
        {'t', 'i', 'o'},
        {'n', 'O', 'p'},
        {'e', 'r', 'a'}
    };

    transpose(matrix);

    for (const auto& row : matrix) {
        for (const auto& col : row) {
            std::cout << col << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}