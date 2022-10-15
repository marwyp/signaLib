#include "signalFunctions.h"
#include <random>
#include <string.h>
#include <cmath>

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

// Signal To Noise Ratio
double signaLib::SNR(const std::vector<comp> &signal, const std::vector<comp> &signalWithNoise){
    double numerator = 0.0;
    double denoimator = 0.0;
    for (int i = 0; i < signal.size(); i++){
        numerator += pow(abs(signal[i]), 2);
        denoimator += pow(abs(signal[i] - signalWithNoise[i]), 2);
    }

    return 10 * log10(numerator / denoimator);
}