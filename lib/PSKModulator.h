#include <cmath>
#include "Modulator.h"

namespace signaLib{
    class PSKModulator : public Modulator{
        public:
        using Modulator::Modulator;

        // modulates given signal x, x must be vector of ints between 0 and modulationOrder - 1
        std::vector<comp> modulate(const std::vector<int> &x);

        // demodulates given signal x
        std::vector<int> demodulate(const std::vector<comp> &x);

        private:
        int demodulateOneSample(const comp &sample);
    };
}