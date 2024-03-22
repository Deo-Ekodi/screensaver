# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Source files directory
SRC_DIR = src
SETTINGS_DIR = $(SRC_DIR)/settings

# Object files directory
OBJ_DIR = build

# Resource files directory
RES_DIR = $(SETTINGS_DIR)

# Executable name
EXEC = my_screensaver.exe

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Resource files
RES_FILES = $(wildcard $(RES_DIR)/*.rc)
RES_OBJS = $(patsubst $(RES_DIR)/%.rc,$(OBJ_DIR)/%.res,$(RES_FILES))

# Build executable
$(EXEC): $(OBJS) $(RES_OBJS)
	$(CC) $(OBJS) $(RES_OBJS) -o $@ -lgdi32

# Compile C++ source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Compile resource files
$(OBJ_DIR)/%.res: $(RES_DIR)/%.rc
	windres $< -O coff -o $@

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.res $(EXEC)
