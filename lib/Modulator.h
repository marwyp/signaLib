#pragma once

#include <complex>
#include <vector>
#include "signalConstsAndDirectives.h"

namespace signaLib{
    class Modulator{
        public:
        Modulator(int modulationOrder = 0, double phaseOffset = 0.0);

        virtual std::vector<comp> modulate(const std::vector<int> &x) = 0;
        virtual std::vector<int> demodulate(const std::vector<comp> &x) = 0;

        // modulation order getter
        int getModulationOrder();

        // phase offset getter, deg - for degrees, rad - for radians
        double getPhaseOffset(std::string unit = "deg");

        protected:
        int modulationOrder;      // modulation order
        double phaseOffset;       // phase offset in degrees
    };
}   