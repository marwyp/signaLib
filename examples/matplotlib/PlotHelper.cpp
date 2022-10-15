#include "PlotHelper.h"
#include <algorithm>

PlotHelper::CoordinateSystemInfo PlotHelper::getCoordinateSystemInfo(const std::vector<comp> &x){
    PlotHelper::CoordinateSystemInfo info;

    std::vector<double> r;
    std::vector<double> i;

    for (auto number : x){
        r.push_back(real(number));
        i.push_back(imag(number));
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

    info.rMin = rMin;
    info.rMax = rMax;
    info.iMin = iMin;
    info.iMax = iMax;

    info.xAxisX = {rMin, rMax};
    info.xAxisY = {0, 0};

    info.yAxisX = {0, 0};
    info.yAxisY = {iMin, iMax};

    return info;
}