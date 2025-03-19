# Compiler and Flags
CC = gcc
CFLAGS = -I./inc \
		 -I./build \
		 -I../<Abstract_FeatureName> \
#Receiver Interface Include path
		 -I../<Abstract_FeatureName>/<IReceiverInterfaceName>/inc \
#Sender Interface Include path
		-I../<Abstract_FeatureName>/<ISenderInterfaceName>/inc \

		 -Wall -Wextra -g

# Source and output files
SRC = ./build/main.c \
# Test code source 
	  ./build/tc .c \
# Base class definition source
	./src/<CompName>.c \
# Runable source
	./src/<CompName>_ru<RunableNames>.c \
#Interface source definition
	../<Abstract_FeatureName>/<IInterfaceName>/src/<IInterfaceName>.c \
	../<Abstract_FeatureName>/<ISenderInterfaceName>/src/<ISenderInterfaceName>.c \
	../<Abstract_FeatureName>/<IReceiverInterfaceName>/src/<IReceiverInterfaceName>.c \
OUT = ./build/main.exe

# Target
all: $(OUT)

# Outputfile
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean
clean:
	if exist build\*.exe del /Q build\*.exe

