CC = gcc
CFLAGS = -I./include -Wall
SRC = src/speed_control.c src/main.c
OBJ = $(SRC:.c=.o)
OUT = my_program.exe

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)
