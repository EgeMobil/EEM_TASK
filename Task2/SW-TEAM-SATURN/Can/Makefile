#Compiler
CC = gcc

#Compiler flags
CFLAGS = -Wall -Wextra -std=c99 \
		-ISrc/Application \
		-ISrc/HAL \
		-ISrc/Movement

#Target file
TARGET = program


#Source files
SRCS = Src/Application/ApplicationStateMachine.c
SRCS += Src/HAL/Hal.c
SRCS += Src/Movement/Move.c
SRCS += Src/Main/main.c

OBJS = $(SRCS:.c=.o)

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
