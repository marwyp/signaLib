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

################
matplotlibTest: matplotlibTest.cpp
	$(CC) -std=$(CPP_VERSION) -w -o $(BUILD_DIR)/matplotlibTest matplotlibTest.cpp -I $(PYTHON_DIR) $(PYTHON)

PSKModulatorExample: PSKModulatorExample.cpp
	$(CC) -std=$(CPP_VERSION) -w -o $(BUILD_DIR)/PSKModulatorExample PSKModulatorExample.cpp -I $(PYTHON_DIR) $(PYTHON)