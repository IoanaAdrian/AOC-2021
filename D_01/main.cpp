#include <iostream>
#include "../AOC_Clib/AOClib.h"

int solution(std::vector<int>::iterator current, std::vector<int>::iterator first, std::queue<int> &q, int maxQ) {

    if (current != first - 1) {
        if (q.size() != maxQ) {
            q.push(*current);
            return solution(current - 1, first, q, maxQ);
        } else {
            int firstSum,secondSum;
            firstSum = aoc::sumQ(q);
            q.pop();q.push(*current);
            secondSum = aoc::sumQ(q);
            return solution(current - 1, first, q, maxQ) + (secondSum < firstSum ? 1 : 0);
        }
    } else
        return 0;
}


int main() {
    std::ifstream f("input.in");

    aoc::fileReader reader(f);
    std::vector<int> v = reader.readAs<int>();

    std::queue<int> q;
    if (!v.empty())
        std::cout << solution(v.end() - 1, v.begin(), q, 3);

    return 0;
}
