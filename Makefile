# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11

# Source files
SRCS = screensaver.cpp

# Object files
OBJS = $(addprefix build/,$(SRCS:.cpp=.o))

# Executable name
EXEC = screensaver.exe

# Default target
all: build $(EXEC)

# Create build directory if it doesn't exist
build:
	mkdir -p build

# Rule to compile .cpp files to .o files
build/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ -lgdi32

# Clean up build directory and executable
clean:
	rm -rf build
	rm -f $(EXEC)

# Phony targets
.PHONY: all clean
