#include <vector>
#include <complex>

using comp = std::complex<double>;

namespace signaLib{
    // returns n samples of random signal between 0 and maxNumber
    std::vector<int> randomSignalGenerator(int maxNumber, int n);

    // complex numbers to string
    std::string complexToString(std::complex<double> number);

    // get real part from complex vector
    std::vector<double> real(const std::vector<comp> &x);

    // get imag part from complex vector
    std::vector<double> imag(const std::vector<comp> &x);

    // Signal To Noise Ratio
    double SNR(const std::vector<comp> &signal, const std::vector<comp> &signalWithNoise);
}