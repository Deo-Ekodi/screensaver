# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++23

# Source files
# SRCS = def_screen_saver_proc.cpp register_dialog_classes.cpp screen_saver_configure_dialog.cpp screen_saver_proc.cpp
SRCS = src/*

# Object files
OBJS = $(addprefix build/obj/,$(SRCS:.cpp=.o))

# Executable name
EXEC = build/exe/screensaver.src

# Default target
all: build/exe/ $(EXEC)

# Create build directory if it doesn't exist
build:
	mkdir -p build/obj
	cd build
	mkdir exe

# Rule to compile .cpp files to .o files
build/obj/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(EXEC): build $(OBJS)
	$(CC) $(OBJS) -o $@ -lgdi32

# Clean up build directory and executable
clean:
	rm -rf build/obj/*
	rm -rf build/exe/*
	rm -f $(EXEC)

# Phony targets
.PHONY: all clean
