#include "Modulator.h"
#include <cmath>

const double PI = atan(1) * 4;

namespace signaLib{
    class PSKModulator : public Modulator{
        public:
        using Modulator::Modulator;

        // modulates given signal x, x must be vector of ints between 0 and modulationOrder - 1
        std::vector<comp> modulate(const std::vector<int> &x);
    };
}

std::vector<comp> signaLib::PSKModulator::modulate(const std::vector<int> &x){
    std::vector<comp> result;
    for (auto bit : x){
        double angle = bit * 360;       // angle in degrees
        angle /= modulationOrder;
        angle += phaseOffset;
        angle *= (PI / 180);            // amgle in radians
        double i = sin(angle);          // imaginary part               
        double r = cos(angle);          // real part
        comp bitModulated{r, i};        // complex number
        result.push_back(bitModulated);
    }
    return result;
}
