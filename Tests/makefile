
CXX      = g++ -g -O0
#CXX      = g++ -O2

CXXFLAGS = -std=c++20 -Wall -Wextra -I ..
LDFLAGS  = -lm   # Add any required libraries (e.g., -lm for math)

# Directories
TST_DIR = .
SRC_DIR = ../src
OBJ_DIR = ../obj
BIN_DIR = ../bin

TARGET = $(BIN_DIR)/tests
HEADERS = $(wildcard $(SRC_DIR)/*.h) $(wildcard $(SRC_DIR)/*.hpp)
TESTS   = $(wildcard $(TST_DIR)/*.cpp)
OBJECTS = $(patsubst $(TST_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TESTS))

all: $(OBJ_DIR) $(BIN_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR)/catch_amalgamated.o: ../catch2/catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJECTS): $(HEADERS) | $(OBJ_DIR)

$(TARGET): $(OBJ_DIR)/catch_amalgamated.o $(OBJECTS) $(HEADERS) | $(BIN_DIR)
	$(CXX) $(OBJ_DIR)/catch_amalgamated.o $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(TST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
