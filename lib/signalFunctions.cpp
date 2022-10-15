#include "signalFunctions.h"
#include <random>
#include <string.h>

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

// complex numbers to string
std::string signaLib::complexToString(std::complex<double> number){
    return std::to_string(real(number)) + " + " + std::to_string(imag(number)) + " * j";
}

// get real part from complex vector
std::vector<double> signaLib::real(const std::vector<comp> &x){
    std::vector<double> result;

    for (auto number : x){
        result.push_back(std::real(number));
    }

    return result;
}

// get imag part from complex vector
std::vector<double> signaLib::imag(const std::vector<comp> &x){
    std::vector<double> result;

    for (auto number : x){
        result.push_back(std::imag(number));
    }

    return result;
}