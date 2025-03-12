# Compiler and Flags
CC = gcc
CFLAGS = -I./inc  -I./build  -Wall -Wextra -g

# Source and output files
SRC = ./main.c ./src/AccelerationManager.c ./src/AccelerationManager_ruInit.c ./src/AccelerationManager_ruControl.c ./src/AccelerationManager_ruUpdate.c

OUT = ./build/Executable.exe

# Target
all: $(OUT)

# Outputfile
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean
clean:
	if exist build\*.exe del /Q build\*.exe

