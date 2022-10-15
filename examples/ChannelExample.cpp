#include "../lib/signaLib.h"
#include "../lib/PSKModulator.h"
#include "../lib/Channel.h"
#include "matplotlib/matplotlibcpp.h"

int main(){
    int n = 1000;
    int modulationOrder = 8;
    std::vector<int> x;
    x = signaLib::randomSignalGenerator(n, modulationOrder - 1);    // signal generation
    std::vector<comp> y;
    signaLib::PSKModulator modulator(modulationOrder);              // modulator
    y = modulator.modulate(x);                                      // signal modulation
    double channelPhaseOffset = 15;                                 // channel phase offset in degrees
    signaLib::Channel channel;                                      // channel
    y = channel.transfer(y);                                        // signal after channel                                  

    return 0;
}