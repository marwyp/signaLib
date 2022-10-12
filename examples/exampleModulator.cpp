#include <iostream>
#include "PSKModulator.h"

int main(){
    PSKModulator modulator(4);
    std::cout << "Modulation oreder = " << modulator.modulationOrder << std::endl;
    std::vector<int> x{3, 1, 0, 3, 1, 2, 0};
    std::vector<comp> y = modulator.modulate(x);
    for (int i = 0; i < x.size(); i++){
        std::cout << x[i] << ": " << real(y[i]) << " + i * " << imag(y[i]) <<std::endl;
    }
    return 0;
}