CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11 -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

TARGET = Main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET) || del /F /Q src\*.o $(TARGET)
