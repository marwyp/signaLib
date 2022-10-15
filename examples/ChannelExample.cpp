#include "../lib/signaLib.h"
#include "matplotlib/matplotlibcpp.h"
#include "matplotlib/PlotHelper.h"

namespace plt = matplotlibcpp;

int main(){
    int n = 10;
    int modulationOrder = 2;
    std::vector<int> x;
    x = signaLib::randomSignalGenerator(modulationOrder - 1, n);    // signal generation

    std::vector<comp> y;
    signaLib::PSKModulator modulator(modulationOrder);              // modulator
    y = modulator.modulate(x);                                      // signal modulation
    double channelPhaseOffset = 20;                                 // channel phase offset in degrees

    //plt::figure(1);
    //PlotHelper::scatterComplexData(y);

    signaLib::Channel channel(15);                                  // channel
    std::vector<comp> z;
    z = channel.transfer(y);                                        // signal after channel

    for (auto number : z){
        std::cout << signaLib::complexToString(number) << std::endl;
    }

    plt::figure(1);
    PlotHelper::scatterComplexData(z);
    plt::show();

    return 0;
}