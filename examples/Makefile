CXX = g++
CXXFLAGS = -std=c++17 -I../library
LIB_DIR = ../library/build
BUILD_DIR = build
LIB_NAME = myvector

.PHONY: all clean

all: $(BUILD_DIR)/demo

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/demo: $(BUILD_DIR) demo.cpp
	$(CXX) $(CXXFLAGS) demo.cpp -L$(LIB_DIR) -l$(LIB_NAME) -o $(BUILD_DIR)/demo

clean:
	rm -rf $(BUILD_DIR)
