CC = gcc
CFLAGS = -Wall -Wextra -Iinc
SRC = src/main.c src/traction_control.c
OBJ = $(SRC:.c=.o)
TARGET = program.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
