# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Output executable name
TARGET = main.exe

# Default rule to compile the program
all: $(TARGET)

# Compile main.c
$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

# Clean up compiled files
clean:
	rm -f $(TARGET)
