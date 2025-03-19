# Derleyici ve bayraklar
CC = gcc
CFLAGS = -Iinc -Wall -Wextra -std=c11
LDFLAGS = 

# Kaynak ve hedef dosyalar
SRC = src/main.c src/ldr_control.c
OBJ = $(SRC:.c=.o)
TARGET = build/main.exe


# Varsayılan derleme hedefi
all: $(TARGET)

# Derleme kuralları
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Kaynak dosyaları nesne dosyalarına çevirme
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Temizleme komutu
clean:
	rm -f src/*.o $(TARGET)
