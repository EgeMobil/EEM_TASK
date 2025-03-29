CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = ./main.c ./acceleration_control.c
OUT = ./main.exe

all: $(OUT)


$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)
