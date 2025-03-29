# Derleyici ve bayraklar
CC = gcc
CFLAGS = -Iinc -Wall -Wextra -std=c11
LDFLAGS = 

# Kaynak ve hedef dosyalar
SRC = src/climate_control.c main.c
OBJ = $(SRC:.c=.o)
TARGET = build/climate_control

# Varsayılan derleme hedefi
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Kaynak dosyaları nesne dosyalarına çevirme
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Temizleme komutu
clean:
	rm -f src/*.o main.o $(TARGET)
