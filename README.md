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
### Specs
1. TODO
