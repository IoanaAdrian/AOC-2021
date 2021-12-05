#include "../AOC_Clib/AOClib.h"
#include <iostream>
#include <bitset>
#include <algorithm>

int mat[1005][1005];

int main() {
    std::ifstream f("input.in");
    aoc::fileReader reader(f);

    std::vector<std::string> lines = reader.readLines();
    std::string s = ",-> ";
    for (const auto &line: lines) {
        std::vector<int> numbers = reader.readNumbers(line, ",-> ");
        int x1 = *numbers.begin(), y1 = *(numbers.begin() + 1),
                x2 = *(numbers.begin() + 2), y2 = *(numbers.begin() + 3);
        if (x1 == x2) {
            for (int i = std::min(y1, y2); i <= std::max(y1, y2); i++) {
                ++mat[i][x1];
            }
        } else if (y1 == y2) {
            for (int i = std::min(x1, x2); i <= std::max(x1, x2); i++) {
                ++mat[y1][i];
            }
        } else { ///// PART 2
            y2 += (y1 > y2) ? -1 : 1;
            x2 += (x1 > x2) ? -1 : 1;
            while (x1 != x2) {
                ++mat[y1][x1];
                x1 += (x1 > x2) ? -1 : 1;
                y1 += (y1 > y2) ? -1 : 1;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (mat[i][j] > 1) {
                ++result;
            }
        }
    }
    std::cout << result;
    return 0;
}
