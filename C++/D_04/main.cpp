#include "../AOC_Clib/AOClib.h"
#include <iostream>
#include <bitset>

void updateMatrices(int w, std::vector<std::vector<std::vector<int>>> &matrixList);

void wonMatrix(std::vector<std::vector<std::vector<int>>> matrixList, bool &won, std::vector<std::vector<int>> &result);

int *freq;

int main() {
    std::ifstream f("input.in");
    aoc::fileReader reader(f);

    std::vector<std::string> lines = reader.readLines();
    std::vector<int> withdrawnNumbers = reader.readNumbers(*lines.begin(), ",");

    freq = (int *) (malloc(sizeof(int) * 500));

    std::vector<std::vector<std::vector<int>>> matrixList;
    auto currentLine = lines.begin() + 1;
    while (currentLine != lines.end()) {
        currentLine++;
        std::vector<std::vector<int>> matrix;
        for (int i = 1; i <= 5; i++) {
            std::vector<int> lineNumbers = reader.readNumbers(*currentLine, " ");
            matrix.push_back(lineNumbers);
            currentLine++;
        }
        matrixList.push_back(matrix);
    }
    for (int k = 0; k < matrixList.size(); k++) {
        freq[k] = 0;
    }

    for (auto w:withdrawnNumbers) {
        updateMatrices(w, matrixList);
        bool won = false;
        std::vector<std::vector<int>> resultMatrix;
        wonMatrix(matrixList, won, resultMatrix);
        if (won) {
            int sum = 0;
            for (const auto &line:resultMatrix) {
                for (auto number:line) {
                    if (number != -1) {
                        sum += number;
                    }
                }
            }
            std::cout << sum * w;
            return 0;
        }
    }
    return 0;
}

void updateMatrices(int w, std::vector<std::vector<std::vector<int>>> &matrixList) {
    for (auto &mat:matrixList) {
        for (auto &line:mat) {
            for (auto &num: line) {
                if (num == w) {
                    num = -1;
                }
            }
        }
    }
}

void
wonMatrix(std::vector<std::vector<std::vector<int>>> matrixList, bool &won, std::vector<std::vector<int>> &result) {
    std::vector<std::vector<std::vector<int>>>::iterator mat;
    for (mat = matrixList.begin(); mat != matrixList.end(); mat++) {
        int ok = 0;
        for (int i = 0; i < (*mat).size(); i++) {
            int col = 0, line = 0;
            for (int j = 0; j < (*mat)[i].size(); j++) {
                if ((*mat)[i][j] == -1) {
                    line++;
                }
                if ((*mat)[j][i] == -1) {
                    col++;
                }
            }
            if (col == (*mat).size() || line == (*mat).size()) {
                ok = 1;
            }
        }
        if (ok) {
            freq[mat - matrixList.begin()] = 1;
            int p = 0;
            for (int k = 0; k < matrixList.size(); k++) {
                if (freq[k] == 1) {
                    p++;
                }
            }
            if (p == matrixList.size()) {
                won = true;
                result = *mat;
                return;
            }
        }
    }
    won = false;
}