# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Target executable and source files
TARGET = test_main
SOURCES = ring_buffer_test.c ring_buffer.c

# Default target: build the executable
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Run the test program
test: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)

