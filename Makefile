# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Output executable name
TARGET = matrix_program.exe

# Source files
SRC = main.cpp matrix.cpp
OBJ = $(SRC:.cpp=.o)

# Default rule: Compile the program
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile .cpp files into .o files
%.o: %.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	del /Q $(OBJ) $(TARGET) 2>nul || exit 0
