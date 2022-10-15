#include "Channel.h"

namespace signaLib{
    class AWGNChannel : public Channel{
        public:
        AWGNChannel(double SNR, double phaseOffset = 0.0);

        protected:
        double SNR;

        // AWGN channel characteristics
        std::vector<comp> channelCharacteristics(const std::vector<comp> &x);
    };
}