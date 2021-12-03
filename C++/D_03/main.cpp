#include "../AOC_Clib/AOClib.h"
#include <iostream>
#include <bitset>

std::string solution(std::vector<std::string> lines, int co2);

int main() {
    ///// ----------PART1------------
    /*
    std::ifstream f("input.in");
    std::vector<int> freq[2];

    aoc::fileReader reader(f);
    std::vector<std::string> lines = reader.readLines();
    std::bitset<20> gammaString, epsilonString;
    if (lines.empty())
        return 0;

    for (auto letter:*lines.begin()) {
        freq[0].push_back(0);
        freq[1].push_back(0);
    }

    for (const auto &line:lines) {
        for (int i = 0; i < line.size(); i++) {
            freq[line[i] - '0'][i]++;
        }
    }
    for (int i = 0; i < freq[1].size(); i++) {
        gammaString.set(freq[1].size()-i-1, freq[0][i] < freq[1][i]);
        epsilonString.set(freq[1].size()-i-1, freq[0][i] > freq[1][i]);
    }
    std::cout<<gammaString<<" "<<epsilonString<<"\n";
    std::cout << gammaString.to_ullong() << " " << epsilonString.to_ullong() <<"\n";
    std::cout << gammaString.to_ullong()  * epsilonString.to_ullong();


    return 0;
     */

    ///// ---------------------------
    ///// ---------------------------
    ///// ---------------------------



    ///// ----------PART2------------

    std::ifstream f("input.in");


    aoc::fileReader reader(f);
    std::vector<std::string> lines = reader.readLines();
    std::bitset<20> CO2, O2;

    if (lines.empty())
        return 0;
    std::string resultCO2 = solution(lines, 1);
    std::string resultO2 = solution(lines, 0);
    for (int i = 0; i < resultCO2.size(); i++) {
        CO2.set(resultCO2.size() - i - 1, resultCO2[i] - '0');
        O2.set(resultO2.size() - i - 1, resultO2[i] - '0');
    }
    std::cout << CO2 << " " << O2 << "\n";
    std::cout << CO2.to_ullong() * O2.to_ullong();


    return 0;
}

std::string solution(std::vector<std::string> lines, int co2) {
    std::vector<int> freq[2];
    int step = 0;
    while (lines.size() == 1) {
        freq[0].erase(freq[0].begin(), freq[0].end());
        freq[1].erase(freq[1].begin(), freq[1].end());
        for (__attribute__((unused)) auto _:*lines.begin()) {
            freq[0].push_back(0);
            freq[1].push_back(0);
        }
        for (const auto &line:lines) {
            for (int i = 0; i < line.size(); i++) {
                freq[line[i] - '0'][i]++;
            }
        }
        bool maxVal = freq[0][step] < freq[1][step];
        bool minVal = freq[0][step] > freq[1][step];
        bool Eq = freq[0][step] == freq[1][step];
        std::cout << step << " " << freq[0][step] << " " << freq[1][step] << "\n";
        for (int i = 0; i < lines.size(); i++) {
            if ((lines[i][step] - '0' != maxVal && !Eq && co2) ||
                ((lines[i][step] - '0' != minVal && !Eq && !co2) || (Eq && lines[i][step] - '0' != 1 && co2)
                 || (Eq && lines[i][step] - '0' != 0 && !co2))) {
                lines.erase(lines.begin() + i);
                i--;
            }
        }
        step++;
    }
    return *lines.begin();
}