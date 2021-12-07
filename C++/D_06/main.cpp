#include "../AOC_Clib/AOClib.h"
#include <iostream>
#include <bitset>
#include <algorithm>

int main() {
    std::ifstream f("input.in");
    aoc::fileReader reader(f);

    std::vector<std::string> lines = reader.readLines();
    std::vector<int> numbers = reader.readNumbers(*lines.begin(), ",");
    std::vector<long long> freq(10, 0);
    for (auto numb:numbers) {
        freq[numb]++;
    }
    int days = 256;
    while (days != 0) {
        std::vector<long long> tmpFreq(10, 0);
        for (int i = 0; i < freq.size(); i++) {
            if (i == 0) {
                tmpFreq[6] += freq[0];
                tmpFreq[8] += freq[0];
                freq[0] = 0;
            } else {
                freq[i - 1] += freq[i];
                freq[i] = 0;
            }
        }
        freq[6] += tmpFreq[6];
        freq[8] += tmpFreq[8];
        days--;
    }
    long long s = 0;
    for (long long j : freq) {
        s += j;
    }
    std::cout << s;
    return 0;
}
