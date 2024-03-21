# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++23

# Source files directory
SRCDIR = src

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Object files directory
OBJDIR = build

# Object files
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.obj,$(SRCS))

# Executable name
EXEC = $(OBJDIR)/screensaver.scr

# Default target
all: $(EXEC)

# Create build directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Rule to compile .cpp files to .obj files
$(OBJDIR)/%.obj: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into the screensaver
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ -lgdi32

# Clean up build directory and screensaver file
clean:
	rm $(OBJDIR)/*

# Phony targets
.PHONY: all clean
