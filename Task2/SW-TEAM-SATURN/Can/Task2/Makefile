#Compiler
CC = gcc

#Compiler flags
CFLAGS = -Wall -Wextra -std=c99 \
		-IInc \
		-IAcc \
		-ISensor 

#Target file
TARGET = program


#Source files
SRCS += Acc/acc.c
SRCS += Main/main.c
SRCS += Sensor/sensor.c

OBJS = $(SRCS:.c=.o)

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
