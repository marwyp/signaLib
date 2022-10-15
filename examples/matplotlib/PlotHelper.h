#include <vector>
#include <complex>
#include <iostream>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;
using comp = std::complex<double>;

namespace PlotHelper{
    void scatterComplexData(const std::vector<comp> &x, bool coordinateSystem = true);
}

void PlotHelper::scatterComplexData(const std::vector<comp> &x, bool coordinateSystem){
    std::vector<double> r;
    std::vector<double> i;

    for (auto number : x){
        r.push_back(std::real(number));
        i.push_back(std::imag(number));
    }

    plt::scatter(r, i, 20);

    // plot coordinate system
    if (coordinateSystem){
        double coefficient = 1.1;

        double rMax = *std::max_element(r.begin(), r.end());
        rMax *= coefficient;
        double rMin = *std::min_element(r.begin(), r.end());
        rMin *= coefficient;

        double iMax = *std::max_element(i.begin(), i.end());
        iMax *= coefficient;
        double iMin = *std::min_element(i.begin(), i.end());
        iMin *= coefficient;


        if (rMin < iMin){
            iMin = rMin;
        }else{
            rMin = iMin;
        }

        if(rMax > iMax){
            iMax = rMax;
        }else{
            rMax = iMax;
        }

        std::vector<double> xAxisX{rMin, rMax};
        std::vector<double> xAxisY{0, 0};

        std::vector<double> yAxisX{0, 0};
        std::vector<double> yAxisY{iMin, iMax};

        plt::plot(xAxisX, xAxisY, "k");
        plt::plot(yAxisX, yAxisY, "k");
        plt::xlim(rMin, rMax);
        plt::ylim(iMin, iMax);
    }
}