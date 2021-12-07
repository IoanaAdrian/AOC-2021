#include "../AOC_Clib/AOClib.h"
#include <iostream>
#include <bitset>
#include <algorithm>

int main() {
    std::ifstream f("input.in");
    aoc::fileReader reader(f);

    std::vector<std::string> lines = reader.readLines();
    std::vector<int> numbers = reader.readNumbers(*lines.begin(), ",");
    int resultCost = -1;
    int maxi = *numbers.begin();
    for (auto num:numbers) {
        maxi = std::max(maxi, num);
    }
    for (int num=0;num<maxi;num++) {
        int cost = 0;
        for (auto target:numbers) {
            int tmp = abs(target - num);
            tmp = tmp * (tmp + 1) / 2;
            cost += tmp;
        }
        if (resultCost == -1) {
            resultCost = cost;
        } else {
            resultCost = std::min(resultCost, cost);
        }
        //std::cout << resultCost << " " << num << "\n";
    }
    std::cout << resultCost;

    return 0;
}
