#include <vector>
#include <complex>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;
using comp = std::complex<double>;

namespace PlotHelper{
    void scatterComplexData(std::vector<comp> x);
}

void PlotHelper::scatterComplexData(std::vector<comp> x){
    std::vector<double> r;
    std::vector<double> i;

    for (auto number : x){
        r.push_back(std::real(number));
        i.push_back(std::imag(number));
    }

    double coefficient = 1.1;

    double rMax = *std::max_element(r.begin(), r.end());
    rMax *= coefficient;
    double rMin = *std::min_element(r.begin(), r.end());
    rMin *= coefficient;

    double iMax = *std::max_element(i.begin(), i.end());
    iMax *= coefficient;
    double iMin = *std::min_element(i.begin(), i.end());
    iMin *= coefficient;

    std::vector<double> xAxisX{rMin, rMax};
    std::vector<double> xAxisY{0, 0};

    std::vector<double> yAxisX{0, 0};
    std::vector<double> yAxisY{iMin, iMax};

    plt::scatter(r, i, 20);
    plt::plot(xAxisX, xAxisY, "k");
    plt::plot(yAxisX, yAxisY, "k");
    plt::xlim(rMin, rMax);
    plt::ylim(iMin, iMax);
}