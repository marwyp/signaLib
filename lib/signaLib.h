#pragma once
#include <vector>
#include <random>

namespace signaLib{
    // returns n samples of random signal between 0 and maxNumber
    std::vector<int> randomSignalGenerator(int maxNumber, int n);
}

std::vector<int> signaLib::randomSignalGenerator(int maxNumber, int n){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0,maxNumber);

    std::vector<int> randomSignal;
    for (int i = 0; i < n; i++){
        randomSignal.push_back(distribution(generator));
    }

    return randomSignal;
}