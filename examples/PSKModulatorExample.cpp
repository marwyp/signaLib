#include <iostream>
#include "../lib/PSKModulator.h"
//#include "matplotlibcpp.h"

int main(){
    PSKModulator modulator(8, 15);
    std::vector<int> x{0, 1, 2, 3, 4, 5, 6, 7};
    std::vector<comp> y = modulator.modulate(x);
    for (int i = 0; i < x.size(); i++){
        std::cout << x[i] << ": " << real(y[i]) << " + i * " << imag(y[i]) <<std::endl;
    }
    return 0;
}