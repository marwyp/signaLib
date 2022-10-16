# compiler
CC = g++

# c++ version
CPP_VERSION = c++11

# python directory
PYTHON_DIR = /usr/include/python3.10

# python version
PYTHON_VERSION = 3.10

# python
PYTHON = -lpython$(PYTHON_VERSION)

# build directory
BUILD_DIR = build

# lib directory
LIB_DIR = ../lib

# other files
OTHER_FILES = matplotlib/PlotHelper.cpp

# library files list
LIB_FILE_LIST = $(LIB_DIR)/signalExceptions.h $(LIB_DIR)/Modulator.cpp $(LIB_DIR)/PSKModulator.cpp \
$(LIB_DIR)/signalFunctions.cpp $(LIB_DIR)/Channel.cpp $(LIB_DIR)/AWGNChannel.cpp


################
matplotlibTest: matplotlibTest.cpp
	$(CC) -std=$(CPP_VERSION) -w -o $(BUILD_DIR)/matplotlibTest matplotlibTest.cpp -I $(PYTHON_DIR) $(PYTHON)

PSKModulatorExample: PSKModulatorExample.cpp
	$(CC) -std=$(CPP_VERSION) -w -o $(BUILD_DIR)/PSKModulatorExample PSKModulatorExample.cpp $(LIB_FILE_LIST) \
	$(OTHER_FILES) -I $(PYTHON_DIR) $(PYTHON)

ChannelExample: ChannelExample.cpp
	$(CC) -std=$(CPP_VERSION) -w -o $(BUILD_DIR)/ChannelExample ChannelExample.cpp $(LIB_FILE_LIST) \
	$(OTHER_FILES) -I $(PYTHON_DIR) $(PYTHON)

AWGNChannelExample: AWGNChannelExample.cpp
	$(CC) -std=$(CPP_VERSION) -w -o $(BUILD_DIR)/AWGNChannelExample AWGNChannelExample.cpp $(LIB_FILE_LIST) \
	$(OTHER_FILES) -I $(PYTHON_DIR) $(PYTHON)