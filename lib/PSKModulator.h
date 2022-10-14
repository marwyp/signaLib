#include "Modulator.h"
#include <cmath>

class PSKModulator : public Modulator{
    public:
    using Modulator::Modulator;

    // modulates given signal x, x must be vector of ints between 0 and modulationOrder - 1
    std::vector<comp> modulate(std::vector<int> x);
};

std::vector<comp> PSKModulator::modulate(std::vector<int> x){
    std::vector<comp> result;
    double baseAngle = 360 / modulationOrder;
    baseAngle *= (M_PI / 180);
    double phaseOffsetInRadians = getPhaseOffset("rad");
    for (auto bit : x){
        double angle = bit * baseAngle + phaseOffsetInRadians; 
        double i = sin(angle);
        double r = cos(angle);
        comp bitModulated{r, i};
        result.push_back(bitModulated);
    }
    return result;
}
