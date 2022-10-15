#include <vector>
#include <complex>

using comp = std::complex<double>;

namespace PlotHelper{
    struct CoordinateSystemInfo{
        std::vector<double> xAxisX;
        std::vector<double> xAxisY;
        std::vector<double> yAxisX;
        std::vector<double> yAxisY;
        double rMin;
        double rMax;
        double iMin;
        double iMax;
    };

    CoordinateSystemInfo getCoordinateSystemInfo(const std::vector<comp> &x);
}