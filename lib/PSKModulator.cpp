#include "PSKModulator.h"
#include <iostream>

std::vector<comp> signaLib::PSKModulator::modulate(const std::vector<int> &x){
    std::vector<comp> result;
    for (auto bit : x){
        double angle = bit * 360;       // angle in degrees
        angle /= modulationOrder;
        angle += phaseOffset;
        angle *= (signaLib::PI / 180);            // amgle in radians
        double i = sin(angle);          // imaginary part               
        double r = cos(angle);          // real part
        comp bitModulated{r, i};        // complex number
        result.push_back(bitModulated);
    }
    return result;
}

// demodulates given signal x
std::vector<int> signaLib::PSKModulator::demodulate(const std::vector<comp> &x){
    std::vector<int> result;

    for (auto sample : x){
        result.push_back(demodulateOneSample(sample));
    }

    return result;
}

int signaLib::PSKModulator::demodulateOneSample(const comp &sample){
    double angle = std::arg(sample * exp(getPhaseOffset("rad") * signaLib::IMAG_MINUS_J));
    if (angle < 0){
        angle += 2 * signaLib::PI;
    }
    int demodulatedSample = static_cast<int>(round((angle * modulationOrder) / (2 * signaLib::PI))) % modulationOrder;
    return demodulatedSample;
}