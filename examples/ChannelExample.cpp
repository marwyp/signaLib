#include "../lib/signaLib.h"
#include "matplotlib/matplotlibcpp.h"
#include "matplotlib/PlotHelper.h"

namespace plt = matplotlibcpp;

int main(int argc, char *argv[]){
    // initial values
    int n = 100;
    int modulationOrder = 2;
    double channelPhaseOffset = 15;    // channel phase offset in degrees

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
        }else if (args[i] == "-n"){
            if(i + 1 < args.size()){
                try{
                    n = std::stoi(args[i + 1]);
                }catch (std::invalid_argument e){
                    valid = false;
                }
            }else{
                valid = false;
            }
        }else if (args[i] == "-o"){
            if(i + 1 < args.size()){
                try{
                    channelPhaseOffset = std::stod(args[i + 1]);
                }catch (std::invalid_argument e){
                    valid = false;
                }
            }else{
                valid = false;
            }
        }
    }

    if (valid){
        std::vector<int> x;
        x = signaLib::randomSignalGenerator(modulationOrder - 1, n);    // signal generation

        std::vector<comp> y;
        signaLib::PSKModulator modulator(modulationOrder);              // modulator
        y = modulator.modulate(x);                                      // signal modulation

        // plot 1
        std::vector<double> r = signaLib::real(y);
        std::vector<double> i = signaLib::imag(y);

        auto info = PlotHelper::getCoordinateSystemInfo(y);

        plt::figure(1);
        plt::scatter(r, i, 20);
        plt::title("Signal after modulation");

        plt::plot(info.xAxisX, info.xAxisY, "k");
        plt::plot(info.yAxisX, info.yAxisY, "k");
        plt::xlim(info.rMin, info.rMax);
        plt::ylim(info.iMin, info.iMax);

        // channel
        signaLib::Channel channel(channelPhaseOffset);                  // channel
        y = channel.transfer(y);                                        // signal after channel

        // plot 2
        r = signaLib::real(y);
        i = signaLib::imag(y);

        info = PlotHelper::getCoordinateSystemInfo(y);

        plt::figure(2);
        plt::scatter(r, i, 20);
        plt::title("Signal after channel");

        plt::plot(info.xAxisX, info.xAxisY, "k");
        plt::plot(info.yAxisX, info.yAxisY, "k");
        plt::xlim(info.rMin, info.rMax);
        plt::ylim(info.iMin, info.iMax);
        
        plt::show();
    }else{
        std::cout<< "Channel example\n\n";
        std::cout<< "-m <modulation order>\t\tmodulation order, default is 2" << std::endl;
        std::cout<< "-o <channel phase offset>\t\tchannel phase offset in degrees, default is 15" << std::endl;
        std::cout<< "-n <number of samples>\t\tnumber of sameples, default is 100" << std::endl;
    }

    return 0;
}