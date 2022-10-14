#include <iostream>
#include "../lib/PSKModulator.h"
#include "matplotlib-cpp.h"

namespace plt = matplotlibcpp;

int main(){
    PSKModulator modulator(8, 15);
    std::vector<int> x{0, 1, 2, 3, 4, 5, 6, 7};
    std::vector<comp> y = modulator.modulate(x);

    std::vector<double> r;
    std::vector<double> i;

    for (auto number : y){
        r.push_back(real(number));
        i.push_back(imag(number));
    }

    double rMax = *std::max_element(r.begin(), r.end()) + 1;
    double rMin = *std::min_element(r.begin(), r.end()) - 1;

    double iMax = *std::max_element(i.begin(), i.end()) + 1;
    double iMin = *std::min_element(i.begin(), i.end()) - 1;

    std::vector<double> xAxisX{rMin, rMax};
    std::vector<double> xAxisY{0, 0};

    std::vector<double> yAxisX{0, 0};
    std::vector<double> yAxisY{iMin, iMax};

    plt::figure();
    plt::scatter(r, i);
    plt::plot(xAxisX, xAxisY);
    plt::plot(yAxisX, yAxisY);
    plt::show();

    return 0;
}