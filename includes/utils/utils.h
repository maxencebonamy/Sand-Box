#ifndef SANDBOX_UTILS_H
#define SANDBOX_UTILS_H

#include <random>

int randInt(int a, int b);

template<typename T>
T randVector(const std::vector<T>& list) {
    return list[randInt(0, list.size()-1)];
}

#endif
