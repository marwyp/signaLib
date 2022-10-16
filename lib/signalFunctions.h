#include <vector>
#include <complex>
#include "signalConstsAndDirectives.h"

namespace signaLib{
    // error functions return structure
    struct ErrorInfo
    {
        int errorNumber;
        double errorRatio;
    };
    
    // returns n samples of random signal between 0 and maxNumber
    std::vector<int> randomSignalGenerator(int maxNumber, int n);

    // get real part from complex vector
    std::vector<double> real(const std::vector<comp> &x);

    // get imag part from complex vector
    std::vector<double> imag(const std::vector<comp> &x);

    // Signal To Noise Ratio
    double SNR(const std::vector<comp> &signal, const std::vector<comp> &signalWithNoise);

    // Symbol Error Rate
    ErrorInfo SER(std::vector<int> referenceSignal, std::vector<int> signal);

    ///////////////////////////////////////////////////////////////////////////
    //                          to string functions                          //
    ///////////////////////////////////////////////////////////////////////////

    // complex numbers to string
    std::string toString(std::complex<double> number);

    // vector<int> to string
    std::string toString(const std::vector<int> &vec);

    // vector<comp> to string
    std::string toString(const std::vector<comp> &vec);
}