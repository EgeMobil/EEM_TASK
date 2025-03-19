CC = gcc
CFLAGS = -Wall -Wextra -I./inc
BUILD_DIR = build
SRC_DIR = src

# Just compile the source files directly to main.exe
$(BUILD_DIR)/main.exe: $(SRC_DIR)/steering_control.c $(BUILD_DIR)/main.c
	$(CC) $(CFLAGS) $^ -o $@

# Default target
all: $(BUILD_DIR)/main.exe

# Run the program
run: $(BUILD_DIR)\main.exe
	$(BUILD_DIR)\main.exe

# Clean only object files
clean:
	if exist "$(BUILD_DIR)\*.o" del /Q /F "$(BUILD_DIR)\*.o"
	if exist "$(SRC_DIR)\*.o" del /Q /F "$(SRC_DIR)\*.o"

.PHONY: all run clean