//
// Created by Adrian on 12/1/2021.
//

#ifndef C___QUEUEUTILS_H
#define C___QUEUEUTILS_H

#include <queue>
namespace aoc {
    int sumQ(std::queue<int> q) { // returns the sum between all elements of the queue
        int s = 0;
        while (!q.empty()) {
            s += q.front();
            q.pop();
        }
        return s;
    }

    bool findInQ(std::queue<int> q, int elm) { // returns true if elm is in q
        while (!q.empty()) {
            if (q.front() == elm)
                return true;
            q.pop();
        }
        return false;
    }
}
#endif //C___QUEUEUTILS_H
