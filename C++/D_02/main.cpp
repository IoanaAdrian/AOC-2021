#include "../AOC_Clib/AOClib.h"
#include <cstring>
#include <iostream>
#include <sstream>

int main() {
    std::ifstream f("input.in");

    aoc::fileReader reader(f);
    std::vector<std::string> lines = reader.readLines();

    int horizontalResult = 0, depthResult = 0, aim = 0;
    for (const auto &line: lines) {
        std::stringstream ss(line);
        char *dir = (char *) malloc(sizeof(char) * 7);
        int value = 0;
        ss >> dir >> value;
        if (strcmp(dir, "forward") == 0) {
            horizontalResult += value;
            depthResult += (aim * value);
        } else if (strcmp(dir, "up") == 0) {
            //depthResult -= value;
            aim -= value;
        } else {
            aim += value;
            //depthResult += value;
        }
    }
    std::cout << horizontalResult * depthResult;
    return 0;
}