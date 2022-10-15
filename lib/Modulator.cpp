#include "Modulator.h"
#include "signalExceptions.h"


// constructor
signaLib::Modulator::Modulator(int modulationOrder, double phaseOffset){
    this->modulationOrder = modulationOrder;
    this->phaseOffset = phaseOffset;
}

// modulation order getter
int signaLib::Modulator::getModulationOrder(){
    return this->modulationOrder;
}

// phase offset getter, deg - for degrees, rad - for radians
double signaLib::Modulator::getPhaseOffset(std::string unit){
    if (unit == "deg"){
        return this->phaseOffset;
    }else if (unit == "rad"){
        return this->phaseOffset * (M_PI / 180);
    }else{
        throw signaLib::UnknownUnitException();
    }
}