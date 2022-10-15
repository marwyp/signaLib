#include <complex>
#include <vector>
#include "signalExceptions.h"

using comp = std::complex<double>;

namespace signaLib{
    class Modulator{
        public:
        Modulator(int modulationOrder = 0, double phaseOffset = 0.0);

        virtual std::vector<comp> modulate(const std::vector<int> &x) = 0;

        int getModulationOrder();
        double getPhaseOffset(std::string unit = "deg");

        protected:
        int modulationOrder;      // modulation order
        double phaseOffset;       // phase offset in degrees
    };
}

// constructor
signaLib::Modulator::Modulator(int modulationOrder, double phaseOffset){
    this->modulationOrder = modulationOrder;
    this->phaseOffset = phaseOffset;
}

// modulation order getter
int signaLib::Modulator::getModulationOrder(){
    return this->modulationOrder;
}

// phase offset getter, deg - for degrees, rad - for radians
double signaLib::Modulator::getPhaseOffset(std::string unit){
    if (unit == "deg"){
        return this->phaseOffset;
    }else if (unit == "rad"){
        return this->phaseOffset * (M_PI / 180);
    }else{
        throw UnknownUnitException();
    }
}
    