# Compiler and Flags
CC = gcc
CFLAGS = -I./inc  -I./build  -Wall -Wextra -g

# Source and output files
SRC = ./build/main.c ./src/acceleration_control.c ./build/tcCompName.c

OUT = ./build/main.exe

# Target
all: $(OUT)

# Outputfile
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean
clean:
	if exist build\*.exe del /Q build\*.exe

