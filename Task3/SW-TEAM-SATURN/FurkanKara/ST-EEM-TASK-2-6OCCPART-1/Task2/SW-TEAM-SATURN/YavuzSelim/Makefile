CFLAGS = -I./inc -Wall -Wextra -g
SRC = ./build/main.c \
      ./src/speed_control.c
OUT = ./build/main.exe

all: $(OUT)

$(OUT): $(SRC)
		$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
		rm -f obj/*.o obj/speed_control.o main.d speed_control.d