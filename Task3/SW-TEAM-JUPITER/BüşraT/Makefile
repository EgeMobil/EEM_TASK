# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror
TARGET_EXE = acceleration_control.exe
TARGET_OUT = acceleration_control.out

# Source files
SRC = main.c acceleration_control.c
OBJ = $(SRC:.c=.o)

# Default rule to compile the program
all: $(TARGET_EXE) $(TARGET_OUT)

# Compile object files first
$(TARGET_EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET_EXE)

$(TARGET_OUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET_OUT)

# Compile each C file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJ) $(TARGET_EXE) $(TARGET_OUT)