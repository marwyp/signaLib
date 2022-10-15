#include <iostream>
#include "../lib/PSKModulator.h"
#include "../lib/signaLib.h"
#include "matplotlib/PlotHelper.h"

namespace plt = matplotlibcpp;

int main(int argc, char *argv[]){
    // initial values
    int modulationOrder = 2;
    double phaseOffset = 0;

    // cmd handling
    std::vector<std::string> args(argv, argv + argc);
    bool valid = true;
    for (int i = 0; i < argc; i++){
        if (args[i] == "-m"){
            if(i + 1 < args.size()){
                try{
                    modulationOrder = std::stoi(args[i + 1]);
                }catch (std::invalid_argument e){
                    valid = false;
                }
                
            }else{
                valid = false;
            }
        }else if (args[i] == "-o"){
            if(i + 1 < args.size()){
                try{
                    phaseOffset = std::stod(args[i + 1]);
                }catch (std::invalid_argument e){
                    valid = false;
                }
            }else{
                valid = false;
            }
        }
    }
    if (valid){
        // example
        signaLib::PSKModulator modulator(modulationOrder, phaseOffset);
        std::vector<int> x;
        for (int i = 0; i < modulationOrder; i++){
            x.push_back(i);
        }
        std::vector<comp> y = modulator.modulate(x);
        plt::figure();
        PlotHelper::scatterComplexData(y);
        plt::show();
    }else{
        std::cout<< "PSK modulator example\n\n";
        std::cout<< "-m <modulation order>\t\tmodulation order, default is 2" << std::endl;
        std::cout<< "-o <phase offset>\t\tphase offset in degrees, default is 0" << std::endl;
    }
    

    return 0;
}