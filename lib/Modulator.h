
#include <complex>
#include <vector>

using comp = std::complex<double>;

class Modulator{
    public:
    Modulator();
    Modulator(int modulationOrder);
    Modulator(int modulationOrder, int phaseOffset);

    virtual std::vector<comp> modulate(std::vector<int> x) = 0;

    
    int modulationOrder;      // modulation order
    int phaseOffset;          // phase offset in degrees
};

// constructors

Modulator::Modulator(){
    this->modulationOrder = 2;
    this->phaseOffset = 0;
}

Modulator::Modulator(int modulationOrder){
    this->modulationOrder = modulationOrder;
    this->phaseOffset = 0;
}

Modulator::Modulator(int modulationOrder, int phaseOffset){
    this->modulationOrder = modulationOrder;
    this->phaseOffset = phaseOffset;
}