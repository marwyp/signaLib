#include "PSKModulator.h"


std::vector<comp> signaLib::PSKModulator::modulate(const std::vector<int> &x){
    std::vector<comp> result;
    for (auto bit : x){
        double angle = bit * 360;       // angle in degrees
        angle /= modulationOrder;
        angle += phaseOffset;
        angle *= (M_PI / 180);            // amgle in radians
        double i = sin(angle);          // imaginary part               
        double r = cos(angle);          // real part
        comp bitModulated{r, i};        // complex number
        result.push_back(bitModulated);
    }
    return result;
}