# compiler
CC = g++

# c++ version
CPP_VERSION = c++11

# python directory
PYTHON_DIR = /usr/include/python3.10

# python
PYTHON = -lpython3.10

# build directory
BUILD_DIR = build

# lib directory
LIB_DIR = ../lib

################
matplotlibTest: matplotlibTest.cpp
	$(CC) -std=$(CPP_VERSION) -w -o $(BUILD_DIR)/matplotlibTest matplotlibTest.cpp -I $(PYTHON_DIR) $(PYTHON)

PSKModulatorExample: PSKModulatorExample.cpp
	$(CC) -std=$(CPP_VERSION) -w -o $(BUILD_DIR)/PSKModulatorExample PSKModulatorExample.cpp $(LIB_DIR)/Modulator.cpp \
	$(LIB_DIR)/PSKModulator.cpp -I $(PYTHON_DIR) $(PYTHON)

ChannelExample: ChannelExample.cpp
	$(CC) -std=$(CPP_VERSION) -w -o $(BUILD_DIR)/ChannelExample ChannelExample.cpp $(LIB_DIR)/Modulator.cpp \
	$(LIB_DIR)/PSKModulator.cpp $(LIB_DIR)/Channel.cpp -I $(PYTHON_DIR) $(PYTHON)