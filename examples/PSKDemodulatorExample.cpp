#include <iostream>
#include "../lib/signaLib.h"
#include <string.h>

int main(int argc, char *argv[]){
    // initial values
    int n = 100;
    int modulationOrder = 2;
    double channelPhaseOffset = 0;    // channel phase offset in degrees
    double SNR = 15;

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
        }else if (args[i] == "-s"){
            if(i + 1 < args.size()){
                try{
                    SNR = std::stod(args[i + 1]);
                }catch (std::invalid_argument e){
                    valid = false;
                }
            }else{
                valid = false;
            }
        }
    }

    if (valid){
        // signal generation
        std::vector<int> x;
        x = signaLib::randomSignalGenerator(modulationOrder - 1, n);    // signal generation

        // signal modulation
        std::vector<comp> xModulated;
        signaLib::PSKModulator modulator(modulationOrder);              // modulator
        xModulated = modulator.modulate(x);                             // signal modulation

        // channel
        std::vector<comp> xAfterChannel;
        signaLib::AWGNChannel channel(SNR, channelPhaseOffset);         // channel
        xAfterChannel = channel.transfer(xModulated);                   // signal after channel

        // demodulation
        signaLib::PSKModulator demodulator(modulationOrder, channelPhaseOffset);
        std::vector<int> xDemodulated = demodulator.demodulate(xAfterChannel);

        // results
        signaLib::ErrorInfo SER = signaLib::SER(x, xDemodulated);

        std::string xString = "[";
        std::string xDemodString = "[";

        for (int i = 0; i < x.size(); i++){
            xString = xString + std::to_string(x[i]) + ", ";
            xDemodString = xDemodString + std::to_string(xDemodulated[i]) + ", ";
        }

        xString += "]";
        xDemodString += "]";

        std::cout << "SER = " << SER.errorRatio << std::endl;
        std::cout << "x      = " << xString << std::endl;
        std::cout << "xDemod = " << xDemodString << std::endl;

    }else{
        std::cout<< "Channel example\n\n";
        std::cout<< "-m <modulation order>\t\tmodulation order, default is 2" << std::endl;
        std::cout<< "-o <channel phase offset>\t\tchannel phase offset in degrees, default is 0" << std::endl;
        std::cout<< "-n <number of samples>\t\tnumber of sameples, default is 100" << std::endl;
        std::cout<< "-s <SNR>\t\tSNR value, default is 15" << std::endl;
    }

    return 0;
}