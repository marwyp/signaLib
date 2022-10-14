#include "matplotlib-cpp.h"
#include <vector>
#include <cmath>

namespace plt = matplotlibcpp;

int main(){
    std::vector<double> y = {1, 2, 3, 4};
    std::vector<double> x = {1.5, 2.5, 3.5, 4.5};

    plt::figure();
    plt::plot(x, y, "bo-");
    plt::xlabel("time [s]");
    plt::ylabel("observations [m]");
    plt::title("Matplotlib test");
    plt::show();

    return 0;
}