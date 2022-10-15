#pragma once
#include <complex>
#include <vector>

using comp = std::complex<double>;

namespace signaLib{
    class Channel{
        public:
        // constructor
        Channel(double phaseOffset = 0.0);

        // transfer data through channel
        std::vector<comp> transfer(const std::vector<comp> &x);

        // phase offset getter, deg - for degrees, rad - for radians
        double getPhaseOffset(std::string unit);

        protected:
        // phase offset in degrees
        double phaseOffset;

        // channel characteristics
        virtual std::vector<comp> channelCharacteristics(const std::vector<comp> &x);
    };
}