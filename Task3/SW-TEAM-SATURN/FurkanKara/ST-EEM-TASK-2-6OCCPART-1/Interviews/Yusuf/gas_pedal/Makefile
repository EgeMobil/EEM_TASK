CC      = gcc
CFLAGS  = -Wall -Wextra -Iinclude
LDFLAGS = -lm

SRC     = src/main.c src/controller.c src/interface.c src/system.c src/logger.c
OBJ     = $(SRC:.c=.o)
TARGET  = gas_pedal

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
