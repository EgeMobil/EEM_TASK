# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Output executable name
TARGET = steering_app.exe

# Default rule to compile the program
all: $(TARGET)

# Compile main.c and steering_control.c together
$(TARGET): main.c steering_control.c
	$(CC) $(CFLAGS) main.c steering_control.c -o $(TARGET)

# Clean up compiled files
clean:
	rm -f $(TARGET)
