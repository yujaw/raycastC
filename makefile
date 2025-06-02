# Compiler to use
CC = gcc

# Name of the output executable
TARGET = raycast

# Source files
SRC = main.c glad.c

# Compiler flags: show all warnings, use C11 standard
CFLAGS = -Wall -std=c11

# Include directories (will be overwritten below)
INCLUDES = -Iinclude

# Get the Homebrew prefix for glfw
BREW_PREFIX = $(shell brew --prefix glfw)

# Include directories: project include and glfw include
INCLUDES = -Iinclude -I$(BREW_PREFIX)/include

# Libraries to link: glfw, OpenGL framework, dl, math
LIBS = -L$(BREW_PREFIX)/lib -lglfw -framework OpenGL -ldl -lm

# Default target: build the executable
all: $(TARGET)

# Link the executable from source files
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(INCLUDES) $(LIBS)

# Clean up build artifacts
clean:
	rm -f $(TARGET)