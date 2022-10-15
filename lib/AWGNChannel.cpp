#include "AWGNChannel.h"
#include <random>

// constructor
signaLib::AWGNChannel::AWGNChannel(double SNR, double phaseOffset)
: Channel(phaseOffset){
    this->SNR = SNR;
}

// AWGN channel characteristics
std::vector<comp> signaLib::AWGNChannel::channelCharacteristics(const std::vector<comp> &x){
    std::default_random_engine dre;
    std::normal_distribution<double> normalDistribution(0.0, 1.0);

    std::vector<comp> result;
    double sigma = sqrt(pow(10, (-(SNR + 3) / 10)));    // +3dB beacuase there is complex data instead of real

    double r, i;

    for (auto number : x){
        r = sigma * normalDistribution(dre);
        i = sigma * normalDistribution(dre);
        comp noiseSample(r, i);
        result.push_back(noiseSample + number);
    }

    return result;
}