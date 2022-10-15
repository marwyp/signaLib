#include "Channel.h"

// constructor
signaLib::Channel::Channel(double phaseOffset){
    this->phaseOffset = phaseOffset;
}

// transfer data through channel
std::vector<comp> signaLib::Channel::transfer(const std::vector<comp> &x){
    std::vector<comp> y;

    // characteristics of channel
    y = channelCharacteristics(x);

    // phase shift
    double phaseOffsetInRadians = getPhaseOffset("rad");
    for (int i = 0; i < y.size(); i++){
        y[i] *= exp(phaseOffsetInRadians);
    }
    return y;
}

// channel characteristics
std::vector<comp> channelCharacteristics(const std::vector<comp> &x){
    std::vector<comp> result;
    return result;
}

// phase offset getter, deg - for degrees, rad - for radians
double signaLib::Channel::getPhaseOffset(std::string unit){
    if (unit == "deg"){
        return this->phaseOffset;
    }else if (unit == "rad"){
        return this->phaseOffset * (M_PI / 180);
    }else{
        throw signaLib::UnknownUnitException();
    }
}