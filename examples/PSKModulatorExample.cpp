#include <iostream>
#include "../lib/PSKModulator.h"
#include "matplotlib/PlotHelper.h"

namespace plt = matplotlibcpp;

int main(){
    PSKModulator modulator(8, 15);
    std::vector<int> x{0, 1, 2, 3, 4, 5, 6, 7};
    std::vector<comp> y = modulator.modulate(x);
    plt::figure();
    PlotHelper::scatterComplexData(y);
    plt::show();

    return 0;
}