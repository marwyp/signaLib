#include <iostream>
#include "../lib/signaLib.h"
#include "matplotlib/PlotHelper.h"
#include "matplotlib/matplotlibcpp.h"

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

        // plot
        std::vector<double> r = signaLib::real(y);
        std::vector<double> i = signaLib::imag(y);

        auto info = PlotHelper::getCoordinateSystemInfo(y);

        plt::figure();
        plt::scatter(r, i, 20);

        // coordinates
        plt::plot(info.xAxisX, info.xAxisY, "k");
        plt::plot(info.yAxisX, info.yAxisY, "k");
        plt::xlim(info.rMin, info.rMax);
        plt::ylim(info.iMin, info.iMax);

        plt::show();
    }else{
        std::cout<< "PSK modulator example\n\n";
        std::cout<< "-m <modulation order>\t\tmodulation order, default is 2" << std::endl;
        std::cout<< "-o <phase offset>\t\tphase offset in degrees, default is 0" << std::endl;
    }
    

    return 0;
}