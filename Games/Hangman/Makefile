# Makefile

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source files
SRCS = src/main.cpp

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = hangman

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)