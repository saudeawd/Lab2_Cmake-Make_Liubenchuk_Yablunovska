CXX = g++
CXXFLAGS = -std=c++17 -fPIC
LIB_NAME = myvector
BUILD_DIR = build

.PHONY: all clean

all: $(BUILD_DIR)/lib$(LIB_NAME).a $(BUILD_DIR)/lib$(LIB_NAME).so

$(BUILD_DIR)/$(LIB_NAME).o: *.cpp *.hpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c *.cpp -o $(BUILD_DIR)/$(LIB_NAME).o

$(BUILD_DIR)/lib$(LIB_NAME).a: $(BUILD_DIR)/$(LIB_NAME).o
	ar rcs $(BUILD_DIR)/lib$(LIB_NAME).a $(BUILD_DIR)/$(LIB_NAME).o

$(BUILD_DIR)/lib$(LIB_NAME).so: $(BUILD_DIR)/$(LIB_NAME).o
	$(CXX) -shared -o $(BUILD_DIR)/lib$(LIB_NAME).so $(BUILD_DIR)/$(LIB_NAME).o

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
