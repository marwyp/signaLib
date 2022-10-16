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

signaLib::ErrorInfo signaLib::SER(std::vector<int> referenceSignal, std::vector<int> signal){
    int numberOfSamples = referenceSignal.size();
    int errors = 0;

    for (int i = 0; i < numberOfSamples; i++){
        if (referenceSignal[i] != signal[i]){
            errors++;
        }
    }

    signaLib::ErrorInfo info{errors, 1.0 * errors / numberOfSamples};

    return info;
}

///////////////////////////////////////////////////////////////////////////
//                          to string functions                          //
///////////////////////////////////////////////////////////////////////////

// complex numbers to string
std::string signaLib::toString(std::complex<double> number){
    return std::to_string(real(number)) + " + " + std::to_string(imag(number)) + " * j";
}

// vector<int> to string
std::string signaLib::toString(const std::vector<int> &vec){
    std::string result = "[";

    for (int i = 0; i < vec.size(); i++){
        result = result + std::to_string(vec[i]) + ", ";
    }

    result[result.length() - 1] = ']';

    return result;
}

// vector<comp> to string
std::string signaLib::toString(const std::vector<comp> &vec){
    std::string result = "[";

    for (int i = 0; i < vec.size(); i++){
        result = result + signaLib::toString(vec[i]) + ", ";
    }

    result[result.length() - 1] = ']';

    return result;
}