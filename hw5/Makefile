# Compiler and flags
CXX = c++
CXXFLAGS = -std=c++23 -g

# Target executable
TARGET = solution

# Source files
SRC = solution.cpp

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Run tests
test:
	pytest test_game.py

# Clean build files
clean:
	rm -f $(TARGET) *.o

