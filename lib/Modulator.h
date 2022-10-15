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