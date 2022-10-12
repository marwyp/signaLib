#include "Modulator.h"
#include <cmath>

class PSKModulator : public Modulator{
    public:
    PSKModulator(double modulationOrder){
        this->modulationOrder = modulationOrder;
    }

    // modulates given signal x, x must be vector of ints between 0 and modulationOrder - 1
    std::vector<comp> modulate(std::vector<int> x);
};

std::vector<comp> PSKModulator::modulate(std::vector<int> x){
    std::vector<comp> result;
    double baseAngle = 360 / modulationOrder;
    baseAngle *= (M_PI / 180);
    for (auto bit : x){
        double angle = bit * baseAngle; 
        double i = sin(angle);
        if (abs(i) < pow(10, -15)){
            i = 0;
        }
        double r = cos(angle);
        if (abs(r) < pow(10, -15)){
            r = 0;
        }
        comp bitModulated{r, i};
        result.push_back(bitModulated);
    }
    return result;
}
