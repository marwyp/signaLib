#include "PlotHelper.h"
#include <algorithm>

void PlotHelper::getCoordinateSystemInfo(const std::vector<comp> &x, std::vector<double> &xAxisX,  std::vector<double> &xAxisY, 
std::vector<double> &yAxisX, std::vector<double> &yAxisY, double &rMin, double &rMax, double &iMin, double &iMax){
    std::vector<double> r;
    std::vector<double> i;

    for (auto number : x){
        r.push_back(real(number));
        i.push_back(imag(number));
    }

    double coefficient = 1.1;

    rMax = *std::max_element(r.begin(), r.end());
    rMax *= coefficient;
    rMin = *std::min_element(r.begin(), r.end());
    rMin *= coefficient;

    iMax = *std::max_element(i.begin(), i.end());
    iMax *= coefficient;
    iMin = *std::min_element(i.begin(), i.end());
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

    xAxisX = {rMin, rMax};
    xAxisY = {0, 0};

    yAxisX = {0, 0};
    yAxisY = {iMin, iMax};
}