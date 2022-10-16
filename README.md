# signaLib
SignaLib is c++ library for making signal simulations.

### Examples
1. PSKModulatorExample -m *mdulation-order* -o *phase-offset*
   - PSKModulatorExample -m 8 -o 15
   
   ![alt text](https://github.com/marwyp/signaLib/blob/master/examples/img/PSKModulatorExample.jpg?raw=true)
   
2. ChannelExample -m *mdulation-order* -o *channel-phase-offset* -n *number-of-samples*
   - ChannelExample -m 4 -o 20 -n 50
   
   ![alt text](https://github.com/marwyp/signaLib/blob/master/examples/img/ChannelExample.jpg?raw=true)
   
3. AWGNChannelExample -m *mdulation-order* -o *channel-phase-offset* -n *number-of-samples* -s *SNR*
    - ChannelExample -m 4 -o 0 -n 100 -s 15
    
    ![alt text](https://github.com/marwyp/signaLib/blob/master/examples/img/AWGNChannelExample.jpg?raw=true)
### Compilation
1. Download source code: *git clone git@github.com:marwyp/signaLib.git*
2. If you want to you use matplotlib-cpp:
   - install Python: *apt install python3 python3-dev*
   - install matplotlib-cpp: *pip3 install matplotlib*
   - change Python.h directory and Python version in Makefile: *locate 'Python.h'*
   - for more information visit: [documentation](https://matplotlib-cpp.readthedocs.io/en/latest/), [github](https://github.com/lava/matplotlib-cpp)
3. Use Makefile to compile the code:
   - e.g. in examples directory: *make PSKModulatorExample*
   - e.g. in examples directory: *make AWGNChannelExample*
### Specification
1. abstract class Modulator(int modulationOrder = 0, double phaseOffset = 0.0) - base class for different modulators
   - *public virtual vector<complex<double>> modulate(const vector<int> &x) = 0* - modulates given signal x
   - *public int getModulationOrder()* - modulation order getter
   - *public double getPhaseOffset(string unit = "deg")* - phase offset getter, deg - for degrees, rad - for radians
   - *protected int modulationOrder* - modulation order
   - *protected double phaseOffset* - phase offset in degrees
2. class PSKModulator(int modulationOrder = 0, double phaseOffset = 0.0) : public Modulator - PSK modulator class
   - *public vector<complex<double>> modulate(const vector<int> &x)* - modulates given signal x using PSK modulation, x must be vector of ints between 0 and modulationOrder
3. class Channel(double phaseOffset = 0.0) - base class for different channels
   - *public vector<complex<double>> transfer(const vector<complex<double>> &x)* - transfer data through channel
   - *public double getPhaseOffset(string unit)* - channel phase offset getter, deg - for degrees, rad - for radians
   - *protected virtual vector<complex<double>> channelCharacteristics(const vector<complex<double>> &x)* - channel characteristics, function is called by transfer function, for base channel class this function does not change the signal
   - *protected double phaseOffset* - phase offset in degrees
4. class AWGNChannel(double SNR, double phaseOffset = 0.0) - AWGN channel class
   - *protected vector<complex<double>> channelCharacteristics(const vector<complex<double>> &x)* -  - channel characteristics, function is called by transfer function, adds Additive white Gaussian noise to signal x using given SNR
   - *protected double SNR* - Signal to Noise ration for AWGN calculations
5. functions
   - *vector<int> randomSignalGenerator(int maxNumber, int n)* - returns n samples of random signal between 0 and maxNumber
   - *string complexToString(complex<double> number)* - complex numbers to string
   - *vector<double> real(const vector<complex<double>> &x)* - get real part from complex vector
   - *vector<double> imag(const vector<complex<double>> &x)* - get imag part from complex vector
   - *double SNR(const vector<complex<double>> &signal, const vector<complex<double>> &signalWithNoise)* - calculates Signal To Noise Ratio based on given reference signal and noised signal
6. Exceptions
   - *UnknownUnitException* - thrown when wrong unit is given e.g. expected "deg" or "rad" and sth else is given
